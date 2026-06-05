### プロジェクト2: テーブルランプ

**説明**

一般的なテーブルランプはLEDとボタンを使い、ボタンを押すことでランプのオン/オフを制御できます。

**ボタンの原理**

ボタンモジュールはデジタルセンサーで、0か1しか読み取れません。モジュールが押されていないときは高レベル（1）で、押されると低レベル（0）になります。

![画像22](../media/41f565d4f355abb96e105119660e80ba.png)

**ボタンのピン**

| **ボタン1** | **16** |
| --- | --- |
| **ボタン2** | **27** |


#### プロジェクト2.1 ボタンの読み取り

**説明**

ボタンの状態値を読み取り、それをシリアルモニタに表示して直感的に確認します。

**テストコード**

```python
from machine import Pin
import time

button1 = Pin(16, Pin.IN, Pin.PULL_UP)
button2 = Pin(27, Pin.IN, Pin.PULL_UP)

while True:
    btnVal1 = button1.value()  # Reads the value of button 1
    btnVal2 = button2.value()
    print("button1 =",btnVal1)  #Print it out in the shell
    print("button2 =",btnVal2)
    time.sleep(0.1) #delay 0.1s
```
**テスト結果**

実行ボタンをクリックすると、button1とbutton2の状態値がシェルに表示されます。スマートホームのボタンを押すと、状態値の変化が確認できます。

![画像23](../media/1b984da67c0e89a72a9601c39362567d.png)


#### プロジェクト2.2 テーブルランプ

**説明**

一般的なシンプルなテーブルランプは、ボタンを押すと点灯し、もう一度押すと消灯します。

**テストコード**

ボタンが押された回数を数え、2で割った余りをとることで、0または1の2状態を得ることができます。

```python
from machine import Pin
import time

button1 = Pin(16, Pin.IN, Pin.PULL_UP)
led = Pin(12, Pin.OUT)
count = 0

while True:
    btnVal1 = button1.value()  # Reads the value of button 1
    #print("button1 =",btnVal1)  #Print it out in the shell
    if(btnVal1 == 0):
        time.sleep(0.01)
        while(btnVal1 == 0):
            btnVal1 = button1.value()
            if(btnVal1 == 1):
                count = count + 1
                print(count)
    val = count % 2
    if(val == 1):
        led.value(1)
    else:
        led.value(0)
    time.sleep(0.1) #delay 0.1s
```
**テスト結果**

シェルにはボタンが押された回数が表示されます。ボタンを1回押すとLEDが点灯し、もう1回押すと消灯します。

![画像24](../media/1bc079eabd93cb2e8a8e15f0ab7f1367.png)