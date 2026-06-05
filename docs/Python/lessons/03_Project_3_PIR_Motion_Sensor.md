### Progetto 3: PIR Motion Sensor

**Descrizione**

Il PIR motion sensor ha molti scenari di applicazione nella vita quotidiana, come l'illuminazione automatica delle scale, il rubinetto a induzione automatica del lavabo, ecc.

È anche un sensore digitale come i pulsanti, che ha due valori di stato 0 o 1. E verrà rilevato quando le persone si muovono.

![immagine25](../media/c1518252606b111bfa66878a2bfcc965.png)

**Pin di controllo**

| PIR motion sensor | 14 |
| --- | --- |
| \ |   |


#### Progetto 3.1 Leggere il PIR Motion Sensor

Visualizzeremo il valore del PIR motion sensor sul monitor seriale.

**Codice di prova**

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
**Risultato del test**

Quando stai fermo davanti al sensore, il valore letto è 0; muoviti un po', cambierà a 1.

![immagine26](../media/f8c6be9a6ad7a6423c1fa1456f771406.png)


#### Progetto 3.2 PIR Motion Sensor

Se qualcuno si muove davanti al sensore, il LED si accenderà.

**Codice di prova**

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
**Risultato del test**

Muovi la mano davanti al sensore, il LED si accenderà. Dopo alcuni secondi di inattività, il LED si spegnerà.