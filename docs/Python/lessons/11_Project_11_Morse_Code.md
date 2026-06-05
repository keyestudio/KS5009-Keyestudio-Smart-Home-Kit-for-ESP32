### Projet 11 : Code Morse

Le code Morse, également appelé mot de passe Morse, est un code de signalisation constitué d'impulsions courtes et longues qui permet d'exprimer différentes lettres, chiffres et signes de ponctuation selon des séquences différentes. Nous l'utilisons maintenant comme notre porte d'accès par mot de passe.

Le code Morse correspond aux caractères suivants :

![tableau du code Morse](../media/1a5e70c0d091e2617acbfc274827b4fd.png)


#### Projet 11.1 : Ouverture de la porte par code Morse

**Description**

Nous utilisons ![mot de passe correct](../media/9491f7768f28ee4901e6fdb83632c27c.png)\ comme mot de passe correct. De plus, il existe un fichier de bibliothèque OneButton, qui permet très simplement le clic, le double-clic, l'appui long et d'autres fonctions. Pour le mot de passe Morse, un clic correspond à « . », un appui long suivi du relâchement correspond à « - ».

**Code de test**

```python
# Import machine, time and dht modules.
from machine import Pin, PWM
from time import sleep_ms, ticks_ms
from machine import SoftI2C, Pin
from i2c_lcd import I2cLcd

DEFAULT_I2C_ADDR = 0x27

# Initialize SCL/SDA pins and enable internal pull-up
scl_pin = Pin(22, Pin.OUT, pull=Pin.PULL_UP)  # GPIO22 with internal pull-up
sda_pin = Pin(21, Pin.OUT, pull=Pin.PULL_UP)  # GPIO21 with internal pull-up

i2c = SoftI2C(scl=Pin(22), sda=Pin(21), freq=100000)
lcd = I2cLcd(i2c, DEFAULT_I2C_ADDR, 2, 16)

button1 = Pin(16, Pin.IN, Pin.PULL_UP)
button2 = Pin(27, Pin.IN, Pin.PULL_UP)
count = 0
time_count = 0
password = ""   # Input password
correct_password = "-.-"  # Correct password
lcd.putstr("Enter password")
pwm = PWM(Pin(13))
pwm.freq(50)

while True:
    btnVal1 = button1.value()  # Reads the value of button 1
    if(btnVal1 == 0):
        sleep_ms(10)
        while(btnVal1 == 0):
            time_count = time_count + 1  # Start counting how long the button is pressed
            sleep_ms(200)                # Time accumulates in 200ms increments
            btnVal1 = button1.value()
            if(btnVal1 == 1):
                count = count + 1
                print(count)
                print(time_count)
                if(time_count > 3):      # If button pressed longer than 200*3ms, add "-" to password
                    lcd.clear()
                    #lcd.move_to(1, 1)
                    password = password + "-"
                else:
                    lcd.clear()
                    password = password + "."  # Otherwise add "."
                lcd.putstr('{}'.format(password))
                time_count = 0

    btnVal2 = button2.value()
    if(btnVal2 == 0):
        if(password == correct_password):  # If password is correct
            lcd.clear()
            lcd.putstr("open")
            pwm.duty(128)  # Open door
            password = ""  # Clear password
            sleep_ms(1000)
        else:              # If password is wrong
            lcd.clear()
            lcd.putstr("error")
            pwm.duty(25)  # Close door
            sleep_ms(2000)
            lcd.clear()
            lcd.putstr("enter again")
            password = ""  # Clear password
```
**Résultat du test**

Au départ, le LCD1602 affiche « Entrez le mot de passe », puis effectuez un clic ou un appui long sur le bouton 1 pour saisir le mot de passe. Si nous saisissons le mot de passe correct « -.- », puis appuyons sur le bouton 2, la porte s'ouvrira et le LCD1602 affichera « ouvert ».

Si d'autres mots de passe incorrects sont saisis, la porte restera fermée et le LCD1602 affichera « erreur », puis affichera « entrez à nouveau » 2 s plus tard.