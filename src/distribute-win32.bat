@echo off
REM  Script that creates a distributable binary .zip archive.
REM  Must be run after install-win32.bat.
REM  Must be run from the parent of the 'src' directory.
REM  Requires Cygwin's zip command to be in the path.

@echo on
cd Release

set d=burgerspace-win32-1.9.0
mkdir %d%
copy ..\COPYING %d%
copy ..\README %d%
copy *.exe %d%
copy *.dll %d%
copy *.wav %d%

del ..\%d%.zip
zip ../%d%.zip %d%/*.*

cd ..
@echo off

echo ======================================================
if exist %d%.zip (
        echo %d%.zip is ready for distribution.
) else (
        echo FAILURE: %d%.zip not found
)
