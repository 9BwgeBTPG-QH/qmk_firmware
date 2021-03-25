#include QMK_KEYBOARD_H
#include"keymap_jp.h"
#include "default_incE.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {



  [L_EUCALYN] = LAYOUT_directional( \
KC_ESC,       KC_1,       KC_2,      KC_3,     KC_4,      KC_5,       KC_JYEN,       KC_6,      KC_7,           KC_8,          KC_9,         KC_0,         KC_CIRC,   KC_NO,   KC_BSPC,\
KC_TAB,      KC_Q,      KC_W,     KC_E,      KC_R,      KC_T,       JP_LBRC,       KC_Y,      KC_U,           KC_I,          KC_O,         KC_P,             JP_AT,                  KC_BSPC,\
KC_LCTL,      KC_A,      KC_S,      KC_D,      KC_F,      KC_G,     JP_RBRC,      KC_H,       KC_J,           KC_K,           KC_L,   KC_SCLN,                                          KC_ENT,\
KC_LSFT,      KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,         KC_RO,      KC_N,     KC_M, KC_COMM,     KC_DOT,    KC_SLSH,           KC_UP,                   KC_APP,\
MO(1),KC_LGUI,   KC_LALT,      LT(2,KC_MHEN),       KC_SPC,          KC_HENK,           LT(3,KC_DEL),   KC_DEL,KC_LEFT,     KC_DOWN,      KC_RGHT\
  ),

  [L_QWERTY] = LAYOUT_directional( \
KC_ESC,             KC_1,           KC_2,           KC_3,        KC_4,        KC_5,     KC_JYEN,     KC_6,     KC_7,   KC_8,    KC_9,     KC_0,    KC_MINS,   KC_NO,   KC_BSPC,\
KC_TAB,      KC_SCLN, KC_COMM,      KC_DOT,        KC_P,       KC_Q,      JP_LBRC,     KC_Y,    KC_G,   KC_D,  KC_M,      KC_F,                  KC_LBRC,     KC_BSPC,\
KC_LCTL,           KC_A,          KC_O,           KC_E,         KC_I,        KC_U,     JP_RBRC,     KC_B,    KC_N,    KC_T,   KC_R,      KC_S,                                       KC_ENT,\
KC_LSFT,            KC_Z,          KC_X,           KC_C,        KC_V,      KC_W,        KC_RO,     KC_H,     KC_J,    KC_K,   KC_L,KC_SLSH,                       KC_UP,     KC_APP,\
MO(2),     KC_LGUI,   KC_LALT,            LT(2,KC_MHEN),   KC_SPC,                 KC_HENK,        LT(3,KC_DEL),KC_DEL,KC_LEFT,KC_DOWN, KC_RGHT\
  ),

  [L_LOWER] = LAYOUT_directional( \
KC_TRNS,        KC_F1,          KC_F2,        KC_F3,       KC_F4,       KC_F5,      KC_NO,       KC_F6,       KC_F7,        KC_F8,        KC_F9,      KC_F10,    JP_TILD,KC_NO,KC_DEL,\
  KC_ESC,     JP_EXLM,    JP_DQUO,    JP_HASH,     JP_DLR,   JP_PERC,                 ,  JP_AMPR,  JP_QUOT,    JP_LPRN,    JP_RPRN,      JP_EQL,   JP_ASTR,                        ,\
KC_LCTL,            KC_1,           KC_2,           KC_3,        KC_4,        KC_5,    KC_JYEN,        KC_6,         KC_7,          KC_8,          KC_9,          KC_0,                          KC_TRNS,\
KC_LSFT,          KC_F1,         KC_F2,         KC_F3,       KC_F4,      KC_F5,    KC_JYEN,       KC_F6,       KC_F7,        KC_F8,        KC_F9,      KC_F10,    KC_TRNS,       KC_TRNS,\
KC_TRNS,KC_TRNS,  KC_TRNS,             KC_NO,              KC_MINS,                  LSFT(KC_7),                         KC_TRNS, KC_TRNS,   KC_MS_L,  KC_MS_D,   JP_AT\
  ),

  [L_RAISE] = LAYOUT_directional( \
KC_TRNS,   RGB_TOG,   RGB_MOD,  RGB_HUI,   RGB_SAI, RGB_SPI,  RGB_M_P,RGB_M_R,    RGB_M_SN,   RGB_M_X,  RGB_M_T,   KC_NO,  JP_TILD,KC_NO,RESET,\
KC_NO,       KC_NO,       RGB_RMOD,RGB_HUD, RGB_SAD,RGB_SPD,RGB_M_B, RGB_M_SW, RGB_M_K,     RGB_M_G,  KC_NO,      KC_NO,  KC_NO,             TG(1),\
KC_NO,        KC_NO,      KC_NO,        KC_NO,      KC_NO,    KC_NO,   KC_NO,    KC_NO,        KC_NO,         KC_NO,       KC_NO,     KC_NO,                     KC_TRNS,\
KC_NO,        KC_NO,      KC_NO,        KC_NO,       KC_NO,    KC_NO,   JP_CIRC,   KC_NO,    LCTL(KC_M),     KC_NO,      KC_NO,     KC_NO,  KC_NO,           KC_NO,\
KC_NO,    KC_NO,          KC_NO,                 KC_NO,              KC_MINS,               KC_NO,                             KC_NO,       KC_NO,     KC_NO,  KC_NO,           KC_NO\
  ),

};
