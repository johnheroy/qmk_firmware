#include QMK_KEYBOARD_H
#include "action_layer.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // 0: Base Layer
  // TODO: support right FN layer as well from RALT key
  LAYOUT_all(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSLS,  KC_GRV,    \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSPC,   \
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_NO,             KC_ENT,    \
      KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, KC_RSFT,    F(0),      \
      KC_CAPS, KC_LGUI, KC_LALT,                          KC_SPC,                          KC_RALT, KC_RGUI,  KC_NO,   KC_NO,    KC_NO),

  // 1: Function Layer (classic HHKB fn)
  LAYOUT_all(
      RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_INS,   KC_DEL,    \
      KC_CAPS, KC_TRNS, RGB_M_G, RGB_M_R, RGB_TOG,KC_TRNS,KC_TRNS,KC_TRNS,KC_PSCR,KC_SLCK,   KC_PAUS, KC_UP,  KC_TRNS,           KC_TRNS,   \
      KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS,KC_TRNS,KC_PAST,KC_PSLS,KC_HOME,KC_PGUP, KC_LEFT, KC_RGHT,  KC_NO,             KC_TRNS,   \
      KC_LSFT, KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT,KC_TRNS,KC_TRNS,KC_PPLS,KC_PMNS,KC_END,  KC_PGDN, KC_DOWN,  KC_RSFT, KC_TRNS,    KC_TRNS,   \
      KC_TRNS, KC_LGUI, KC_LALT,                          KC_SPC,                          KC_TRNS, KC_TRNS,  KC_NO,   KC_NO,    KC_NO),

};

// Custom Actions
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
};

// Macros
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) { register_code(KC_RSFT); }
      else { unregister_code(KC_RSFT); }
      break;
  }

  return MACRO_NONE;
};

// Loop
void matrix_scan_user(void) {
  // Empty
};
