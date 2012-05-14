#!/bin/bash
cp ./arch/arm/configs/android_galaxys2_defconfig ./android_galaxys2_defconfig
make mrproper
make android_galaxys2_defconfig
make -j4 zImage
cp ./arch/arm/boot/zImage ~/android/aosp/device/samsung/galaxys2/zImage
rm android_galaxys2_defconfig


