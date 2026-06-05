### Project 6: Sfeerlamp

**Beschrijving**

De sfeerlamp van het slimme huis bestaat uit 4 SK6812RGB LEDs. RGB LED behoort tot een eenvoudige lichtmodule, die de kleur kan aanpassen om het lamp-effect van verschillende kleuren te creëren. Verder kan het op grote schaal worden gebruikt in gebouwen, bruggen, wegen, tuinen, binnenplaatsen, verdiepingen en andere gebieden van decoratieve verlichting en locatie-indeling, tijdens Kerstmis, Halloween, Valentijnsdag, Pasen, de Nationale Feestdag en andere feestdagen en scènes voor sfeer.

In dit experiment zullen we verschillende lichteffecten maken.

**Componentkennis**

Uit het schema kunnen we zien dat deze vier RGB LEDs allemaal in serie zijn aangesloten. In feite, hoeveel het er ook zijn, we kunnen één pin gebruiken om een SK6812 RGB LED te regelen en deze elke kleur laten weergeven. Elke RGBLED is een onafhankelijk pixel, bestaande uit R, G en B kleuren, die 256 helderheidsniveaus kunnen bereiken en de volledige waarheidsgetrouwe kleurdweergave van 16777216 kleuren kunnen voltooien.

Bovendien bevat het pixelpunt een data-latch signaalvormende versterker/drive-circuit en een signaalvormingscircuit, wat effectief waarborgt dat de kleur van het pixellicht zeer consistent is.

![afbeelding31](../media/86e292d0666046b72a1e0e68adfb17e8.png)

![afbeelding32](../media/c0df93f61c6b9272f62b1847ccfbdb10.png)

**Pin**

| SK6812 | 26 |
| --- | --- |
| \ |   |


#### Project 6.1 RGB Sk6812

We zullen SK6812 aansturen om verschillende lichteffecten weer te geven.

**Testcode**

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
**Testresultaat**

De sfeerlampen van het slimme huis tonen rood, groen, blauw en wit.


#### Project 6.2 Button Control Sk6812

**Beschrijving**

Er zijn twee schakelaars om de kleur van de sfeerlamp te veranderen.

**Testcode**

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
**Testresultaat**

We kunnen de kleur van de sfeerlamp wisselen door op knoppen 1 en 2 te drukken.