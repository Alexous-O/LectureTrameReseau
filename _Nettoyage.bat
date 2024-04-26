@echo off
del *.user
rmdir /q /s _build
rmdir /q /s doc\html
mkdir "./_build"
REM Pause
