### Project 2: Table Lamp

**Description**

The common table lamp uses LED lights and buttons, which can control the
light on and off pressing the button.

**Button Principle**

The button module is a digital sensor, which can only read 0 or 1. When
the module is not pressed, it is in a high level state, that is, 1, when
pressed, it is a low level 0.

![image22](../media/41f565d4f355abb96e105119660e80ba.png)

**Pins of the Button**

| **Button 1** | **16** |
| --- | --- |
| **Button 2** | **27** |


#### Project 2.1 Read the Button

**Description**

We will work to read the status value of the button and display it on
the serial monitor, so as to see it intuitively.

**Test Code**

```python
from machine import Pin
import time

button1 = Pin(16, Pin.IN, Pin.PULL_UP)
button2 = Pin(27, Pin.IN, Pin.PULL_UP)

while True:
    btnVal1 = button1.value()  # Reads the value of button 1
    btnVal2 = button2.value()
    print("button1 =",btnVal1)  #Print it out in the shell
    print("button2 =",btnVal2)
    time.sleep(0.1) #delay 0.1s
```
**Test Result**

Click the run button, then you can see the status values of button1 and
button 2 printed in shell. Click the button of the smart home, and you
can see the change of the status values.

![image23](../media/1b984da67c0e89a72a9601c39362567d.png)


#### Project 2.2. Table Lamp

**Description**

For common simple table lamp, click the button it will be opened, click
it again, the lamp will be closed.

**Test Code**

Calculate the clicked button times and take the remainder of 2, you can
get 0 or 1 two state values.

```python
from machine import Pin
import time

button1 = Pin(16, Pin.IN, Pin.PULL_UP)
led = Pin(12, Pin.OUT)
count = 0

while True:
    btnVal1 = button1.value()  # Reads the value of button 1
    #print("button1 =",btnVal1)  #Print it out in the shell
    if(btnVal1 == 0):
        time.sleep(0.01)
        while(btnVal1 == 0):
            btnVal1 = button1.value()
            if(btnVal1 == 1):
                count = count + 1
                print(count)
    val = count % 2
    if(val == 1):
        led.value(1)
    else:
        led.value(0)
    time.sleep(0.1) #delay 0.1s
```
**Test Result**

The shell will print out the clicked button times, then click the button
once, the LED will be on, click it again, it will be off.

![image24](../media/1bc079eabd93cb2e8a8e15f0ab7f1367.png)

