### Progetto 8: Display LCD1602

**Descrizione**

Come sappiamo, lo schermo è uno dei modi migliori per interagire con i dispositivi elettronici.

**Informazioni sul componente**

1602 è una serie che può visualizzare 16 caratteri. Ci sono due righe, che usano il protocollo di comunicazione IIC.

![immagine34](../media/066e093f1711ada67d3309ddc9bdc66e.png)

**Pin di controllo**

| SDA | SDA |
| --- | --- |
| SCL | SCL |


#### Progetto 8.1: Caratteri del display LCD1602

**Descrizione**

Useremo i file di libreria i2c_lcd.py e lcd_api.py, che devono essere salvati nella memoria dell'ESP32.

![immagine35](../media/b5d74645d450d329aded48064bd599c8.png)

**Operazioni**

Aprire “Thonny”, fare clic su “This computer”→“D:”→“2. Python Projects”→“pj8_1_lcd1602”. Selezionare “i2c_lcd.py”, fare clic con il tasto destro del mouse per selezionare “\ **Upload to /**\ ”, attendere che “i2c_lcd.py” venga caricato sull'ESP32; poi selezionare “lcd_api.py”, fare clic con il tasto destro del mouse per selezionare “\ **Upload to /**\ ”, attendere che “lcd_api.py” venga caricato sull'ESP32.

![Immagine](../media/img-20250603131246.png)

![immagine36](../media/img-20250603131916.png)

I nomi salvati sono i2c_lcd.py e lcd_api.py

![immagine37](../media/img-20250603132138.png)

**Codice di prova**

```python
from time import sleep_ms, ticks_ms
from machine import I2C, Pin
from i2c_lcd import I2cLcd

DEFAULT_I2C_ADDR = 0x27

i2c = I2C(scl=Pin(22), sda=Pin(21), freq=400000)
lcd = I2cLcd(i2c, DEFAULT_I2C_ADDR, 2, 16)

lcd.move_to(1, 0)
lcd.putstr('Hello')
lcd.move_to(1, 1)
lcd.putstr('keyestudio')

# The following line of code should be tested
# using the REPL:

# 1. To print a string to the LCD:
#    lcd.putstr('Hello world')
# 2. To clear the display:
#lcd.clear()
# 3. To control the cursor position:
# lcd.move_to(2, 1)
# 4. To show the cursor:
# lcd.show_cursor()
# 5. To hide the cursor:
#lcd.hide_cursor()
# 6. To set the cursor to blink:
#lcd.blink_cursor_on()
# 7. To stop the cursor on blinking:
#lcd.blink_cursor_off()
# 8. To hide the currently displayed character:
#lcd.display_off()
# 9. To show the currently hidden character:
#lcd.display_on()
# 10. To turn off the backlight:
#lcd.backlight_off()
# 11. To turn ON the backlight:
#lcd.backlight_on()
# 12. To print a single character:
#lcd.putchar('x')
# 13. To print a custom character:
#happy_face = bytearray([0x00, 0x0A, 0x00, 0x04, 0x00, 0x11, 0x0E, 0x00])
#lcd.custom_char(0, happy_face)
#lcd.putchar(chr(0))
```
**Risultato del test**

La prima riga del LCD1602 mostra 'Hello' e la seconda riga mostra 'keyestudio'.


#### Progetto 8.2 Allarme gas pericoloso

**Descrizione**

Quando un sensore di gas rileva un'alta concentrazione di gas pericoloso, il buzzer emetterà un allarme e il display mostrerà 'dangerous'.

**Informazioni sul componente**

**Sensore di fumo MQ2**:

È un dispositivo di monitoraggio delle perdite di gas per abitazioni e fabbriche, adatto al rilevamento di gas liquefatti, benzene, alcani, alcoli, idrogeno e fumo. Il nostro sensore ha un'uscita digitale D e un'uscita analogica A; in questo progetto è collegato a D come sensore digitale.

![immagine38](../media/4550c4935e6c08e595a1e8707b54b551.png)

**Pin di controllo**

| Sensore di gas | 23 |
| --- | --- |
| \ |   |

**Codice di prova**

```python
from time import sleep_ms, ticks_ms
from machine import SoftI2C, Pin
from i2c_lcd import I2cLcd

DEFAULT_I2C_ADDR = 0x27

scl_pin = Pin(22, Pin.OUT, pull=Pin.PULL_UP)  # GPIO22 with internal pull-up enabled
sda_pin = Pin(21, Pin.OUT, pull=Pin.PULL_UP)  # GPIO21 with internal pull-up enabled

i2c = SoftI2C(scl=Pin(22), sda=Pin(21), freq=100000)
lcd = I2cLcd(i2c, DEFAULT_I2C_ADDR, 2, 16)

from machine import Pin
import time
gas = Pin(23, Pin.IN, Pin.PULL_UP)

while True:
    gasVal = gas.value()  # Reads the value of button 1
    print("gas =",gasVal)  #Print it out in the shell
    lcd.move_to(1, 1)
    lcd.putstr('val: {}'.format(gasVal))
    if(gasVal == 1):
        #lcd.clear()
        lcd.move_to(1, 0)
        lcd.putstr('Safety       ')
    else:
        lcd.move_to(1, 0)
        lcd.putstr('dangerous')
    time.sleep(0.1) #delay 0.1s
```
**Risultato del test**

Lo schermo visualizza 'safety' nello stato normale. Tuttavia, quando il sensore di gas rileva gas pericolosi, come monossido di carbonio, a una certa concentrazione, il buzzer emetterà un allarme e lo schermo mostrerà 'dangerous'.