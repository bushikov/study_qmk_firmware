// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "analog.h"  // これをincludeしないとanalogReadPin関数が使えない

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_1x2(KC_B, KC_C)
};

#ifdef JOYSTICK_ENABLE
// デッドゾーンの定義
#define X_THRESHOULD_MIN 459
#define X_THRESHOULD_MAX 564
#define Y_THRESHOULD_MIN 459
#define Y_THRESHOULD_MAX 564

int16_t x_pos = 0;
int16_t y_pos = 0;

bool w_pressed = false, a_pressed = false, s_pressed = false, d_pressed = false;

void matrix_scan_user(void) {
    x_pos = analogReadPin(JOYSTICK_X_PIN);  // Get joystick X position
    y_pos = analogReadPin(JOYSTICK_Y_PIN);  // Get joystick Y position

    if (x_pos <= X_THRESHOULD_MIN && !a_pressed) {
        register_code(KC_A);
        a_pressed = true;
    } else if (x_pos >= X_THRESHOULD_MAX && !d_pressed) {
        register_code(KC_D);
        d_pressed = true;
    } else if ((x_pos > X_THRESHOULD_MIN && x_pos < X_THRESHOULD_MAX) && (a_pressed || d_pressed)) {
        unregister_code(KC_A);
        unregister_code(KC_D);
        a_pressed = false;
        d_pressed = false;
    }

    if (y_pos < Y_THRESHOULD_MIN && !w_pressed) {
        register_code(KC_W);
        w_pressed = true;
    } else if (y_pos >= Y_THRESHOULD_MAX && !s_pressed){
        register_code(KC_S);
        s_pressed = true;
    } else if ((y_pos > Y_THRESHOULD_MIN && y_pos < Y_THRESHOULD_MAX) && (w_pressed || s_pressed)) {
        unregister_code(KC_W);
        unregister_code(KC_S);
        w_pressed = false;
        s_pressed = false;
    }
};
#endif
