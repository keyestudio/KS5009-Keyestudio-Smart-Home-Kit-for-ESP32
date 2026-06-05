### Projekt 3: PIR-Bewegungssensor

**Beschreibung**

Der PIR-Bewegungssensor hat viele Anwendungsszenarien im Alltag, wie automatische Treppenbeleuchtung, automatische berührungslose Armaturen am Waschbecken usw.

Er ist ebenfalls ein digitaler Sensor wie Tasten, der zwei Zustandswerte 0 oder 1 hat. Er reagiert, wenn sich Personen bewegen.

![Bild25](../media/c1518252606b111bfa66878a2bfcc965.png)

**Steuerpin**

| PIR-Bewegungssensor | 14 |
| --- | --- |
| \ |   |


#### Projekt 3.1: Den PIR-Bewegungssensor auslesen

Wir geben den Wert des PIR-Bewegungssensors über den seriellen Monitor aus.

**Test Code**

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
**Testergebnis**

Wenn Sie still vor dem Sensor stehen, ist der Messwert 0; bewegen Sie sich ein wenig, ändert er sich auf 1.

![Bild26](../media/f8c6be9a6ad7a6423c1fa1456f771406.png)


#### Projekt 3.2: PIR-Bewegungssensor

Bewegt sich jemand vor dem Sensor, leuchtet die LED auf.

**Test Code**

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
**Testergebnis**

Bewegen Sie Ihre Hand vor dem Sensor, die LED schaltet sich ein. Nach einigen Sekunden ohne Bewegung schaltet sie sich wieder aus.