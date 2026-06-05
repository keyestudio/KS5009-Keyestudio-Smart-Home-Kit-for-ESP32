### プロジェクト9: 温湿度センサー

**コンポーネントの知識**

通信方式はシリアルデータとシングルバスです。温度測定範囲は -20 ~ +60℃、精度は ±2℃です。湿度測定範囲は 5 ~ 95%RH、精度は ±5%RH です。

![画像39](../media/0b9c44c3e4f3706638b9cf15871b861c.png)

**制御ピン**

| 温湿度センサー | 17 |
| --- | --- |
| \ |   |


#### プロジェクト9.1 温湿度テスター

**テストコード**

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
**テスト結果**

LCD1602 は温度（T = \*\* ° C）と湿度（H = \*\* %RH）を表示します。温湿度センサーに息を吹きかけると、湿度が上昇するのが確認できます。