### Project 4: 音楽を再生

**説明**

車用拡張ボードにはオーディオパワーアンプ素子が搭載されており、外部の増幅装置として音楽を再生します。

このプロジェクトでは、それを使って曲を再生します。

**部品の知識**

**パッシブブザー：**

オーディオパワーアンプ（パッシブブザーなど）には内部発振回路がありません。制御する際は、部品の正極に異なる周波数の矩形波を入力し、負極を接地して、パワーアンプに異なる周波数の音を鳴らすよう制御する必要があります。

![画像27](../media/2e6fd6b7975ef84ab94eee896161347b.png)

**制御ピン**

| パッシブブザー | 25 |
| --- | --- |
| \ |   |


#### Project 4.1 ハッピーバースデーを再生

**テストコード**

```python
from machine import Pin, PWM
from time import sleep
buzzer = PWM(Pin(25))

buzzer.duty(1000)

# Happy birthday
buzzer.freq(294)
sleep(0.25)
buzzer.freq(440)
sleep(0.25)
buzzer.freq(392)
sleep(0.25)
buzzer.freq(532)
sleep(0.25)
buzzer.freq(494)
sleep(0.25)
buzzer.freq(392)
sleep(0.25)
buzzer.freq(440)
sleep(0.25)
buzzer.freq(392)
sleep(0.25)
buzzer.freq(587)
sleep(0.25)
buzzer.freq(532)
sleep(0.25)
buzzer.freq(392)
sleep(0.25)
buzzer.freq(784)
sleep(0.25)
buzzer.freq(659)
sleep(0.25)
buzzer.freq(532)
sleep(0.25)
buzzer.freq(494)
sleep(0.25)
buzzer.freq(440)
sleep(0.25)
buzzer.freq(698)
sleep(0.25)
buzzer.freq(659)
sleep(0.25)
buzzer.freq(532)
sleep(0.25)
buzzer.freq(587)
sleep(0.25)
buzzer.freq(532)
sleep(0.5)
buzzer.duty(0)
```
**テスト結果**

パッシブブザーが「ハッピーバースデー」を再生します。