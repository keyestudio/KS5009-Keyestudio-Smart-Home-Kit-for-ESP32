### Project 7: Fan

**Description**

In this project, we will learn how to make a small fan.

**Component Knowledge**

The small fan uses a 130 DC motor and safe fan blades. You can use PWM
output to control the fan speed.

![image33](../media/33da52918e88862a94035d61a9050f2e.png)

**Control Method**

Two pins are required to control the motor of the fan, one for INA and
two for INB. The PWM value range is 0~255. When the PWM output of the
two pins is different, the fan can rotate.

| INA - INB <= -45 | Rotate clockwise |
| --- | --- |
| INA - INB >= 45 | Rotate anticlockwise |
| INA ==0, INB == 0 | Stop |

**Control Pins**

| INA | 19 |
| --- | --- |
| INB | 18 |


#### Project 7.1 Fan

We can control the anticlockwise and clockwise rotation speed of the
fan.

**Test Code**

```python
from machine import Pin,PWM
import time
#Two pins of the motor
INA =PWM(Pin(19,Pin.OUT),10000)#INA corresponds to IN+
INB =PWM(Pin(18,Pin.OUT),10000)#INB corresponds to IN-

try:
    while True:
        #Counterclockwise 2s
        INA.duty(0) #The range of duty cycle is 0-1023
        INB.duty(700)
        time.sleep(2)
        #stop 1s
        INA.duty(0)
        INB.duty(0)
        time.sleep(1)
        #Turn clockwise for 2s
        INA.duty(600)
        INB.duty(0)
        time.sleep(2)
        #stop 1s
        INA.duty(0)
        INB.duty(0)
        time.sleep(1)
except:
    INA.duty(0)
    INB.duty(0)
    INA.deinit()
    INB.deinit()
```
**Test Result**

The fan will rotate clockwise and anticlockwise at different speeds.


#### Project 7.2 Button Control Fan

Button one controls the fan switch.

**Test Code**

```python
from machine import Pin,PWM
import time
#Two pins of the motor
INA =PWM(Pin(19,Pin.OUT),10000)#INA corresponds to IN+
INB =PWM(Pin(18,Pin.OUT),10000)#INB corresponds to IN-
button1 = Pin(16, Pin.IN, Pin.PULL_UP)
count = 0

try:
    while True:
        btnVal1 = button1.value()  # Reads the value of button 1
        if(btnVal1 == 0):
            time.sleep(0.01)
            while(btnVal1 == 0):
                btnVal1 = button1.value()
                if(btnVal1 == 1):
                    count=count + 1
                    print(count)
        val = count % 2
        if(val == 1):
            INA.duty(0) #The range of duty cycle is 0-1023
            INB.duty(700)
        else:
            INA.duty(0)
            INB.duty(0)
except:
    INA.duty(0)
    INB.duty(0)
    INA.deinit()
    INB.deinit()
```
**Test Result**

Click button 1, the fan starts to rotate, the press the button 1 again,
the fan stops.

