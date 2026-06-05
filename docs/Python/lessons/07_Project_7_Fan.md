### Progetto 7: Ventola

**Descrizione**

In questo progetto impareremo come realizzare una piccola ventola.

**Conoscenze sui componenti**

La piccola ventola utilizza un motore DC 130 e pale della ventola sicure. Puoi usare l'uscita PWM per controllare la velocità della ventola.

![immagine33](../media/33da52918e88862a94035d61a9050f2e.png)

**Metodo di controllo**

Sono necessari due pin per controllare il motore della ventola, uno per INA e due per INB. L'intervallo di valori PWM è 0~255. Quando l'uscita PWM dei due pin è diversa, la ventola può ruotare.

| INA - INB <= -45 | Ruota in senso orario |
| --- | --- |
| INA - INB >= 45 | Ruota in senso antiorario |
| INA ==0, INB == 0 | Si ferma |

**Pin di controllo**

| INA | 19 |
| --- | --- |
| INB | 18 |


#### Progetto 7.1 Ventola

Possiamo controllare la velocità di rotazione della ventola in senso antiorario e orario.

**Codice di test**

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
**Risultato del test**

La ventola ruoterà in senso orario e antiorario a velocità diverse.


#### Progetto 7.2 Controllo della ventola con pulsante

Il pulsante 1 controlla l'accensione/spegnimento della ventola.

**Codice di test**

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
**Risultato del test**

Premendo il pulsante 1, la ventola inizia a ruotare; premendo di nuovo il pulsante 1, la ventola si ferma.