### Projet 1 : Contrôler la LED

Nous allons d'abord apprendre à contrôler la LED.

![image16](../media/0cda68ae8719d9b6c1bb79d64160d31d.png)

**Principe de fonctionnement**

La LED est une diode électroluminescente, qui peut être intégrée dans un module électronique. Elle s'allume si nous contrôlons les broches pour produire un niveau haut, sinon elle reste éteinte.

**Paramètres**

| **Tension de fonctionnement** | **DC 3~5V** |
| --- | --- |
| **Courant de fonctionnement** | **<20mA** |
| **Puissance** | **0.1W** |

**Broche de contrôle**

| LED jaune | 12 |
| --- | --- |
| \ |   |


#### Projet 1.1 Clignotement de la LED

**Description**

Nous pouvons faire sortir un niveau haut et un niveau bas sur la broche de la LED pour la faire clignoter.

**Code de test**

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
Ouvrir le code d'exemple

![image17](../media/39658e26aad2c9794bd3db9df3c70732.png)

![image18](../media/166384572a1fa595858d933aea5af710.png)

**Résultat du test**

Cliquez sur le bouton

![image19](../media/c5e28dda04f63745f59ef351025e82e8.png)

On peut voir que la LED jaune clignote.


#### Projet 1.2 LED 'respiration'

**Description**

Une "LED respirante" est un phénomène où la luminosité d'une LED change progressivement de sombre à lumineuse puis de nouveau à sombre, en continu, donnant l'illusion que la LED "respire". Mais comment contrôler la luminosité de la LED ?

Il est logique d'utiliser le PWM. En faisant varier le nombre de niveaux haut et bas sur une unité de temps, plus le niveau haut occupe de temps, plus la valeur du PWM est grande et plus la LED est brillante.

![image20](../media/704984700612966b997127cb9bde5c96.jpeg)

**Code de test**

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
**Résultat du test**

Cliquez sur le bouton.

![image21](../media/609b283e0909b5e5c14809c4ccf892ed.png)

La LED s'assombrit puis s'éclaircit progressivement, de manière cyclique, comme si elle respirait.