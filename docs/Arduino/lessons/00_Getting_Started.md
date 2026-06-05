
## 5.1 Paquete comprimido de recursos

El paquete de recursos contiene archivos de código, librerías, APP y controladores. Debes tener este recurso para continuar aprendiendo.

[Paquete comprimido de recursos](../Resource-compression-package.7z)


## 5.2 Comenzando con Arduino

---

### 5.2.1 Placa de desarrollo ESP32 PLUS

![imagen1](../media/201911d851d2d7fa6e854d6428bb5b67.png)

ESP32PLUS es una placa de desarrollo universal con WiFi y Bluetooth basada en ESP32, integrada con el módulo ESP32-WOROOM-32 y compatible con Arduino.

Tiene un sensor de efecto Hall, SDIO/SPI de alta velocidad, UART, I2S así como I2C. Además, está equipada con el sistema operativo freeRTOS, lo que la hace muy adecuada para el Internet de las cosas y hogar inteligente.

![imagen2](../media/e00562548e84b885ad18510b261ade05.png)

---

### 5.2.2 Sistema Windows

![imagen3](../media/6cf6312dc7c7db27794b54d58a8bf80c.png)


#### 1 Instalación del Arduino IDE

Cuando recibas la placa de control, necesitas descargar primero el Arduino IDE y el controlador.

Puedes descargar el Arduino IDE desde la página oficial: https://www.arduino.cc/, haz clic en **SOFTWARE** en la barra de navegación para entrar a la página de descargas, como se muestra a continuación:

![imagen4](../media/83a843a56d49e93ec9f99bfb33fee269.png)

⚠️ **Recordatorio especial:** Si no puedes encontrar el Arduino IDE en la sección SOFTWARE del sitio oficial mencionado, puedes hacer clic en este enlace：\ https://www.arduino.cc/en/software para acceder directamente a la página de descarga del Arduino IDE.

Hay varias versiones del IDE para Arduino. Simplemente descarga una versión compatible con tu sistema. Aquí te mostraremos cómo descargar e instalar la versión para Windows del Arduino IDE.

![imagen5](../media/fac59eb6f401fa9e6ce711bb5f3f62f2.png)

Puedes elegir entre el instalador (.exe) y los paquetes Zip. Te sugerimos usar el primero que instala directamente todo lo que necesitas para usar el Arduino Software (IDE), incluidos los controladores. Con el paquete Zip necesitas instalar los controladores manualmente. El archivo Zip también es útil si quieres crear una instalación portátil.

![imagen6](../media/0ab58d5303a100e9638be44131a34b51.png)

Solo necesitas hacer clic JUST DOWNLOAD.


#### 2 Instalar un controlador

⚠️ **Recordatorio especial: Si ya has instalado el controlador CH340, simplemente sáltalo.**

Conecta la placa de control principal a tu ordenador con un cable USB, y el controlador se instalará automáticamente en MacOS y Windows10. Si el proceso de instalación del controlador falla, necesitarás instalar el controlador manualmente.

(1) Comprueba si el ordenador instala el controlador automáticamente:

Haz clic derecho en Equipo → Propiedades → Administrador de dispositivos; la siguiente imagen muestra la instalación exitosa:

![imagen7](../media/789a5b530a3e6c44687099a219575666.png)

(2) Instalación manual:

Haz clic derecho en “\ **USB2.0-Serial**\ ” y haz clic en “\ **Update drive...**\ ”

![imagen8](../media/378b65e69d5a926721245ecb4d2209a7.png)

Haz clic en “\ **Browse my computer for driver software**\ ”

![imagen9](../media/dc27c46ecc96141df0ff60cf605875f3.png)

Haz clic en “\ **Browse...**\ ” y selecciona la “\ **usb_ch341_3.1.2009.06 folder**\ ”.

![imagen10](../media/32e5e41e0c42893596d82c48e8914802.png)

Vuelve a comprobar el estado de la conexión del puerto serie; como se muestra en la figura siguiente, el controlador se ha instalado correctamente.

![imagen11](../media/789a5b530a3e6c44687099a219575666.png)


#### 3 Añadir el entorno ESP32 (agregar versión 3.1.0)

（1）Abre el Arduino IDE, haz clic en File > Preferences, como se muestra a continuación:

![imagen12](../media/cd670e08b43572b8b90f11a3d1edd61c.png)

（2）Copia el enlace：\ `https://espressif.github.io/arduino-esp32/package_esp32_index.json` .

（3）Abre el botón marcado a continuación:

![imagen13](../media/bb39b0b271fcdfb85e6a7ff284c290dd.png)

(4) Pégalo dentro y haz clic en OK, como se muestra a continuación

![imagen14](../media/58a1317f28e334e6fcdc833bf7161f29.png)

![Imagen](../media/img-20250603083908.png)

