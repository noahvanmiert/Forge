@echo off

pushd ..
Vendor\Binaries\premake\premake5.exe --file=Build.lua vs2022
popd

pause