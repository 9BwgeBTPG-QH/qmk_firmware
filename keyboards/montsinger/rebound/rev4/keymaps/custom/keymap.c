#include QMK_KEYBOARD_H
#include"keymap_jp.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_names {
  _QWERTY,
  _LOWER,
  _RAISE,
  _NUM
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

#define NUMBER MO(_NUM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_all(
   KC_TAB,                             KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                KC_Y,      KC_U,    KC_I,            KC_O,      KC_P,     KC_BSPC,
   MT(MOD_LCTL,KC_BSPC),  KC_A,    KC_S,     KC_D,    KC_F,    KC_G,   NUMBER,            KC_H,      KC_J,    KC_K,             KC_L,      KC_SCLN, KC_ENT,
   OSM(MOD_LSFT),               KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LALT(KC_SPC),     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    JP_AT,
   KC_LGUI, LGUI_T(KC_LALT), KC_NO, LT(1,KC_MHEN), KC_NO,   KC_SPC,RCTL(KC_M),  KC_HENK,  KC_NO,   LT(2,KC_DEL), KC_NO, LALT_T(JP_PIPE),JP_UNDS
),

[_LOWER] = LAYOUT_all(
KC_ESC, JP_EXLM, JP_DQUO, JP_HASH, JP_DLR, JP_PERC,                                    JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN, JP_EQL,   JP_ASTR,
KC_LCTL,      KC_1,        KC_2,        KC_3,    KC_4,      KC_5,              RESET,                     KC_6,        KC_7,       KC_8,       KC_9,    KC_0, JP_COLN,
RESET,     KC_F1,      KC_F2,      KC_F3,   KC_F4,    KC_F5,            KC_CAPS,                  KC_F6,      KC_F7,     KC_F8,     KC_F9, KC_F10,    JP_TILD,
   KC_LGUI, LGUI_T(KC_LALT), KC_NO, LT(1,KC_MHEN), KC_NO,   KC_MINS,RCTL(KC_M),  JP_PLUS,  KC_NO,   LT(2,KC_DEL), KC_NO, LALT_T(JP_PIPE),JP_UNDS
),

[_RAISE] = LAYOUT_all(
KC_ESC,           KC_BTN1,KC_UP,       KC_BTN2,KC_PGUP,KC_HOME,                  LSFT(KC_HOME),KC_NO,JP_LBRC,         JP_RBRC,             KC_QUOT,KC_BSPC,
LSFT(KC_CAPS),KC_LEFT,KC_DOWN,KC_RGHT,KC_PGDN,KC_END,     RESET,     LSFT(KC_END),    KC_F11,KC_F12,            KC_F13,             KC_F14,    JP_COLN,
KC_TRNS,           KC_F15,KC_F16,       KC_F17,  KC_F18,     KC_F19,  KC_CAPS,    SGUI(KC_S),         KC_NO,LGUI(KC_LEFT), LGUI(KC_RGHT),KC_NO,    KC_TRNS,
   KC_LGUI, LGUI_T(KC_LALT), KC_NO, LT(1,KC_MHEN), KC_NO,   KC_MINS,RCTL(KC_M),  JP_PLUS,  KC_NO,   LT(2,KC_DEL), KC_NO, LALT_T(JP_PIPE),JP_UNDS
),

[_NUM] =  LAYOUT_all(
KC_ESC,           KC_BTN1,KC_UP,       KC_BTN2,KC_PGUP,KC_HOME,                  JP_LPRN,       KC_7, KC_8, KC_9,       JP_EQL,     KC_BSPC,
LSFT(KC_CAPS),KC_LEFT,KC_DOWN,KC_RGHT,KC_PGDN,KC_END,     RESET,     JP_RPRN,       KC_4,KC_5,  KC_6,       JP_ASTR,    KC_ENT,
KC_TRNS,           KC_F15,KC_F16,       KC_F17,  KC_F18,     KC_F19,  KC_CAPS,    SGUI(KC_S),   KC_1, KC_2, KC_3,        KC_SLSH,    KC_DEL,
   KC_LGUI, LGUI_T(KC_LALT), KC_NO, LT(1,KC_MHEN), KC_NO,   KC_MINS,RCTL(KC_M),  JP_PLUS,  KC_NO,   KC_0, KC_NO, KC_DOT,KC_ENT
)
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code16(S(KC_VOLD));
    } else {
      tap_code16(KC_VOLU);
    }
}
