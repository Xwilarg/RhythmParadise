#!/bin/sh
mkdir -p build                   
cd build
conan remote add SFML https://api.bintray.com/conan/bincrafters/public-conan
conan install .. --build=missing
if [ ! -d "irrKlang" ]; then
    if [ `uname -m` == 'x86_64' ]; then
        url='http://www.ambiera.at/downloads/irrKlang-64bit-1.6.0.zip'
    else
        url='http://www.ambiera.at/downloads/irrKlang-32bit-1.6.0.zip'
    fi
    curl $url > irrKlang.zip
    unzip irrKlang.zip -d irrKlang
    rm irrKlang.zip
fi
cmake ..
cmake --build . --config RELEASE
cp ../build/bin/RythmHero.exe ..