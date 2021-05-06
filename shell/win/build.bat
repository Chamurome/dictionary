@echo off
@REM  averigua el directorio que aloja el script
set dir=%~d0%~p0
call %dir%config
cd "%dir%..\..\build"
cmake --build . 
cd "%dir%..\.."
echo --------------------------------------------------------------------------------
