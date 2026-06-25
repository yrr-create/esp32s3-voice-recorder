# Development Log

## 2026-06-23

- 在 `G:\Personalportfolio\esp32s3-voice-recorder` 建立项目仓库。
- 明确第一阶段目标：ESP32-S3 启动、TF 卡文件读写、INMP441 采音、WAV 保存、电脑播放。
- 暂不加入屏幕、电池、蓝牙、Wi-Fi、AI 转写和 USB 麦克风功能。

## 2026-06-25

- 硬件到手：ESP32-S3 开发板、TF 卡模块、8GB microSD 卡、INMP441 麦克风模块、OLED 屏、USB 读卡器。
- 当前电脑识别到 ESP32-S3 为 `COM6 - USB 串行设备`。
- 当前电脑还未安装 Arduino IDE，也未检测到 `idf.py` / `esptool.py`，下一步需要安装 ESP32-S3 烧录工具。
- 尝试通过 Scoop 安装 `arduino-cli`、通过 pip 安装 `esptool`，但下载超时，暂未成功。
