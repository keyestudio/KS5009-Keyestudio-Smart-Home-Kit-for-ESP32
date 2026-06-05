### Projet 6 : Lampe d'ambiance

**Description**

La lampe d'ambiance de la maison intelligente est composée de 4 LED SK6812RGB. La LED RGB est un module lumineux simple, qui peut ajuster la couleur pour produire des effets lumineux de différentes couleurs. De plus, elle peut être largement utilisée dans les bâtiments, ponts, routes, jardins, cours, étages et autres domaines d'éclairage décoratif et d'aménagement de lieux, ainsi que pour créer des ambiances lors de Noël, Halloween, la Saint-Valentin, Pâques, la Fête nationale et d'autres festivités ou scènes.

Dans cette expérience, nous allons réaliser divers effets d'éclairage.

**Connaissances sur les composants**

D'après le schéma, on voit que ces quatre LED RGB sont toutes connectées en série. En fait, quel que soit leur nombre, nous pouvons utiliser une broche pour contrôler une LED RGB et lui faire afficher n'importe quelle couleur. Chaque RGBLED est un pixel indépendant, composé des couleurs R, G et B, qui peut afficher 256 niveaux de luminosité et réaliser l'affichage en vraie couleur sur 16777216 couleurs.

De plus, le pixel contient un circuit d'amplification de commande à mise en mémoire du signal et un circuit de mise en forme du signal, ce qui garantit efficacement une grande cohérence des couleurs des pixels lumineux.

![image31](../media/86e292d0666046b72a1e0e68adfb17e8.png)

![image32](../media/c0df93f61c6b9272f62b1847ccfbdb10.png)

**Broche**

| SK6812 | 26 |
| --- | --- |
| \ |   |


#### Projet 6.1 RGB Sk6812

Nous contrôlerons le SK6812 pour afficher divers effets lumineux.

**Code de test**

```python
#Import Pin, neopiexl and time modules.
from machine import Pin
import neopixel
import time

#Define the number of pin and LEDs connected to neopixel.
pin = Pin(26, Pin.OUT)
np = neopixel.NeoPixel(pin, 4)

#brightness :0-255
brightness=100
colors=[[brightness,0,0],                    #red
        [0,brightness,0],                    #green
        [0,0,brightness],                    #blue
        [brightness,brightness,brightness],  #white
        [0,0,0]]                             #close

#Nest two for loops to make the module repeatedly display five states of red, green, blue, white and OFF.
while True:
    for i in range(0,5):
        for j in range(0,4):
            np[j]=colors[i]
            np.write()
            time.sleep_ms(50)
        time.sleep_ms(500)
    time.sleep_ms(500)
```
**Résultat du test**

Les lampes d'ambiance de la maison intelligente afficheront du rouge, du bleu-vert ainsi que du blanc.


#### Projet 6.2 Contrôle par bouton Sk6812

**Description**

Il y a deux boutons pour changer la couleur de la lampe d'ambiance.

**Code de test**

```python
#Import Pin, neopiexl and time modules.
from machine import Pin
import neopixel
import time

button1 = Pin(16, Pin.IN, Pin.PULL_UP)
button2 = Pin(27, Pin.IN, Pin.PULL_UP)
count = 0

#Define the number of pin and LEDs connected to neopixel.
pin = Pin(26, Pin.OUT)
np = neopixel.NeoPixel(pin, 4)

#brightness :0-255
brightness=100
colors=[[0,0,0],
        [brightness,0,0],                    #red
        [0,brightness,0],                    #green
        [0,0,brightness],                    #blue
        [brightness,brightness,brightness]  #white
        ]                             #close

def func_color(val):
    for j in range(0,4):
        np[j]=colors[val]
        np.write()
        time.sleep_ms(50)

#Nest two for loops to make the module repeatedly display five states of red, green, blue, white and OFF.
while True:
    btnVal1 = button1.value()  # Reads the value of button 1
    #print("button1 =",btnVal1)  #Print it out in the shell
    if(btnVal1 == 0):
        time.sleep(0.01)
        while(btnVal1 == 0):
            btnVal1 = button1.value()
            if(btnVal1 == 1):
                count = count - 1
                print(count)
                if(count <= 0):
                    count = 0

    btnVal2 = button2.value()
    if(btnVal2 == 0):
        time.sleep(0.01)
        while(btnVal2 == 0):
            btnVal2 = button2.value()
            if(btnVal2 == 1):
                count = count + 1
                print(count)
                if(count >= 4):
                    count = 4

    if(count == 0):
        func_color(0)
    elif(count == 1):
        func_color(1)
    elif(count == 2):
        func_color(2)
    elif(count == 3):
        func_color(3)
    elif(count == 4):
        func_color(4)
```
**Résultat du test**

Nous pouvons changer la couleur de la lampe d'ambiance en appuyant sur les boutons 1 et 2.