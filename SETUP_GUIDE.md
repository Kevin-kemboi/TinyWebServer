# TinyWebServer - Setup Instructions

## Current Situation
Your system doesn't have a C compiler installed. Here are several ways to proceed:

## Option 1: Install MinGW-w64 (Recommended)
1. Go to: https://sourceforge.net/projects/mingw-w64/files/
2. Download the latest installer
3. Install to C:\mingw64
4. Add C:\mingw64\bin to your System PATH
5. Restart your terminal
6. Run: gcc --version to verify

## Option 2: Install Visual Studio Build Tools
1. Go to: https://visualstudio.microsoft.com/downloads/
2. Download "Build Tools for Visual Studio"
3. Install with "C++ build tools" workload
4. Open "Developer Command Prompt for VS"
5. Navigate to your project folder
6. Compile with: cl server.c /Fe:server.exe ws2_32.lib

## Option 3: Use Online Compiler (Quick Demo)
1. Go to https://www.onlinegdb.com/online_c_compiler
2. Copy the code from `server_online.c`
3. Click "Run" to see a simulation

## Option 4: Use GitHub Codespaces or Repl.it
1. Upload your code to GitHub
2. Create a Codespace (has gcc pre-installed)
3. Run: gcc server.c -o server && ./server

## Files in this project:
- `server.c` - Full web server (needs compilation)
- `server_online.c` - Simplified simulation for online compilers
- `index.html` - Web page served by the server
- `compile.bat` - Auto-compilation script (once compiler is installed)
- `makefile` - Build configuration

## Once you have a compiler:
1. Run `compile.bat` or
2. Run: gcc -o server.exe server.c -lws2_32
3. Run: server.exe
4. Open browser to: http://localhost:8080
