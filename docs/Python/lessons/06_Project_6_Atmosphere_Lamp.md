### Proyecto 6: Lámpara ambiental

**Descripción**

La lámpara ambiental de la casa inteligente está compuesta por 4 LEDs SK6812RGB. El LED RGB pertenece a un módulo luminoso sencillo, que puede ajustar el color para producir el efecto de iluminación de diferentes colores. Además, puede usarse ampliamente en edificios, puentes, carreteras, jardines, patios, suelos y otros campos de iluminación decorativa y disposición de escenarios, en Navidad, Halloween, San Valentín, Pascua, Día Nacional y otras festividades o escenas ambientales.

En este experimento, haremos varios efectos de iluminación.

**Conocimientos del componente**

A partir del diagrama esquemático, podemos ver que estos cuatro LEDs RGB están conectados en serie. De hecho, no importa cuántos sean, podemos usar un pin para controlar un LED RGB y hacer que muestre cualquier color. Cada RGBLED es un píxel independiente, compuesto por los colores R, G y B, que puede alcanzar 256 niveles de brillo y completar la visualización de color verdadero completa de 16777216 colores.

Además, el punto píxel contiene un circuito de amplificador de conducción de conformado de señal de retención de datos y un circuito de conformado de señal, que asegura de manera efectiva que el color de la luz del píxel sea altamente consistente.

![imagen31](../media/86e292d0666046b72a1e0e68adfb17e8.png)

![imagen32](../media/c0df93f61c6b9272f62b1847ccfbdb10.png)

**Pin**

| SK6812 | 26 |
| --- | --- |
| \ |   |


#### Proyecto 6.1 RGB Sk6812

Controlaremos SK6812 para mostrar varios efectos de iluminación.

**Código de prueba**

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
**Resultado de la prueba**

Las lámparas ambientales de la casa inteligente mostrarán rojo, verde, azul y blanco.


#### Proyecto 6.2 Control con botones Sk6812

**Descripción**

Hay dos botones interruptores para cambiar el color de la lámpara ambiental.

**Código de prueba**

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
**Resultado de la prueba**

Podemos cambiar el color de la lámpara ambiental pulsando los botones 1 y 2.