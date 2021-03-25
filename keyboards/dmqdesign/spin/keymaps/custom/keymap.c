/* Copyright 2019-2020 DMQ Design
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers
{
  _BL,
  _FL
};

uint8_t currentLayer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT(/* Base */
                KC_7, KC_8, KC_9, TG(_FL),
                KC_4, KC_5, KC_6, KC_AUDIO_MUTE,
                KC_1, KC_2, KC_3, RCTL(KC_M),
                KC_0, KC_DOT, LT(1,KC_ENT)
                ),

    [_FL] = LAYOUT(/* Base */
                KC_HOME, KC_UP, KC_PGUP, KC_TRNS,
                KC_LEFT, KC_LSFT, KC_RIGHT, KC_TRNS,
                KC_END, KC_DOWN, KC_PGDN, RGB_TOG,
                KC_BSPC, KC_DEL, KC_TRNS
                )
};
#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
        switch (get_highest_layer(layer_state)) {
            case _BL:
                if (clockwise) {
                    tap_code16(C(KC_Y));
                } else {
                    tap_code16(C(KC_Z));
                }
                break;
            case _FL:
                 if (clockwise) {
                    rgblight_increase_hue(); //Cycle through the RGB hue
                  } else {
                    rgblight_decrease_hue();
                  }
                break;
        }

  } else if (index == 1) { /* Second encoder */  
        switch (get_highest_layer(layer_state)) {
            case _BL:
                 if (clockwise) {
                   tap_code(KC_VOLU); //Example of using tap_code which lets you use keycodes outside of the keymap
                 } else {
                   tap_code(KC_VOLD);
                 }
                break;
            case _FL:
                 if (clockwise) {
                   rgblight_increase_sat();
                 } else {
                   rgblight_decrease_sat();
                 }
                break;
        }

  } else if (index == 2) { /* Third encoder */  
        switch (get_highest_layer(layer_state)) {
            case _BL:
        if (clockwise) {
            tap_code16(S(C(KC_TAB)));
            clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        } else {
            tap_code16(C(KC_TAB));
            clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
            }
                break;
            case _FL:
             if (clockwise) {
               rgblight_increase_val(); //Change brightness on the RGB LEDs
             } else {
               rgblight_decrease_val();
    }
                break;
        }
    }
}
#endif