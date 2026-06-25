# Firmware

这里后续放 ESP-IDF 工程。

当前已有一个最小验证工程：

```text
hello_world/
```

用途：

- 验证 ESP-IDF 环境可用。
- 验证 ESP32-S3 可以编译、烧录、串口输出。
- 后续确认硬件稳定后，再开始 TF 卡和 INMP441 驱动。

计划模块：

```text
main/
  app_main.c
  audio_i2s.c
  audio_i2s.h
  wav_writer.c
  wav_writer.h
  sd_storage.c
  sd_storage.h
  recorder.c
  recorder.h
```
