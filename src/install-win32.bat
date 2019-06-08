@echo off
REM  Script that adds necessary files to directory where
REM  burgerspace.exe can be run.

copy src\sounds\*.wav Release
copy ..\SDL-1.2.14\lib\SDL.dll Release
copy ..\SDL_mixer-1.2.11\lib\SDL_mixer.lib Release
copy ..\SDL_image-1.2.10\lib\SDL_image.lib Release
