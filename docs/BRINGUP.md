# Bring-up Plan

## 阶段 1：ESP32-S3 基础确认

1. ESP32-S3 通过 USB 连接电脑。
2. 能下载最小程序。
3. 串口能看到启动日志。
4. 能点亮板载 LED 或外接 LED。

## 阶段 2：TF 卡文件读写

1. 初始化 SPI。
2. 挂载 FATFS。
3. 创建 `test.txt`。
4. 重新读取 `test.txt`。
5. 断电重启后确认文件还在。

成功标准：

```text
SD mounted
write test.txt OK
read test.txt OK
```

## 阶段 3：INMP441 音频采集

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

1. 创建 `REC0001.WAV`。
2. 写入 WAV header。
3. 持续写入 PCM 数据。
4. 停止时回填 WAV 文件长度。
5. 用电脑播放 WAV。

推荐格式：

```text
16000 Hz
16-bit
mono
PCM WAV
```

## 阶段 5：加入按键和 LED

1. 按 REC 开始录音。
2. 再按 REC 停止录音。
3. 录音时 LED 闪烁或常亮。
4. 错误状态用 LED 快闪提示。

## 阶段 6：基础可靠性

1. 自动文件编号。
2. 每隔几秒 `f_sync`。
3. 存储满时停止录音。
4. 麦克风无数据时提示错误。
5. 后续再做异常断电后的 WAV header 修复。

