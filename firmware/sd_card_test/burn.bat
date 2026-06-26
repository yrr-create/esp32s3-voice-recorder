@echo off

C:\devtools\esp\eim-cli-windows-x64.exe run "idf.py set-target esp32s3" esp-idf-v5.5.4 --esp-idf-json-path C:\Espressif\tools --do-not-track true || exit /b 1

C:\devtools\esp\eim-cli-windows-x64.exe run "idf.py build" esp-idf-v5.5.4 --esp-idf-json-path C:\Espressif\tools --do-not-track true || exit /b 1
