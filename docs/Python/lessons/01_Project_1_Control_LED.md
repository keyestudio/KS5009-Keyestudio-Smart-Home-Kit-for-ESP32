### Project 1: LED besturen

We zullen eerst leren hoe een LED te besturen.

![afbeelding16](../media/0cda68ae8719d9b6c1bb79d64160d31d.png)

**Werkingsprincipe**

LED is een lichtuitstralende diode die als een elektronisch module kan worden gemaakt. Hij zal oplichten wanneer we de pinnen een hoge uitgang geven; anders is hij uit.

**Parameters**

| **Werkspanning** | **DC 3~5V** |
| --- | --- |
| **Werkstroom** | **<20mA** |
| **Vermogen** | **0.1W** |

**Controlepin**

| Gele LED | 12 |
| --- | --- |
| \ |   |


#### Project 1.1 LED knipperen

**Beschrijving**

We kunnen de LED-pin een hoog en laag uitgangsniveau laten geven om de LED te laten knipperen.

**Testcode**

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
Open de voorbeeldcode

![afbeelding17](../media/39658e26aad2c9794bd3db9df3c70732.png)

![afbeelding18](../media/166384572a1fa595858d933aea5af710.png)

**Testresultaat**

Klik op de knop

![afbeelding19](../media/c5e28dda04f63745f59ef351025e82e8.png)

We kunnen zien dat de gele LED knippert.


#### Project 1.2 Ademende LED

**Beschrijving**

Een "breathing LED" is een verschijnsel waarbij de helderheid van een LED geleidelijk verandert van donker naar helder en weer naar donker, dit blijft zich herhalen en geeft de illusie dat de LED "ademt". Maar hoe bestuur je de helderheid van een LED?

Het is logisch om gebruik te maken van PWM. Door in een tijdseenheid het aantal hoge en lage niveaus uit te geven — hoe meer tijd het hoge niveau inneemt, hoe groter de PWM-waarde en hoe helderder de LED.

![afbeelding20](../media/704984700612966b997127cb9bde5c96.jpeg)

**Testcode**

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
**Testresultaat**

Klik op de knop.

![afbeelding21](../media/609b283e0909b5e5c14809c4ccf892ed.png)

De LED wordt geleidelijk donkerder en vervolgens helderder, cyclisch, alsof hij ademt.