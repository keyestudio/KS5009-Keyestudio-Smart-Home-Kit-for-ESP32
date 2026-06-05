### Projet 10 : Module RFID RC522

**Informations sur le composant**

L'identification par radiofréquence, le lecteur de cartes est composé d'un module radiofréquence et d'un champ magnétique de haut niveau. Le transpondeur Tag est un dispositif de détection, qui ne contient pas de batterie. Il contient uniquement de minuscules puces de circuit intégré et des supports pour le stockage des données ainsi que des antennes pour recevoir et transmettre les signaux.

Pour lire les données dans le tag, placez-le d'abord dans la portée de lecture du lecteur de cartes. Le lecteur va générer un champ magnétique, qui peut produire de l'électricité selon la loi de Lenz, puis le tag RFID alimentera le dispositif, activant ainsi l'appareil.

![image40](../media/982ac6a9da0e8f55465ca5a969ac0dfe.png)

**Broches de contrôle**

Utiliser la communication IIC

| SDA | SDA |
| --- | --- |
| SCL | SCL |


#### Projet 10.1 Ouvrir la porte

Ouvrez le dossier où se trouvent mfrc522_config.py, soft_iic.py et mfrc522_i2c.py

Ouvrez “Thonny”, cliquez sur “Cet ordinateur”→“D:”→“2. Python Projects”→“pj10_rc522_RFID”. Sélectionnez “mfrc522_config.py”, faites un clic droit et sélectionnez “\ **Téléverser vers /**\ ”, attendez que “mfrc522_config.py” soit téléversé sur ESP32 ; sélectionnez ensuite “soft_iic.py”, faites un clic droit et sélectionnez “\ **Téléverser vers /**\ ”, attendez que “soft_iic.py” soit téléversé sur ESP32 ; puis sélectionnez “mfrc522_i2c.py”, faites un clic droit et sélectionnez “\ **Téléverser vers /**\ ”, attendez que “mfrc522_i2c.py” soit téléversé sur ESP32.

![image41](../media/img-20250603132607.png)

![image42](../media/img-20250603132647.png)

![image43](../media/img-20250603132729.png)

Les noms enregistrés sont mfrc522_config.py, soft_iic.py et mfrc522_i2c.py.

![image44](../media/img-20250603132756.png)

**Code de test**

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
**Résultat du test**

Approchez la carte fournie de la zone d'induction RFID, la porte tournera et s'ouvrira, et la console affiche "open". Appuyez sur le bouton 1 et la porte tourne et se ferme. Cependant, en passant un autre bloc d'induction bleu, la console affiche "Error".

![image45](../media/03fd569d64704a7e9705c1891f4d4856.png)