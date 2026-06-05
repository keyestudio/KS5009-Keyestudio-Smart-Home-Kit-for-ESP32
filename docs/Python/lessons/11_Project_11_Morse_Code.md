### Project 11: Morsecode

Morsecode, ook bekend als Morse-wachtwoord, is een pulserend signaalcode die verschillende letters, cijfers en leestekens in verschillende reeksen uitdrukt. Nu gebruiken we het als onze wachtwoordpoort.

De Morsecode komt overeen met de volgende tekens:

![afbeelding46](../media/1a5e70c0d091e2617acbfc274827b4fd.png)


#### Project 11.1 Morsecode: Deur openen

**Beschrijving**

We gebruiken ![afbeelding47](../media/9491f7768f28ee4901e6fdb83632c27c.png)\ als het correcte wachtwoord. Daarnaast is er een knopbibliotheekbestand OneButton, waarmee klikken, dubbelklikken, lang indrukken en andere functies heel eenvoudig zijn. Voor het Morse-wachtwoord is een klik "." en een lang indrukken en loslaten "-".

**Testcode**

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
**Testresultaat**

Eerst toont de LCD1602 "Voer wachtwoord in", daarna klik of houd knop 1 ingedrukt om het wachtwoord in te voeren. Als we het correcte wachtwoord "-.-" invoeren en vervolgens knop 2 indrukken, opent de deur en toont de LCD1602 "open".

Als er andere onjuiste wachtwoorden worden ingevoerd, blijft de deur gesloten en toont de LCD1602 "fout", waarna 2 s later "voer opnieuw in" wordt weergegeven.