#!/bin/bash
cp ./arch/arm/configs/android_galaxys2_defconfig ./android_galaxys2_defconfig
make mrproper
make android_galaxys2_defconfig
make modules
cp drivers/samsung/fm_si4709/Si4709_driver.ko ~/android/device/samsung/galaxys2/modules/
cp drivers/scsi/scsi_wait_scan.ko ~/android/aosp/device/samsung/galaxys2/modules/
cp drivers/net/wireless/bcmdhd/dhd.ko ~/android/aosp/device/samsung/galaxys2/modules
make -j4 zImage
cp ./arch/arm/boot/zImage ~/android/aosp/device/samsung/galaxys2/zImage
rm android_galaxys2_defconfig


