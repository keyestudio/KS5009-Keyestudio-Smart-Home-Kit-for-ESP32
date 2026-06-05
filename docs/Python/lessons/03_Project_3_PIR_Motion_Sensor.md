### Proyecto 3: Sensor de movimiento PIR

**Descripción**

El sensor de movimiento PIR tiene muchas aplicaciones en la vida diaria, como lámparas automáticas para escaleras, grifos automáticos para lavabos, etc.

También es un sensor digital, al igual que los botones, que tiene dos valores de estado: 0 o 1. Detecta cuando hay movimiento de personas.

![imagen25](../media/c1518252606b111bfa66878a2bfcc965.png)

**Pin de control**

| Sensor de movimiento PIR | 14 |
| --- | --- |
| \ |   |


#### Proyecto 3.1 Leer el sensor de movimiento PIR

Imprimiremos el valor del sensor de movimiento PIR en el monitor serie.

**Código de prueba**

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
**Resultado de la prueba**

Cuando te quedas quieto frente al sensor, el valor leído es 0; si te mueves un poco, cambiará a 1.

![imagen26](../media/f8c6be9a6ad7a6423c1fa1456f771406.png)


#### Proyecto 3.2 Sensor de movimiento PIR

Si alguien se mueve frente al sensor, el LED se encenderá.

**Código de prueba**

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
**Resultado de la prueba**

Mueve la mano frente al sensor, el LED se encenderá. Tras unos segundos de inmovilidad, el LED se apagará.