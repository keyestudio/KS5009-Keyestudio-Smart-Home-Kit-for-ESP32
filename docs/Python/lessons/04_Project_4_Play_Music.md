### Proyecto 4: Reproducir música

**Descripción**

Hay un elemento amplificador de potencia de audio en la placa de expansión del coche, que actúa como un equipo de amplificación externo para reproducir música.

**Conocimiento del componente**

**Zumbador pasivo:**

El amplificador de potencia de audio (como el zumbador pasivo) no tiene oscilación interna. Al controlarlo, necesitamos introducir ondas cuadradas de diferentes frecuencias en el polo positivo del componente y conectar a tierra el polo negativo para controlar que el amplificador produzca sonidos de diferentes frecuencias.

![imagen27](../media/2e6fd6b7975ef84ab94eee896161347b.png)

**Pin de control**

| Zumbador pasivo | 25 |
| --- | --- |
| \ |   |


#### Proyecto 4.1 Reproducir 'Happy Birthday'

**Código de prueba**

```python
from machine import Pin, PWM
from time import sleep
buzzer = PWM(Pin(25))

buzzer.duty(1000)

# Happy birthday
buzzer.freq(294)
sleep(0.25)
buzzer.freq(440)
sleep(0.25)
buzzer.freq(392)
sleep(0.25)
buzzer.freq(532)
sleep(0.25)
buzzer.freq(494)
sleep(0.25)
buzzer.freq(392)
sleep(0.25)
buzzer.freq(440)
sleep(0.25)
buzzer.freq(392)
sleep(0.25)
buzzer.freq(587)
sleep(0.25)
buzzer.freq(532)
sleep(0.25)
buzzer.freq(392)
sleep(0.25)
buzzer.freq(784)
sleep(0.25)
buzzer.freq(659)
sleep(0.25)
buzzer.freq(532)
sleep(0.25)
buzzer.freq(494)
sleep(0.25)
buzzer.freq(440)
sleep(0.25)
buzzer.freq(698)
sleep(0.25)
buzzer.freq(659)
sleep(0.25)
buzzer.freq(532)
sleep(0.25)
buzzer.freq(587)
sleep(0.25)
buzzer.freq(532)
sleep(0.5)
buzzer.duty(0)
```
**Resultado de la prueba**

El zumbador pasivo reproducirá 'Happy Birthday'.