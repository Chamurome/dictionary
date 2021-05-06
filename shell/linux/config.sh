#!/bin/sh
clear 
# averigua el directorio que aloja el script
SCRIPT=$(readlink -f $0);
dir=`dirname $SCRIPT`
cd $dir/../../build
export CXX=g++
export CMAKE_GENERATOR=Ninja
cmake ..

