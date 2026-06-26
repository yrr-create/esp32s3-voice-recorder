# Wiring

当前先接 TF 卡模块，不接 INMP441 和 OLED。所有模块必须共地。

## TF 卡模块，SPI 模式

| TF 卡模块引脚 | ESP32-S3 GPIO | 说明 |
| --- | --- | --- |
| `VCC` | `3V3` | 优先使用 3.3V |
| `GND` | `GND` | 共地 |
| `CS/DO3` | `GPIO10` | SPI chip select |
| `CLK` / `SCLK` | `GPIO12` | SPI clock |
| `MISO/DO0` | `GPIO13` | SPI MISO |
| `MOSI/CMD` | `GPIO11` | SPI MOSI |
| `DO1` | 不接 | SPI 模式暂时不用 |
| `DO2` | 不接 | SPI 模式暂时不用 |

注意：

- 断电后再插拔杜邦线。
- TF 卡插好后再上电或按 `RST/EN` 复位。
- 如果出现 `ESP_ERR_TIMEOUT`，优先检查 `MOSI/CMD` 和 `MISO/DO0` 是否接反。
- 杜邦线尽量短，先不要把线绕得太长。

## INMP441 I2S 麦克风，后续阶段

| INMP441 引脚 | ESP32-S3 建议 GPIO | 说明 |
| --- | --- | --- |
| `VCC` | `3V3` | 使用 3.3V |
| `GND` | `GND` | 共地 |
| `SCK/BCLK` | `GPIO5` | I2S bit clock |
| `WS/LRCL` | `GPIO6` | I2S word select |
| `SD` | `GPIO7` | I2S data in |
| `L/R` | `GND` | 选择左声道 |

## 按键和 LED，后续阶段

| 功能 | ESP32-S3 建议 GPIO | 说明 |
| --- | --- | --- |
| REC 按键 | 普通 GPIO | 使用上拉输入，避开启动敏感脚 |
| 录音 LED | 普通 GPIO | 串联限流电阻 |
