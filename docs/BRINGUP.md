# Bring-up Plan

## 阶段 1：ESP32-S3 基础确认

目标：

1. ESP32-S3 通过 USB-UART 口连接电脑。
2. 能识别串口。
3. 能编译、烧录最小程序。
4. 串口能看到启动日志和应用输出。

验证工程：

```text
firmware/hello_world
```

当前结果：已完成。串口能看到：

```text
ESP32-S3 voice recorder board boot OK
hello esp32-s3: 0
```

## 阶段 2：TF 卡文件读写

目标：

1. 初始化 SPI。
2. 挂载 FATFS。
3. 创建 `/sdcard/hello.txt`。
4. 写入 `ESP32-S3 SD card test OK`。
5. 重新读取文件内容。

验证工程：

```text
firmware/sd_card_test
```

成功标准：

```text
SD card mounted
Read from file: ESP32-S3 SD card test OK
SD card test finished
```

当前结果：程序已成功编译和烧录，但 TF 卡初始化失败：

```text
Failed to mount SD card :ESP_ERR_TIMEOUT
```

下一步：

1. 确认 TF 卡插到底。
2. 按 `RST/EN` 复位后再看串口。
3. 逐根确认 `CS/CLK/MISO/MOSI/VCC/GND`。
4. 如果仍失败，把 SPI 频率从 `4000 kHz` 降到 `1000 kHz` 再试。

## 阶段 3：INMP441 音频采集

目标：

1. 初始化 I2S。
2. 读取一小段 PCM 数据。
3. 串口打印音量幅度。
4. 说话时幅度明显变化。

成功标准：

```text
mic peak: small when quiet
mic peak: larger when speaking
```

## 阶段 4：保存 WAV

目标：

1. 创建 `REC0001.WAV`。
2. 写入 WAV header。
3. 持续写入 PCM 数据。
4. 停止录音时回填 WAV 文件长度。
5. 用电脑播放 WAV。

推荐格式：

```text
16000 Hz
16-bit
mono
PCM WAV
```

## 阶段 5：按键和 LED

目标：

1. 按 REC 开始录音。
2. 再按 REC 停止录音。
3. 录音时 LED 常亮或闪烁。
4. 错误状态用 LED 快闪提示。

## 阶段 6：基础可靠性

目标：

1. 自动文件编号。
2. 定时 `f_sync`。
3. 存储满时停止录音。
4. 麦克风无数据时提示错误。
5. 后续再做异常断电后的 WAV header 修复。
