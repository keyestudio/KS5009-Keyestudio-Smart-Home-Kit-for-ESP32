### Projekt 1: LED steuern

Zuerst lernen wir, wie man eine LED steuert.

![Bild 16](../media/0cda68ae8719d9b6c1bb79d64160d31d.png)

**Funktionsprinzip**

Eine LED ist eine Leuchtdiode, die als elektronisches Modul ausgeführt sein kann. Sie leuchtet, wenn wir die Pins dazu bringen, einen High-Pegel auszugeben, andernfalls ist sie aus.

**Parameter**

| **Betriebsspannung** | **DC 3~5V** |
| --- | --- |
| **Betriebsstrom** | **<20mA** |
| **Leistung** | **0.1W** |

**Steuerpin**

| Gelbe LED | 12 |
| --- | --- |
| \ |   |


#### Projekt 1.1 LED blinken

**Beschreibung**

Wir können den LED-Pin so steuern, dass er High- und Low-Pegel ausgibt, damit die LED blinkt.

**Test Code**

```python
from machine import Pin
import time

led = Pin(12, Pin.OUT)# Build an LED object, connect the external LED light to pin 0, and set pin 0 to output mode
while True:
    led.value(1)# turn on led
    time.sleep(1)# delay 1s
    led.value(0)# turn off led
    time.sleep(1)# delay 1s
```
Öffne den Beispielcode

![Bild 17](../media/39658e26aad2c9794bd3db9df3c70732.png)

![Bild 18](../media/166384572a1fa595858d933aea5af710.png)

**Testergebnis**

Klicke auf die Schaltfläche

![Bild 19](../media/c5e28dda04f63745f59ef351025e82e8.png)

Wir können sehen, dass die gelbe LED blinkt.


#### Projekt 1.2 Atmende LED

**Beschreibung**

Eine "atmende LED" ist ein Phänomen, bei dem die Helligkeit einer LED sanft von dunkel zu hell und wieder zurück zu dunkel wechselt, fortlaufend, sodass der Eindruck entsteht, die LED "atme". Aber wie steuert man die Helligkeit einer LED?

Hier bietet sich PWM an. Es wird in einer Zeiteinheit die Anzahl der High- und Low-Pegel ausgegeben — je mehr Zeit der High-Pegel einnimmt, desto größer der PWM-Wert und desto heller die LED.

![Bild 20](../media/704984700612966b997127cb9bde5c96.jpeg)

**Test Code**

```python
import time
from machine import Pin,PWM

#The way that the ESP32 PWM pins output is different from traditionally controllers.
#It can change frequency and duty cycle by configuring PWM’s parameters at the initialization stage.
#Define GPIO 0’s output frequency as 10000Hz and its duty cycle as 0, and assign them to PWM.
pwm =PWM(Pin(12,Pin.OUT),10000)

try:
    while True:
#The range of duty cycle is 0-1023, so we use the first for loop to control PWM to change the duty
#cycle value,making PWM output 0% -100%; Use the second for loop to make PWM output 100%-0%.
        for i in range(0,1023):
            pwm.duty(i)
            time.sleep_ms(1)

        for i in range(0,1023):
            pwm.duty(1023-i)
            time.sleep_ms(1)
except:
#Each time PWM is used, the hardware Timer will be turned ON to cooperate it. Therefore, after each use of PWM,
#deinit() needs to be called to turned OFF the timer. Otherwise, the PWM may fail to work next time.
    pwm.deinit()
```
**Testergebnis**

Klicke auf den Button.

![Bild 21](../media/609b283e0909b5e5c14809c4ccf892ed.png)

Die LED wird allmählich dunkler und dann wieder heller, zyklisch, wie beim menschlichen Atmen.