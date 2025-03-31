from machine import Pin
import time

class softIIC:

    def __init__(self, scl_, sda_, addr_):
        self.addr = addr_
        self.scl  = scl_
        self.sda  = sda_
        
        
    def IIC_start(self):
        Pin_scl = Pin(self.scl, Pin.OUT, value=1)    # create output pin
        Pin_sda = Pin(self.sda, Pin.OUT, value=1)    # create output pin                   
        #Pin_sda.value(1)
        #Pin_scl.value(1)
        time.sleep_us(5)
        #time.sleep(1)
        Pin_sda.value(0)                    
        time.sleep_us(5)
        Pin_scl.value(0)         
        #time.sleep(1)
        

    def IIC_stop(self):
        Pin_scl = Pin(self.scl, Pin.OUT, value=0)    # create output pin
        Pin_sda = Pin(self.sda, Pin.OUT, value=0)    # create output pin
        #Pin_scl.value(0) 
        #Pin_sda.value(0)                  
        time.sleep_us(5)
        Pin_scl.value(1)
        Pin_sda.value(1)
        time.sleep_us(5)  


    def IIC_master_ack(self):
        Pin_scl = Pin(self.scl, Pin.OUT, value=0)    # create output pin
        Pin_sda = Pin(self.sda, Pin.OUT, value=0)    # create output pin
        #Pin_scl.value(0)
        #Pin_sda.value(0)
        time.sleep_us(5)
        
        Pin_scl.value(1)
        time.sleep_us(5)
        Pin_scl.value(0)
        #Pin_sda.value(1)                      


    def IIC_master_notack(self):
        Pin_scl = Pin(self.scl, Pin.OUT, value=0)    # create output pin
        Pin_sda = Pin(self.sda, Pin.OUT, value=1)    # create output pin
        #Pin_scl.value(0)
        #Pin_sda.value(1)
        time.sleep_us(5)
        Pin_scl.value(1)                  
        time.sleep_us(5)
        Pin_scl.value(0)


    def IIC_slave_ack(self):
        i=0
        Pin_scl = Pin(self.scl, Pin.OUT, value=0)    # create output pin
        Pin_sda = Pin(self.sda, Pin.IN, Pin.PULL_UP)     # create input pin       
        Pin_scl.value(1)
        time.sleep_us(5)
        while Pin_sda.value() == 1:
            time.sleep_us(1)
            i = i+1
            if i>20:
                while 1 :
                    print("IIC slave device not ack")
                    time.sleep(1)
                #return
                    

    def IIC_read_byte(self):
        dat = 0
        Pin_scl = Pin(self.scl, Pin.OUT, value=0)    # create input pin
        Pin_sda = Pin(self.sda, Pin.IN, Pin.PULL_UP)     # create input pin        
        for i in range(8):
            Pin_scl.value(0)
            time.sleep_us(3)
            Pin_scl.value(1)
            time.sleep_us(2)
            #print(Pin_sda.value())
            if Pin_sda.value() == 1:
                dat = dat<<1 | 1
            else:
                dat = dat<<1
            time.sleep_us(5)
        return dat


    def IIC_write_byte(self, dat):
        Pin_scl = Pin(self.scl, Pin.OUT, value=0)    # create output pin
        Pin_sda = Pin(self.sda, Pin.OUT, value=0)    # create output pin        
        for i in range(8):
            if 0x80 & dat == 0x80:
                Pin_sda.value(1)
                #print(1)
            else:
                Pin_sda.value(0)
                #print(0)
            Pin_scl.value(1)
            time.sleep_us(5)
            Pin_scl.value(0)
            time.sleep_us(5)
            dat = dat<<1
        #print("--------------------")
 
 
    def Read(self, _adr, _reg):
        self.IIC_start()
        self.IIC_write_byte(_adr<<1)
        self.IIC_slave_ack()
        #print("--------------1")
        self.IIC_write_byte(_reg)
        self.IIC_slave_ack()
        self.IIC_stop()
        #print("--------------2")
        self.IIC_start()
        self.IIC_write_byte((_adr<<1)|1)
        self.IIC_slave_ack()
        #print("--------------3")
        dat = self.IIC_read_byte()
        self.IIC_master_notack()
        self.IIC_stop()
        return dat


    def Write(self, _adr, _reg, _dat):
        self.IIC_start()
        self.IIC_write_byte(_adr<<1)
        self.IIC_slave_ack()
        
        self.IIC_write_byte(_reg)
        self.IIC_slave_ack()
 
        self.IIC_write_byte(_dat)
        self.IIC_slave_ack()
        self.IIC_stop()
        
        