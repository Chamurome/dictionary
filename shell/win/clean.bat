@echo off
cls
@REM  averigua el directorio que aloja el script
set dir=%~d0%~p0
cd "%dir%\..\..\build"
cmake --build . --target clean
cd "%dir%..\.."
