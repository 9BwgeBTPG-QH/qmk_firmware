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
// 薙刀式
#include "naginata.h"
NGKEYS naginata_keys;
// 薙刀式
/*
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, \
    K300, K301, K302,     K304,       K306,       K308,   K309, K310, K311  \
*/

enum keymap_layers {
  0,// Base, QWERTY
  1,// 薙刀式入力レイヤー
  2,// Extra Keys
  3,// Num and FN
  4,// Mouse

};

enum custom_keycodes {
  0 = NG_SAFE_RANGE,
  1,
  2,
  3,
  4
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_all( /* Base */
    LT(3,KC_TAB),            KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,          KC_I,          KC_O,       KC_P,                 KC_BSPC,
    CTL_T(KC_ESC),          KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,           KC_K,         KC_L,      KC_SCLN,     LT(4,KC_ENT),
    KC_LSFT, XXXXXXX,    KC_Z,      KC_X,     KC_C,   KC_V,   KC_B,     KC_N,   KC_M,    KC_COMM,    KC_DOT,                   LT(4,KC_SLSH),
    KC_LGUI, XXXXXXX, LT(2,KC_LALT),   LT(2,KC_MHEN),       KC_SPC,            KC_HENK, LT(3,KC_DEL), XXXXXXX,               LT(4,JP_PIPE)
  ),

  [1] = LAYOUT_all( /* 薙刀式 */
    LT(3,KC_TAB),            NG_Q,    NG_W,    NG_E,    NG_R,    NG_T,    NG_Y,    NG_U,          NG_I,          NG_O,       NG_P,                 KC_BSPC,
    CTL_T(KC_ESC),          NG_A,     NG_S,    NG_D,    NG_F,    NG_G,    NG_H,    NG_J,           NG_K,         NG_L,      NG_SCLN,     LT(4,KC_ENT),
    KC_LSFT, XXXXXXX,    NG_Z,      NG_X,     NG_C,   NG_V,   NG_B,     NG_N,   NG_M,    NG_COMM,    NG_DOT,                   LT(4,KC_SLSH),
    KC_LGUI, XXXXXXX, LT(2,KC_LALT),   LT(2,KC_MHEN),       KC_SPC,            KC_HENK, LT(3,KC_DEL), XXXXXXX,                       LT(4,JP_PIPE)
  ),

  [2] = LAYOUT_all( /* Extra Keys */
    LT(2,KC_TAB),     JP_EXLM,    JP_DQUO,  JP_HASH,    JP_DLR,    JP_PERC,    JP_AMPR,    JP_QUOT,    JP_LPRN,    JP_RPRN,    JP_EQL,   JP_ASTR,
    CTL_T(KC_ESC),        KC_1,        KC_2,        KC_3,           KC_4,        KC_5,         KC_6,           KC_7,           KC_8,         KC_9,         KC_0,    JP_COLN,
    KC_LSFT, XXXXXXX,   KC_F1,      KC_F2,      KC_F3,         KC_F4,       KC_F5,      KC_F6,         KC_F7,          KC_F8,        KC_F9,                     KC_F10,
    KC_LGUI, XXXXXXX, KC_LALT,   KC_TRNS,       JP_MINS,            JP_PLUS,       JP_PLUS, XXXXXXX, JP_AT
  ),
  [3] = LAYOUT_all( /* Num and FN */
    LT(2,KC_TAB),       KC_BTN1,   KC_UP,         KC_BTN2,   KC_PGUP,   KC_HOME,   LSFT(KC_HOME),   JP_TILD,    JP_LBRC,         JP_RBRC,             JP_LCBR,    JP_RCBR,
    CTL_T(KC_ESC),       KC_LEFT,   KC_DOWN,  KC_RGHT,   KC_PGDN,   KC_END,      LSFT(KC_END),      KC_F11,    KC_F12,           KC_F13,               KC_F14,      KC_F14,
    KC_LSFT,  XXXXXXX,   KC_F15,  KC_F16,        KC_F17,       KC_F18,       KC_F19,        SGUI(KC_S),        JP_CIRC,   LGUI(KC_LEFT), LGUI(KC_RGHT),   KC_AUDIO_MUTE,
    KC_LGUI, XXXXXXX, KC_LALT,   JP_TILD,       JP_UNDS,            JP_CIRC, KC_TRNS, XXXXXXX, RESET
  ),
  [4] = LAYOUT_all( /* Mouse */
    LT(2,KC_TAB),       KC_BTN1,   KC_MS_U,         KC_BTN2,   KC_PGUP,   KC_HOME,   LSFT(KC_HOME),   JP_TILD,    JP_LBRC,         JP_RBRC,             JP_LCBR,    JP_RCBR,
    CTL_T(KC_ESC),       KC_MS_L,   KC_MS_D,  KC_MS_R,   KC_PGDN,   KC_END,      LSFT(KC_END),      KC_F11,    KC_F12,           KC_F13,               TG(0),      KC_F14,
    KC_LSFT,  XXXXXXX,   KC_F15,  KC_F16,        KC_F17,       KC_F18,       KC_F19,        SGUI(KC_S),        JP_CIRC,   LGUI(KC_LEFT), LGUI(KC_RGHT),   KC_AUDIO_MUTE,
    KC_LGUI, XXXXXXX, KC_LALT,   JP_TILD,       JP_UNDS,            JP_CIRC, KC_TRNS, XXXXXXX, RESET
  )
};

void matrix_init_user(void) {
  // 薙刀式
  set_naginata(1);
  #ifdef NAGINATA_EDIT_MAC
  set_unicode_input_mode(UC_OSX);
  #endif
  #ifdef NAGINATA_EDIT_WIN
  set_unicode_input_mode(UC_WINC);
  #endif
  // 薙刀式

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    // 薙刀式
  bool a = true;
  if (naginata_state()) { // 薙刀式モードONなら
    naginata_mode(keycode, record); // modifierを押していたら薙刀式レイヤーはOFFにする
    a = process_naginata(keycode, record); // 薙刀式の処理をする
    // update_led();
  }
  if (a == false) return false; // 以降のevent chainを中断する
  // 薙刀式

    return true;
}

