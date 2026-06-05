
## 5.1 Resource compressiepakket

Het resourcepakket bevat Code, Libraries, APP en Driver-bestanden. Je
moet dit resourcepakket hebben om verder te kunnen leren.

[Resource compressiepakket](../Resource-compression-package.7z)


## 5.2 Aan de slag met Arduino

---

### 5.2.1 ESP32 PLUS Development board

![afbeelding1](../media/201911d851d2d7fa6e854d6428bb5b67.png)

ESP32PLUS is een universeel WiFi plus Bluetooth ontwikkelbord gebaseerd
op ESP32, geïntegreerd met het ESP32-WOROOM-32 module en compatibel met
Arduino.

Het heeft een hallsensor, high-speed SDIO/SPI, UART, I2S en ook I2C.
Verder is het uitgerust met het freeRTOS besturingssysteem, wat het zeer
geschikt maakt voor het Internet of Things en smart home toepassingen.

![afbeelding2](../media/e00562548e84b885ad18510b261ade05.png)

---

### 5.2.2 Windows-systeem

![afbeelding3](../media/6cf6312dc7c7db27794b54d58a8bf80c.png)


#### 1 Arduino IDE installeren

Wanneer je het control board ontvangt, moet je eerst de Arduino IDE en
de driver downloaden.

Je kunt de Arduino IDE downloaden van de officiële website:
https://www.arduino.cc/, klik op **SOFTWARE** in de browsebalk om de
downloadpagina te openen, zoals hieronder weergegeven:

![afbeelding4](../media/83a843a56d49e93ec9f99bfb33fee269.png)

⚠️ **Bijzondere herinnering:** Als je de Arduino IDE niet kunt vinden in
de software op de eerder genoemde officiële website, kun je op deze
link klikken：\ https://www.arduino.cc/en/software om direct naar de
Arduino IDE downloadpagina te gaan.

Er zijn verschillende versies van de IDE voor Arduino. Download gewoon
een versie die compatibel is met jouw systeem. Hier laten we zien hoe je
de Windows-versie van de Arduino IDE downloadt en installeert.

![afbeelding5](../media/fac59eb6f401fa9e6ce711bb5f3f62f2.png)

Je kunt kiezen tussen de Installer (.exe) en de Zip-pakketten. Wij raden
aan de eerste te gebruiken die direct alles installeert wat je nodig
hebt om de Arduino-software (IDE) te gebruiken, inclusief de drivers.
Met het Zip-pakket moet je de drivers handmatig installeren. Het Zip-bestand
is ook handig als je een draagbare installatie wilt maken.

![afbeelding6](../media/0ab58d5303a100e9638be44131a34b51.png)

Je hoeft alleen maar op JUST DOWNLOAD te klikken.


#### 2 Een driver installeren

⚠️ **Bijzondere herinnering: Als je de CH340-driver al hebt
geïnstalleerd, sla deze stap dan over.**

Verbind het main control board met je computer met een USB-kabel, en de
driver wordt automatisch geïnstalleerd op MacOS en Windows10 systemen. Als
het installatieproces van de driver faalt, moet je de driver handmatig
installeren.

(1) Controleer of de computer de driver automatisch installeert:

Klik met de rechtermuisknop op Computer----- Klik Eigenschappen-----Klik
Apparaatbeheer, de volgende afbeelding toont de succesvolle installatie:

![afbeelding7](../media/789a5b530a3e6c44687099a219575666.png)

(2) Handmatige installatie:

Klik met de rechtermuisknop op “\ **USB2.0-Serial**\ ” en klik “\ **Update
driver...**\ ”

![afbeelding8](../media/378b65e69d5a926721245ecb4d2209a7.png)

Klik “\ **Browse my computer for driver software**\ ”

![afbeelding9](../media/dc27c46ecc96141df0ff60cf605875f3.png)

Klik“\ **Browse...**\ ”en selecteer de“\ **usb_ch341_3.1.2009.06
folder**\ ”.

![afbeelding10](../media/32e5e41e0c42893596d82c48e8914802.png)

Controleer de seriële poortverbinding opnieuw, zoals weergegeven in de
volgende figuur; de driver is succesvol geïnstalleerd.

![afbeelding11](../media/789a5b530a3e6c44687099a219575666.png)


#### 3 Voeg de ESP32-omgeving toe (voeg versie 3.1.0 toe)

（1）Open de arduino IDE，click File > Preferences，zoals hieronder:

![afbeelding12](../media/cd670e08b43572b8b90f11a3d1edd61c.png)

（2）Kopieer de link：\ `https://espressif.github.io/arduino-esp32/package_esp32_index.json`
.

（3）Open de knop die hieronder is gemarkeerd:

![afbeelding13](../media/bb39b0b271fcdfb85e6a7ff284c290dd.png)

(4) Plak deze erin en klik OK, zoals hieronder

![afbeelding14](../media/58a1317f28e334e6fcdc833bf7161f29.png)

![Afbeelding](../media/img-20250603083908.png)

(5) Klik Tools > Board > Boards Manager

![afbeelding15](../media/dab13b40132ce5c687ca4726b75733f6.png)

