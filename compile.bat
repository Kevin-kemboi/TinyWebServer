@echo off
echo Attempting to compile the web server...

REM Try GCC first
where gcc >nul 2>&1
if %errorlevel% == 0 (
    echo Using GCC compiler...
    gcc -Wall -Wextra -O2 -o server.exe server.c -lws2_32
    if %errorlevel% == 0 (
        echo Compilation successful!
        goto :run
    )
)

REM Try Visual Studio compiler
where cl >nul 2>&1
if %errorlevel% == 0 (
    echo Using Microsoft Visual C++ compiler...
    cl server.c /Fe:server.exe ws2_32.lib
    if %errorlevel% == 0 (
        echo Compilation successful!
        goto :run
    )
)

echo No suitable C compiler found!
echo Please install one of the following:
echo 1. MinGW-w64: https://www.mingw-w64.org/downloads/
echo 2. Visual Studio with C++ support: https://visualstudio.microsoft.com/
echo 3. Build Tools for Visual Studio: https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2022
pause
exit /b 1

:run
echo Starting the web server...
server.exe
