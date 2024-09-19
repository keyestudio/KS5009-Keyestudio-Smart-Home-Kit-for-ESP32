from machine import Pin
import time
from mfrc522_config import mfrc522Config
from soft_iic import softIIC

class mfrc522(mfrc522Config,softIIC):
   
    def __init__(self, scl_, sda_, addr_):
        # Invoke the parent class's constructor
        softIIC.__init__(self, scl_, sda_, addr_)


    # Writes a byte to the specified register in the MFRC522 chip.
    # The interface is described in the datasheet section 8.1.2. 
    def PCD_WriteRegister(self,  
                          _reg,  #The register to write to. One of the PCD_Register enums.
                          _dat   #The value to write.
                          ):
        self.Write(self.addr, _reg, _dat)

    # Writes a number of bytes to the specified register in the MFRC522 chip.
    # The interface is described in the datasheet section 8.1.2.
    def PCD_WriteRegister_(self,  
                           reg,    #The register to write to. One of the PCD_Register enums.
                           count,  #The number of bytes to write to the register
                           lst     #The values to write. Byte array.
                           ):
        self.IIC_start()
        self.IIC_write_byte(self.addr<<1)
        self.IIC_slave_ack()
        
        self.IIC_write_byte(reg)
        self.IIC_slave_ack()
        
        for i in range(count):
            self.IIC_write_byte(lst[i])
            self.IIC_slave_ack()
        self.IIC_stop()
 

    # Reads a byte from the specified register in the MFRC522 chip.
    # The interface is described in the datasheet section 8.1.2.
    def PCD_ReadRegister(self, _reg):     # The register to read from. One of the PCD_Register enums.
        return self.Read(self.addr,_reg)
        # End PCD_ReadRegister()


    # Reads a number of bytes from the specified register in the MFRC522 chip.
    # The interface is described in the datasheet section 8.1.2.
    # self.PCD_ReadRegister_(self.FIFODataReg, n, backData, rxAlign)
    def PCD_ReadRegister_(self,
                          reg,       # The register to read from. One of the PCD_Register enums.
                          count,     # The number of bytes to read
                          values,    # Byte array to store the values in.
                          rxAlign = 0    # Only bit positions rxAlign..7 in values[0] are updated.
                          ):
        if count == 0:
            return
        self.IIC_start()
        self.IIC_write_byte(self.addr<<1)
        self.IIC_slave_ack()
        #print("--------------1")
        self.IIC_write_byte(reg)
        self.IIC_slave_ack()
        self.IIC_stop()
        #print("--------------2")
        self.IIC_start()
        self.IIC_write_byte((self.addr<<1)|1)
        self.IIC_slave_ack()
        #print("--------------3")
        
        for i in range(count):
            if i == 0 and rxAlign != 0:         # Only update bit positions rxAlign..7 in values[0]
                # Create bit mask for bit positions rxAlign..7
                mask = 0
                for i in range(rxAlign, 8):
                    mask |= (1<<i)
                # Read value and tell that we want to read the same address again.
                value = self.IIC_read_byte()
                # Apply mask to both current value of values[0] and the new data in value.
                values[0] = (values[i] & ~mask) | (value & mask)
            else:   # Normal case
                values[i] = self.IIC_read_byte()
            
            if i < count - 1:
                self.IIC_master_ack()
            else:
                self.IIC_master_notack()
                self.IIC_stop()
        #print(values)     
        # End PCD_ReadRegister()
        
        
    def PCD_Init(self):
        self.PCD_Reset()

        # When communicating with a PICC we need a timeout if something goes wrong.
        # f_timer = 13.56 MHz / (2*TPreScaler+1) where TPreScaler = [TPrescaler_Hi:TPrescaler_Lo].
        # TPrescaler_Hi are the four low bits in TModeReg. TPrescaler_Lo is TPrescalerReg.
        self.PCD_WriteRegister(self.TModeReg, 0x80)      # TAuto=1; timer starts automatically at the end of the transmission in all communication modes at all speeds
        self.PCD_WriteRegister(self.TPrescalerReg, 0xA9) # TPreScaler = TModeReg[3..0]:TPrescalerReg, ie 0x0A9 = 169 => f_timer=40kHz, ie a timer period of 25�s.
        self.PCD_WriteRegister(self.TReloadRegH, 0x03)   # Reload timer with 0x3E8 = 1000, ie 25ms before timeout.
        self.PCD_WriteRegister(self.TReloadRegL, 0xE8)   

        self.PCD_WriteRegister(self.TxASKReg, 0x40)      # Default 0x00. Force a 100 % ASK modulation independent of the ModGsPReg register setting
        self.PCD_WriteRegister(self.ModeReg, 0x3D)       # Default 0x3F. Set the preset value for the CRC coprocessor for the CalcCRC command to 0x6363 (ISO 14443-3 part 6.2.4)
        self.PCD_AntennaOn()                        # Enable the antenna driver pins TX1 and TX2 (they were disabled by the reset)
        # End PCD_Init()

        
    # Performs a soft reset on the MFRC522 chip and waits for it to be ready again.
    def PCD_Reset(self):
        # Issue the SoftReset command.
        self.PCD_WriteRegister(self.CommandReg, self.PCD_SoftReset)
        time.sleep(1)
        
        if self.PCD_ReadRegister(self.CommandReg) & (1<<4):
            print("Reset error!")


    # Turns the antenna on by enabling pins TX1 and TX2.
    # After a reset these pins are disabled.
    def PCD_AntennaOn(self):
        value = self.PCD_ReadRegister(self.TxControlReg)
        #print("AntennaOn data:" + str(value))
        if value & 0x03 != 0x03:
            self.PCD_WriteRegister(self.TxControlReg, value | 0x03)
        #End PCD_AntennaOn()
 
 
    # Turns the antenna off by disabling pins TX1 and TX2.
    def PCD_AntennaOff(self):
        self.PCD_ClearRegisterBitMask(self.TxControlReg, 0x03)

    
    # Sets the bits given in mask in register reg.
    def PCD_SetRegisterBitMask(self,
                               reg,              # The register to update. One of the PCD_Register enums.
                               mask              # The bits to set.
                               ):
        tmp = self.PCD_ReadRegister(reg)
        self.PCD_WriteRegister(reg, tmp | mask)  # set bit mask
        # End PCD_SetRegisterBitMask()
    
    
    # Clears the bits given in mask from register reg.
    def PCD_ClearRegisterBitMask(self,
                                 reg,   # The register to update. One of the PCD_Register enums.
                                 mask   # The bits to clear.
                                 ):
        tmp = self.PCD_ReadRegister(reg)
        self.PCD_WriteRegister(reg, tmp & (~mask))  #clear bit mask
        #  End PCD_ClearRegisterBitMask()
        
        
    # Use the CRC coprocessor in the MFRC522 to calculate a CRC_A.  
    #
    # @return STATUS_OK on success, STATUS_??? otherwise.
    def PCD_CalculateCRC(self,
                         data,   #In: Pointer to the data to transfer to the FIFO for CRC calculation.
                         length, #In: The number of bytes to transfer.
                         result  #Out: Pointer to result buffer. Result is written to result[0..1], low byte first.
                         ):
        self.PCD_WriteRegister(self.CommandReg, self.PCD_Idle)      # Stop any active command.
        self.PCD_WriteRegister(self.DivIrqReg, 0x04)                # Clear the CRCIRq interrupt request bit
        self.PCD_SetRegisterBitMask(self.FIFOLevelReg, 0x80)        # FlushBuffer = 1, FIFO initialization
        self.PCD_WriteRegister_(self.FIFODataReg, length, data)      # Write data to the FIFO
        self.PCD_WriteRegister(self.CommandReg, self.PCD_CalcCRC)   # Start the calculation
        # Wait for the CRC calculation to complete. Each iteration of the while-loop takes 17.73�s.
        while True:
            n = self.PCD_ReadRegister(self.DivIrqReg)    # DivIrqReg[7..0] bits are: Set2 reserved reserved MfinActIRq reserved CRCIRq reserved reserved
            if (n & 0x04):                               # CRCIRq bit set - calculation done
                break
            if (--i == 0):                               # The emergency break. We will eventually terminate on this one after 89ms. Communication with the MFRC522 might be down.
                return self.STATUS_TIMEOUT
        self.PCD_WriteRegister(self.CommandReg, self.PCD_Idle)     # Stop calculating CRC for new content in the FIFO. 
        
        # Transfer the result from the registers to the result buffer
        result[0] = self.PCD_ReadRegister(self.CRCResultRegL)
        result[1] = self.PCD_ReadRegister(self.CRCResultRegH)
        return self.STATUS_OK        
        # End PCD_CalculateCRC()


    # Executes the Transceive command.
    # CRC validation can only be done if backData and backLen are specified.
    # 
    # @return STATUS_OK on success, STATUS_??? otherwise.
    def PCD_TransceiveData(self,
                           sendData,   # Pointer to the data to transfer to the FIFO.
                           sendLen,    # Number of bytes to transfer to the FIFO.
                           backData,   # NULL or pointer to buffer if data should be read back after executing the command.
                           backLen,    # In: Max number of bytes to write to *backData. Out: The number of bytes returned.
                           validBits,  # In/Out: The number of valid bits in the last byte. 0 for 8 valid bits. Default NULL.
                           rxAlign,    # In: Defines the bit position in backData[0] for the first bit received. Default 0.
                           checkCRC    # In: True => The last two bytes of the response is assumed to be a CRC_A that must be validated.
                           ):
        waitIRq = 0x30
        return self.PCD_CommunicateWithPICC(self.PCD_Transceive, waitIRq, sendData, sendLen, backData, backLen, validBits, rxAlign, checkCRC)
        # End PCD_TransceiveData()
        
        
    # Transfers data to the MFRC522 FIFO, executes a command, waits for completion and transfers data back from the FIFO.
    # CRC validation can only be done if backData and backLen are specified.
    #
    # @return STATUS_OK on success, STATUS_??? otherwise.
    # result = self.PCD_TransceiveData(buffer, bufferUsed, responseBuffer, responseLength, tLB, rxAlign, 0)
    def PCD_CommunicateWithPICC(self,
                                command,        # The command to execute. One of the PCD_Command enums.
                                waitIRq,        # The bits in the ComIrqReg register that signals successful completion of the command.
                                sendData,       # Pointer to the data to transfer to the FIFO.
                                sendLen,        # Number of bytes to transfer to the FIFO.
                                backData,       # NULL or pointer to buffer if data should be read back after executing the command.
                                backLen,        # In: Max number of bytes to write to *backData. Out: The number of bytes returned.
                                validBits,      # In/Out: The number of valid bits in the last byte. 0 for 8 valid bits.
                                rxAlign,        # In: Defines the bit position in backData[0] for the first bit received. Default 0.
                                checkCRC        # In: True => The last two bytes of the response is assumed to be a CRC_A that must be validated.
                                ):
        txLastBits = validBits[0] if validBits != None else 0
        bitFraming = (rxAlign << 4) + txLastBits    # RxAlign = BitFramingReg[6..4]. TxLastBits = BitFramingReg[2..0]
        
        self.PCD_WriteRegister(self.CommandReg, self.PCD_Idle)        # Stop any active command.
        self.PCD_WriteRegister(self.ComIrqReg, 0x7F)                  # Clear all seven interrupt request bits
        self.PCD_SetRegisterBitMask(self.FIFOLevelReg, 0x80)          # FlushBuffer = 1, FIFO initialization
        self.PCD_WriteRegister_(self.FIFODataReg, sendLen, sendData)  # Write sendData to the FIFO
        self.PCD_WriteRegister(self.BitFramingReg, bitFraming)        # Bit adjustments
        self.PCD_WriteRegister(self.CommandReg, command)              # Execute the command
        if command == self.PCD_Transceive:
            self.PCD_SetRegisterBitMask(self.BitFramingReg, 0x80)     # StartSend=1, transmission of data starts

        # Wait for the command to complete.
        # In PCD_Init() we set the TAuto flag in TModeReg. This means the timer automatically starts when the PCD stops transmitting.
        # Each iteration of the do-while-loop takes 17.86�s.
        i = 2000
        while True:
            n = self.PCD_ReadRegister(self.ComIrqReg)    #ComIrqReg[7..0] bits are: Set1 TxIRq RxIRq IdleIRq HiAlertIRq LoAlertIRq ErrIRq TimerIRq
            if n & waitIRq:
                break
            if n & 0x01:
                return self.STATUS_TIMEOUT
            if --i == 0:
                return self.STATUS_TIMEOUT
        
        # Stop now if any errors except collisions were detected.
        errorRegValue = self.PCD_ReadRegister(self.ErrorReg)    # ErrorReg[7..0] bits are: WrErr TempErr reserved BufferOvfl CollErr CRCErr ParityErr ProtocolErr
        if errorRegValue & 0x13:                                # BufferOvfl ParityErr ProtocolErr
            return self.STATUS_ERROR
        
        # If the caller wants data back, get it from the MFRC522.
        if backData != None and backLen != None :
            n = self.PCD_ReadRegister(self.FIFOLevelReg)    # Number of bytes in the FIFO
            if n> backLen[0]:
                return self.STATUS_NO_ROOM
            backLen[0] = n                                     # Number of bytes returned
            # Note: Use list mutable types in Python
            self.PCD_ReadRegister_(self.FIFODataReg, n, backData, rxAlign)  # Get received data from FIFO
            #print("backData:")
            #print(backData)
            _validBits = self.PCD_ReadRegister(self.ControlReg) & 0x07  # RxLastBits[2:0] indicates the number of valid bits in the last received byte. If this value is 000b, the whole byte is valid.
            if validBits != None:
                validBits[0] = _validBits
                
        # Tell about collisions
        if errorRegValue & 0x08: # collErr
            return self.STATUS_COLLISION
        
        # Perform CRC_A validation if requested.
        if backData != None and  backLen != None  and checkCRC != 0:
            # In this case a MIFARE Classic NAK is not OK.
            if backLen[0] == 1 and _validBits[0] == 4:
                return self.STATUS_MIFARE_NACK
            # We need at least the CRC_A value and all 8 bits of the last byte must be received.
            if backLen[0] < 2 or _validBits != 0:
                return self.STATUS_CRC_WRONG
            # Verify CRC_A - do our own calculation and store the control in controlBuffer.
            controlBuffer = [0, 0]
            n = self.PCD_CalculateCRC(backData[0], backLen[0] - 2, controlBuffer[0])
            if n != self.STATUS_OK:
                return n
            if (backData[backLen[0] - 2] != controlBuffer[0]) or (backData[backLen[0] - 1] != controlBuffer[1]):
                return self.STATUS_CRC_WRONG
        return self.STATUS_OK;
        # End PCD_CommunicateWithPICC()
        
            
    # Transmits a REQuest command, Type A. Invites PICCs in state IDLE to go to READY and prepare for anticollision or selection. 7 bit frame.
    # Beware: When two PICCs are in the field at the same time I often get STATUS_TIMEOUT - probably due do bad antenna design.
    # 
    # @return STATUS_OK on success, STATUS_??? otherwise.
    def PICC_RequestA(self,
                      bufferATQA,  # The buffer to store the ATQA (Answer to request) in
                      bufferSize   # Buffer size, at least two bytes. Also number of bytes returned if STATUS_OK.
                      ):
        cmd    = [self.PICC_CMD_REQA]
        return self.PICC_REQA_or_WUPA(cmd, bufferATQA, bufferSize)
        # End PICC_RequestA()
        
 
    # Transmits REQA or WUPA commands.
    # Beware: When two PICCs are in the field at the same time I often get STATUS_TIMEOUT - probably due do bad antenna design.
    # 
    # @return STATUS_OK on success, STATUS_??? otherwise.
    def PICC_REQA_or_WUPA(self,
                          command,     # The command to send - PICC_CMD_REQA or PICC_CMD_WUPA
                          bufferATQA,  # The buffer to store the ATQA (Answer to request) in
                          bufferSize   # Buffer size, at least two bytes. Also number of bytes returned if STATUS_OK.
                          ):
        if bufferATQA == None or bufferSize[0] < 2:   # The ATQA response is 2 bytes long.
            return self.STATUS_NO_ROOM
        self.PCD_ClearRegisterBitMask(self.CollReg, 0x80) # ValuesAfterColl=1 => Bits received after collision are cleared.
        validBits = [7]  # For REQA and WUPA we need the short frame format - transmit only 7 bits of the last (and only) byte. TxLastBits = BitFramingReg[2..0]
        status = self.PCD_TransceiveData(command, 1, bufferATQA, bufferSize, validBits, 0, 0)
        if status != self.STATUS_OK:
            return status
        if bufferSize[0] != 2 or validBits[0] != 0:
            return self.STATUS_ERROR
        return self.STATUS_OK
        # End PICC_REQA_or_WUPA()
    

    # Transmits SELECT/ANTICOLLISION commands to select a single PICC.
    # Before calling this function the PICCs must be placed in the READY(*) state by calling PICC_RequestA() or PICC_WakeupA().
    # On success:
    #       - The chosen PICC is in state ACTIVE(*) and all other PICCs have returned to state IDLE/HALT. (Figure 7 of the ISO/IEC 14443-3 draft.)
    #       - The UID size and value of the chosen PICC is returned in *uid along with the SAK.
    # 
    # A PICC UID consists of 4, 7 or 10 bytes.
    # Only 4 bytes can be specified in a SELECT command, so for the longer UIDs two or three iterations are used:
    #       UID size    Number of UID bytes    Cascade levels    Example of PICC
    #       ========    ===================    ==============    ===============
    #       single               4                   1           MIFARE Classic
    #       double               7                   2           MIFARE Ultralight
    #       triple              10                   3           Not currently in use?
    # 
    # @return STATUS_OK on success, STATUS_??? otherwise.
    def PICC_Select(self,
                    uid,           # Pointer to Uid struct. Normally output, but can also be used to supply a known UID.
                    validBits      # The number of known UID bits supplied in *uid. Normally 0. If set you must also supply uid->size.
                    ):
        uidComplete = False
        selectDone = False
        useCascadeTag = False
        cascadeLevel = 1
        result = 0
        count = 0
        index = 0
        uidIndex = 0                     # The first index in uid->uidByte[] that is used in the current Cascade Level.
        currentLevelKnownBits = 0        # The number of known UID bits in the current Cascade Level.
        buffer = [0,0,0,0,0,0,0,0,0]     # The SELECT/ANTICOLLISION commands uses a 7 byte standard frame + 2 bytes CRC_A
        bufferUsed = 0                   # The number of bytes used in the buffer, ie the number of bytes to transfer to the FIFO.
        rxAlign = 0                      # Used in BitFramingReg. Defines the bit position for the first bit received.
        txLastBits = 0                   # Used in BitFramingReg. The number of valid bits in the last transmitted byte.
        responseBuffer = [0]
        responseLength = [0]
        # Description of buffer structure:
        #       Byte 0: SEL                 Indicates the Cascade Level: PICC_CMD_SEL_CL1, PICC_CMD_SEL_CL2 or PICC_CMD_SEL_CL3
        #       Byte 1: NVB                 Number of Valid Bits (in complete command, not just the UID): High nibble: complete bytes, Low nibble: Extra bits.
        #       Byte 2: UID-data or CT      See explanation below. CT means Cascade Tag.
        #       Byte 3: UID-data
        #       Byte 4: UID-data
        #       Byte 5: UID-data
        #       Byte 6: BCC                 Block Check Character - XOR of bytes 2-5
        #       Byte 7: CRC_A
        #       Byte 8: CRC_A
        #  The BCC and CRC_A is only transmitted if we know all the UID bits of the current Cascade Level.
        # 
        #  Description of bytes 2-5: (Section 6.5.4 of the ISO/IEC 14443-3 draft: UID contents and cascade levels)
        #       UID size    Cascade level   Byte2   Byte3   Byte4   Byte5
        #       ========    =============   =====  =====    =====   =====
        #        4 bytes        1           uid0    uid1    uid2    uid3
        #        7 bytes        1           CT      uid0    uid1    uid2
        #                       2           uid3    uid4    uid5    uid6
        #       10 bytes        1           CT      uid0    uid1    uid2
        #                       2           CT      uid3    uid4    uid5
        #                       3           uid6    uid7    uid8    uid9
    
        # Sanity checks
        if validBits > 80:
            return self.STATUS_INVALID
    
        # Prepare MFRC522
        self.PCD_ClearRegisterBitMask(self.CollReg, 0x80)    # ValuesAfterColl=1 => Bits received after collision are cleared.

        # Repeat Cascade Level loop until we have a complete UID.
        uidComplete = False
        while uidComplete == False:
            # Set the Cascade Level in the SEL byte, find out if we need to use the Cascade Tag in byte 2.    
            if cascadeLevel == 1:
                buffer[0] = self.PICC_CMD_SEL_CL1
                uidIndex = 0
                useCascadeTag = validBits and uid.size > 4    # When we know that the UID has more than 4 bytes
            elif cascadeLevel == 2:
                buffer[0] = self.PICC_CMD_SEL_CL2
                uidIndex = 3
                useCascadeTag = validBits and uid.size > 7    # When we know that the UID has more than 7 bytes
            elif cascadeLevel == 3:
                buffer[0] = self.PICC_CMD_SEL_CL3
                uidIndex = 6
                useCascadeTag = False                         # Never used in CL3.           
            else:
                return self.STATUS_INTERNAL_ERROR
    
            # How many UID bits are known in this Cascade Level?
            currentLevelKnownBits = validBits - (8 * uidIndex)
            if currentLevelKnownBits < 0:
                currentLevelKnownBits = 0
        
            # Copy the known bits from uid->uidByte[] to buffer[]
            index = 2  # destination index in buffer[]
            #print(useCascadeTag);
            if useCascadeTag:
                index = index+1
                buffer[index] = self.PICC_CMD_CT
            # The number of bytes needed to represent the known bits for this level.
            bytesToCopy = 1 if currentLevelKnownBits % 8 > 0 else 0 # (currentLevelKnownBits % 8 ? 1 : 0) 
            bytesToCopy = currentLevelKnownBits // 8 + bytesToCopy
            if bytesToCopy:
                maxBytes = 3 if useCascadeTag else 4  # maxBytes = useCascadeTag ? 3 : 4
                if bytesToCopy > maxBytes:
                    bytesToCopy = maxBytes
                for i in range(bytesToCopy):
                    index = index+1
                    buffer[index] = uid.uidByte[uidIndex + i]
            # Now that the data has been copied we need to include the 8 bits in CT in currentLevelKnownBits
            if useCascadeTag:
                currentLevelKnownBits = currentLevelKnownBits + 8
        
            # Repeat anti collision loop until we can transmit all UID bits + BCC and receive a SAK - max 32 iterations.
            selectDone = False            
            while selectDone == False:
                # Find out how many bits and bytes to send and receive. 
                if currentLevelKnownBits >= 32:  # All UID bits in this Cascade Level are known. This is a SELECT.
                    # Serial.print(F("SELECT: currentLevelKnownBits=")); Serial.println(currentLevelKnownBits, DEC);
                    buffer[1] = 0x70 # NVB - Number of Valid Bits: Seven whole bytes
                    # Calculate BCC - Block Check Character
                    buffer[6] = buffer[2] ^ buffer[3] ^ buffer[4] ^ buffer[5]
                    # Calculate CRC_A
                    tmpBuffer = [buffer[7], buffer[8]]
                    result = self.PCD_CalculateCRC(buffer, 7, tmpBuffer)
                    buffer[7] = tmpBuffer[0]
                    buffer[8] = tmpBuffer[1]
                    
                    if result != self.STATUS_OK:
                        return result
                    txLastBits  = 0   # 0 => All 8 bits are valid.
                    bufferUsed  = 9
                    # Store response in the last 3 bytes of buffer (BCC and CRC_A - not needed after tx)
                    responseBuffer = [0].copy()
                    responseBuffer[0] = buffer[6]
                    responseBuffer = responseBuffer + buffer[7:]
                    responseLength[0] = 3
                    bufferFlag = 6
                    
                else: # This is an ANTICOLLISION.
                    # Serial.print(F("ANTICOLLISION: currentLevelKnownBits=")); Serial.println(currentLevelKnownBits, DEC);
                    txLastBits      = currentLevelKnownBits % 8
                    count           = currentLevelKnownBits // 8      # Number of whole bytes in the UID part.
                    index           = 2 + count                           # Number of whole bytes: SEL + NVB + UIDs
                    buffer[1]       = (index << 4) + txLastBits           # NVB - Number of Valid Bits
                
                    bufferUsed      = 1 if txLastBits else 0
                    bufferUsed      = index + bufferUsed
                    
                    responseBuffer = [0].copy()
                    # Store response in the unused part of buffer
                    responseBuffer[0]  = buffer[index]
                    responseBuffer     = responseBuffer + buffer[index+1:]
                    responseLength[0]  = len(buffer) - index
                    bufferFlag = index

                # Set bit adjustments
                rxAlign = txLastBits              # Having a seperate variable is overkill. But it makes the next line easier to read.
                self.PCD_WriteRegister(self.BitFramingReg, (rxAlign << 4) + txLastBits)   # RxAlign = BitFramingReg[6..4]. TxLastBits = BitFramingReg[2..0]
    
                #Transmit the buffer and receive the response.
                tLB = [txLastBits]
                result = self.PCD_TransceiveData(buffer, bufferUsed, responseBuffer, responseLength, tLB, rxAlign, 0)
                for i in range(bufferFlag, bufferFlag+responseLength[0]):
                    buffer[i] = responseBuffer[i-bufferFlag]

                if result == self.STATUS_COLLISION:    # More than one PICC in the field => collision.
                    result = self.PCD_ReadRegister(CollReg) # CollReg[7..0] bits are: ValuesAfterColl reserved CollPosNotValid CollPos[4:0]
                    if result & 0x20:
                        return self.STATUS_COLLISION   # Without a valid collision position we cannot continue
                    collisionPos = result & 0x1F       # Values 0-31, 0 means bit 32.
                    if collisionPos == 0:
                        collisionPos = 32
                    if collisionPos <= currentLevelKnownBits:  # No progress - should not happen
                        return self.STATUS_INTERNAL_ERROR
                    # Choose the PICC with the bit set.
                    currentLevelKnownBits = collisionPos
                    count = (currentLevelKnownBits - 1) % 8    # The bit to modify
                    index = 1 if count else 0
                    index = 1 + (currentLevelKnownBits / 8) + index  # First byte is index 0.
                    buffer[index] = buffer[index] | (1 << count)
                elif result != self.STATUS_OK:
                    return result
                else: # STATUS_OK
                    if currentLevelKnownBits >= 32:  # This was a SELECT.
                        selectDone = True            # No more anticollision
                        # We continue below outside the while.
                    else:  # This was an ANTICOLLISION.
                        # We now have all 32 bits of the UID in this Cascade Level
                        currentLevelKnownBits = 32
                        # Run loop again to do the SELECT.
            # End of while (!selectDone)
    
            # We do not check the CBB - it was constructed by us above.
            # Copy the found UID bytes from buffer[] to uid->uidByte[]
            index = 3 if buffer[2] == self.PICC_CMD_CT else 2  # source index in buffer[]
            bytesToCopy = 3 if buffer[2] == self.PICC_CMD_CT else 4
            for i in range(bytesToCopy):
                uid.uidByte[uidIndex + i] = buffer[index]
                index = index+1
              
            # Check response SAK (Select Acknowledge)
            if responseLength[0] != 3 or txLastBits != 0: # SAK must be exactly 24 bits (1 byte + CRC_A).
                return self.STATUS_ERROR
            # Verify CRC_A - do our own calculation and store the control in buffer[2..3] - those bytes are not needed anymore.          
            CRCbuffer = [buffer[2]]
            CRCbuffer = CRCbuffer + buffer[3:]
            result = self.PCD_CalculateCRC(responseBuffer, 1, CRCbuffer)
            buffer[2] = CRCbuffer[0]
            buffer[3] = CRCbuffer[1]
            
            if result != self.STATUS_OK:
                return result
            
            if (buffer[2] != responseBuffer[1]) or (buffer[3] != responseBuffer[2]):
                return self.STATUS_CRC_WRONG
            if responseBuffer[0] & 0x04: # Cascade bit set - UID not complete yes
                cascadeLevel = cascadeLevel+1
            else:
                uidComplete = True
                uid.sak = responseBuffer[0] 
        # End of while (!uidComplete)
            
        # Set correct uid->size
        uid.size = 3 * cascadeLevel + 1       
        return self.STATUS_OK
        #  End PICC_Select()
                
                
    # Returns true if a PICC responds to PICC_CMD_REQA.
    # Only "new" cards in state IDLE are invited. Sleeping cards in state HALT are ignored.
    # 
    # @return bool
    def PICC_IsNewCardPresent(self):
        bufferATQA = [0, 0]
        bufferSize = [len(bufferATQA)]
        result = self.PICC_RequestA(bufferATQA, bufferSize)
        return result == self.STATUS_OK or result == self.STATUS_COLLISION
        #  End PICC_IsNewCardPresent()
        

    # Simple wrapper around PICC_Select.
    # Returns true if a UID could be read.
    # Remember to call PICC_IsNewCardPresent(), PICC_RequestA() or PICC_WakeupA() first.
    # The read UID is available in the class variable uid.
    # 
    # @return bool
    def PICC_ReadCardSerial(self):
        result = self.PICC_Select(self.uid, 0)
        return (result == self.STATUS_OK)
        # End PICC_ReadCardSerial()
        
        
    # Show details of PCD - MFRC522 Card Reader details.
    def ShowReaderDetails(self):
        v = self.PCD_ReadRegister(self.VersionReg)
        version = str(v)
        if v == 0x91:
            version = version + " = v1.0"
        elif v == 0x92:
            version = version + " = v2.0"
        else:
            version = version + "unknown"   
        print("MFRC522 Software Version:" + version)



