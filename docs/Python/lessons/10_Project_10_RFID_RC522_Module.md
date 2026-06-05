### Project 10: RFID RC522 Module

**Component Knowledge**

Radio frequency identification、カードリーダーは無線周波数モジュールと高レベルの磁場で構成されています。Tag transponderはバッテリを含まないセンシングデバイスです。小さな集積回路チップとデータ保存用の媒体、信号の受信・送信用アンテナのみを含みます。

タグ内のデータを読み取るには、まずタグをカードリーダーの読み取り範囲に入れます。リーダーは磁場を生成し、レンツの法則に従って電力を発生させることができ、RFIDタグは電力を供給してデバイスを動作させます。

![画像40](../media/982ac6a9da0e8f55465ca5a969ac0dfe.png)

**Control Pins**

Use IIC communication

| SDA | SDA |
| --- | --- |
| SCL | SCL |


#### Project 10.1 Open the Door

mfrc522_config.py、soft_iic.py、mfrc522_i2c.py があるフォルダーを開きます

“Thonny”を開き、“This computer”→“D:”→“2. Python Projects”→“pj10_rc522_RFID” をクリックします。 “mfrc522_config.py”を選択し、右クリックして“\ **Upload to /**\ ”を選択し、mfrc522_config.py が ESP32 にアップロードされるのを待ちます；次に “soft_iic.py” を選択し、右クリックして“\ **Upload to /**\ ”を選択し、soft_iic.py が ESP32 にアップロードされるのを待ちます；その後 “mfrc522_i2c.py” を選択し、右クリックして“\ **Upload to /**\ ”を選択し、mfrc522_i2c.py が ESP32 にアップロードされるのを待ちます。

![画像41](../media/img-20250603132607.png)

![画像42](../media/img-20250603132647.png)

![画像43](../media/img-20250603132729.png)

保存された名前は mfrc522_config.py、soft_iic.py、mfrc522_i2c.py です。

![画像44](../media/img-20250603132756.png)

**Test Code**

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
**Test Result**

付属のカードをRFIDの感知領域に近づけると、ドアが回転して開き、シェルに "open" と表示されます。ボタン1を押すとドアが回転して閉じます。しかし、別の青い誘導ブロックをスワイプすると、シェルには "Error" と表示されます。

![画像45](../media/03fd569d64704a7e9705c1891f4d4856.png)