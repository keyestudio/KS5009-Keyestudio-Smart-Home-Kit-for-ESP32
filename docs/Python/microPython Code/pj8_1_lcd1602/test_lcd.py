from time import sleep_ms, ticks_ms 
from machine import SoftI2C, Pin 
from i2c_lcd import I2cLcd 

DEFAULT_I2C_ADDR = 0x27

# 初始化 SCL/SDA 引脚并启用内部上拉
scl_pin = Pin(22, Pin.OUT, pull=Pin.PULL_UP)  # GPIO22 启用内部上拉
sda_pin = Pin(21, Pin.OUT, pull=Pin.PULL_UP)  # GPIO21 启用内部上拉

i2c = SoftI2C(scl=Pin(22), sda=Pin(21), freq=100000)

devices = i2c.scan()
if not devices:
    print("未检测到 I2C 设备！检查接线/供电/上拉电阻")
else:
    print("检测到设备地址：", [hex(addr) for addr in devices])  # 输出十六进制地址‌:ml-citation{ref="3,8" data="citationList"}

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