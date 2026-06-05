### Projekt 4: Musik abspielen

**Beschreibung**

Auf der Erweiterungsplatine des Fahrzeugs befindet sich ein Audio-Leistungsverstärker, der als externes Verstärkungsgerät zum Abspielen von Musik dient.

In diesem Projekt werden wir damit ein Musikstück abspielen.

**Komponentenwissen**

**Passiver Summer:**

Der Audio-Leistungsverstärker (wie der passive Summer) hat keine interne Schwingung. Bei der Steuerung müssen wir Rechtecksignale mit unterschiedlichen Frequenzen an den positiven Pol der Komponente einspeisen und den negativen Pol auf Masse legen, um den Leistungsverstärker Töne unterschiedlicher Frequenzen erzeugen zu lassen.

![Bild 27](../media/2e6fd6b7975ef84ab94eee896161347b.png)

**Steuerpin**

| Passiver Summer | 25 |
| --- | --- |
| \ |   |


#### Projekt 4.1 Happy Birthday abspielen

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
**Testergebnis**

Der passive Summer spielt "Happy Birthday".