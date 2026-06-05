### Projet 5 : Portes et fenêtres automatiques

**Description**

Les portes et fenêtres automatiques nécessitent un dispositif d'alimentation, qui devient plus automatisé avec un servo à 180 degrés et quelques capteurs. En ajoutant un capteur de pluie, vous pouvez obtenir la fermeture automatique des fenêtres lorsqu'il pleut. En ajoutant un module RFID, on peut réaliser l'ouverture de la porte par lecture, etc.

**Connaissances des composants**

**Servo :**

Le servo est un actionneur de position constitué d'un boîtier, d'une carte électronique, d'un moteur sans noyau, d'un engrenage et d'un détecteur de position.

Son principe de fonctionnement est que le servo reçoit le signal envoyé par le MCU ou le récepteur et produit un signal de référence d'une période de 20 ms et d'une largeur de 1,5 ms, puis compare la tension continue acquise au potentiomètre et obtient la différence de tension en sortie.

L'IC sur la carte juge le sens de rotation, puis commande le moteur sans noyau pour démarrer la rotation. La puissance est transmise au bras oscillant via l'engrenage de réduction, et le signal est renvoyé par le détecteur de position pour juger si le positionnement a été atteint, ce qui convient aux systèmes de contrôle nécessitant un changement d'angle constant et pouvant être maintenu.

Lorsque la vitesse du moteur est constante, le potentiomètre est entraîné à tourner via l'engrenage de réduction en cascade, ce qui fait que la différence de tension est nulle, et le moteur s'arrête de tourner. En général, l'intervalle d'angle de rotation du servo est de 0° à 180°.

La période d'impulsion du servo de commande est de 20 ms, la largeur d'impulsion est de 0,5 ms à 2,5 ms, et la position correspondante est de -90° à +90°. Voici un exemple de servo 180° :

![image28](../media/708316fde05c62113a3024e0efb0c237.jpeg)

En général, le servo possède trois fils : marron, rouge et orange. Le fil marron est la masse, le fil rouge est le pôle positif et le fil orange est le fil de signal.

![image29](../media/35084ae289a08e35bdb8c89ceb134ba4.png)

![image30](../media/6cbf6f177ea204f7632b872497fde010.png)

**Pin**

| Servomoteur de la fenêtre | 5 |
| --- | --- |
| Servomoteur de la porte | 13 |


#### Projet 5.1 Contrôler la porte

**Code de test**

```python
from machine import Pin, PWM
import time
pwm = PWM(Pin(13))
pwm.freq(50)

'''
Duty cycle corresponding to the Angle
0°----2.5%----25
45°----5%----51.2
90°----7.5%----77
135°----10%----102.4
180°----12.5%----128
'''
angle_0 = 25
angle_90 = 77
angle_180 = 128

while True:
    pwm.duty(angle_0)
    time.sleep(1)
    pwm.duty(angle_90)
    time.sleep(1)
    pwm.duty(angle_180)
    time.sleep(1)
```
**Résultat du test**

Le servomoteur de la porte fait bouger la porte d'avant en arrière.


#### Projet 5.2 Fermer la fenêtre

**Description**

Nous allons utiliser un servo et un capteur de pluie pour réaliser un dispositif fermant automatiquement les fenêtres lorsqu'il pleut.

**Connaissances des composants**

**Capteur de pluie :** Il s'agit d'un module d'entrée analogique : plus la surface de détection couverte d'eau est grande, plus la valeur renvoyée est élevée (plage 0~4096).

**Code de test**

```python
# Import Pin, ADC and DAC modules.
from machine import ADC,Pin,DAC,PWM
import time
pwm = PWM(Pin(5))
pwm.freq(50)

# Turn on and configure the ADC with the range of 0-3.3V
adc=ADC(Pin(34))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)

# Read ADC value once every 0.1seconds, convert ADC value to DAC value and output it, and print these data to “Shell”.
try:
    while True:
        adcVal=adc.read()
        dacVal=adcVal//16
        voltage = adcVal / 4095.0 * 3.3
        print("ADC Val:",adcVal,"DACVal:",dacVal,"Voltage:",voltage,"V")
        if(voltage > 0.6):
            pwm.duty(46)
        else:
            pwm.duty(100)
        time.sleep(0.1)
except:
    pass
```
**Résultat du test**

Au départ, la fenêtre s'ouvre automatiquement ; si vous touchez le capteur de pluie avec une main mouillée, la fenêtre se fermera.