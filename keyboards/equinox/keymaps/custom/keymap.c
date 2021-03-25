/* Copyright 2019 Ryota Goto
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
#include"keymap_jp.h"
/*
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, \
    K300, K301, K302,     K304,       K306,       K308,   K309, K310, K311  \
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_all( /* Base */
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, 
    KC_LCTL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,                 , KC_ENT, 
    KC_LSFT, KC_LGUI, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  ,KC_SLSH, 
    KC_GESEC, KC_LGUI, KC_LALT,          LT(2,KC_MHEN),           KC_SPC,       KC_HENK      LT(3,KC_DEL),  KC_RGUI, KC_UNDS
  ),
  [1] = LAYOUT_all( /* Extra Keys */
KC_TAB,KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_DQUO,KC_BSPC,
KC_LCTL,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,
KC_LSFT,KC_LGUI,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,
    KC_GESEC, KC_LGUI, KC_LALT,          KC_TRNS,           KC_MINS,       KC_PLUS      KC_GRV,  KC_RGUI, KC_AMPR
  ),
  [2] = LAYOUT_all( /* Num and FN */
KC_TRNS,KC_BTN1,KC_UP,KC_BTN2,KC_PGUP,KC_HOME,                    LSFT(KC_HOME),JP_PIPE,JP_LPRN,JP_RPRN,KC_QUOT,TG(1),\
KC_LCTL,KC_LEFT,KC_DOWN,KC_RGHT,KC_PGDN,KC_END,       LSFT(KC_END),JP_UNDS,KC_F11,KC_F12,KC_F13,KC_F14,\
KC_LSFT,KC_TRNS,KC_F15,KC_F16,KC_F17,KC_F18,KC_F19,                                 ,SGUI(KC_S),JP_GRV,KC_LBRC,KC_RBRC,KC_TRNS,
    KC_GESEC, KC_LGUI, KC_LALT,          KC_SCLN,           KC_COLN,       KC_TRNS      KC_GRV,  KC_RGUI, RESET
  )
};

