#!/bin/sh
mkdir -p build                   
cd build
conan remote add SFML https://api.bintray.com/conan/bincrafters/public-conan
set -e
conan install .. --build=missing
if [ ! -d "irrKlang" ]; then
    if [ $(uname -m) = 'x86_64' ]; then
        url='http://www.ambiera.at/downloads/irrKlang-64bit-1.6.0.zip'
    else
        url='http://www.ambiera.at/downloads/irrKlang-32bit-1.6.0.zip'
    fi
    curl $url > irrKlang.zip
    unzip irrKlang.zip
    rm irrKlang.zip
    mv irrKlang-* irrKlang
    cp irrKlang/lib/Winx64-visualStudio/irrKlang.lib .
    if [ $OSTYPE = 'msys' ]; then
        if [ $(uname -m) = 'x86_64' ]; then
            cp irrKlang/bin/winx64-visualStudio/irrKlang.dll ..
        else
            cp irrKlang/bin/winx32-visualStudio/irrKlang.dll ..
        fi
    else
        if [ $(uname -m) = 'x86_64' ]; then
            cp irrKlang/bin/linux-gcc-64/libIrrKlang.so .
        else
            cp irrKlang/bin/linux-gcc-32/libIrrKlang.so .
        fi
    fi
fi
cmake ..
cmake --build . --config RELEASE
cp ../build/bin/RythmHero.exe ..