### Progetto 10: Modulo RFID RC522

**Informazioni sul componente**

L'identificazione a radiofrequenza, il lettore di tessere è composto da un modulo a radiofrequenza e da un campo magnetico. Il transponder Tag è un dispositivo sensore che non contiene una batteria. Contiene solo piccoli circuiti integrati e supporti per l'archiviazione dei dati e antenne per ricevere e trasmettere segnali.

Per leggere i dati nel tag, prima posizionarlo nell'area di lettura del lettore di tessere. Il lettore genererà un campo magnetico, che può produrre elettricità secondo la legge di Lenz, quindi il tag RFID fornirà alimentazione, attivando così il dispositivo.

![immagine40](../media/982ac6a9da0e8f55465ca5a969ac0dfe.png)

**Pin di controllo**

Utilizzare la comunicazione IIC

| SDA | SDA |
| --- | --- |
| SCL | SCL |


#### Progetto 10.1 Aprire la porta

Aprire la cartella in cui si trovano mfrc522_config.py, soft_iic.py e mfrc522_i2c.py

Aprire “Thonny”, cliccare “This computer”→“D:”→“2. Python Projects”→“pj10_rc522_RFID”. Selezionare “mfrc522_config.py”, fare clic con il tasto destro del mouse e selezionare “\ **Upload to /**\ ”, attendere che “mfrc522_config.py” venga caricato su ESP32; selezionare “soft_iic.py”, fare clic con il tasto destro del mouse e selezionare “\ **Upload to /**\ ”, attendere che “soft_iic.py” venga caricato su ESP32; infine selezionare “mfrc522_i2c.py”, fare clic con il tasto destro del mouse e selezionare “\ **Upload to /**\ ”, attendere che “mfrc522_i2c.py” venga caricato su ESP32.

![immagine41](../media/img-20250603132607.png)

![immagine42](../media/img-20250603132647.png)

![immagine43](../media/img-20250603132729.png)

I nomi salvati sono mfrc522_config.py, soft_iic.py e mfrc522_i2c.py.

![immagine44](../media/img-20250603132756.png)

**Codice di test**

```python
from machine import Pin, PWM,I2C, Pin
import time
from mfrc522_i2c import mfrc522


pwm = PWM(Pin(13))
pwm.freq(50)
button1 = Pin(16, Pin.IN, Pin.PULL_UP)
#i2c config
addr = 0x28
scl = 22
sda = 21

rc522 = mfrc522(scl, sda, addr)
rc522.PCD_Init()
rc522.ShowReaderDetails()            # Show details of PCD - MFRC522 Card Reader details

data = 0

while True:
    if rc522.PICC_IsNewCardPresent():
        #print("Is new card present!")
        if rc522.PICC_ReadCardSerial() == True:
            print("Card UID:")
            #print(rc522.uid.uidByte[0 : rc522.uid.size])
            for i in rc522.uid.uidByte[0 : rc522.uid.size]:
                data = data + i
        print(data)
        if(data == 510):
            pwm.duty(128)
            print("open")
        else:
            print("error")
        data = 0
    btnVal1 = button1.value()
    if(btnVal1 == 0):
        pwm.duty(25)
        print("close")
    time.sleep(1)
```
**Risultato del test**

Avvicinando la tessera fornita all'area di induzione RFID, la porta ruota e si apre, e la console mostra "open". Premendo il pulsante 1 la porta ruota e si chiude. Tuttavia, passando un altro blocco di induzione blu, la console mostra "Error".

![immagine45](../media/03fd569d64704a7e9705c1891f4d4856.png)