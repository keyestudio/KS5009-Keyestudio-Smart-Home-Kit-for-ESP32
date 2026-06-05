### Progetto 5: Porte e Finestre Automatiche

**Descrizione**

Porte e finestre automatiche necessitano di un dispositivo motorizzato, che può diventare più automatico con un servo da 180 gradi e alcuni sensori. Aggiungendo un sensore di pioggia, è possibile ottenere l'effetto di chiudere automaticamente le finestre quando piove. Se si aggiunge un RFID, possiamo realizzare l'effetto di strisciare una tessera per aprire la porta e così via.

**Conoscenze sui componenti**

**Servo:**

Servo è un dispositivo driver di posizionamento che consiste in un involucro, una scheda elettronica, un motore senza nucleo, un ingranaggio e un rilevatore di posizione.

Il suo principio di funzionamento è che il servo riceve il segnale inviato dal MCU o dal ricevitore e genera un segnale di riferimento con periodo di 20ms e larghezza di 1.5ms, quindi confronta la tensione di polarizzazione continua acquisita con la tensione del potenziometro e ottiene la differenza di tensione in uscita.

L'IC sulla scheda giudica la direzione di rotazione, e poi aziona il motore senza nucleo per avviare la rotazione. La potenza viene trasmessa al braccio oscillante attraverso l'ingranaggio di riduzione, e il segnale viene restituito dal rilevatore di posizione per verificare se il posizionamento è stato raggiunto, il che è adatto per quei sistemi di controllo che richiedono un cambiamento angolare preciso e che possono essere mantenuti.

Quando la velocità del motore è costante, il potenziometro viene fatto ruotare attraverso il riduttore a cascata, il che porta la differenza di tensione a 0, e il motore smette di ruotare. Generalmente, l'intervallo di rotazione del servo è 0° --180°.

Il periodo dell'impulso di controllo del servo è 20ms, la larghezza dell'impulso è 0.5ms ~ 2.5ms, e la posizione corrispondente è -90°~ +90°. Ecco un esempio di un servo a 180°:

![immagine28](../media/708316fde05c62113a3024e0efb0c237.jpeg)

In generale, il servo ha tre fili di colore marrone, rosso e arancione. Il filo marrone è collegato a massa, quello rosso è il polo positivo e quello arancione è il filo di segnale.

![immagine29](../media/35084ae289a08e35bdb8c89ceb134ba4.png)

![immagine30](../media/6cbf6f177ea204f7632b872497fde010.png)

**Pin**

| Servo della finestra | 5 |
| --- | --- |
| Servo della porta | 13 |


#### Progetto 5.1 Controllo della porta

**Codice di test**

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
**Risultato del test**

Il servo della porta si muove insieme alla porta, avanti e indietro


#### Progetto 5.2 Chiusura della finestra

**Descrizione**

Lavoreremo per utilizzare un servo e un sensore di pioggia per realizzare un dispositivo che chiude automaticamente le finestre quando piove.

**Conoscenze sui componenti**

**Sensore di pioggia:** Questo è un modulo di ingresso analogico: maggiore è l'area coperta dall'acqua sulla superficie di rilevamento, maggiore è il valore restituito (intervallo 0~4096).

**Codice di test**

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
**Risultato del test**

All'inizio la finestra si apre automaticamente, e quando tocchi il sensore di pioggia con la mano (che ha acqua sulla pelle), la finestra si chiuderà.