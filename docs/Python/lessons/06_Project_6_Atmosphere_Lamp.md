### Projekt 6: Atmosphärenlampe

**Description**

Die Atmosphärenlampe des Smart Home besteht aus 4 SK6812RGB LEDs. RGB LED gehört zu einem einfachen Leuchtmodul, das die Farbe einstellen kann, um verschiedene Lampeneffekte zu erzeugen. Darüber hinaus kann es in Gebäuden, Brücken, Straßen, Gärten, Höfen, Etagen und anderen Bereichen der dekorativen Beleuchtung und Veranstaltungsanordnung sowie bei Weihnachten, Halloween, Valentinstag, Ostern, Nationalfeiertagen und anderen Festen weit verbreitet eingesetzt werden, um Atmosphäre und andere Szenen zu schaffen.

In diesem Experiment werden wir verschiedene Lichteffekte erzeugen.

**Component Knowledge**

Aus dem Schaltplan ist ersichtlich, dass diese vier RGB LEDs alle in Reihe geschaltet sind. Tatsächlich können wir, egal wie viele es sind, eine einzige Pin verwenden, um eine RGB LED zu steuern und sie in jeder Farbe anzeigen zu lassen. Jede RGBLED ist ein unabhängiges Pixel, das aus den Farben R, G und B besteht und 256 Helligkeitsstufen erreichen kann und so die vollständige True-Color-Anzeige von 16777216 Farben ermöglicht.

Außerdem enthält der Pixelpunkt eine Datenlatch-Signalformungs-, Verstärkeransteuerungs- und Signalformungsschaltung, die effektiv sicherstellt, dass die Farbe der Pixelbeleuchtung sehr gleichmäßig ist.

![Bild 31](../media/86e292d0666046b72a1e0e68adfb17e8.png)

![Bild 32](../media/c0df93f61c6b9272f62b1847ccfbdb10.png)

**Pin**

| SK6812 | 26 |
| --- | --- |
| \ |   |


#### Projekt 6.1 RGB Sk6812

Wir werden SK6812 steuern, um verschiedene Lichteffekte anzuzeigen.

**Test Code**

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
**Test Result**

Die Atmosphärenlampen des Smart Home werden Rot, Grün, Blau sowie Weiß anzeigen.


#### Projekt 6.2 Button Control Sk6812

**Description**

Es gibt zwei Tasten, um die Farbe der Atmosphärenlampe zu ändern.

**Test Code**

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
**Test Result**

Wir können die Farbe der Atmosphärenlampe durch Drücken der Tasten 1 und 2 umschalten.