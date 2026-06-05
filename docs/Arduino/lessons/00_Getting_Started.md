
## 5.1 Resource compression package

Das Ressourcenpaket enthält Code, Libraries, APP- und Treiberdateien. Sie
müssen dieses Ressourcenpaket haben, um weiter lernen zu können.

[Resource compression package](../Resource-compression-package.7z)


## 5.2 Getting started with Arduino

---

### 5.2.1 ESP32 PLUS Development board

![Bild1](../media/201911d851d2d7fa6e854d6428bb5b67.png)

ESP32PLUS ist ein universelles WiFi- plus Bluetooth-Entwicklungsboard basierend auf
ESP32, integriert mit dem ESP32-WOROOM-32 Modul und kompatibel mit
Arduino.

Es hat einen Hall-Sensor, High-Speed SDIO/SPI, UART, I2S sowie I2C.
Außerdem ist es mit dem freeRTOS Betriebssystem ausgestattet, was es
sehr geeignet für das Internet der Dinge und Smart Home macht.

![Bild2](../media/e00562548e84b885ad18510b261ade05.png)

---

### 5.2.2 Windows System

![Bild3](../media/6cf6312dc7c7db27794b54d58a8bf80c.png)


#### 1 Installing Arduino IDE

Wenn Sie das Kontrollboard erhalten, müssen Sie zuerst die Arduino IDE und den Treiber
herunterladen.

Sie können die Arduino IDE von der offiziellen Website herunterladen:
https://www.arduino.cc/, klicken Sie auf **SOFTWARE** in der Menüleiste, um
zur Download-Seite zu gelangen, wie unten gezeigt:

![Bild4](../media/83a843a56d49e93ec9f99bfb33fee269.png)

⚠️ **Besonderer Hinweis:** Wenn Sie die Arduino IDE nicht unter der
Software auf der oben genannten offiziellen Website finden können, können
Sie direkt auf diesen Link klicken：\ https://www.arduino.cc/en/software um
die Download-Seite der Arduino IDE direkt aufzurufen.

Es gibt verschiedene Versionen der Arduino IDE. Laden Sie einfach eine Version
herunter, die mit Ihrem System kompatibel ist. Hier zeigen wir Ihnen, wie
Sie die Windows-Version der Arduino IDE herunterladen und installieren.

![Bild5](../media/fac59eb6f401fa9e6ce711bb5f3f62f2.png)

Sie können zwischen dem Installer (.exe) und den Zip-Paketen wählen. Wir
empfehlen die erste Option, die alles Notwendige direkt installiert,
einschließlich der Treiber. Mit dem Zip-Paket müssen Sie die Treiber manuell installieren.
Die Zip-Datei ist auch nützlich, wenn Sie eine portable Installation erstellen möchten.

![Bild6](../media/0ab58d5303a100e9638be44131a34b51.png)

Klicken Sie einfach auf JUST DOWNLOAD.


#### 2 Install a driver

⚠️ **Besonderer Hinweis: Wenn Sie den CH340-Treiber bereits installiert haben, überspringen Sie diesen Schritt.**

Schließen Sie das Main-Control-Board mit einem USB-Kabel an Ihren Computer an, und
der Treiber wird auf MacOS und Windows10-Systemen automatisch installiert.
Wenn die Treiberinstallation fehlschlägt, müssen Sie den Treiber manuell installieren.

(1) Prüfen, ob der Computer den Treiber automatisch installiert:

Rechtsklick auf Computer----- Eigenschaften anklicken----- Geräte-Manager anklicken, das
folgende Bild zeigt die erfolgreiche Installation:

![Bild7](../media/789a5b530a3e6c44687099a219575666.png)

(2) Manuelle Installation:

Rechtsklicken Sie auf “\ **USB2.0-Serial**\ ” und klicken Sie auf “\ **Update driver...**\ ”

![Bild8](../media/378b65e69d5a926721245ecb4d2209a7.png)

Klicken Sie “\ **Browse my computer for driver software**\ ”

![Bild9](../media/dc27c46ecc96141df0ff60cf605875f3.png)

Klicken Sie “\ **Browse...**\ ” und wählen Sie den “\ **usb_ch341_3.1.2009.06 folder**\ ” aus.

![Bild10](../media/32e5e41e0c42893596d82c48e8914802.png)

Prüfen Sie den Status der seriellen Schnittstelle erneut, wie in der folgenden
Abbildung gezeigt; der Treiber ist erfolgreich installiert.

![Bild11](../media/789a5b530a3e6c44687099a219575666.png)


#### 3 Add the ESP32 Environment(add version 3.1.0)

（1）Öffnen Sie die arduino IDE，klicken Sie auf Datei > Voreinstellungen，wie unten gezeigt:

![Bild12](../media/cd670e08b43572b8b90f11a3d1edd61c.png)

（2）Kopieren Sie den Link：
`https://espressif.github.io/arduino-esp32/package_esp32_index.json`
.

（3）Öffnen Sie die Schaltfläche, die unten markiert ist:

![Bild13](../media/bb39b0b271fcdfb85e6a7ff284c290dd.png)

(4) Fügen Sie ihn dort ein und klicken Sie auf OK, wie unten gezeigt

![Bild14](../media/58a1317f28e334e6fcdc833bf7161f29.png)

![Bild](../media/img-20250603083908.png)

(5) Klicken Sie Tools > Board > Boards Manager

