# Development Log

## 2026-06-23

- 在 `G:\Personalportfolio\esp32s3-voice-recorder` 建立项目仓库。
- 明确第一阶段目标：ESP32-S3 启动、TF 卡文件读写、INMP441 采音、WAV 保存、电脑播放。
- 暂不加入屏幕、电池、蓝牙、Wi-Fi、AI 转写和 USB 麦克风功能。

## 2026-06-25

- 硬件到手：ESP32-S3 开发板、TF 卡模块、8GB microSD 卡、INMP441 麦克风模块、OLED 屏、USB 读卡器。
- 已通过 `python -m esptool --port COM13 chip-id` 确认开发板为 ESP32-S3，端口为 `COM13 - USB-Enhanced-SERIAL CH343`。
- 芯片信息：ESP32-S3，8MB PSRAM，MAC `e8:3d:c1:f1:99:24`。
- 当前电脑已安装 `esptool`，还未安装 Arduino IDE，也未检测到 `idf.py`。
- 尝试通过 Scoop 安装 `arduino-cli` 超时，暂未成功。
- 已通过清华 PyPI 镜像安装 `esptool` 成功。
