
## 5.1 Resource compression package

The resource package contains Code, Libraries, APP and Driver files. You
must have this resourse to continue learing.

[Resource compression package](../Resource-compression-package.7z)


## 5.2 Getting started with Arduino

---

### 5.2.1 ESP32 PLUS Development board

![image1](../media/201911d851d2d7fa6e854d6428bb5b67.png)

ESP32PLUS is a universal WiFi plus Bluetooth development board based on
ESP32, integrated with ESP32-WOROOM-32 module and compatible with
Arduino.

It has a hall sensor, high-speed SDIO/SPI, UART, I2S as well as I2C.
Furthermore, equipped with freeRTOS operating system, which is quite
suitable for the Internet of things and smart home.

![image2](../media/e00562548e84b885ad18510b261ade05.png)

---

### 5.2.2 Windows System

![image3](../media/6cf6312dc7c7db27794b54d58a8bf80c.png)


#### 1 Installing Arduino IDE

When you get control board, you need to download Arduino IDE and driver
firstly.

You could download Arduino IDE from the official website:
https://www.arduino.cc/, click the **SOFTWARE** on the browse bar to
enter download page, as shown below:

![image4](../media/83a843a56d49e93ec9f99bfb33fee269.png)

⚠️ **Special reminder:** If you cannot find the Arduino IDE in the
software on the aforementioned official website, you can click on this
link：\ https://www.arduino.cc/en/software to directly access the
Arduino IDE download page.

There are various versions of IDE for Arduino. Just download a version
compatible with your system. Here we will show you how to download and
install the windows version of Arduino IDE.

![image5](../media/fac59eb6f401fa9e6ce711bb5f3f62f2.png)

You can choose between the Installer (.exe) and the Zip packages. We
suggest you use the first one that installs directly everything you need
to use the Arduino Software (IDE), including the drivers. With the Zip
package you need to install the drivers manually. The Zip file is also
useful if you want to create a portable installation.

![image6](../media/0ab58d5303a100e9638be44131a34b51.png)

You just need to click JUST DOWNLOAD.


#### 2 Install a driver

⚠️ **Special reminder: If you have installed the CH340 driver, just skip
it.**

Connect the main control board to your computer with a USB cable, and
the driver will be installed automatically on MacOS and Windows10
system. If the driver installation process fails, you need to install
the driver manually.

(1) Check whether the computer automatically installs the driver:

Right click Computer----- Click Properties-----Click Device Manager, the
following picture shows the successful installation:

![image7](../media/789a5b530a3e6c44687099a219575666.png)

(2) Manual installation:

Right-click “\ **USB2.0-Serial**\ ” and click “\ **Update drive...**\ ”

![image8](../media/378b65e69d5a926721245ecb4d2209a7.png)

Click “\ **Browse my computer for driver software**\ ”

![image9](../media/dc27c46ecc96141df0ff60cf605875f3.png)

Click“\ **Browse...**\ ”and select the“\ **usb_ch341_3.1.2009.06
folder**\ ”.

![image10](../media/32e5e41e0c42893596d82c48e8914802.png)

Check the serial port connection status again, as shown in the following
figure, the driver is successfully installed.

![image11](../media/789a5b530a3e6c44687099a219575666.png)


#### 3 Add the ESP32 Environment(add version 3.1.0)

（1）Open the arduino IDE，click File > Preferences，as shown below:

![image12](../media/cd670e08b43572b8b90f11a3d1edd61c.png)

（2）Copy the
link：\ `https://espressif.github.io/arduino-esp32/package_esp32_index.json`
.

（3）Open the button marked below:

![image13](../media/bb39b0b271fcdfb85e6a7ff284c290dd.png)

(4) Paste it inside and click OK, as shown below

![image14](../media/58a1317f28e334e6fcdc833bf7161f29.png)

![Img](../media/img-20250603083908.png)

(5) Click Tools > Board > Boards Manager

