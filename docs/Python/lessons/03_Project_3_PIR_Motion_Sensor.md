### Project 3: PIR-bewegingssensor

**Beschrijving**

De PIR-bewegingssensor kent veel toepassingsscenario's in het dagelijks leven, zoals automatische sensorlampen bij trappen, automatische kranen bij wastafels, enz.

Het is ook een digitale sensor, net als knoppen, die twee toestanden heeft: 0 of 1. De sensor geeft een signaal wanneer er beweging is.

![afbeelding25](../media/c1518252606b111bfa66878a2bfcc965.png)

**Besturingspin**

| PIR-bewegingssensor | 14 |
| --- | --- |
| \ |   |


#### Project 3.1 Uitlezen van de PIR-bewegingssensor

We zullen de waarde van de PIR-bewegingssensor afdrukken via de seriële monitor.

**Testcode**

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
**Testresultaat**

Als je stil voor de sensor staat, is de uitgelezen waarde 0; beweeg je iets, dan verandert deze naar 1.

![afbeelding26](../media/f8c6be9a6ad7a6423c1fa1456f771406.png)


#### Project 3.2 PIR-bewegingssensor

Als iemand voor de sensor beweegt, gaat de LED branden.

**Testcode**

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
**Testresultaat**

Beweeg je hand voor de sensor, dan gaat de LED aan. Na een paar seconden zonder beweging gaat de LED weer uit.