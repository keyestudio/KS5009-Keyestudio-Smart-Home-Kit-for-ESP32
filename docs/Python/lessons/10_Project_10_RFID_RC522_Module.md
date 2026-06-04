### Project 10: RFID RC522 Module

**Component Knowledge**

Radio frequency identification, the card reader is composed of a radio
frequency module and a high-level magnetic field. The Tag transponder is
a sensing device, which doesn’t contain a battery. It only contains tiny
integrated circuit chips and media for storing data and antennas for
receiving and transmitting signals.

To read the data in the tag, first put it into the reading range of the
card reader. The reader will generate a magnetic field, which can
produce electricity according to Lenz's law, then the RFID tag will
supply power, thereby activating the device.

![image40](../media/982ac6a9da0e8f55465ca5a969ac0dfe.png)

**Control Pins**

Use IIC communication

| SDA | SDA |
| --- | --- |
| SCL | SCL |


#### Project 10.1 Open the Door

Open the folder where the mfrc522_config.py , soft_iic.py and
mfrc522_i2c.py are located

Open“Thonny”，click“This computer”→“D:”→“2. Python
Projects”→“pj10_rc522_RFID”. Select “mfrc522_config.py”, right-click
your mouse to select “\ **Upload to /**\ ”，wait for “mfrc522_config.py”
to be uploaded to ESP32; and select “soft_iic.py”, right-click your
mouse to select “\ **Upload to /**\ ”，wait for “soft_iic.py” to be
uploaded to ESP32; and then select “mfrc522_i2c.py”, right-click your
mouse to select “\ **Upload to /**\ ”，wait for “mfrc522_i2c.py” to be
uploaded to ESP32.

![image41](../media/img-20250603132607.png)

![image42](../media/img-20250603132647.png)

![image43](../media/img-20250603132729.png)

The saved name are mfrc522_config.py , soft_iic.py and mfrc522_i2c.py.

![image44](../media/img-20250603132756.png)

**Test Code**

```python
from machine import Pin, PWM,I2C, Pin
import time
from mfrc522_i2c import mfrc522


pwm = PWM(Pin(13))
pwm.freq(50)
button1 = Pin(16, Pin.IN, Pin.PULL_UP)
#i2c config
addr = 0x28
scl = 22
sda = 21

rc522 = mfrc522(scl, sda, addr)
rc522.PCD_Init()
rc522.ShowReaderDetails()            # Show details of PCD - MFRC522 Card Reader details

data = 0

while True:
    if rc522.PICC_IsNewCardPresent():
        #print("Is new card present!")
        if rc522.PICC_ReadCardSerial() == True:
            print("Card UID:")
            #print(rc522.uid.uidByte[0 : rc522.uid.size])
            for i in rc522.uid.uidByte[0 : rc522.uid.size]:
                data = data + i
        print(data)
        if(data == 510):
            pwm.duty(128)
            print("open")
        else:
            print("error")
        data = 0
    btnVal1 = button1.value()
    if(btnVal1 == 0):
        pwm.duty(25)
        print("close")
    time.sleep(1)
```
**Test Result**

Close the provided card to the RFID induction area, the door will turn
and open, and the shell shows "open". Click button 1 and the door turns
and closes. However, when swiping another blue induction block, the
shell shows "Error".

![image45](../media/03fd569d64704a7e9705c1891f4d4856.png)

