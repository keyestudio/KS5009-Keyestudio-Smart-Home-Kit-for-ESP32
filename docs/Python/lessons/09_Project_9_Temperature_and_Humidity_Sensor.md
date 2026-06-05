### Project 9: Temperatuur- en vochtigheidssensor

**Componentkennis**

De communicatiemodus is seriële data en single-bus. Het temperatuurbereik is -20 ~ +60℃, de nauwkeurigheid is ±2℃. Het vochtigheidsbereik is 5 ~ 95%RH, de nauwkeurigheid is ±5%RH.

![afbeelding39](../media/0b9c44c3e4f3706638b9cf15871b861c.png)

**Besturingspin**

| Temperatuur- en vochtigheidssensor | 17 |
| --- | --- |
| \ |   |


#### Project 9.1 Temperatuur- en vochtigheidstester

**Testcode**

```python
# Import machine, time and dht modules.
import machine
import time
import dht
from time import sleep_ms, ticks_ms
from machine import SoftI2C, Pin
from i2c_lcd import I2cLcd

#Associate DHT11 with Pin(17).
DHT = dht.DHT11(machine.Pin(17))

DEFAULT_I2C_ADDR = 0x27

i2c = SoftI2C(scl=Pin(22), sda=Pin(21), freq=100000)
lcd = I2cLcd(i2c, DEFAULT_I2C_ADDR, 2, 16)

while True:
    DHT.measure() # Start DHT11 to measure data once.
   # Call the built-in function of DHT to obtain temperature
   # and humidity data and print them in “Shell”.
    print('temperature:',DHT.temperature(),'℃','humidity:',DHT.humidity(),'%')
    lcd.move_to(1, 0)
    lcd.putstr('T= {}'.format(DHT.temperature()))
    lcd.move_to(1, 1)
    lcd.putstr('H= {}'.format(DHT.humidity()))
    time.sleep_ms(1000)
```
**Testresultaat**

De LCD1602 toont de temperatuur (T = \*\* ° C) en luchtvochtigheid (H = \*\* %RH). Wanneer je in de T/H-sensor blaast, zie je dat de luchtvochtigheid stijgt.