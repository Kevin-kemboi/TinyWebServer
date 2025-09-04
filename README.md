"# TinyWebServer

A simple HTTP web server written in C that serves static HTML files.

## Features
- Serves HTML files on port 8080
- Cross-platform (Windows/Linux/macOS)
- Simple HTTP/1.1 implementation
- Basic error handling

## Requirements
You need a C compiler. Choose one of:

### Option 1: MinGW-w64 (Recommended for Windows)
1. Download from: https://www.mingw-w64.org/downloads/
2. Install to default location
3. Add to PATH: `C:\mingw64\bin`

### Option 2: Visual Studio Build Tools
1. Download from: https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2022
2. Install with "C++ build tools" workload

## How to Compile and Run

### Easy way (Windows):
1. Double-click `compile.bat`

### Manual way:
```bash
# With GCC:
gcc -Wall -Wextra -O2 -o server.exe server.c -lws2_32

# With Visual Studio:
cl server.c /Fe:server.exe ws2_32.lib

# Run the server:
./server.exe
```

## Usage
1. Compile and run the server
2. Open your web browser
3. Go to: http://localhost:8080
4. You should see "Hello, World!" page

## Files
- `server.c` - Main web server implementation
- `index.html` - HTML page served by the server
- `compile.bat` - Easy compilation script for Windows
- `makefile` - Build configuration for make/gcc" 
