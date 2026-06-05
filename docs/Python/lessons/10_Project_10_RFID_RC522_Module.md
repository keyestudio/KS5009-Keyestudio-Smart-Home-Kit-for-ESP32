### Project 10: RFID RC522-module

**Kennis van componenten**

Radiofrequentie-identificatie, de kaartlezer bestaat uit een radiofrequentiemodule en een sterk magnetisch veld. De Tag-transponder is een detectieapparaat dat geen batterij bevat. Het bevat alleen kleine geïntegreerde schakelingen, opslagmedia voor gegevens en antennes voor het ontvangen en versturen van signalen.

Om de gegevens in de tag te lezen, plaats je deze eerst in het leesbereik van de kaartlezer. De lezer genereert een magnetisch veld, dat volgens de wet van Lenz elektriciteit kan opwekken; de RFID-tag levert dan stroom en activeert daarmee het apparaat.

![afbeelding40](../media/982ac6a9da0e8f55465ca5a969ac0dfe.png)

**Besturingspinnen**

Gebruik IIC-communicatie

| SDA | SDA |
| --- | --- |
| SCL | SCL |


#### Project 10.1 De deur openen

Open de map waarin mfrc522_config.py, soft_iic.py en mfrc522_i2c.py zich bevinden

Open “Thonny”, klik op “Deze computer”→“D:”→“2. Python Projects”→“pj10_rc522_RFID”. Selecteer “mfrc522_config.py”, klik met de rechtermuisknop en selecteer “\ **Upload to /**\ ”, wacht tot “mfrc522_config.py” naar ESP32 is geüpload; selecteer vervolgens “soft_iic.py”, klik met de rechtermuisknop en selecteer “\ **Upload to /**\ ”, wacht tot “soft_iic.py” naar ESP32 is geüpload; en selecteer ten slotte “mfrc522_i2c.py”, klik met de rechtermuisknop en selecteer “\ **Upload to /**\ ”, wacht tot “mfrc522_i2c.py” naar ESP32 is geüpload.

![afbeelding41](../media/img-20250603132607.png)

![afbeelding42](../media/img-20250603132647.png)

![afbeelding43](../media/img-20250603132729.png)

De opgeslagen namen zijn mfrc522_config.py, soft_iic.py en mfrc522_i2c.py.

![afbeelding44](../media/img-20250603132756.png)

**Testcode**

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
**Testresultaat**

Houd de bijgeleverde kaart dicht bij het RFID-detectiegebied, de deur draait open en in de shell wordt "open" weergegeven. Druk op knop 1 en de deur draait dicht. Wanneer je echter met een ander blauw inductieblok veegt, toont de shell "Error".

![afbeelding45](../media/03fd569d64704a7e9705c1891f4d4856.png)