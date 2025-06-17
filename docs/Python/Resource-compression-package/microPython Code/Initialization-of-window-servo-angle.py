from machine import Pin, PWM
import time
pwm = PWM(Pin(5))  
pwm.freq(50)

'''
The duty cycle corresponding to the angle 
0°----2.5%----25
45°----5%----51.2
90°----7.5%----77
135°----10%----102.4
180°----12.5%----128
'''
angle_0 = 25
angle_90 = 77
angle_180 = 128

pwm.duty(angle_0)
time.sleep(1)
pwm.duty(angle_90)
time.sleep(1)
pwm.duty(angle_0)
time.sleep(1)

# while True:

    