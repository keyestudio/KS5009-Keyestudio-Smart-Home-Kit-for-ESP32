### Projet 7 : Ventilateur

**Description**

Dans ce projet, nous allons apprendre comment fabriquer un petit ventilateur.

**Connaissances sur les composants**

Le petit ventilateur utilise un moteur DC 130 et des pales de ventilateur sécurisées. Vous pouvez utiliser la sortie PWM pour contrôler la vitesse du ventilateur.

![image33](../media/33da52918e88862a94035d61a9050f2e.png)

**Méthode de contrôle**

Deux broches sont nécessaires pour contrôler le moteur du ventilateur, une pour INA et une pour INB. La plage de valeurs PWM est 0~255. Lorsque la sortie PWM des deux broches est différente, le ventilateur peut tourner.

| INA - INB <= -45 | Rotation dans le sens horaire |
| --- | --- |
| INA - INB >= 45 | Rotation dans le sens anti-horaire |
| INA ==0, INB == 0 | Arrêt |

**Broches de contrôle**

| INA | 19 |
| --- | --- |
| INB | 18 |


#### Projet 7.1 Ventilateur

Nous pouvons contrôler la vitesse de rotation du ventilateur dans les sens anti-horaire et horaire.

**Code de test**

```python
from machine import Pin,PWM
import time
#Two pins of the motor
INA =PWM(Pin(19,Pin.OUT),10000)#INA corresponds to IN+
INB =PWM(Pin(18,Pin.OUT),10000)#INB corresponds to IN-

try:
    while True:
        #Counterclockwise 2s
        INA.duty(0) #The range of duty cycle is 0-1023
        INB.duty(700)
        time.sleep(2)
        #stop 1s
        INA.duty(0)
        INB.duty(0)
        time.sleep(1)
        #Turn clockwise for 2s
        INA.duty(600)
        INB.duty(0)
        time.sleep(2)
        #stop 1s
        INA.duty(0)
        INB.duty(0)
        time.sleep(1)
except:
    INA.duty(0)
    INB.duty(0)
    INA.deinit()
    INB.deinit()
```
**Résultat du test**

Le ventilateur tournera dans les sens horaire et anti-horaire à différentes vitesses.


#### Projet 7.2 Ventilateur contrôlé par bouton

Le bouton 1 contrôle l'interrupteur du ventilateur.

**Code de test**

```python
from machine import Pin,PWM
import time
#Two pins of the motor
INA =PWM(Pin(19,Pin.OUT),10000)#INA corresponds to IN+
INB =PWM(Pin(18,Pin.OUT),10000)#INB corresponds to IN-
button1 = Pin(16, Pin.IN, Pin.PULL_UP)
count = 0

try:
    while True:
        btnVal1 = button1.value()  # Reads the value of button 1
        if(btnVal1 == 0):
            time.sleep(0.01)
            while(btnVal1 == 0):
                btnVal1 = button1.value()
                if(btnVal1 == 1):
                    count=count + 1
                    print(count)
        val = count % 2
        if(val == 1):
            INA.duty(0) #The range of duty cycle is 0-1023
            INB.duty(700)
        else:
            INA.duty(0)
            INB.duty(0)
except:
    INA.duty(0)
    INB.duty(0)
    INA.deinit()
    INB.deinit()
```
**Résultat du test**

Appuyez sur le bouton 1, le ventilateur commence à tourner ; appuyez à nouveau sur le bouton 1, le ventilateur s'arrête.