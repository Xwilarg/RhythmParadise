#!/bin/sh
New-Item -ItemType Directory -Force -Path build                  
cd build
conan remote add SFML https://api.bintray.com/conan/bincrafters/public-conan
$ErrorActionPreference = "Stop"
conan install .. --build=missing
if (-Not (Test-Path "irrKlang"))
{
    if ([Environment]::Is64BitProcess)
    {
        $url = 'http://www.ambiera.at/downloads/irrKlang-64bit-1.6.0.zip'
    }
    else
    {
        $url = 'http://www.ambiera.at/downloads/irrKlang-32bit-1.6.0.zip'
    }
    Invoke-WebRequest $url -OutFile irrKlang.zip
    Add-Type -AssemblyName System.IO.Compression.FileSystem
    [System.IO.Compression.ZipFile]::ExtractToDirectory($PSScriptRoot + "\build\irrKlang.zip", $PSScriptRoot + "\build")
    rm irrKlang.zip
    mv irrKlang-* irrKlang
    cp irrKlang/lib/Winx64-visualStudio/irrKlang.lib .
    if ([Environment]::Is64BitProcess)
    {
        cp irrKlang/bin/winx64-visualStudio/irrKlang.dll ..
    }
    else
    {
        cp irrKlang/bin/winx32-visualStudio/irrKlang.dll ..
    }
}
cmake ..
cmake --build . --config RELEASE
cp bin/RythmHero.exe ..
cd ..