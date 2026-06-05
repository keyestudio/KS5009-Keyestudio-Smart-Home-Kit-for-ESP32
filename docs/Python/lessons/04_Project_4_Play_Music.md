### Progetto 4: Riprodurre musica

**Descrizione**

Sulla scheda di espansione per auto è presente un elemento amplificatore audio,
che funge da dispositivo di amplificazione esterno per riprodurre musica.

In questo progetto useremo questo elemento per riprodurre un brano musicale.

**Conoscenze sul componente**

**Cicalino passivo:**

L'amplificatore audio (come il cicalino passivo) non dispone di
oscillazione interna. Per il controllo è necessario inviare onde quadre di
diverse frequenze al polo positivo del componente e collegare a massa
il polo negativo per far suonare l'amplificatore a frequenze diverse.

![immagine27](../media/2e6fd6b7975ef84ab94eee896161347b.png)

**Pin di controllo**

| Cicalino passivo | 25 |
| --- | --- |
| \ |   |


#### Progetto 4.1 Riprodurre Happy Birthday

**Codice di test**

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
**Risultato del test**

Il cicalino passivo riprodurrà Happy Birthday.