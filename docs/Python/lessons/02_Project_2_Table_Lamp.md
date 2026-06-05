### Projekt 2: Tischlampe

**Beschreibung**

Eine übliche Tischlampe verwendet LED-Leuchten und Tasten, mit denen das
Licht durch Drücken der Taste ein- und ausgeschaltet werden kann.

**Funktionsprinzip der Taste**

Das Tastenmodul ist ein digitaler Sensor, der nur 0 oder 1 lesen kann. Wenn
das Modul nicht gedrückt ist, befindet es sich im High-Zustand, also 1; beim
Drücken ist es im Low-Zustand, also 0.

![Bild22](../media/41f565d4f355abb96e105119660e80ba.png)

**Pins der Taste**

| **Taste 1** | **16** |
| --- | --- |
| **Taste 2** | **27** |


#### Projekt 2.1 Taste auslesen

**Beschreibung**

Wir werden den Statuswert der Taste auslesen und im seriellen Monitor anzeigen,
um ihn anschaulich zu sehen.

**Testcode**

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
**Testergebnis**

Klicken Sie auf die Run-Schaltfläche, dann sehen Sie die Statuswerte von button1 und
button2 in der Konsole ausgegeben. Drücken Sie die Taste am Smart-Home-Modul, und Sie
können die Änderung der Statuswerte beobachten.

![Bild23](../media/1b984da67c0e89a72a9601c39362567d.png)


#### Projekt 2.2: Tischlampe

**Beschreibung**

Bei einer einfachen Tischlampe: Drückt man die Taste, wird das Licht eingeschaltet;
drückt man sie erneut, wird es ausgeschaltet.

**Testcode**

Zähle die Anzahl der Tastendrücke und bilde den Rest bei Division durch 2, so
erhältst du die beiden Zustände 0 oder 1.

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
**Testergebnis**

Die Konsole gibt die Anzahl der Tastendrücke aus. Drückt man die Taste einmal,
leuchtet die LED; drückt man sie erneut, erlischt sie.

![Bild24](../media/1bc079eabd93cb2e8a8e15f0ab7f1367.png)