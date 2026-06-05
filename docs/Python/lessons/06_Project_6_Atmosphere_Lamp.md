### Progetto 6: Lampada d'atmosfera

**Descrizione**

La lampada d'atmosfera della casa intelligente è composta da 4 SK6812RGB LED. Un RGB LED appartiene a un semplice modulo luminoso, che può regolare il colore per ottenere l'effetto luminario di diverse tonalità. Inoltre, può essere ampiamente utilizzata in edifici, ponti, strade, giardini, cortili, piani e altri campi di illuminazione decorativa e allestimento di locali, durante Natale, Halloween, San Valentino, Pasqua, la Festa nazionale nonché in altre festività e scene d'atmosfera.

In questo esperimento realizzeremo vari effetti di illuminazione.

**Conoscenze sul componente**

Dal diagramma schematico possiamo vedere che questi quattro RGB LED sono tutti collegati in serie. In realtà, indipendentemente dal loro numero, possiamo usare un pin per controllare un RGB LED e farlo visualizzare qualsiasi colore. Ogni RGBLED è un pixel indipendente, composto dai colori R, G e B, che può raggiungere 256 livelli di luminosità e completare la riproduzione a colori vera di 16777216 colori.

Inoltre, il pixel contiene un circuito driver amplificatore per il condizionamento del segnale di latch dei dati e un circuito di rimodellamento del segnale, che garantiscono efficacemente un'elevata coerenza del colore del punto luce.

![immagine31](../media/86e292d0666046b72a1e0e68adfb17e8.png)

![immagine32](../media/c0df93f61c6b9272f62b1847ccfbdb10.png)

**Pin**

| SK6812 | 26 |
| --- | --- |
| \ |   |


#### Progetto 6.1 RGB Sk6812

Controlleremo gli SK6812 per mostrare vari effetti di illuminazione.

**Codice di test**

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
**Risultato del test**

Le lampade d'atmosfera della casa intelligente mostreranno rosso, verde, blu e bianco.


#### Progetto 6.2 Controllo con pulsanti Sk6812

**Descrizione**

Ci sono due pulsanti a interruttore per cambiare il colore della lampada d'atmosfera.

**Codice di test**

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
**Risultato del test**

Possiamo cambiare il colore della lampada d'atmosfera premendo i pulsanti 1 e 2.