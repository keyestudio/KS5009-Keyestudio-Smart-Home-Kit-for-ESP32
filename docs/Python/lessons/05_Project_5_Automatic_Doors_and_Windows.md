### Proyecto 5: Puertas y Ventanas Automáticas

**Descripción**

Las puertas y ventanas automáticas necesitan un dispositivo de accionamiento, que se volverá más automático con un servo de 180 grados y algunos sensores. Añadiendo un sensor de gotas de lluvia, se puede conseguir el efecto de cerrar las ventanas automáticamente cuando llueve. Si se añade un RFID, podemos realizar el efecto de deslizar para abrir la puerta, entre otros.

**Conocimientos del componente**

**Servo:**

Un servo es un dispositivo controlador de posición que consiste en una carcasa, una placa de circuito, un motor sin núcleo, un engranaje y un detector de posición.

Su principio de funcionamiento es que el servo recibe la señal enviada por el MCU o el receptor y produce una señal de referencia con un período de 20 ms y un ancho de 1,5 ms, luego compara la tensión de polarización continua adquirida con la tensión del potenciómetro y obtiene la diferencia de tensión de salida.

El IC en la placa de circuito juzga la dirección de rotación y luego impulsa el motor sin núcleo para que comience a girar. La potencia se transmite al brazo oscilante a través del engranaje reductor, y el detector de posición envía la señal de retroalimentación para juzgar si se ha alcanzado el posicionamiento, lo que lo hace adecuado para aquellos sistemas de control que requieren un cambio de ángulo constante y que pueda mantenerse.

Cuando la velocidad del motor es constante, el potenciómetro se hace girar a través del engranaje reductor en cascada, lo que hace que la diferencia de tensión sea 0 y el motor deje de girar. Normalmente, el rango de ángulo de rotación del servo es de 0° a 180°.

El periodo de pulso del servo de control es de 20 ms, el ancho de pulso es de 0,5 ms ~ 2,5 ms, y la posición correspondiente es -90° ~ +90°. Aquí hay un ejemplo de un servo de 180°:

![imagen28](../media/708316fde05c62113a3024e0efb0c237.jpeg)

En general, el servo tiene tres cables en marrón, rojo y naranja. El cable marrón va a tierra, el rojo es la línea de polo positivo y el naranja es la línea de señal.

![imagen29](../media/35084ae289a08e35bdb8c89ceb134ba4.png)

![imagen30](../media/6cbf6f177ea204f7632b872497fde010.png)

**Pin**

| El servo de la ventana | 5 |
| --- | --- |
| El servo de la puerta | 13 |


#### Proyecto 5.1 Controlar la puerta

**Código de prueba**

```python
from machine import Pin, PWM
import time
pwm = PWM(Pin(13))
pwm.freq(50)

'''
Duty cycle corresponding to the Angle
0°----2.5%----25
45°----5%----51.2
90°----7.5%----77
135°----10%----102.4
180°----12.5%----128
'''
angle_0 = 25
angle_90 = 77
angle_180 = 128

while True:
    pwm.duty(angle_0)
    time.sleep(1)
    pwm.duty(angle_90)
    time.sleep(1)
    pwm.duty(angle_180)
    time.sleep(1)
```
**Resultado de la prueba**

El servo de la puerta gira con la puerta, de ida y vuelta.


#### Proyecto 5.2 Cerrar la ventana

**Descripción**

Trabajaremos para usar un servo y un sensor de gotas de lluvia para hacer un dispositivo que cierre las ventanas automáticamente cuando esté lloviendo.

**Conocimientos del componente**

**Sensor de gotas de lluvia:** Este es un módulo de entrada analógica, cuanto mayor sea el área cubierta por agua en la superficie de detección, mayor será el valor devuelto (rango 0~4096).

**Código de prueba**

```python
# Import Pin, ADC and DAC modules.
from machine import ADC,Pin,DAC,PWM
import time
pwm = PWM(Pin(5))
pwm.freq(50)

# Turn on and configure the ADC with the range of 0-3.3V
adc=ADC(Pin(34))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)

# Read ADC value once every 0.1seconds, convert ADC value to DAC value and output it, and print these data to “Shell”.
try:
    while True:
        adcVal=adc.read()
        dacVal=adcVal//16
        voltage = adcVal / 4095.0 * 3.3
        print("ADC Val:",adcVal,"DACVal:",dacVal,"Voltage:",voltage,"V")
        if(voltage > 0.6):
            pwm.duty(46)
        else:
            pwm.duty(100)
        time.sleep(0.1)
except:
    pass
```
**Resultado de la prueba**

Al principio, la ventana se abre automáticamente, y cuando tocas el sensor de gotas de lluvia con la mano (que tiene agua en la piel), la ventana se cerrará.