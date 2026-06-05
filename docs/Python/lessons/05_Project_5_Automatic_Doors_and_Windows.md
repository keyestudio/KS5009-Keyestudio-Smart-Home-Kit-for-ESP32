### Project 5: 自動ドアと窓

**説明**

自動ドアや窓は電動化が必要で、180度のServoといくつかのセンサーを使うことでより自動化できます。雨滴センサーを追加すれば、雨が降ったときに自動的に窓を閉めることができます。RFIDを追加すれば、カードをかざしてドアを開けるといった機能を実現できます。

**コンポーネントの知識**

**Servo:**

Servoは筐体、回路基板、コアレスモーター、ギア、位置検出器で構成される位置制御用のドライバ装置です。

その動作原理は、ServoがMCUや受信機から送られた信号を受信し、周期20ms・幅1.5msの基準信号を生成し、取得した直流バイアス電圧とポテンショメータの電圧を比較して電圧差を出力することです。

基板上のICは回転方向を判断し、コアレスモーターを駆動して回転を開始します。減速ギアを介して出力がスイングアームに伝えられ、位置検出器によって信号が返され、所定の位置に達したかどうかを判断します。これは一定角度の変化が必要で維持できる制御システムに適しています。

モーターの速度が一定になると、カスケード減速ギアを介してポテンショメータが回転され、電圧差が0になりモーターが回転を停止します。一般に、Servoの回転角度範囲は0°～180°です。

制御Servoのパルス周期は20ms、パルス幅は0.5ms～2.5msで、対応する位置は-90°～+90°です。以下は180°Servoの例です:

![画像28](../media/708316fde05c62113a3024e0efb0c237.jpeg)

一般的にServoは茶色、赤、橙の3本の線があります。茶色の線は接地、赤は電源線、橙は信号線です。

![画像29](../media/35084ae289a08e35bdb8c89ceb134ba4.png)

![画像30](../media/6cbf6f177ea204f7632b872497fde010.png)

**Pin**

| 窓の Servo | 5 |
| --- | --- |
| 扉の Servo | 13 |


#### Project 5.1 ドアを制御する

**テストコード**

```python
from machine import Pin, PWM
import time
pwm = PWM(Pin(13))
pwm.freq(50)

'''
Duty cycle corresponding to the Angle
0°----2.5%----25
45°----5%----51.2
90°----7.5%----77
135°----10%----102.4
180°----12.5%----128
'''
angle_0 = 25
angle_90 = 77
angle_180 = 128

while True:
    pwm.duty(angle_0)
    time.sleep(1)
    pwm.duty(angle_90)
    time.sleep(1)
    pwm.duty(angle_180)
    time.sleep(1)
```
**テスト結果**

扉のServoは扉と一緒に前後に回転します。


#### Project 5.2 窓を閉める

**説明**

ここでは、Servoと雨滴センサーを使って、雨のときに自動で窓を閉める装置を作ります。

**コンポーネントの知識**

**雨滴センサー:** これはアナログ入力モジュールで、検出面に水が広く付着しているほど返される値が大きくなります（範囲 0~4096）。

**テストコード**

```python
# Import Pin, ADC and DAC modules.
from machine import ADC,Pin,DAC,PWM
import time
pwm = PWM(Pin(5))
pwm.freq(50)

# Turn on and configure the ADC with the range of 0-3.3V
adc=ADC(Pin(34))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)

# Read ADC value once every 0.1seconds, convert ADC value to DAC value and output it, and print these data to “Shell”.
try:
    while True:
        adcVal=adc.read()
        dacVal=adcVal//16
        voltage = adcVal / 4095.0 * 3.3
        print("ADC Val:",adcVal,"DACVal:",dacVal,"Voltage:",voltage,"V")
        if(voltage > 0.6):
            pwm.duty(46)
        else:
            pwm.duty(100)
        time.sleep(0.1)
except:
    pass
```
**テスト結果**

最初は窓が自動で開き、手（肌に水が付いている状態）で雨滴センサーに触れると、窓が閉まります。