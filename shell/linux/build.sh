#!/bin/sh
clear 
# averigua el directorio que aloja el script
SCRIPT=$(readlink -f $0);
dir=`dirname $SCRIPT`
cd $dir/../../build
cmake --build .

