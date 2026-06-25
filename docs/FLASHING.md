# 识别与烧录

## 1. 先确认开发板被电脑识别

第一步只接 ESP32-S3 开发板，不接 TF 卡、麦克风、屏幕。

Windows 设备管理器里应该出现类似：

```text
Silicon Labs CP210x USB to UART Bridge (COMx)
```

当前这台电脑识别到的是：

```text
COM3 - Silicon Labs CP210x USB to UART Bridge
```

这说明开发板的 USB-UART 口已经被电脑识别。

## 2. 两个 USB-C 口怎么选

很多 ESP32-S3 开发板有两个 Type-C 口：

- `USB-UART` / `UART` / `COM`：优先用这个口烧录和看串口日志。
- `USB-OTG` / `USB`：后续做 USB MSC/U 盘功能时再用。

第一阶段先使用 USB-UART 口。

## 3. 下载模式

如果自动烧录失败，手动进入下载模式：

1. 按住 `BOOT`。
2. 点按一下 `RST` / `EN`。
3. 松开 `BOOT`。
4. 再执行烧录命令。

烧录完成后，按一下 `RST` / `EN` 运行程序。

## 4. 当前工具状态

这台电脑目前有：

```text
Git
Python
CMake
Ninja
GCC
```

还没有检测到：

```text
idf.py
esptool.py
```

所以下一步需要安装 ESP32-S3 的开发/烧录工具。初学阶段推荐两条路线：

## 5. 推荐路线

### 路线 A：Arduino IDE，最快点亮和烧录

适合先确认板子能烧录、串口能输出、GPIO 能控制。

优点：

- 上手最快。
- 图形界面选择开发板和串口。
- 适合第一天验证硬件。

缺点：

- 后面做录音、TF 卡、WAV 文件结构时，工程管理不如 ESP-IDF 正规。

### 路线 B：ESP-IDF，后续正式项目路线

适合正式做 ESP32-S3 录音器固件。

优点：

- 官方 SDK。
- 适合 I2S、FATFS、SD 卡、USB MSC 等功能。
- 更适合写成作品集项目。

缺点：

- 安装和环境配置比 Arduino IDE 稍复杂。

本项目最终建议使用 ESP-IDF，但第一天可以先用 Arduino IDE 验证开发板。

