# Firmware

这里存放 ESP-IDF 工程。

## 当前工程

```text
hello_world/
sd_card_test/
```

## hello_world

用途：

- 验证 ESP-IDF 环境可用。
- 验证 ESP32-S3 可以编译、烧录和串口输出。
- 当前已验证成功。

## sd_card_test

用途：

- 验证 TF 卡模块 SPI 通信。
- 验证 FATFS 挂载。
- 验证创建、写入和读取 `/sdcard/hello.txt`。

当前状态：

- 编译成功。
- 烧录成功。
- 串口启动正常。
- TF 卡初始化失败，错误为 `ESP_ERR_TIMEOUT`。

下一步优先排查接线、TF 卡插入状态和 SPI 频率。

## 后续正式录音固件计划

后续可以从 `sd_card_test` 和 I2S 麦克风测试逐步合并成正式录音工程：

```text
main/
  audio_i2s.c
  audio_i2s.h
  wav_writer.c
  wav_writer.h
  sd_storage.c
  sd_storage.h
  recorder.c
  recorder.h
```
