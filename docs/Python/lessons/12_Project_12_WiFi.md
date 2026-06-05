### Progetto 12: WiFi

Il modo più semplice per accedere a Internet è utilizzare una connessione WiFi. La scheda di controllo principale ESP32 è dotata di un modulo WiFi, rendendo la nostra casa intelligente facilmente accessibile a Internet.

![immagine48](../media/img-20250620091803.png)


#### Progetto 12.1 Stazione WiFi

**Descrizione**

Colleghiamo la casa intelligente a una LAN, che può essere il WiFi di casa tua o l'hotspot del tuo telefono. Dopo che la connessione è avvenuta con successo, verrà assegnato un indirizzo. Stamperemo l'indirizzo assegnato nella shell.

![immagine49](../media/278cbdc272b5cc1a6461a7934eabe5c0.png)

**Codice di test**

Nota: ssiD e password nel codice devono essere compilati con il nome e la password del tuo WiFi.

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
**Risultato del test**

Se il WiFi si connette correttamente, il monitor seriale stamperà il nome della rete WiFi connessa e l'indirizzo IP assegnato.

![immagine50](../media/8c021cf89562d7ee27a6446f54be17bf.png)