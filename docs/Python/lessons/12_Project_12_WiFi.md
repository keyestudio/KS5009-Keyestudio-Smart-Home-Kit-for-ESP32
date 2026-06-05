### Projet 12 : WiFi

La façon la plus simple d'accéder à Internet est d'utiliser une connexion WiFi. La carte principale ESP32 est équipée d'un module WiFi, ce qui rend notre maison intelligente facilement accessible depuis Internet.

![image48](../media/img-20250620091803.png)


#### Projet 12.1 : Station WiFi

**Description**

Nous connectons la maison intelligente à un réseau local (LAN), c'est-à-dire au WiFi de votre domicile ou au hotspot de votre téléphone. Après une connexion réussie, une adresse sera attribuée. Nous afficherons l'adresse attribuée dans la console.

**Code de test**

Remarque : ssiD et password dans le code doivent être remplis avec le nom et le mot de passe de votre propre WiFi.

![image49](../media/278cbdc272b5cc1a6461a7934eabe5c0.png)

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
**Résultat du test**

Si le WiFi est connecté avec succès, le moniteur série affichera le nom du WiFi connecté et l'adresse IP attribuée.

![image50](../media/8c021cf89562d7ee27a6446f54be17bf.png)