#!/bin/bash
cp ./arch/arm/configs/android_i777_defconfig ./android_i777_defconfig
make mrproper
make android_i777_defconfig
make modules
cp drivers/samsung/fm_si4709/Si4709_driver.ko ~/android/device/samsung/i777/modules/
cp drivers/scsi/scsi_wait_scan.ko ~/android/aosp/device/samsung/i777/modules/
cp drivers/net/wireless/bcmdhd/dhd.ko ~/android/aosp/device/samsung/i777/modules
make -j4 zImage
cp ./arch/arm/boot/zImage ~/android/aosp/device/samsung/i777/zImage
rm android_i777_defconfig


