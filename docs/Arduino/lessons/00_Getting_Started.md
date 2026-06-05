
## 5.1 リソース圧縮パッケージ

リソースパッケージには Code、Libraries、APP、Driver ファイルが含まれています。学習を続けるにはこのリソースが必要です。

[Resource compression package](../Resource-compression-package.7z)


## 5.2 Getting started with Arduino

---

### 5.2.1 ESP32 PLUS Development board

![1](../media/201911d851d2d7fa6e854d6428bb5b67.png)

ESP32PLUS は ESP32 をベースにした汎用の WiFi プラス Bluetooth 開発ボードで、ESP32-WOROOM-32 モジュールを統合しており Arduino と互換性があります。

ホールセンサ、高速 SDIO/SPI、UART、I2S および I2C を備えています。さらに、freeRTOS オペレーティングシステムを搭載しており、IoT やスマートホームに非常に適しています。

![2](../media/e00562548e84b885ad18510b261ade05.png)

---

### 5.2.2 Windows システム

![3](../media/6cf6312dc7c7db27794b54d58a8bf80c.png)


#### 1 Arduino IDE のインストール

コントロールボードを入手したら、まず Arduino IDE とドライバをダウンロードする必要があります。

公式サイトから Arduino IDE をダウンロードできます: https://www.arduino.cc/、ブラウザバーの **SOFTWARE** をクリックしてダウンロードページにアクセスしてください。以下のように表示されます:

![4](../media/83a843a56d49e93ec9f99bfb33fee269.png)

⚠️ **特別な注意:** 前述の公式サイトの SOFTWARE 内で Arduino IDE が見つからない場合は、次のリンクをクリックして直接 Arduino IDE のダウンロードページにアクセスできます：\ https://www.arduino.cc/en/software

Arduino には様々なバージョンの IDE があります。お使いのシステムに対応したバージョンをダウンロードしてください。ここでは Windows 版 Arduino IDE のダウンロードとインストール方法を示します。

![5](../media/fac59eb6f401fa9e6ce711bb5f3f62f2.png)

Installer (.exe) と Zip パッケージのどちらかを選べます。インストーラー（最初のもの）を使用することをおすすめします。これにより使用に必要なすべて（ドライバを含む）が直接インストールされます。Zip パッケージではドライバを手動でインストールする必要があります。Zip ファイルはポータブルインストールを作成したい場合にも便利です。

![6](../media/0ab58d5303a100e9638be44131a34b51.png)

JUST DOWNLOAD をクリックするだけです。


#### 2 ドライバをインストールする

⚠️ **特別な注意: CH340 ドライバを既にインストールしている場合は、この手順をスキップしてください。**

USB ケーブルでメインコントロールボードをコンピュータに接続すると、MacOS と Windows10 ではドライバが自動的にインストールされます。ドライバのインストールが失敗した場合は、手動でドライバをインストールする必要があります。

(1) コンピュータがドライバを自動インストールするか確認する：

Computer を右クリック----- プロパティをクリック----- デバイス マネージャーをクリック、以下のはインストール成功を示しています:

![7](../media/789a5b530a3e6c44687099a219575666.png)

(2) 手動インストール:

“USB2.0-Serial” を右クリックして “Update drive...” をクリックします

![8](../media/378b65e69d5a926721245ecb4d2209a7.png)

“Browse my computer for driver software” をクリックします

![9](../media/dc27c46ecc96141df0ff60cf605875f3.png)

“Browse...” をクリックして “usb_ch341_3.1.2009.06 folder” を選択します。

![10](../media/32e5e41e0c42893596d82c48e8914802.png)

シリアルポートの接続状況を再確認すると、以下の図のようにドライバが正常にインストールされています。

![11](../media/789a5b530a3e6c44687099a219575666.png)


#### 3 ESP32 環境の追加（バージョン 3.1.0 を追加）

（1）Arduino IDE を開き、File > Preferences をクリックします。以下のように表示されます:

![12](../media/cd670e08b43572b8b90f11a3d1edd61c.png)

（2）次のリンクをコピーします：
`https://espressif.github.io/arduino-esp32/package_esp32_index.json`。

（3）下記でマークされたボタンを開きます:

![13](../media/bb39b0b271fcdfb85e6a7ff284c290dd.png)

(4) それを内部に貼り付けて OK をクリックします。以下のように表示されます

![14](../media/58a1317f28e334e6fcdc833bf7161f29.png)

![](../media/img-20250603083908.png)

