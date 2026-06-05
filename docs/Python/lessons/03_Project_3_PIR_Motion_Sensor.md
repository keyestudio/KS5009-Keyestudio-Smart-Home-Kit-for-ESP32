### プロジェクト 3: PIRモーションセンサー

**説明**

PIRモーションセンサーは、階段の自動点灯や洗面台の自動水栓など、日常生活で多くの応用例があります。

ボタンのようなデジタルセンサーで、状態は0か1の二値です。人が動いているときに検知されます。

![画像25](../media/c1518252606b111bfa66878a2bfcc965.png)

**制御ピン**

| PIRモーションセンサー | 14 |
| --- | --- |
| \ |   |


#### プロジェクト 3.1 PIRモーションセンサーの読み取り

シリアルモニタを通してPIRモーションセンサーの値を出力します。

**テストコード**

```python
from machine import Pin
import time

PIR = Pin(14, Pin.IN)
while True:
    value = PIR.value()
    print(value, end = " ")
    if value == 1:
        print("Some body is in this area!")
    else:
        print("No one!")
    time.sleep(0.1)
```
**テスト結果**

センサーの前にじっと立っていると読み取り値は0で、少し動くと1に変わります。

![画像26](../media/f8c6be9a6ad7a6423c1fa1456f771406.png)


#### プロジェクト 3.2 PIRモーションセンサー

誰かがセンサーの前で動くと、LEDが点灯します。

**テストコード**

```python
from machine import Pin
import time

PIR = Pin(14, Pin.IN)
led = Pin(12, Pin.OUT)

while True:
    value = PIR.value()
    print(value)
    if value == 1:
        led.value(1)# turn on led
    else:
        led.value(0)
    time.sleep(0.1)
```
**テスト結果**

センサーの前で手を動かすとLEDが点灯します。数秒間動きがないと、LEDは消灯します。