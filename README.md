# ESP32-S3 Voice Recorder

基于 ESP32-S3 的离线录音存储学习项目。目标是使用 INMP441 数字麦克风采集音频，把录音保存为 WAV 文件到 TF 卡，最后可以通过电脑读取和播放录音文件。

## 当前阶段

第一阶段只做最小闭环：

1. ESP32-S3 可以编译、烧录和串口输出。
2. TF 卡可以通过 SPI 初始化、挂载 FAT 文件系统。
3. 程序可以创建、写入、读取 `/sdcard/hello.txt`。
4. 后续再接 INMP441，保存 PCM/WAV。

## 当前状态

- 开发路线：ESP-IDF。
- ESP-IDF 版本：v5.5.4。
- 当前串口：`COM13 - USB-Enhanced-SERIAL CH343`。
- `firmware/hello_world` 已经成功烧录并输出 `hello esp32-s3`。
- `firmware/sd_card_test` 已经成功编译和烧录。
- TF 卡当前初始化失败，串口错误为 `ESP_ERR_TIMEOUT`，下一步检查 TF 卡插入、接线和 SPI 频率。

## 暂不做

- 不做 App。
- 不做 Wi-Fi。
- 不做蓝牙。
- 不做 AI 转写。
- 不做屏幕。
- 不做电池。
- 不做 USB 麦克风模式。

## 文档

- [BOM](docs/BOM.md)
- [接线表](docs/WIRING.md)
- [调试计划](docs/BRINGUP.md)
- [识别与烧录](docs/FLASHING.md)
- [开发日志](docs/DEV_LOG.md)

## 作品集描述草稿

基于 ESP32-S3 平台预研基础录音存储设备固件，实现数字麦克风采集、WAV 音频封装、TF 卡文件存储和电脑端文件读取。项目用于学习嵌入式音频采集、文件系统、外设接线和基础产品闭环开发。
