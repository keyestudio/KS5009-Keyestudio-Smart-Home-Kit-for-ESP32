### Proyecto 10: Módulo RFID RC522

**Conocimientos del componente**

Radio frequency identification, el lector de tarjetas está compuesto por un módulo de radiofrecuencia y un campo magnético de alto nivel. El transpondedor Tag es un dispositivo sensor, que no contiene una batería. Solo contiene pequeños chips de circuitos integrados y medios para almacenar datos y antenas para recibir y transmitir señales.

Para leer los datos en la etiqueta, primero colóquela dentro del alcance de lectura del lector de tarjetas. El lector generará un campo magnético, que puede producir electricidad según la ley de Lenz, entonces la etiqueta RFID suministrará energía, activando el dispositivo.

![imagen40](../media/982ac6a9da0e8f55465ca5a969ac0dfe.png)

**Pines de control**

Usar comunicación IIC

| SDA | SDA |
| --- | --- |
| SCL | SCL |


#### Proyecto 10.1 Abrir la puerta

Abra la carpeta donde se encuentran mfrc522_config.py , soft_iic.py y mfrc522_i2c.py

Abra "Thonny", haga clic en "This computer" → "D:" → "2. Python Projects" → "pj10_rc522_RFID". Seleccione "mfrc522_config.py", haga clic derecho y seleccione "\ **Subir a /**\ ", espere a que "mfrc522_config.py" se cargue en ESP32; y seleccione "soft_iic.py", haga clic derecho y seleccione "\ **Subir a /**\ ", espere a que "soft_iic.py" se cargue en ESP32; y luego seleccione "mfrc522_i2c.py", haga clic derecho y seleccione "\ **Subir a /**\ ", espere a que "mfrc522_i2c.py" se cargue en ESP32.

![imagen41](../media/img-20250603132607.png)

![imagen42](../media/img-20250603132647.png)

![imagen43](../media/img-20250603132729.png)

Los nombres guardados son mfrc522_config.py , soft_iic.py y mfrc522_i2c.py.

![imagen44](../media/img-20250603132756.png)

**Código de prueba**

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
**Resultado de la prueba**

Acerca la tarjeta proporcionada al área de inducción RFID, la puerta girará y se abrirá, y la consola muestra "open". Haga clic en el botón 1 y la puerta gira y se cierra. Sin embargo, al pasar otro bloque de inducción azul, la consola muestra "Error".

![imagen45](../media/03fd569d64704a7e9705c1891f4d4856.png)