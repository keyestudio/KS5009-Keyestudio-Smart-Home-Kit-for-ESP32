### Proyecto 2: Lámpara de mesa

**Descripción**

La lámpara de mesa común usa luces LED y botones, que permiten encender y apagar la luz pulsando el botón.

**Principio del botón**

El módulo de botón es un sensor digital, que solo puede leer 0 o 1. Cuando el módulo no está pulsado, está en un estado de nivel alto, es decir, 1; cuando se pulsa, está en nivel bajo 0.

![imagen22](../media/41f565d4f355abb96e105119660e80ba.png)

**Pines del botón**

| **Botón 1** | **16** |
| --- | --- |
| **Botón 2** | **27** |


#### Proyecto 2.1 Leer el botón

**Descripción**

Vamos a leer el valor de estado del botón y mostrarlo en el monitor serie para verlo de forma intuitiva.

**Código de prueba**

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
**Resultado de la prueba**

Haz clic en el botón Run, entonces podrás ver los valores de estado de button1 y button2 impresos en el shell. Pulsa el botón del hogar inteligente y verás el cambio de los valores de estado.

![imagen23](../media/1b984da67c0e89a72a9601c39362567d.png)


#### Proyecto 2.2. Lámpara de mesa

**Descripción**

Para una lámpara de mesa simple y común, al pulsar el botón se encenderá; al pulsarlo de nuevo, la lámpara se apagará.

**Código de prueba**

Calculando las veces que se ha pulsado el botón y tomando el resto al dividir por 2, se pueden obtener los dos valores de estado 0 o 1.

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
**Resultado de la prueba**

El shell imprimirá el número de veces que se ha pulsado el botón; al pulsarlo una vez, el LED se encenderá; al pulsarlo de nuevo, se apagará.

![imagen24](../media/1bc079eabd93cb2e8a8e15f0ab7f1367.png)