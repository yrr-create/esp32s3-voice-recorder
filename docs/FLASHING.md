# 识别与烧录

## 1. 确认开发板端口

第一阶段只接 ESP32-S3 开发板，不接麦克风、屏幕等外设。

当前已验证端口：

```text
COM13 - USB-Enhanced-SERIAL CH343
```

芯片识别命令：

```powershell
python -m esptool --port COM13 chip-id
```

已验证结果：

```text
Connected to ESP32-S3 on COM13
Chip type: ESP32-S3
Embedded PSRAM 8MB
MAC: e8:3d:c1:f1:99:24
```

## 2. 两个 USB-C 口怎么选

很多 ESP32-S3 开发板有两个 Type-C 口：

- `USB-UART` / `UART` / `COM`：优先用于烧录和查看串口日志。
- `USB-OTG` / `USB`：后续做 USB MSC/U 盘功能时再用。

当前项目优先使用能识别出 `COM13` 的 USB-UART 口。

## 3. ESP-IDF 环境

本机已安装：

```text
ESP-IDF v5.5.4
IDF_PATH: C:\Espressif\esp-idf-v5.5.4\esp-idf
IDF_TOOLS_PATH: C:\Espressif\tools
```

使用 EIM 执行 IDF 命令：

```powershell
C:\devtools\esp\eim-cli-windows-x64.exe run "idf.py --version" esp-idf-v5.5.4 --esp-idf-json-path C:\Espressif\tools --do-not-track true
```

## 4. hello_world 编译、烧录和监视

```powershell
cd G:\Personalportfolio\esp32s3-voice-recorder\firmware\hello_world
C:\devtools\esp\eim-cli-windows-x64.exe run "idf.py set-target esp32s3" esp-idf-v5.5.4 --esp-idf-json-path C:\Espressif\tools --do-not-track true
C:\devtools\esp\eim-cli-windows-x64.exe run "idf.py build" esp-idf-v5.5.4 --esp-idf-json-path C:\Espressif\tools --do-not-track true
C:\devtools\esp\eim-cli-windows-x64.exe run "idf.py -p COM13 flash" esp-idf-v5.5.4 --esp-idf-json-path C:\Espressif\tools --do-not-track true
C:\devtools\esp\eim-cli-windows-x64.exe run "idf.py -p COM13 monitor" esp-idf-v5.5.4 --esp-idf-json-path C:\Espressif\tools --do-not-track true
```

退出 monitor：

```text
Ctrl + ]
```

## 5. sd_card_test 编译、烧录和监视

```powershell
cd G:\Personalportfolio\esp32s3-voice-recorder\firmware\sd_card_test
.\burn.bat
C:\devtools\esp\eim-cli-windows-x64.exe run "idf.py -p COM13 flash" esp-idf-v5.5.4 --esp-idf-json-path C:\Espressif\tools --do-not-track true
C:\devtools\esp\eim-cli-windows-x64.exe run "idf.py -p COM13 monitor" esp-idf-v5.5.4 --esp-idf-json-path C:\Espressif\tools --do-not-track true
```

## 6. 手动下载模式

如果自动烧录失败，可以手动进入下载模式：

1. 按住 `BOOT`。
2. 点按一次 `RST` / `EN`。
3. 松开 `BOOT`。
4. 再执行烧录命令。

烧录完成后，按一下 `RST` / `EN` 运行程序。
