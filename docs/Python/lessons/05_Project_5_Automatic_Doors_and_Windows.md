### Project 5: Automatische deuren en ramen

**Beschrijving**

Automatische deuren en ramen hebben een aandrijfapparaat nodig, dat geautomatiseerder kan worden met een 180° servo en enkele sensoren. Door een raindrop sensor toe te voegen, kun je het effect bereiken dat ramen automatisch sluiten wanneer het regent. Als je een RFID toevoegt, kunnen we het effect realiseren van swipen om de deur te openen, enzovoort.

**Componentkennis**

**Servo:**

Servo is een position servo driver device bestaat uit een behuizing, een circuit board, een coreless motor, een gear en een position detector.

Het werkingsprincipe is dat de servo het signaal ontvangt dat door de MCU of ontvanger wordt gestuurd en een referentiesignaal produceert met een periode van 20ms en een breedte van 1.5ms, daarna vergelijkt het de verkregen DC bias spanning met de spanning van de potentiometer en bepaalt het spanningsverschil als output.

De IC op de circuit board beoordeelt de draairichting en drijft vervolgens de coreless motor aan om te beginnen met draaien. Het vermogen wordt via het reduction gear overgebracht naar de swing arm, en het signaal wordt teruggestuurd door de position detector om te beoordelen of de positionering is bereikt, wat geschikt is voor die besturingssystemen die een constante hoekverandering vereisen en kunnen worden vastgehouden.

Wanneer de motorsnelheid constant is, wordt de potentiometer via het cascade reduction gear in draaiing gebracht, wat leidt tot dat het spanningsverschil 0 is en de motor stopt met draaien. Over het algemeen is het hoekomvang van de servo rotatie 0° --180 °.

De pulsperiode van de control servo is 20ms, de pulsbreedte is 0.5ms ~ 2.5ms, en de overeenkomstige positie is -90°~ +90°. Hier is een voorbeeld van een 180° servo:

![afbeelding28](../media/708316fde05c62113a3024e0efb0c237.jpeg)

In het algemeen heeft de servo drie draden in bruin, rood en oranje. De bruine draad is aardedraad, de rode is de positieve voedingsdraad en de oranje is een signaaldraad.

![afbeelding29](../media/35084ae289a08e35bdb8c89ceb134ba4.png)

![afbeelding30](../media/6cbf6f177ea204f7632b872497fde010.png)

**Pin**

| De servo van het raam | 5 |
| --- | --- |
| De servo van de deur | 13 |


#### Project 5.1 De deur besturen

**Testcode**

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
**Testresultaat**

De servo van de deur draait mee met de deur, heen en weer


#### Project 5.2 Het raam sluiten

**Beschrijving**

We gaan een servo en een raindrop sensor gebruiken om een apparaat te maken dat ramen automatisch sluit wanneer het regent.

**Componentkennis**

**Raindrop Sensor:** Dit is een analoge ingangsmodule; hoe groter het door water bedekte gebied op het detectievlak, hoe groter de teruggegeven waarde (bereik 0~4096).

**Testcode**

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
**Testresultaat**

Aanvankelijk opent het raam automatisch, en wanneer je met je hand (die water op de huid heeft) de raindrop sensor aanraakt, zal het raam sluiten.