#!/bin/sh
# averigua el directorio que aloja el script
SCRIPT=$(readlink -f $0);
dir=`dirname $SCRIPT`
cd $dir/../..
rm -fr  ./build
mkdir build
echo configutarion removed

