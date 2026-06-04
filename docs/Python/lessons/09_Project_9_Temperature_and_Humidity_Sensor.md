### Project 9: Temperature and Humidity Sensor

**Component Knowledge**

Its communication mode is serial data and single bus. The temperature
measurement range is -20 ~ +60℃, accuracy is ±2℃. However, the humidity
range is 5 ~ 95%RH, the accuracy is ±5%RH.

![image39](../media/0b9c44c3e4f3706638b9cf15871b861c.png)

**Control Pin**

| Temperature and Humidity Sensor | 17 |
| --- | --- |
| \ |   |


#### Project 9.1 Temperature and Humidity Tester

**Test Code**

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
**Test Result**

The LCD1602 displays the temperature (T = \*\* ° C) and humidity (H =
\*\* %RH). When you breathe into the T/H sensor, you can see that the
humidity rises.

