### Proyecto 7: Ventilador

**Descripción**

En este proyecto, aprenderemos cómo hacer un pequeño ventilador.

**Conocimientos del componente**

El pequeño ventilador usa un motor DC 130 y aspas de seguridad. Puedes usar la salida PWM para controlar la velocidad del ventilador.

![imagen33](../media/33da52918e88862a94035d61a9050f2e.png)

**Método de control**

Se requieren dos pines para controlar el motor del ventilador, uno para INA y dos para INB. El rango de valores de PWM es 0~255. Cuando la salida PWM de los dos pines es diferente, el ventilador puede girar.

| INA - INB <= -45 | Girar en el sentido horario |
| --- | --- |
| INA - INB >= 45 | Girar en sentido antihorario |
| INA ==0, INB == 0 | Detenerse |

**Pines de control**

| INA | 19 |
| --- | --- |
| INB | 18 |


#### Proyecto 7.1 Ventilador

Podemos controlar la velocidad de rotación en sentido antihorario y horario del ventilador.

**Código de prueba**

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
**Resultado de la prueba**

El ventilador girará en sentido horario y antihorario a diferentes velocidades.


#### Proyecto 7.2 Control del ventilador con botón

El botón 1 controla el encendido del ventilador.

**Código de prueba**

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
**Resultado de la prueba**

Pulsa el botón 1, el ventilador comienza a girar; pulsa el botón 1 de nuevo y el ventilador se detiene.