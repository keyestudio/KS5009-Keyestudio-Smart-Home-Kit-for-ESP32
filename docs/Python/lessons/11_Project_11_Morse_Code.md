### Progetto 11: Codice Morse

Il codice Morse, noto anche come Morse password, è un codice a segnali acceso-spento che esprime diverse lettere, numeri e segni di punteggiatura in sequenze differenti. Ora lo usiamo come cancellino di accesso.

Il codice Morse corrisponde ai seguenti caratteri:

![immagine46](../media/1a5e70c0d091e2617acbfc274827b4fd.png)


#### Progetto 11.1 Apertura della porta con codice Morse

**Descrizione**

Usiamo ![immagine47](../media/9491f7768f28ee4901e6fdb83632c27c.png) come password corretta. Inoltre è presente un file di libreria per pulsanti OneButton, che rende molto semplice gestire clic singoli, doppio clic, pressione lunga e altre funzioni. Per la password Morse, il clic breve corrisponde a “.”, la pressione lunga e rilascio corrisponde a “-”.

**Codice di test**

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
**Risultato del test**

All'inizio, l'LCD1602 visualizza "Enter password", poi premere brevemente o tenere premuto il pulsante 1 per inserire il codice. Se inseriamo la password corretta "-.-" e poi premiamo il pulsante 2, la porta si aprirà e l'LCD1602 visualizzerà "aperto".

Se vengono inserite altre password errate, la porta rimarrà chiusa e l'LCD1602 visualizzerà "errore", che mostrerà "inserire nuovamente" dopo 2s.