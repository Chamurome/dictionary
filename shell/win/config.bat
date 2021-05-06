@echo off
cls
echo --------------------------------------------------------------------------------
@REM  averigua el directorio que aloja el script
set dir=%~d0%~p0
set bdir=%dir..\..\build
IF NOT EXIST %bdir% mkdir "%bdir%"
cd "%bdir"
cmake -G "Ninja" ..
cd "%dir%..\.."
echo --------------------------------------------------------------------------------
