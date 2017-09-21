#! /bin/bash

git clone git@github.com:wjszlachta/arduino-mock /tmp/arduino-mock
mkdir lib
mkdir include
cp -a  /tmp/arduino-mock/{CMakeLists.txt,build.sh,test,src,lib,include} .
./build.sh test