(5) Tools > Board > Boards Manager をクリックします

![15](../media/dab13b40132ce5c687ca4726b75733f6.png)

(6) ポップアップした Boards Manager で ESP32 を見つけてインストールをクリックします。（バージョン 3.1.3 を追加）!!!非常に重要

![16](../media/aa.png)

(7) Tools > Board > esp32 をクリックして ESP32 Dev Module を選択します。

![17](../media/677ff80219f4525f8aea366eec9a03af.png)


#### 4 Arduino IDE の設定

![18](../media/9035a01879f001b75827e908d7dceb2d.png) アイコンをクリックして、Arduino IDE を開きます。

![19](../media/843b5bb2d4c1d33c215e8d0c76c07abf.png)

プログラムをボードにアップロードするときのエラーを避けるために、コンピュータに接続されたボードと一致する正しい Arduino ボードを選択する必要があります。

Arduino ソフトに戻り、Tools→Board をクリックしてボードを選択してください。（下図参照）

![20](../media/82243fba22e2575044b1c29decef18d9.png)

次に正しい COM ポートを選択します（ドライバが正しくインストールされると対応する COM ポートが表示されます）

![21](../media/d8fe59d73cdbce2afc74b37eb5f8e8c0.png)

ボードにプログラムをアップロードする前に、Arduino IDE ツールバーの各アイコンの機能を説明します。

![22](../media/3d76bbceb5014e1413c7c8d43ea52eb0.png)

1- コンパイルエラーがないか検証するために使用します。

2- スケッチを ESP32 ボードにアップロードするために使用します。

3- ボードから受信したシリアルデータをシリアルプロッタに送るために使用します。

4- ボードから受信したシリアルデータをシリアルモニタに送るために使用します。

---

### 5.2.3 Mac システム

![23](../media/a6fc83596009c574d8e29ef383748549.png)


#### 1 Arduino IDE をダウンロード

![24](../media/77c03a9d0b23a0cc760d32095fa08e21.png)


#### 2 CH340 ドライバをダウンロード

提供しています。5.1 リソースパックを参照してください。

![-20250408105719588](../media/image-20250408105719588.png)


#### 3 CH340 ドライバのインストール方法

ダウンロード後は、以下のように表示されます:

![25](../media/63eee4c4643c4638a659346edbd2500f.png)

インストールパッケージをダブルクリックして Continue をタップします

![26](../media/c51b1c3d15affa4d754770184d5151df.png)

Install をクリックします

![27](../media/de96ded3dc9582e151dd7713d3ef33a1.png)

ユーザーパスワードを入力して Install Software をクリックします

![28](../media/fafdebb694a110227b53ca6369ebc96a.png)

Continue Installation をタップします

![29](../media/55c6bd90dc3ce4762e2598f76700e978.png)

インストールが完了するまで待ちます

![30](../media/535f31eba84df8664c4566e1b9ecd767.png)

インストール完了後に Restart をクリックします

![31](../media/7416a8a6aedcae63e931880a1f033db6.png)


#### 4 Arduino IDE の設定:

COM ポート以外の設定方法は 1.4 章と同じです:

![32](../media/37972c9e070bd6bcf9cdcb3f84679223.jpeg)


## 5.3 ライブラリの追加方法

---

### 5.3.1 ライブラリとは？

[Libraries](https://www.arduino.cc/en/Reference/Libraries) は、センサ、ディスプレイ、モジュールなどを簡単に制御するためのコードの集合です。

たとえば、組み込みの LiquidCrystal ライブラリは LCD ディスプレイとの通信を助けます。インターネット上にはダウンロード可能な追加のライブラリが数百あります。

組み込みライブラリとこれらの追加ライブラリの一部はリファレンスに一覧されています。

https://www.arduino.cc/en/Reference/Libraries

---

### 5.3.2 ZIP ライブラリの追加

ZIP ライブラリを追加する場合は、ZIP ファイルとしてダウンロードし、適切なディレクトリに置く必要があります。Smart Home を実行するために必要な Libraries は以下で見つけることができます：

![33](../media/dd.png)

Sketch---->Include Library—>Add.ZIP Library をクリックし、ダウンロードしたライブラリファイルへ移動して "open" をクリックします。

![34](../media/baef5ce61ba8567f4a18fec16a2e3dae.png)

![-20250329140352208](../media/image-20250329140352208.png)

ライブラリがインポートされます。Include Library リストで確認できます。

![35](../media/fda284b603a4b6b5c14ce3d58788326d.png)
