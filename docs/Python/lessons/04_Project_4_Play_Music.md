### Projet 4 : Jouer de la musique

**Description**

Il y a un élément amplificateur audio de puissance sur la carte d'extension pour voiture, qui sert d'amplificateur externe pour jouer de la musique.

Dans ce projet, nous allons l'utiliser pour jouer un morceau de musique.

**Connaissances sur le composant**

**Buzzer passif :**

L'amplificateur audio de puissance (comme le buzzer passif) n'a pas d'oscillation interne. Lors du contrôle, nous devons fournir des signaux carrés de différentes fréquences à la borne positive du composant et relier la borne négative à la masse pour que l'amplificateur produise des sons de différentes fréquences.

![image27](../media/2e6fd6b7975ef84ab94eee896161347b.png)

**Broche de contrôle**

| Buzzer passif | 25 |
| --- | --- |
| \ |   |


#### Projet 4.1 : Jouer 'Happy Birthday'

**Code de test**

```python
from machine import Pin, PWM
from time import sleep
buzzer = PWM(Pin(25))

buzzer.duty(1000)

# Happy birthday
buzzer.freq(294)
sleep(0.25)
buzzer.freq(440)
sleep(0.25)
buzzer.freq(392)
sleep(0.25)
buzzer.freq(532)
sleep(0.25)
buzzer.freq(494)
sleep(0.25)
buzzer.freq(392)
sleep(0.25)
buzzer.freq(440)
sleep(0.25)
buzzer.freq(392)
sleep(0.25)
buzzer.freq(587)
sleep(0.25)
buzzer.freq(532)
sleep(0.25)
buzzer.freq(392)
sleep(0.25)
buzzer.freq(784)
sleep(0.25)
buzzer.freq(659)
sleep(0.25)
buzzer.freq(532)
sleep(0.25)
buzzer.freq(494)
sleep(0.25)
buzzer.freq(440)
sleep(0.25)
buzzer.freq(698)
sleep(0.25)
buzzer.freq(659)
sleep(0.25)
buzzer.freq(532)
sleep(0.25)
buzzer.freq(587)
sleep(0.25)
buzzer.freq(532)
sleep(0.5)
buzzer.duty(0)
```
**Résultat du test**

Le buzzer passif jouera 'Happy Birthday'.