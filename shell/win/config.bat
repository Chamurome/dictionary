@echo off
cls
echo --------------------------------------------------------------------------------
@REM  averigua el directorio que aloja el script
set dir=%~d0%~p0
cd "%dir%..\..\build"
cmake -G "Ninja" ..
cd "%dir%..\.."
echo --------------------------------------------------------------------------------
