### Projet 2 : Lampe de table

**Description**

La lampe de table courante utilise des LED et des boutons, qui peuvent contrôler l'allumage et l'extinction de la lumière en appuyant sur le bouton.

**Principe du bouton**

Le module de bouton est un capteur numérique, qui ne peut lire que 0 ou 1. Lorsque le module n'est pas pressé, il est à un état de niveau haut, c'est-à-dire 1 ; lorsqu'il est pressé, il est à un niveau bas 0.

![image22](../media/41f565d4f355abb96e105119660e80ba.png)

**Broches du bouton**

| **Bouton 1** | **16** |
| --- | --- |
| **Bouton 2** | **27** |


#### Projet 2.1 Lire le bouton

**Description**

Nous allons lire la valeur d'état du bouton et l'afficher dans le moniteur série, afin de le voir de manière intuitive.

**Test Code**

```python
from machine import Pin
import time

button1 = Pin(16, Pin.IN, Pin.PULL_UP)
button2 = Pin(27, Pin.IN, Pin.PULL_UP)

while True:
    btnVal1 = button1.value()  # Reads the value of button 1
    btnVal2 = button2.value()
    print("button1 =",btnVal1)  #Print it out in the shell
    print("button2 =",btnVal2)
    time.sleep(0.1) #delay 0.1s
```
**Résultat du test**

Cliquez sur le bouton run, puis vous pourrez voir les valeurs d'état de button1 et button 2 imprimées dans le shell. Appuyez sur le bouton, et vous verrez le changement des valeurs d'état.

![image23](../media/1b984da67c0e89a72a9601c39362567d.png)


#### Projet 2.2. Lampe de table

**Description**

Pour une lampe de table simple, appuyez sur le bouton pour l'allumer, appuyez de nouveau pour l'éteindre.

**Test Code**

En calculant le nombre de fois que le bouton a été pressé et en prenant le reste de la division par 2, vous obtenez 0 ou 1, deux états possibles.

```python
from machine import Pin
import time

button1 = Pin(16, Pin.IN, Pin.PULL_UP)
led = Pin(12, Pin.OUT)
count = 0

while True:
    btnVal1 = button1.value()  # Reads the value of button 1
    #print("button1 =",btnVal1)  #Print it out in the shell
    if(btnVal1 == 0):
        time.sleep(0.01)
        while(btnVal1 == 0):
            btnVal1 = button1.value()
            if(btnVal1 == 1):
                count = count + 1
                print(count)
    val = count % 2
    if(val == 1):
        led.value(1)
    else:
        led.value(0)
    time.sleep(0.1) #delay 0.1s
```
**Résultat du test**

Le shell affichera le nombre de fois où le bouton a été pressé ; appuyez une fois sur le bouton, la LED s'allumera, appuyez de nouveau, elle s'éteindra.

![image24](../media/1bc079eabd93cb2e8a8e15f0ab7f1367.png)