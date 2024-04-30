// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum my_keycode {
    MY_CHANGE = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_1x1(MY_CHANGE)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MY_CHANGE:
            if (record->event.pressed) {
                pimoroni_trackball_set_cpi(2*128*125);
            } else {
                pimoroni_trackball_set_cpi(128*125);
            }
            break;
    }
    return true;
};

void pointing_device_init_user() {
    uint8_t addr = 0x14;
    uint8_t data[] = { 0x91, 0x00 };
    uint16_t timeout = 100;
    i2c_status_t status;
    status = i2c_transmit(addr, data, 2, timeout);
    if (status != 0) {
        return;
    }
};
