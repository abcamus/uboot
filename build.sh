#!/bin/sh

sec_path="./CodeSign4SecureBoot"
ROOT_DIR=$(pwd)

rm -rf u-boot.bin
make -j$CPU_JOB_NUM

if [ ! -f u-boot.bin ]
then
	echo "!!!not found u-boot.bin"
fi

#cat spl/u-boot-spl.bin pad00.bin > image.bin
#./mkbl2 image.bin bl2.bin 14336
#cp -rf bl2.bin $sec_path

cat spl/landrover-spl.bin env.bin u-boot.bin > image.bin
