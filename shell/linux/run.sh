#!/bin/sh
clear 
# averigua el directorio que aloja el script
SCRIPT=$(readlink -f $0);
dir=`dirname $SCRIPT`
$dir/config.sh
$dir/build.sh
echo --------------------------------------------------------------------------------
$dir/../build/app
echo --------------------------------------------------------------------------------

