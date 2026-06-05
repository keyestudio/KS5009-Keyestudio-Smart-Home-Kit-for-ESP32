### Project 2: Tafellamp

**Beschrijving**

De gewone tafellamp gebruikt LED-verlichting en knoppen, waarmee je het
licht kunt aan- en uitzetten door op de knop te drukken.

**Principe van de knop**

De knopmodule is een digitale sensor, die alleen 0 of 1 kan lezen. Wanneer
de module niet is ingedrukt, is de uitgang hoog (1); wanneer hij
ingedrukt is, is hij laag (0).

![afbeelding22](../media/41f565d4f355abb96e105119660e80ba.png)

**Pinnen van de knop**

| **Knop 1** | **16** |
| --- | --- |
| **Knop 2** | **27** |


#### Project 2.1 Lees de knop

**Beschrijving**

We gaan de statuswaarde van de knop lezen en deze op de seriële monitor weergeven, zodat je het intuïtief kunt zien.

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
**Testresultaat**

Klik op de run-knop, dan zie je de statuswaarden van button1 en button 2 in de shell afgedrukt. Druk op de knop van het slimme huis en je ziet de verandering van de statuswaarden.

![afbeelding23](../media/1b984da67c0e89a72a9601c39362567d.png)


#### Project 2.2. Tafellamp

**Beschrijving**

Bij een eenvoudige tafellamp druk je eenmaal op de knop om hem aan te doen, druk je nogmaals om de lamp uit te doen.

**Testcode**

Tel het aantal keren dat op de knop is gedrukt en neem de rest bij deling door 2; zo krijg je twee toestandswaarden: 0 of 1.

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
**Testresultaat**

De shell zal het aantal keren dat op de knop is gedrukt afdrukken; klik eenmaal op de knop, de LED gaat aan, klik nogmaals, dan gaat deze uit.

![afbeelding24](../media/1bc079eabd93cb2e8a8e15f0ab7f1367.png)