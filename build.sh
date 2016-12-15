#!/bin/sh

###
# QMK Firmware - Installation script
###

#
# Edit this configurations if you need
#
QMK_FIRMWARE="https://github.com/jackhumbert/qmk_firmware"
OUTPUT_FOLDER="qmk_firmware"

KEYBOARD="planck"
KEYMAP_FOLDER="bruno"

echo "Cloning repo..."
git clone --depth 1 ${QMK_FIRMWARE} ${OUTPUT_FOLDER}

echo "Copying sources..."
mkdir -pv "${OUTPUT_FOLDER}/keyboards/${KEYBOARD}/keymaps/${KEYMAP_FOLDER}"
cp * "${OUTPUT_FOLDER}/keyboards/${KEYBOARD}/keymaps/${KEYMAP_FOLDER}"

cd "${OUTPUT_FOLDER}/keyboards/${KEYBOARD}/keymaps/${KEYMAP_FOLDER}"
echo "Finish!"