
## 5.1 Package de compression de ressources

Ce pack de ressources contient le code, les bibliothèques, l'application et les fichiers du pilote. Vous devez disposer de cette ressource pour poursuivre votre apprentissage.

[package de compression de ressources](../Resource-compression-package.7z)


## 5.2 Premiers pas avec Arduino

---

### 5.2.1 Carte de développement ESP32 PLUS

![image1](../media/201911d851d2d7fa6e854d6428bb5b67.png)

L'ESP32PLUS est une carte de développement universelle WiFi et Bluetooth basée sur l'ESP32, intégrant le module ESP32-WOROOM-32 et compatible avec Arduino.

Elle dispose d'un capteur à effet Hall, d'interfaces SDIO/SPI haut débit, UART, I2S et I2C.

De plus, elle est équipée du système d'exploitation FreeRTOS, particulièrement adapté à l'Internet des objets et à la domotique.

![image2](../media/e00562548e84b885ad18510b261ade05.png)

---

### 5.2.2 Windows System

![image3](../media/6cf6312dc7c7db27794b54d58a8bf80c.png)


#### 1 Installing Arduino IDE

Lorsque vous obtenez la carte de contrôle, vous devez télécharger l'IDE Arduino et le pilote d'abord.

Vous pouvez télécharger l'IDE Arduino depuis le site officiel :
https://www.arduino.cc/, cliquez sur **LOGICIEL** dans la barre de navigation pour
entrez dans la page de téléchargement, comme indiqué ci-dessous :

![image4](../media/83a843a56d49e93ec9f99bfb33fee269.png)

⚠️ **Rappel spécial :** Si vous ne trouvez pas l'IDE Arduino dans la
section software du site officiel mentionné ci‑dessus, vous pouvez cliquer
sur ce lien：\ https://www.arduino.cc/en/software pour accéder
directement à la page de téléchargement de l'IDE Arduino.

Il existe différentes versions de l'IDE Arduino. Téléchargez simplement une version compatible avec votre système. Nous allons vous montrer comment télécharger et installer la version Windows de l'IDE Arduino.

![image5](../media/fac59eb6f401fa9e6ce711bb5f3f62f2.png)

Vous pouvez choisir entre le programme d'installation (.exe) et le fichier ZIP.
Nous vous conseillons d'utiliser le premier, qui installe directement tout le nécessaire pour utiliser le logiciel Arduino (IDE), y compris les pilotes. Avec le fichier ZIP, vous devrez installer les pilotes manuellement.
Le fichier ZIP est également utile si vous souhaitez créer une installation portable.

![image6](../media/0ab58d5303a100e9638be44131a34b51.png)

Il vous suffit de cliquer sur JUST DOWNLOAD.


#### 2 Installer un pilote

⚠️ **Rappel spécial : Si vous avez installé le pilote CH340, passez cette étape.**

Connectez la carte de contrôle principale à votre ordinateur à l'aide d'un câble USB.

Le pilote s'installera automatiquement sous macOS et Windows 10.

Si l'installation du pilote échoue, vous devrez l'installer manuellement.

(1) Vérifiez si l'ordinateur installe automatiquement le pilote :

Cliquez droit sur Ordinateur----- Cliquez sur Propriétés-----Cliquez sur Gestionnaire de périphériques, l'image suivante montre l'installation réussie :

![image7](../media/789a5b530a3e6c44687099a219575666.png)

(2) Installation manuelle :

Cliquez avec le bouton droit sur “\ **USB2.0-Serial**\ ” et cliquez sur “\ **Update drive...**\ ”

![image8](../media/378b65e69d5a926721245ecb4d2209a7.png)

Cliquez sur “\ **Browse my computer for driver software**\ ”

![image9](../media/dc27c46ecc96141df0ff60cf605875f3.png)

Cliquez sur “\ **Browse...**\ ” et sélectionnez le “\ **usb_ch341_3.1.2009.06 folder**\ ”.

![image10](../media/32e5e41e0c42893596d82c48e8914802.png)

Vérifiez à nouveau l'état de la connexion du port série, comme montré dans la figure suivante, le pilote est installé avec succès.

![image11](../media/789a5b530a3e6c44687099a219575666.png)


#### 3 Ajouter l'environnement ESP32 (ajouter la version 3.1.0)

（1）Ouvrez l'IDE Arduino, cliquez sur Fichier > Préférences, comme indiqué ci-dessous :

![image12](../media/cd670e08b43572b8b90f11a3d1edd61c.png)

（2）Copiez le lien：`https://espressif.github.io/arduino-esp32/package_esp32_index.json`
.

（3）Ouvrez le bouton indiqué ci-dessous :

![image13](../media/bb39b0b271fcdfb85e6a7ff284c290dd.png)

(4) Collez-le à l'intérieur et cliquez sur OK, comme indiqué ci-dessous

![image14](../media/58a1317f28e334e6fcdc833bf7161f29.png)

![Image](../media/img-20250603083908.png)

