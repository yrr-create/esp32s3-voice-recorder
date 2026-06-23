# Wiring

具体 GPIO 等开发板到手后可根据引脚图调整。下面是第一版建议接线。

## INMP441 I2S 麦克风

| INMP441 引脚 | ESP32-S3 建议 GPIO | 说明 |
| --- | --- | --- |
| VCC | 3V3 | 使用 3.3V |
| GND | GND | 共地 |
| SCK/BCLK | GPIO5 | I2S bit clock |
| WS/LRCL | GPIO6 | I2S word select |
| SD | GPIO7 | I2S data in |
| L/R | GND | 选择左声道 |

## TF 卡模块，SPI 模式

| TF 模块引脚 | ESP32-S3 建议 GPIO | 说明 |
| --- | --- | --- |
| VCC | 3V3 | 优先使用 3.3V |
| GND | GND | 共地 |
| SCK/CLK | GPIO12 | SPI clock |
| MISO/DO | GPIO13 | SPI MISO |
| MOSI/DI | GPIO11 | SPI MOSI |
| CS | GPIO10 | SPI chip select |

## 后续按键和 LED

| 功能 | ESP32-S3 建议 GPIO | 说明 |
| --- | --- | --- |
| REC 按键 | 普通 GPIO | 使用上拉输入，避免使用启动敏感脚 |
| 录音 LED | 普通 GPIO | 串联限流电阻 |

## 注意

- 所有模块必须共地。
- 第一阶段先用 USB 供电。
- 模块丝印和本文档不一致时，以模块实际丝印为准。
- 如果开发板某些 GPIO 已被板载功能占用，需要换脚。

