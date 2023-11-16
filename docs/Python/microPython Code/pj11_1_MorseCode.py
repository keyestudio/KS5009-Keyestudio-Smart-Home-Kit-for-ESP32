# Import machine, time and dht modules. 
from machine import Pin, PWM
from time import sleep_ms, ticks_ms 
from machine import I2C, Pin 
from i2c_lcd import I2cLcd 

DEFAULT_I2C_ADDR = 0x27

i2c = I2C(scl=Pin(22), sda=Pin(21), freq=400000) 
lcd = I2cLcd(i2c, DEFAULT_I2C_ADDR, 2, 16)

button1 = Pin(16, Pin.IN, Pin.PULL_UP)
button2 = Pin(27, Pin.IN, Pin.PULL_UP)
count = 0
time_count = 0
password = ""   #输入密码
correct_password = "-.-"  #正确密码
lcd.putstr("Enter password")
pwm = PWM(Pin(13))  
pwm.freq(50)

while True:
    btnVal1 = button1.value()  # Reads the value of button 1
    if(btnVal1 == 0):
        sleep_ms(10)
        while(btnVal1 == 0):
            time_count = time_count + 1  #开始计算按键被按下的时间
            sleep_ms(200)                #时间为200ms累加
            btnVal1 = button1.value()
            if(btnVal1 == 1):
                count = count + 1
                print(count)
                print(time_count)
                if(time_count > 3):      #如果按键被按下的时间大于200*3ms，密码加"-"
                    lcd.clear()
                    #lcd.move_to(1, 1)
                    password = password + "-"
                else:
                    lcd.clear()
                    password = password + "."  #否则加"."
                lcd.putstr('{}'.format(password)) 
                time_count = 0
                
    btnVal2 = button2.value()
    if(btnVal2 == 0):
        if(password == correct_password):  #如果输入密码正确
            lcd.clear()
            lcd.putstr("open")
            pwm.duty(128)  #开门
            password = ""  #清除密码
            sleep_ms(1000)
        else:              #如果密码错误
            lcd.clear()
            lcd.putstr("error")
            pwm.duty(25)  #关门
            sleep_ms(2000)
            lcd.clear()
            lcd.putstr("enter again")
            password = ""  #清除密码