(5) Haz clic en Tools > Board > Boards Manager

![imagen15](../media/dab13b40132ce5c687ca4726b75733f6.png)

(6) Busca ESP32 en el pop-up Boards Manager y luego haz clic en install. (añadir versión 3.1.3)!!! Muy importante

![imagen16](../media/aa.png)

(7) Haz clic en Tools > Board > esp32 para elegir el ESP32 Dev Module.

![imagen17](../media/677ff80219f4525f8aea366eec9a03af.png)


#### 4 Configuración del Arduino IDE

Haz clic en el icono ![imagen18](../media/9035a01879f001b75827e908d7dceb2d.png) para abrir el Arduino IDE.

![imagen19](../media/843b5bb2d4c1d33c215e8d0c76c07abf.png)

Para evitar errores al subir el programa a la placa, necesitas seleccionar la placa Arduino correcta que coincida con la placa conectada a tu ordenador.

Luego regresa al software Arduino, debes hacer clic en Tools→Board y seleccionar la placa. (como se muestra a continuación)

![imagen20](../media/82243fba22e2575044b1c29decef18d9.png)

Luego selecciona el puerto COM correcto (puedes ver el puerto COM correspondiente después de que el controlador se haya instalado con éxito)

![imagen21](../media/d8fe59d73cdbce2afc74b37eb5f8e8c0.png)

Antes de subir el programa a la placa, expliquemos la función de cada símbolo en la barra de herramientas del Arduino IDE.

![imagen22](../media/3d76bbceb5014e1413c7c8d43ea52eb0.png)

1- Se utiliza para verificar si hay errores de compilación.

2- Se utiliza para subir el sketch a tu placa ESP32.

3- Se utiliza para enviar los datos seriales recibidos de la placa al Serial Plotter.

4- Se utiliza para enviar los datos seriales recibidos de la placa al Serial Monitor.

---

### 5.2.3 Sistema Mac

![imagen23](../media/a6fc83596009c574d8e29ef383748549.png)


#### 1 Descargar el Arduino IDE

![imagen24](../media/77c03a9d0b23a0cc760d32095fa08e21.png)


#### 2 Descargar el controlador CH340

Lo proporcionamos, por favor ve al paquete de recursos 5.1 para obtenerlo

![imagen-20250408105719588](../media/image-20250408105719588.png)


#### 3 Cómo instalar el controlador CH340

Después de la descarga, verás lo siguiente:

![imagen25](../media/63eee4c4643c4638a659346edbd2500f.png)

Haz doble clic en el paquete de instalación y pulsa Continue

![imagen26](../media/c51b1c3d15affa4d754770184d5151df.png)

Haz clic en Install

![imagen27](../media/de96ded3dc9582e151dd7713d3ef33a1.png)

Introduce tu contraseña de usuario y haz clic en Install Software

![imagen28](../media/fafdebb694a110227b53ca6369ebc96a.png)

Pulsa Continue Installation

![imagen29](../media/55c6bd90dc3ce4762e2598f76700e978.png)

Espera a que se instale

![imagen30](../media/535f31eba84df8664c4566e1b9ecd767.png)

Haz clic en Restart una vez finalizada la instalación

![imagen31](../media/7416a8a6aedcae63e931880a1f033db6.png)


#### 4 Configuración del Arduino IDE:

Excepto por los puertos COM, el método de configuración es el mismo que en el capítulo 1.4:

![imagen32](../media/37972c9e070bd6bcf9cdcb3f84679223.jpeg)


## 5.3 ¿Cómo añadir librerías?

---

### 5.3.1 ¿Qué son las librerías ?

[Libraries](https://www.arduino.cc/en/Reference/Libraries) son una colección de código que facilita controlar un sensor, pantalla, módulo, etc.

Por ejemplo, la librería incorporada LiquidCrystal ayuda a comunicarse con pantallas LCD. Hay cientos de librerías adicionales disponibles en Internet para descargar.

Las librerías incorporadas y algunas de estas librerías adicionales están listadas en la referencia.

https://www.arduino.cc/en/Reference/Libraries

---

### 5.3.2 Añadir librerías ZIP

Cuando quieras añadir una librería zip, necesitas descargarla como archivo ZIP y colocarla en el directorio apropiado. Las librerías necesarias para ejecutar el Smart Home se pueden encontrar en：

![imagen33](../media/dd.png)

Haz clic en Sketch---->Include Library—>Add .ZIP Library, luego navega hasta el archivo de la librería que descargaste y haz clic en "open."

![imagen34](../media/baef5ce61ba8567f4a18fec16a2e3dae.png)

![imagen-20250329140352208](../media/image-20250329140352208.png)

Importa la librería. Puedes encontrarla en la lista de Include Library.

![imagen35](../media/fda284b603a4b6b5c14ce3d58788326d.png)
