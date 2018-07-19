#!/bin/bash

export TOOLCHAINHEAD="/home/andz8891/hdd/perforce/andz8891_ESO7999_Integration_toolchains/qnx660_mmx2p"
export CMAKEHEAD="/home/andz8891/hdd/perforce/andz8891_ESO7999_Integration_toolchains/cmake-2.8.8"


export QNX_HOST=${TOOLCHAINHEAD}/host/linux/x86
export QNX_TARGET=${TOOLCHAINHEAD}/target/qnx6


export PATH=${CMAKEHEAD}/bin:${TOOLCHAINHEAD}/host/linux/x86/usr/bin:$PATH



which gcc

which cmake

rm -rf bin
rm -rf build

echo
echo "INFO - COMPILING"
echo
cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -H. -Bbuild -Wno-dev 

echo
echo "INFO - LINKING"
echo
cmake --build build -- -j3

#cmake .