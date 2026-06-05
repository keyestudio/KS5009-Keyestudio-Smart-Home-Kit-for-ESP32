### Project 12: WiFi

De gemakkelijkste manier om toegang te krijgen tot het Internet is door verbinding te maken via WiFi. De ESP32 hoofdcontrollerkaart wordt geleverd met een WiFi-module, waardoor ons slimme huis eenvoudig toegankelijk wordt voor het Internet.

![afbeelding48](../media/img-20250620091803.png)


#### Project 12.1 WiFi-station

**Beschrijving**

We verbinden het slimme huis met een LAN, dat de WiFi in je huis of de hotspot van je telefoon is. Nadat de verbinding succesvol is, wordt er een adres toegewezen. We zullen het toegewezen adres in de shell afdrukken.

**Testcode**

Opmerking: ssiD en password in de code moeten worden ingevuld met uw eigen WiFi-naam en wachtwoord.

![afbeelding49](../media/278cbdc272b5cc1a6461a7934eabe5c0.png)

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
**Testresultaat**

Als de WiFi succesvol is verbonden, zal de seriële monitor de verbonden WiFi-naam en het toegewezen IP-adres afdrukken.

![afbeelding50](../media/8c021cf89562d7ee27a6446f54be17bf.png)