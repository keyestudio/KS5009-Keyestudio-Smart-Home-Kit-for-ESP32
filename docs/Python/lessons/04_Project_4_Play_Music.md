### Project 4: Play Music

**Description**

There is a audio power amplifier element in the car expansion board,
which is as an external amplification equipment to play music.

In this project, we will work to play a piece of music by using it.

**Component Knowledge**

**Passive Buzzer:**

The audio power amplifier (like the passive buzzer) does not have
internal oscillation. When controlling, we need to input square waves of
different frequencies to the positive pole of the component and ground
the negative pole to control the power amplifier to chime sounds of
different frequencies.

![image27](../media/2e6fd6b7975ef84ab94eee896161347b.png)

**Control Pin**

| Passive Buzzer | 25 |
| --- | --- |
| \ |   |


#### Project 4.1 Play Happy Birthday

**Test Code**

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
**Test Result**

The passive buzzer will play happy Birthday.

