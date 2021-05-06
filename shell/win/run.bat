@echo off
cls
@REM  averigua el directorio que aloja el script
set dir=%~d0%~p0

call "%dir%build.bat"
cd "%dir%..\..\build"
.\app
echo --------------------------------------------------------------------------------
cd "%dir%..\.."


