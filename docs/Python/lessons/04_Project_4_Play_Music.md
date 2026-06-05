### Project 4: Muziek afspelen

**Beschrijving**

There is a audio power amplifier element in the car expansion board,
which is as an external amplification equipment to play music.

In this project, we will work to play a piece of music by using it.

**Componentkennis**

**Passieve zoemer:**

De audioversterker (zoals een passieve zoemer) heeft geen interne oscillator. Bij aansturing moeten we vierkante golven met verschillende frequenties naar de positieve pool van het component sturen en de negatieve pool naar massa verbinden, zodat de versterker tonen met verschillende frequenties produceert.

![afbeelding27](../media/2e6fd6b7975ef84ab94eee896161347b.png)

**Besturingspin**

| Passieve zoemer | 25 |
| --- | --- |
| \ |   |


#### Project 4.1 Speel Happy Birthday

**Testcode**

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
**Testresultaat**

De passieve zoemer zal 'Happy Birthday' afspelen.