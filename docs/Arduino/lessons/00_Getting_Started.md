
## 5.1 Resource compression package

Il pacchetto delle risorse contiene Code, Libraries, APP e file Driver. Devi avere questo pacchetto di risorse per continuare l'apprendimento.

[Resource compression package](../Resource-compression-package.7z)


## 5.2 Getting started with Arduino

---

### 5.2.1 ESP32 PLUS Development board

![immagine1](../media/201911d851d2d7fa6e854d6428bb5b67.png)

ESP32PLUS è una scheda di sviluppo universale WiFi plus Bluetooth basata su ESP32, integrata con il modulo ESP32-WOROOM-32 e compatibile con Arduino.

Ha un sensore hall, SDIO/SPI ad alta velocità, UART, I2S e anche I2C. Inoltre è dotata del sistema operativo freeRTOS, che è molto adatto per l'Internet delle cose e la smart home.

![immagine2](../media/e00562548e84b885ad18510b261ade05.png)

---

### 5.2.2 Windows System

![immagine3](../media/6cf6312dc7c7db27794b54d58a8bf80c.png)


#### 1 Installing Arduino IDE

Quando ricevi la scheda di controllo, devi prima scaricare Arduino IDE e il driver.

Puoi scaricare Arduino IDE dal sito ufficiale: https://www.arduino.cc/, clicca su **SOFTWARE** nella barra di navigazione per entrare nella pagina di download, come mostrato sotto:

![immagine4](../media/83a843a56d49e93ec9f99bfb33fee269.png)

⚠️ **Promemoria speciale:** Se non riesci a trovare Arduino IDE nella sezione software del sito ufficiale sopra menzionato, puoi cliccare su questo link：\ https://www.arduino.cc/en/software per accedere direttamente alla pagina di download di Arduino IDE.

Esistono varie versioni dell'IDE per Arduino. Scarica semplicemente una versione compatibile con il tuo sistema. Qui ti mostreremo come scaricare e installare la versione Windows di Arduino IDE.

![immagine5](../media/fac59eb6f401fa9e6ce711bb5f3f62f2.png)

Puoi scegliere tra l'Installer (.exe) e i pacchetti Zip. Ti suggeriamo di usare il primo che installa direttamente tutto il necessario per usare il Software Arduino (IDE), inclusi i driver. Con il pacchetto Zip dovrai installare i driver manualmente. Il file Zip è utile anche se vuoi creare un'installazione portatile.

![immagine6](../media/0ab58d5303a100e9638be44131a34b51.png)

Devi solo cliccare JUST DOWNLOAD.


#### 2 Install a driver

⚠️ **Promemoria speciale: Se hai già installato il driver CH340, salta questo passo.**

Collega la scheda di controllo al tuo computer con un cavo USB, e il driver verrà installato automaticamente su MacOS e Windows10. Se il processo di installazione del driver fallisce, devi installare il driver manualmente.

(1) Verifica se il computer installa automaticamente il driver:

Clic destro su Computer----- Clicca Proprietà-----Clicca Gestione dispositivi, l'immagine seguente mostra l'installazione avvenuta con successo:

![immagine7](../media/789a5b530a3e6c44687099a219575666.png)

(2) Installazione manuale:

Fai clic destro su “\ **USB2.0-Serial**\ ” e clicca “\ **Update drive...**\ ”

![immagine8](../media/378b65e69d5a926721245ecb4d2209a7.png)

Clicca “\ **Browse my computer for driver software**\ ”

![immagine9](../media/dc27c46ecc96141df0ff60cf605875f3.png)

Clicca“\ **Browse...**\ ”e seleziona la “\ **usb_ch341_3.1.2009.06 folder**\ ”.

![immagine10](../media/32e5e41e0c42893596d82c48e8914802.png)

Controlla di nuovo lo stato della connessione della porta seriale, come mostrato nella figura seguente, il driver è stato installato con successo.

![immagine11](../media/789a5b530a3e6c44687099a219575666.png)


#### 3 Add the ESP32 Environment(add version 3.1.0)

（1）Apri l'arduino IDE，clicca File > Preferences，come mostrato sotto:

![immagine12](../media/cd670e08b43572b8b90f11a3d1edd61c.png)

（2）Copia il link：\ `https://espressif.github.io/arduino-esp32/package_esp32_index.json`
.

（3）Apri il pulsante segnato qui sotto:

![immagine13](../media/bb39b0b271fcdfb85e6a7ff284c290dd.png)

(4) Incollalo all'interno e clicca OK, come mostrato sotto

![immagine14](../media/58a1317f28e334e6fcdc833bf7161f29.png)

![Immagine](../media/img-20250603083908.png)

