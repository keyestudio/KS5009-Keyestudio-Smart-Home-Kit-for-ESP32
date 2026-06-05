### Proyecto 12: WiFi

La forma más fácil de acceder a Internet es usar WiFi para conectarse. La placa de control principal ESP32 viene con un módulo WiFi, lo que hace que nuestra casa inteligente sea accesible a Internet fácilmente.

![imagen48](../media/img-20250620091803.png)


#### Proyecto 12.1 Estación WiFi

**Descripción**

Conectamos la casa inteligente a una LAN, que es el WiFi de tu hogar o el punto de acceso de tu teléfono. Después de que la conexión sea exitosa, se asignará una dirección. Imprimiremos la dirección asignada en la consola (shell).

**Código de prueba**

Nota: ssiD y password en el código deben rellenarse con el nombre y la contraseña de tu WiFi.

![imagen49](../media/278cbdc272b5cc1a6461a7934eabe5c0.png)

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
**Resultado de la prueba**

Si el WiFi se conecta correctamente, el monitor serie imprimirá el nombre del WiFi conectado y la dirección IP asignada.

![imagen50](../media/8c021cf89562d7ee27a6446f54be17bf.png)