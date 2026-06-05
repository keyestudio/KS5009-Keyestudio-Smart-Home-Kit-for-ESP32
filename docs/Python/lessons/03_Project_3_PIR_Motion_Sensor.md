### Projet 3 : Capteur de mouvement PIR

**Description**

Le capteur de mouvement PIR a de nombreux scénarios d'application dans la vie quotidienne, tels que la lampe à détection automatique pour les escaliers, le robinet à détection automatique du lavabo, etc.

C'est également un capteur numérique comme les boutons, qui possède deux états 0 ou 1. Et il détecte la présence lorsqu'une personne bouge.

![image25](../media/c1518252606b111bfa66878a2bfcc965.png)

**Broche de contrôle**

| Capteur de mouvement PIR | 14 |
| --- | --- |
| \ |   |


#### Projet 3.1 Lire le capteur de mouvement PIR

Nous afficherons la valeur du capteur de mouvement PIR via le moniteur série.

**Code de test**

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
**Résultat du test**

Lorsque vous restez immobile devant le capteur, la valeur lue est 0 ; si vous bougez un peu, elle passe à 1.

![image26](../media/f8c6be9a6ad7a6423c1fa1456f771406.png)


#### Projet 3.2 Capteur de mouvement PIR

Si quelqu'un bouge devant le capteur, la LED s'allume.

**Code de test**

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
**Résultat du test**

Déplacez votre main devant le capteur, la LED s'allumera. Après quelques secondes d'immobilité, la LED s'éteindra.