![Bild15](../media/dab13b40132ce5c687ca4726b75733f6.png)

(6) Finden Sie ESP32 im aufpoppenden Boards Manager und klicken Sie dann auf
installieren. (add version 3.1.3)!!! Sehr wichtig

![Bild16](../media/aa.png)

(7) Klicken Sie Tools > Board > esp32, um das ESP32 Dev Module auszuwählen.

![Bild17](../media/677ff80219f4525f8aea366eec9a03af.png)


#### 4 Arduino IDE Setting

Klicken Sie auf das ![Bild18](../media/9035a01879f001b75827e908d7dceb2d.png) Symbol，um die Arduino IDE zu öffnen.

![Bild19](../media/843b5bb2d4c1d33c215e8d0c76c07abf.png)

Um Fehler beim Hochladen des Programms auf das Board zu vermeiden, müssen Sie
das korrekte Arduino-Board auswählen, das mit dem an Ihren Computer
angeschlossenen Board übereinstimmt.

Kehren Sie dann zur Arduino-Software zurück, Sie sollten auf Tools→Board
klicken und das Board auswählen. (wie unten gezeigt)

![Bild20](../media/82243fba22e2575044b1c29decef18d9.png)

Wählen Sie dann den richtigen COM-Port aus (Sie können den entsprechenden COM-Port
sehen, nachdem der Treiber erfolgreich installiert wurde)

![Bild21](../media/d8fe59d73cdbce2afc74b37eb5f8e8c0.png)

Bevor Sie das Programm auf das Board hochladen, lassen Sie uns die Funktion
jedes Symbols in der Arduino IDE-Symbolleiste erklären.

![Bild22](../media/3d76bbceb5014e1413c7c8d43ea52eb0.png)

1- Wird verwendet, um zu überprüfen, ob es Kompilierfehler gibt oder nicht.

2- Wird verwendet, um den Sketch auf Ihr ESP32-Board hochzuladen.

3- Wird verwendet, um die vom Board empfangenen seriellen Daten an den seriellen Plotter zu senden.

4- Wird verwendet, um die vom Board empfangenen seriellen Daten an den seriellen Monitor zu senden.

---

### 5.2.3 Mac System

![Bild23](../media/a6fc83596009c574d8e29ef383748549.png)


#### 1 Download Arduino IDE

![Bild24](../media/77c03a9d0b23a0cc760d32095fa08e21.png)


#### 2 Download the CH340 driver

Wir stellen ihn zur Verfügung, bitte gehen Sie zum Ressourcenpaket in 5.1, um ihn zu erhalten

![Bild-20250408105719588](../media/image-20250408105719588.png)


#### 3 How to install the CH340 driver

Nach dem Download, sieht es wie folgt aus:

![Bild25](../media/63eee4c4643c4638a659346edbd2500f.png)

Doppelklicken Sie auf das Installationspaket und tippen Sie auf Weiter

![Bild26](../media/c51b1c3d15affa4d754770184d5151df.png)

Klicken Sie auf Installieren

![Bild27](../media/de96ded3dc9582e151dd7713d3ef33a1.png)

Geben Sie Ihr Benutzerpasswort ein und klicken Sie auf Software installieren

![Bild28](../media/fafdebb694a110227b53ca6369ebc96a.png)

Tippen Sie auf Installation fortsetzen

![Bild29](../media/55c6bd90dc3ce4762e2598f76700e978.png)

Warten Sie auf die Installation

![Bild30](../media/535f31eba84df8664c4566e1b9ecd767.png)

Klicken Sie nach Abschluss der Installation auf Neustart

![Bild31](../media/7416a8a6aedcae63e931880a1f033db6.png)


#### 4 Arduino IDE Setting:

Abgesehen von den COM-Ports ist die Vorgehensweise dieselbe wie in Kapitel 1.4:

![Bild32](../media/37972c9e070bd6bcf9cdcb3f84679223.jpeg)


## 5.3 How to Add Libraries?

---

### 5.3.1 What are Libraries ?

[Libraries](https://www.arduino.cc/en/Reference/Libraries) sind eine
Sammlung von Code, die es Ihnen erleichtert, einen Sensor, ein Display,
ein Modul usw. anzusteuern.

Zum Beispiel hilft die eingebaute LiquidCrystal-Library bei der
Kommunikation mit LCD-Displays. Es gibt Hunderte zusätzlicher Libraries im
Internet zum Herunterladen.

Die eingebauten Libraries und einige dieser zusätzlichen Libraries sind in
der Referenz aufgelistet.

https://www.arduino.cc/en/Reference/Libraries

---

### 5.3.2 Add ZIP Libraries

Wenn Sie eine ZIP-Library hinzufügen möchten, müssen Sie sie als ZIP-Datei
herunterladen und in das richtige Verzeichnis legen. Die Libraries, die
zum Ausführen des Smart Home benötigt werden, finden Sie unter：

![Bild33](../media/dd.png)

Klicken Sie Sketch---->Bibliothek einbinden—>ZIP-Bibliothek hinzufügen, dann navigieren Sie zur
heruntergeladenen Library-Datei und klicken auf "Öffnen".

![Bild34](../media/baef5ce61ba8567f4a18fec16a2e3dae.png)

![Bild-20250329140352208](../media/image-20250329140352208.png)

Importieren Sie die Library. Sie finden sie in der Liste der eingebundenen Libraries.

![Bild35](../media/fda284b603a4b6b5c14ce3d58788326d.png)
