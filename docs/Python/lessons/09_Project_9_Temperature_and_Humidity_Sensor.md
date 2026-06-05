### Proyecto 9: Sensor de Temperatura y Humedad

**Información del componente**

Su modo de comunicación es datos seriales y bus único. El rango de medición de temperatura es -20 ~ +60℃, la precisión es ±2℃. El rango de humedad es 5 ~ 95%RH, la precisión es ±5%RH.

![imagen39](../media/0b9c44c3e4f3706638b9cf15871b861c.png)

**Pin de control**

| Sensor de Temperatura y Humedad | 17 |
| --- | --- |
| \ |   |


#### Proyecto 9.1 Probador de Temperatura y Humedad

**Código de prueba**

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
**Resultado de la prueba**

La LCD1602 muestra la temperatura (T = ** ° C) y la humedad (H = ** %RH). Cuando respiras sobre el sensor de T/H, puedes ver que la humedad aumenta.