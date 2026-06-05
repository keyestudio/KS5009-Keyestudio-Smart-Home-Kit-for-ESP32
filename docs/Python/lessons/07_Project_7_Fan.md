### Project 7: Ventilator

**Beschrijving**

In dit project leren we hoe we een kleine ventilator kunnen maken.

**Kennis van componenten**

De kleine ventilator gebruikt een 130 DC motor en veilige ventilatorbladen. Je kunt PWM-uitgang gebruiken om de ventilatorsnelheid te regelen.

![afbeelding33](../media/33da52918e88862a94035d61a9050f2e.png)

**Bedieningsmethode**

Twee pinnen zijn vereist om de motor van de ventilator te besturen, één voor INA en twee voor INB. Het PWM-waardebereik is 0~255. Wanneer de PWM-uitgang van de twee pinnen verschillend is, kan de ventilator draaien.

| INA - INB <= -45 | Draai met de klok mee |
| --- | --- |
| INA - INB >= 45 | Draai tegen de klok in |
| INA ==0, INB == 0 | Stop |

**Besturingspinnen**

| INA | 19 |
| --- | --- |
| INB | 18 |


#### Project 7.1 Ventilator

We kunnen de rotatiesnelheid van de ventilator zowel tegen de klok in als met de klok mee regelen.

**Testcode**

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
**Testresultaat**

De ventilator zal met verschillende snelheden met de klok mee en tegen de klok in draaien.


#### Project 7.2 Ventilator met knopbediening

Knop 1 bestuurt de ventilatorschakelaar.

**Testcode**

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
**Testresultaat**

Druk op knop 1, de ventilator begint te draaien; druk nogmaals op knop 1, de ventilator stopt.