### Projekt 5: Automatische Türen und Fenster

**Beschreibung**

Automatische Türen und Fenster benötigen ein Antriebsgerät, das mit einem 180° Servo und einigen Sensoren automatischer wird. Mit einem Regensensor können Fenster bei Regen automatisch geschlossen werden. Wird ein RFID hinzugefügt, kann man beispielsweise per Auflegen die Tür öffnen.

**Komponentenwissen**

**Servo:**

Ein Servo ist ein Positionsantriebsgerät, das aus einem Gehäuse, einer Leiterplatte, einem kernlosen Motor, einem Getriebe und einem Positionsdetektor besteht.

Sein Funktionsprinzip ist, dass der Servo das vom MCU oder Empfänger gesendete Signal empfängt und ein Referenzsignal mit einer Periode von 20ms und einer Breite von 1.5ms erzeugt, dann die erfasste Gleichspannungs-Offsetspannung mit der Spannung des Potentiometers vergleicht und die Spannungsdifferenz zur Ausgabe bringt.

Der IC auf der Leiterplatte beurteilt die Drehrichtung und treibt dann den kernlosen Motor zum Start an. Die Kraft wird über das Untersetzungsgetriebe auf den Schwenkarm übertragen, und die Rückmeldung wird vom Positionsdetektor gesendet, um zu prüfen, ob die Position erreicht ist. Das ist geeignet für Steuerungssysteme, die eine konstante Winkeländerung benötigen und gehalten werden können.

Wenn die Motordrehzahl konstant ist, wird das Potentiometer über das gestufte Untersetzungsgetriebe angetrieben, wodurch die Spannungsdifferenz 0 wird und der Motor aufhört zu drehen. Allgemein liegt der Drehbereich eines Servos bei 0°–180°.

Die Impulsperiode des Steuer-Servos beträgt 20ms, die Impulsbreite 0.5ms ~ 2.5ms und die entsprechende Position -90° ~ +90°. Hier ein Beispiel für einen 180° Servo:

![image28](../media/708316fde05c62113a3024e0efb0c237.jpeg)

Im Allgemeinen hat ein Servo drei Leitungen in Braun, Rot und Orange. Die braune Leitung ist Masse, die rote ist die Versorgungsspannung und die orange ist die Signalleitung.

![image29](../media/35084ae289a08e35bdb8c89ceb134ba4.png)

![image30](../media/6cbf6f177ea204f7632b872497fde010.png)

**Pin**

| Der Servo des Fensters | 5 |
| --- | --- |
| Der Servo der Tür | 13 |


#### Projekt 5.1 Tür steuern

**Test Code**

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
**Testergebnis**

Der Servo der Tür bewegt sich zusammen mit der Tür hin und her.


#### Projekt 5.2 Fenster schließen

**Beschreibung**

Wir werden einen Servo und einen Regensensor verwenden, um ein Gerät zu bauen, das Fenster bei Regen automatisch schließt.

**Komponentenwissen**

**Regensensor:** Dies ist ein analoges Eingangsmodul; je größer die von Wasser bedeckte Fläche auf der Messoberfläche ist, desto größer ist der zurückgegebene Wert (Bereich 0~4096).

**Test Code**

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
**Testergebnis**

Zuerst öffnet sich das Fenster automatisch, und wenn Sie den Regensensor mit Ihrer Hand (die Wasser auf der Haut hat) berühren, schließt sich das Fenster.