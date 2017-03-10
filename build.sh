#!/bin/sh

sec_path="./CodeSign4SecureBoot"
ROOT_DIR=$(pwd)

rm -rf u-boot.bin
make -j$CPU_JOB_NUM

if [ ! -f u-boot.bin ]
then
	echo "!!!not found u-boot.bin"
fi

cp spl/landrover-spl.bin bl2.bin

####################################################
#cat spl/u-boot-spl.bin pad00.bin > image.bin

#./mkbl2 image.bin bl2.bin 14336
####################################################

cp -rf bl2.bin $sec_path
cp -rf u-boot.bin $sec_path
cd $sec_path

echo "fusing image.bin......"

################ for sd MMC boot ##################
cat E4412_N.bl1.SCP2G.bin bl2.bin env.bin u-boot.bin > image.bin
################# for eMMC boot ####################
#cat E4412_N.bl1.SCP2G.bin bl2.bin u-boot.bin > image.bin
####################################################
mv image.bin $ROOT_DIR
cd $ROOT_DIR

echo "done!!!"