(6) Zoek de ESP32 in de pop-up Boards Manager en klik vervolgens op
installeren. (voeg versie 3.1.3 toe)!!! Zeer belangrijk

![afbeelding16](../media/aa.png)

(7) Klik Tools > Board >esp32 om de ESP32 Dev Module te kiezen.

![afbeelding17](../media/677ff80219f4525f8aea366eec9a03af.png)


#### 4 Arduino IDE-instellingen

Klik ![afbeelding18](../media/9035a01879f001b75827e908d7dceb2d.png) icoon, open Arduino IDE.

![afbeelding19](../media/843b5bb2d4c1d33c215e8d0c76c07abf.png)

Om fouten te voorkomen bij het uploaden van het programma naar het bord,
moet je het juiste Arduino-bord selecteren dat overeenkomt met het bord
dat met je computer is verbonden.

Ga daarna terug naar de Arduino-software, je moet klikken op Tools→Board
en het bord selecteren. (zoals hieronder weergegeven)

![afbeelding20](../media/82243fba22e2575044b1c29decef18d9.png)

Selecteer vervolgens de juiste COM-poort (je kunt de bijbehorende COM-poort
zien nadat de driver succesvol is geïnstalleerd)

![afbeelding21](../media/d8fe59d73cdbce2afc74b37eb5f8e8c0.png)

Voordat je het programma naar het bord uploadt, laten we de functie van
elk symbool in de Arduino IDE werkbalk demonstreren.

![afbeelding22](../media/3d76bbceb5014e1413c7c8d43ea52eb0.png)

1- Wordt gebruikt om te verifiëren of er compilerfouten zijn.

2- Wordt gebruikt om de sketch naar je ESP32 bord te uploaden.

3- Wordt gebruikt om de seriële data die vanaf het bord ontvangen wordt
naar de serial plotter te sturen.

4- Wordt gebruikt om de seriële data die vanaf het bord ontvangen wordt
naar de serial monitor te sturen.

---

### 5.2.3 Mac-systeem

![afbeelding23](../media/a6fc83596009c574d8e29ef383748549.png)


#### 1 Arduino IDE downloaden

![afbeelding24](../media/77c03a9d0b23a0cc760d32095fa08e21.png)


#### 2 Download de CH340-driver

We leveren deze; ga naar het 5.1 resource-pakket om deze te halen

![afbeelding-20250408105719588](../media/image-20250408105719588.png)


#### 3 Hoe de CH340-driver te installeren

Na het downloaden zie je het volgende:

![afbeelding25](../media/63eee4c4643c4638a659346edbd2500f.png)

Dubbelklik op het installatiepakket en tik op Doorgaan

![afbeelding26](../media/c51b1c3d15affa4d754770184d5151df.png)

Klik op Install

![afbeelding27](../media/de96ded3dc9582e151dd7713d3ef33a1.png)

Voer je gebruikerswachtwoord in en klik op Install Software

![afbeelding28](../media/fafdebb694a110227b53ca6369ebc96a.png)

Tik op Continue Installation

![afbeelding29](../media/55c6bd90dc3ce4762e2598f76700e978.png)

Wacht tot de installatie is voltooid

![afbeelding30](../media/535f31eba84df8664c4566e1b9ecd767.png)

Klik op Restart nadat de installatie is voltooid

![afbeelding31](../media/7416a8a6aedcae63e931880a1f033db6.png)


#### 4 Arduino IDE-instellingen:

Behalve voor COM-poorten is de instelling hetzelfde als in hoofdstuk 1.4:

![afbeelding32](../media/37972c9e070bd6bcf9cdcb3f84679223.jpeg)


## 5.3 Hoe bibliotheken toe te voegen?

---

### 5.3.1 Wat zijn bibliotheken?

[Libraries](https://www.arduino.cc/en/Reference/Libraries) zijn een
verzameling code die het eenvoudig maakt om een sensor, display,
module, enz. aan te sturen.

Bijvoorbeeld, de ingebouwde LiquidCrystal library helpt bij het communiceren
met LCD-displays. Er zijn honderden extra bibliotheken beschikbaar op het
Internet om te downloaden.

De ingebouwde bibliotheken en enkele van deze extra bibliotheken worden
opgenomen in de reference.

https://www.arduino.cc/en/Reference/Libraries

---

### 5.3.2 ZIP-bibliotheken toevoegen

Wanneer je een zip-bibliotheek wilt toevoegen, moet je deze als een ZIP
bestand downloaden en in de juiste map plaatsen. De bibliotheken die
nodig zijn om de Smart Home te laten werken zijn te vinden op：

![afbeelding33](../media/dd.png)

Klik Sketch---->Include Library—>Add.ZIP Library，ga vervolgens naar het
bibliotheekbestand dat je hebt gedownload en klik "open."

![afbeelding34](../media/baef5ce61ba8567f4a18fec16a2e3dae.png)

![afbeelding-20250329140352208](../media/image-20250329140352208.png)

Importeer de bibliotheek. Je kunt deze vinden in de include library-lijst.

![afbeelding35](../media/fda284b603a4b6b5c14ce3d58788326d.png)
