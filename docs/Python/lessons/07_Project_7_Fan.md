### プロジェクト 7: ファン

**説明**

このプロジェクトでは、小型ファンの作り方を学びます。

**コンポーネントの知識**

この小型ファンは130のDCモーターと安全なファンブレードを使用します。PWM出力を使用してファンの速度を制御できます。

![画像33](../media/33da52918e88862a94035d61a9050f2e.png)

**制御方法**

ファンのモーターを制御するには2つのピンが必要で、1つはINA用、もう1つはINB用です。PWMの値の範囲は0~255です。2つのピンのPWM出力が異なると、ファンは回転します。

| INA - INB <= -45 | 時計回りに回転する |
| --- | --- |
| INA - INB >= 45 | 反時計回りに回転する |
| INA ==0, INB == 0 | 停止 |

**制御ピン**

| INA | 19 |
| --- | --- |
| INB | 18 |


#### プロジェクト 7.1: ファン

ファンの反時計回りおよび時計回りの回転速度を制御できます。

**テストコード**

```python
from machine import Pin,PWM
import time
#Two pins of the motor
INA =PWM(Pin(19,Pin.OUT),10000)#INA corresponds to IN+
INB =PWM(Pin(18,Pin.OUT),10000)#INB corresponds to IN-

try:
    while True:
        #Counterclockwise 2s
        INA.duty(0) #The range of duty cycle is 0-1023
        INB.duty(700)
        time.sleep(2)
        #stop 1s
        INA.duty(0)
        INB.duty(0)
        time.sleep(1)
        #Turn clockwise for 2s
        INA.duty(600)
        INB.duty(0)
        time.sleep(2)
        #stop 1s
        INA.duty(0)
        INB.duty(0)
        time.sleep(1)
except:
    INA.duty(0)
    INB.duty(0)
    INA.deinit()
    INB.deinit()
```
**テスト結果**

ファンは異なる速度で時計回りおよび反時計回りに回転します。


#### プロジェクト 7.2: ボタン制御ファン

ボタン1がファンのスイッチを制御します。

**テストコード**

```python
from machine import Pin,PWM
import time
#Two pins of the motor
INA =PWM(Pin(19,Pin.OUT),10000)#INA corresponds to IN+
INB =PWM(Pin(18,Pin.OUT),10000)#INB corresponds to IN-
button1 = Pin(16, Pin.IN, Pin.PULL_UP)
count = 0

try:
    while True:
        btnVal1 = button1.value()  # Reads the value of button 1
        if(btnVal1 == 0):
            time.sleep(0.01)
            while(btnVal1 == 0):
                btnVal1 = button1.value()
                if(btnVal1 == 1):
                    count=count + 1
                    print(count)
        val = count % 2
        if(val == 1):
            INA.duty(0) #The range of duty cycle is 0-1023
            INB.duty(700)
        else:
            INA.duty(0)
            INB.duty(0)
except:
    INA.duty(0)
    INB.duty(0)
    INA.deinit()
    INB.deinit()
```
**テスト結果**

ボタン1を押すとファンが回転を開始し、再度ボタン1を押すとファンが停止します。