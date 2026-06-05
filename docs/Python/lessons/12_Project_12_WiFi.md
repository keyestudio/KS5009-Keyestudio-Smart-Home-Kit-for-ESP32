### Projekt 12: WiFi

Der einfachste Weg, auf das Internet zuzugreifen, ist die Verbindung über WiFi. Das ESP32 Hauptsteuerungsboard verfügt über ein WiFi-Modul, wodurch unser Smart Home einfach für das Internet zugänglich wird.

![Bild48](../media/img-20250620091803.png)


#### Projekt 12.1 WiFi-Station

**Beschreibung**

Wir verbinden das Smart Home mit einem LAN, also dem WiFi in Ihrem Zuhause oder dem Hotspot Ihres Telefons. Nach erfolgreicher Verbindung wird eine Adresse zugewiesen. Wir geben die zugewiesene Adresse in der Shell aus.

**Testcode**

Hinweis: ssiD und password im Code sollten mit Ihrem eigenen WiFi-Namen und Passwort ausgefüllt werden.

![Bild49](../media/278cbdc272b5cc1a6461a7934eabe5c0.png)

```python
import time
import network #Import network module

#Enter correct router name and password
ssidRouter     = 'LieBaoWiFi359' #Enter the router name
passwordRouter = 'wmbd315931' #Enter the router password

def STA_Setup(ssidRouter,passwordRouter):
    print("Setup start")
    sta_if = network.WLAN(network.STA_IF) #Set ESP32 in Station mode
    if not sta_if.isconnected():
        print('connecting to',ssidRouter)
#Activate ESP32’s Station mode, initiate a connection request to the router
#and enter the password to connect.
        sta_if.active(True)
        sta_if.connect(ssidRouter,passwordRouter)
#Wait for ESP32 to connect to router until they connect to each other successfully.
        while not sta_if.isconnected():
            pass
#Print the IP address assigned to ESP32 in “Shell”.
    print('Connected, IP address:', sta_if.ifconfig())
    print("Setup End")

try:
    STA_Setup(ssidRouter,passwordRouter)
except:
    sta_if.disconnect()
```
**Testergebnis**

Wenn das WiFi erfolgreich verbunden ist, gibt der serielle Monitor den verbundenen WiFi-Namen und die zugewiesene IP-Adresse aus.

![Bild50](../media/8c021cf89562d7ee27a6446f54be17bf.png)