# Development Log

## 2026-06-23

- 在 `G:\Personalportfolio\esp32s3-voice-recorder` 建立项目仓库。
- 明确第一阶段目标：ESP32-S3 启动、TF 卡文件读写、INMP441 采音、WAV 保存、电脑播放。
- 第一阶段暂不加入屏幕、电池、蓝牙、Wi-Fi、AI 转写和 USB 麦克风功能。

## 2026-06-25

- 硬件到手：ESP32-S3 开发板、TF 卡模块、8GB microSD 卡、INMP441 麦克风模块、OLED 屏、USB 读卡器。
- 通过 `python -m esptool --port COM13 chip-id` 确认开发板为 ESP32-S3。
- 当前可用端口：`COM13 - USB-Enhanced-SERIAL CH343`。
- 芯片信息：ESP32-S3，8MB PSRAM，MAC `e8:3d:c1:f1:99:24`。
- 安装并验证 `esptool`。
- 通过 EIM 安装 `ESP-IDF v5.5.4`。
- 新增 `firmware/hello_world` 最小验证工程。
- `idf.py set-target esp32s3` 成功。
- `idf.py build` 成功。

## 2026-06-26

- 选择 ESP-IDF 作为主线开发路线，不使用 Arduino IDE 作为主线。
- `firmware/hello_world` 烧录成功。
- 串口 monitor 成功看到：

```text
Project name: hello_world
ESP32-S3 voice recorder board boot OK
hello esp32-s3: 0
```

- 接入 TF 卡模块，当前 SPI 接线规划：

```text
VCC       -> 3V3
GND       -> GND
CS/DO3    -> GPIO10
CLK/SCLK  -> GPIO12
MISO/DO0  -> GPIO13
MOSI/CMD  -> GPIO11
DO1/DO2   -> 不接
```

- 新增 `firmware/sd_card_test` 工程。
- 修正 ESP-IDF v5.5.4 下 SD SPI 相关组件依赖：

```cmake
REQUIRES fatfs sdmmc esp_driver_sdspi
```

- `sd_card_test` 编译成功，确认目标为 `esp32s3`。
- `sd_card_test` 烧录成功，串口显示项目名为 `sd_card_test`。
- 当前 TF 卡初始化失败，错误为：

```text
sdmmc_card_init failed (0x107)
Failed to mount SD card :ESP_ERR_TIMEOUT
```

- 当前判断：程序、编译、烧录、串口链路均正常，问题集中在 TF 卡通信链路。
- 下一步排查顺序：

```text
1. 确认 TF 卡插到底
2. 按 RST/EN 复位
3. 逐根确认 CS/CLK/MISO/MOSI/VCC/GND
4. 如仍失败，把 host.max_freq_khz 从 4000 改为 1000
5. 再检查 TF 卡是否 FAT32 格式
```