(5) Clicca Tools > Board > Boards Manager

![immagine15](../media/dab13b40132ce5c687ca4726b75733f6.png)

(6) Trova ESP32 nel pop-up Boards Manager e poi clicca install. (add version 3.1.3)!!! Molto importante

![immagine16](../media/aa.png)

(7) Clicca Tools > Board >esp32 per scegliere ESP32 Dev Module.

![immagine17](../media/677ff80219f4525f8aea366eec9a03af.png)


#### 4 Arduino IDE Setting

Clicca ![immagine18](../media/9035a01879f001b75827e908d7dceb2d.png) icona，apri Arduino IDE.

![immagine19](../media/843b5bb2d4c1d33c215e8d0c76c07abf.png)

Per evitare errori durante il caricamento del programma sulla scheda, devi selezionare la scheda Arduino corretta che corrisponde alla scheda collegata al tuo computer.

Poi torna al software Arduino, dovresti cliccare Tools→Board, selezionare la scheda. (come mostrato sotto)

![immagine20](../media/82243fba22e2575044b1c29decef18d9.png)

Quindi seleziona la porta COM corretta (puoi vedere la corrispondente porta COM dopo che il driver è stato installato con successo)

![immagine21](../media/d8fe59d73cdbce2afc74b37eb5f8e8c0.png)

Prima di caricare il programma sulla scheda, presentiamo la funzione di ogni simbolo nella barra degli strumenti di Arduino IDE.

![immagine22](../media/3d76bbceb5014e1413c7c8d43ea52eb0.png)

1- Serve per verificare se ci sono errori di compilazione.

2- Serve per caricare lo sketch sulla tua scheda ESP32.

3- Serve per inviare i dati seriali ricevuti dalla scheda al serial plotter.

4- Serve per inviare i dati seriali ricevuti dalla scheda al serial monitor.

---

### 5.2.3 Mac System

![immagine23](../media/a6fc83596009c574d8e29ef383748549.png)


#### 1 Download Arduino IDE

![immagine24](../media/77c03a9d0b23a0cc760d32095fa08e21.png)


#### 2 Download the CH340 driver

Lo forniamo, per favore vai al pacchetto risorse 5.1 per ottenerlo

![immagine-20250408105719588](../media/image-20250408105719588.png)


#### 3 How to install the CH340 driver

Dopo il download, appare come sotto:

![immagine25](../media/63eee4c4643c4638a659346edbd2500f.png)

Doppio clic sul pacchetto di installazione e premi Continue

![immagine26](../media/c51b1c3d15affa4d754770184d5151df.png)

Clicca Install

![immagine27](../media/de96ded3dc9582e151dd7713d3ef33a1.png)

Inserisci la password dell'utente e clicca Install Software

![immagine28](../media/fafdebb694a110227b53ca6369ebc96a.png)

Premi Continue Installation

![immagine29](../media/55c6bd90dc3ce4762e2598f76700e978.png)

Attendi l'installazione

![immagine30](../media/535f31eba84df8664c4566e1b9ecd767.png)

Clicca Restart dopo che l'installazione è terminata

![immagine31](../media/7416a8a6aedcae63e931880a1f033db6.png)


#### 4 Arduino IDE Setting:

Ad eccezione delle porte COM, il metodo di impostazione è lo stesso del capitolo 1.4:

![immagine32](../media/37972c9e070bd6bcf9cdcb3f84679223.jpeg)


## 5.3 How to Add Libraries?

---

### 5.3.1 What are Libraries ?

[Libraries](https://www.arduino.cc/en/Reference/Libraries) sono una raccolta di codice che rende facile pilotare un sensore, display, modulo, ecc.

Per esempio, la libreria integrata LiquidCrystal aiuta a comunicare con i display LCD. Ci sono centinaia di librerie aggiuntive disponibili su Internet per il download.

Le librerie integrate e alcune di queste librerie aggiuntive sono elencate nella reference.

https://www.arduino.cc/en/Reference/Libraries

---

### 5.3.2 Add ZIP Libraries

Quando vuoi aggiungere una libreria zip, devi scaricarla come file ZIP e metterla nella directory appropriata. Le Libraries necessarie per eseguire lo Smart Home si possono trovare su：

![immagine33](../media/dd.png)

Clicca Sketch---->Include Library—>Add.ZIP Library，poi naviga fino al file della libreria che hai scaricato e clicca "open."

![immagine34](../media/baef5ce61ba8567f4a18fec16a2e3dae.png)

![immagine-20250329140352208](../media/image-20250329140352208.png)

Importa la libreria. Puoi trovarla nella lista include library.

![immagine35](../media/fda284b603a4b6b5c14ce3d58788326d.png)
