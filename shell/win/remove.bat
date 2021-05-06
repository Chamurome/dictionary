@echo off
cls
@REM  averigua el directorio que aloja el script
set dir=%~d0%~p0
cd "%dir%..\.."
rd build /s /Q
mkdir build