![image15](../media/dab13b40132ce5c687ca4726b75733f6.png)

(6) Find the ESP32 from the pop up Boards Manager and then click
install. (add version 3.1.3)!!!Very important

![image16](../media/aa.png)

(7) Click Tools > Board >esp32 to choose the ESP32 Dev Module.

![image17](../media/677ff80219f4525f8aea366eec9a03af.png)


#### 4 Arduino IDE Setting

Click ![image18](../media/9035a01879f001b75827e908d7dceb2d.png) icon，open Arduino IDE.

![image19](../media/843b5bb2d4c1d33c215e8d0c76c07abf.png)

To avoid the errors when uploading the program to the board, you need to
select the correct Arduino board that matches the board connected to
your computer.

Then come back to the Arduino software, you should click Tools→Board,
select the board. (as shown below)

![image20](../media/82243fba22e2575044b1c29decef18d9.png)

Then select the correct COM port (you can see the corresponding COM port
after the driver is successfully installed)

![image21](../media/d8fe59d73cdbce2afc74b37eb5f8e8c0.png)

Before uploading the program to the board, let’s demonstrate the
function of each symbol in the Arduino IDE toolbar.

![image22](../media/3d76bbceb5014e1413c7c8d43ea52eb0.png)

1- Used to verify whether there is any compiling mistakes or not.

2- Used to upload the sketch to your ESP32 board.

3- Used to send the serial data received from board to the serial
plottle.

4- Used to send the serial data received from board to the serial
monitor.

---

### 5.2.3 Mac System

![image23](../media/a6fc83596009c574d8e29ef383748549.png)


#### 1 Download Arduino IDE

![image24](../media/77c03a9d0b23a0cc760d32095fa08e21.png)


#### 2 Download the CH340 driver

We provide,please go to 5.1 resourse pack to get

![image-20250408105719588](../media/image-20250408105719588.png)


#### 3 How to install the CH340 driver

After the download, seen as below:

![image25](../media/63eee4c4643c4638a659346edbd2500f.png)

Double-click installation package and tap Continue

![image26](../media/c51b1c3d15affa4d754770184d5151df.png)

Click Install

![image27](../media/de96ded3dc9582e151dd7713d3ef33a1.png)

Input your user password and click Install Software

![image28](../media/fafdebb694a110227b53ca6369ebc96a.png)

Tap Continue Installation

![image29](../media/55c6bd90dc3ce4762e2598f76700e978.png)

Wait to install

![image30](../media/535f31eba84df8664c4566e1b9ecd767.png)

Click Restart after the installation is finished

![image31](../media/7416a8a6aedcae63e931880a1f033db6.png)


#### 4 Arduino IDE Setting:

Except for COM ports, the setting method is the same as in chapter 1.4:

![image32](../media/37972c9e070bd6bcf9cdcb3f84679223.jpeg)


## 5.3 How to Add Libraries?

---

### 5.3.1 What are Libraries ?

[Libraries](https://www.arduino.cc/en/Reference/Libraries) are a
collection of code that makes it easy for you to drive a sensor,display,
module, etc.

For example, the built-in LiquidCrystal library helps talk to LCD
displays. There are hundreds of additional libraries available on the
Internet for download.

The built-in libraries and some of these additional libraries are listed
in the reference.

https://www.arduino.cc/en/Reference/Libraries

---

### 5.3.2 Add ZIP Libraries

When you want to add a zip library, you need to download it as a ZIP
file, put in the proper directory. The Libraries needed to run the Smart
Home can be found on：

![image33](../media/dd.png)

Click Sketch---->Include Library—>Add.ZIP Library，then Then navigate to
the library file you downloaded and click "open."

![image34](../media/baef5ce61ba8567f4a18fec16a2e3dae.png)

![image-20250329140352208](../media/image-20250329140352208.png)

Import the library. You can find it in the include library list.

![image35](../media/fda284b603a4b6b5c14ce3d58788326d.png)
