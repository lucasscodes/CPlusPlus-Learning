@echo off

rem This will use VS2015 for compiler
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsx86_amd64.bat"

cl /nologo /W3 /O2 /fp:fast /Gm- /Fedemo.exe main.c user32.lib gdi32.lib Msimg32.lib /link /incremental:no
