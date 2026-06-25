# 识别与烧录

## 1. 先确认开发板被电脑识别

第一步只接 ESP32-S3 开发板，不接 TF 卡、麦克风、屏幕。

Windows 设备管理器里应该出现类似：

```text
Silicon Labs CP210x USB to UART Bridge (COMx)
```

当前这台电脑识别到并验证可连接 ESP32-S3 的端口是：

```text
COM13 - USB-Enhanced-SERIAL CH343
```

这说明开发板已经被电脑识别。后续烧录和串口监视先使用 `COM13`。

已验证命令：

```powershell
python -m esptool --port COM13 chip-id
```

验证结果：

```text
Detecting chip type... ESP32-S3
Connected to ESP32-S3 on COM13
Embedded PSRAM 8MB
MAC: e8:3d:c1:f1:99:24
```

## 2. 两个 USB-C 口怎么选

很多 ESP32-S3 开发板有两个 Type-C 口：

- `USB-UART` / `UART` / `COM`：优先用这个口烧录和看串口日志。本开发板当前对应 `COM13`。
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
esptool
```

还没有检测到：

```text
Arduino IDE
idf.py
```

所以下一步需要安装 ESP32-S3 的编译开发环境。初学阶段推荐两条路线：

## 5. 推荐路线

本机已安装：

```text
ESP-IDF v5.5.4
安装路径：C:\Espressif\esp-idf-v5.5.4\esp-idf
工具路径：C:\Espressif\tools
```

使用 EIM 运行 IDF 命令：

```powershell
C:\devtools\esp\eim-cli-windows-x64.exe run "idf.py --version" esp-idf-v5.5.4 --esp-idf-json-path C:\Espressif\tools --do-not-track true
```

编译 hello_world：

```powershell
cd G:\Personalportfolio\esp32s3-voice-recorder\firmware\hello_world
C:\devtools\esp\eim-cli-windows-x64.exe run "idf.py set-target esp32s3" esp-idf-v5.5.4 --esp-idf-json-path C:\Espressif\tools --do-not-track true
C:\devtools\esp\eim-cli-windows-x64.exe run "idf.py build" esp-idf-v5.5.4 --esp-idf-json-path C:\Espressif\tools --do-not-track true
```

烧录 hello_world：

```powershell
cd G:\Personalportfolio\esp32s3-voice-recorder\firmware\hello_world
C:\devtools\esp\eim-cli-windows-x64.exe run "idf.py -p COM13 flash" esp-idf-v5.5.4 --esp-idf-json-path C:\Espressif\tools --do-not-track true
```

项目里的第一个验证工程：

```text
firmware/hello_world
```

当前 `hello_world` 已经编译成功。烧录时如果提示 `COM13` 不存在，先重新插开发板，确认设备管理器里再次出现 `USB-Enhanced-SERIAL CH343 (COM13)`。

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