(5) Cliquez Tools > Board > Boards Manager

![image15](../media/dab13b40132ce5c687ca4726b75733f6.png)

(6) Dans le Gestionnaire de cartes qui s'affiche, sélectionnez l'ESP32, puis cliquez sur Installer. (Ajoutez la version 3.1.3 !) ! Très important

![image16](../media/aa.png)

(7) Cliquez Tools > Board >esp32, choisir ESP32 Dev Module.

![image17](../media/677ff80219f4525f8aea366eec9a03af.png)


#### 4 Arduino IDE Setting

Cliquez ![image18](../media/9035a01879f001b75827e908d7dceb2d.png) icône, ouvrir l'IDE Arduino.

![image19](../media/843b5bb2d4c1d33c215e8d0c76c07abf.png)

Pour éviter les erreurs lors du téléversement du programme sur la carte, vous devez sélectionner la carte Arduino compatible avec celle connectée à votre ordinateur.

Ensuite, retournez dans le logiciel Arduino, cliquez sur Outils → Carte, puis sélectionnez la carte. (Voir ci-dessous.)

![image20](../media/82243fba22e2575044b1c29decef18d9.png)

Sélectionnez ensuite le port COM approprié (vous pourrez voir le port COM correspondant une fois le pilote installé avec succès).

![image21](../media/d8fe59d73cdbce2afc74b37eb5f8e8c0.png)

Avant de téléverser le programme sur la carte, démontrons la
fonction de chaque symbole de la barre d'outils de l'IDE Arduino.

![image22](../media/3d76bbceb5014e1413c7c8d43ea52eb0.png)

1- Sert à vérifier s'il y a des erreurs de compilation.

2- Sert à téléverser le sketch sur votre carte ESP32.

3- Sert à envoyer les données série reçues depuis la carte vers le traceur série.

4- Sert à envoyer les données série reçues depuis la carte vers le moniteur série.

---

### 5.2.3 Mac System

![image23](../media/a6fc83596009c574d8e29ef383748549.png)


#### 1 Télécharger Arduino IDE

![image24](../media/77c03a9d0b23a0cc760d32095fa08e21.png)


#### 2 Télécharger CH340 driver

Nous fournissons, veuillez consulter le pack de ressources 5.1 pour obtenir

![image-20250408105719588](../media/image-20250408105719588.png)


#### 3 Comment installer le pilote CH340

Après le téléchargement, voir ci-dessous :

![image25](../media/63eee4c4643c4638a659346edbd2500f.png)

Double-cliquez sur le package d'installation et appuyez sur Continuer

![image26](../media/c51b1c3d15affa4d754770184d5151df.png)

Cliquez Install

![image27](../media/de96ded3dc9582e151dd7713d3ef33a1.png)

Saisissez votre mot de passe utilisateur et cliquez sur Installer le logiciel

![image28](../media/fafdebb694a110227b53ca6369ebc96a.png)

Continue Installation

![image29](../media/55c6bd90dc3ce4762e2598f76700e978.png)

Attendez l'installation

![image30](../media/535f31eba84df8664c4566e1b9ecd767.png)

Cliquez sur Redémarrer une fois l'installation terminée.

![image31](../media/7416a8a6aedcae63e931880a1f033db6.png)


#### 4 Arduino IDE Setting:

À l'exception des ports COM, la méthode de configuration est la même que dans le chapitre 1.4 :

![image32](../media/37972c9e070bd6bcf9cdcb3f84679223.jpeg)


## 5.3 Comment ajouter des bibliothèques ?

---

### 5.3.1 Que sont les bibliothèques ?

Les [bibliothèques](https://www.arduino.cc/en/Reference/Libraries) sont un ensemble de code facilitant le pilotage de capteurs, d'écrans, de modules, etc.

Par exemple, la bibliothèque intégrée LiquidCrystal permet de communiquer avec les écrans LCD.

Des centaines de bibliothèques supplémentaires sont disponibles en téléchargement sur Internet.

Les bibliothèques intégrées et certaines de ces bibliothèques supplémentaires sont répertoriées dans la documentation de référence.

https://www.arduino.cc/en/Reference/Libraries

---

### 5.3.2 Ajouter des bibliothèques ZIP

Pour ajouter une bibliothèque ZIP, vous devez la télécharger au format ZIP.

Placez-la ensuite dans le répertoire approprié. Les bibliothèques nécessaires au fonctionnement de la maison connectée se trouvent ici :

![image33](../media/dd.png)

Cliquez sur Sketch---->Inclure la bibliothèque—>Ajouter une bibliothèque .ZIP，puis naviguez jusqu'au fichier de bibliothèque que vous avez téléchargé et cliquez sur "open."

![image34](../media/baef5ce61ba8567f4a18fec16a2e3dae.png)

![image-20250329140352208](../media/image-20250329140352208.png)

Importez la bibliothèque. Vous la trouverez dans la liste des bibliothèques à inclure.

![image35](../media/fda284b603a4b6b5c14ce3d58788326d.png)
