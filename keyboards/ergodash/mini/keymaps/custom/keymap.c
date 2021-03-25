#include QMK_KEYBOARD_H
#include"keymap_jp.h"

#define _QWERTY 0
#define _EUCALYN 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  EUCALYN,
  LOWER,
  RAISE,
  ADJUST,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,JP_LBRC,                                  KC_JYEN,KC_Y,KC_U,KC_I,KC_O,JP_P,KC_BSPC,\
KC_LCTL,KC_A,KC_S,KC_D,KC_F,KC_G,JP_RBRC,                                 KC_RO,KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_ENT,\
KC_LSFT,KC_Z,KC_X,KC_C,KC_V,KC_B,JP_AT,                                      LSFT(KC_7),KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_SLSH,\
KC_F3,KC_GESC, KC_LGUI,KC_LALT,LT(2,KC_MHEN),KC_SPC,KC_NO,KC_NO,KC_HENK,LT(3,KC_DEL),KC_LEFT,KC_DOWN,KC_UP,KC_RGHT\
  ),

  [_EUCALYN] = LAYOUT( \
KC_TAB,KC_SCLN,KC_COMM,KC_DOT,JP_P,KC_Q,JP_LBRC,             KC_JYEN,KC_Y,KC_G,KC_D,KC_M,KC_F,KC_BSPC,\
KC_LCTL,KC_A,KC_O,KC_E,KC_I,KC_U,JP_RBRC,                                 KC_RO,KC_B,KC_N,KC_T,KC_R,KC_S,KC_ENT,\
KC_LSFT,KC_Z,KC_X,KC_C,KC_V,KC_W,JP_AT,                                    LSFT(KC_7),KC_H,KC_J,KC_K,KC_L,KC_SLSH,KC_SLSH,\
KC_F3,KC_GESC, KC_LGUI,KC_LALT,LT(2,KC_MHEN),KC_SPC,KC_NO,KC_NO,KC_HENK,LT(3,KC_DEL),KC_LEFT,KC_DOWN,KC_UP,KC_RGHT\
  ),

  [_LOWER] = LAYOUT(
KC_ESC,JP_EXLM,JP_DQUO,JP_HASH,JP_DLR,JP_PERC,LSFT(KC_QUOT),        JP_PIPE,JP_AMPR,JP_QUOT,JP_LPRN,JP_RPRN,JP_EQL,JP_ASTR,\
KC_LCTL,KC_1,KC_2,KC_3,KC_4,KC_5,KC_SLSH,                              JP_UNDS,KC_6,KC_7,KC_8,KC_9,KC_0,JP_COLN,\
KC_LSFT,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,JP_PLUS,                                     KC_QUOT,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,RESET,\
TG(2),KC_GESC, KC_LGUI,KC_LALT,LT(2,KC_MHEN),JP_MINS,KC_NO,                     KC_NO,JP_EQL,KC_DEL,KC_HOME,KC_PGDN,KC_PGUP,KC_END\
  ),

  [_RAISE] = LAYOUT(
KC_ESC,KC_NO,KC_UP,KC_NO,KC_PGUP,KC_HOME,JP_LPRN,                 KC_NO,LSFT(KC_HOME),KC_VOLU,KC_NO,KC_NO,JP_CIRC,TG(1),\
LSFT(KC_CAPS),KC_LEFT,KC_DOWN,KC_RGHT,KC_PGDN,KC_END,JP_RPRN,           KC_NO,LSFT(KC_END),KC_F11,KC_F12,KC_F13,KC_F14,KC_F14,\
KC_NO,KC_F15,KC_F16,KC_F17,KC_F18,KC_F19,JP_HASH,                        TG(4),SGUI(KC_S),RCTL(KC_M),LGUI(KC_LEFT), LGUI(KC_RGHT),KC_MS_U,KC_BTN2,\
KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                            KC_NO,KC_NO,KC_NO,KC_NO,KC_MS_L,KC_MS_D,KC_MS_R\
    ),

  [_ADJUST] = LAYOUT(
RGB_TOG,RGB_MOD,RGB_HUI,RGB_SAI,RGB_VAI,RGB_SPI,KC_NO,       KC_NO,RGB_M_P,RGB_M_B,RGB_M_R,RGB_M_SW,RGB_M_SN,RGB_TOG,\
BL_TOGG,RGB_RMOD,RGB_HUD,RGB_SAD,RGB_VAD,RGB_SPD,KC_NO,   KC_NO,RGB_M_K,RGB_M_X,RGB_M_G,RGB_M_T,RGB_TOG,KC_NO,\
BL_STEP,BL_ON,BL_INC,KC_NO,KC_NO,KC_NO,TG(4),                             TG(4),KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,\
BL_BRTG,BL_OFF,BL_DEC,KC_NO,KC_NO,KC_NO,KC_NO,                           KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO\
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
