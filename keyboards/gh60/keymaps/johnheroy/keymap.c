// This is johnheroy's custom keymap.

#include "gh60.h"
#include "action_layer.h"

#define _DEFAULT 0
#define _FN0 1
#define _FN1 2

// Fillers to make layering more clear
#define ______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty gui/alt/space/alt/gui
     * ,-----------------------------------------------------------------------------------------.
     * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  `  |
     * |-----------------------------------------------------------------------------------------+
     * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  Bksp  |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
     * |-----------------------------------------------------------------------------------------+
     * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | RShift    | FN0 |
     * |-----------------------------------------------------------------------------------------+
     * | Caps  |LGUI | LAlt  |               Space                | FN1  |  RAlt   |RGUI | Ctrl  |
     * `-----------------------------------------------------------------------------------------'
     */
    [_DEFAULT] = KEYMAP_HHKB( /* Basic QWERTY */
        KC_ESC,  KC_1,    KC_2,    KC_3, KC_4, KC_5,   KC_6, KC_7, KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV, \
        KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,  \
        KC_LCTL, KC_A,    KC_S,    KC_D, KC_F, KC_G,   KC_H, KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  \
        KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_FN0), \
        KC_CAPS, KC_LGUI, KC_LALT,             KC_SPC,             MO(_FN1),KC_RALT, KC_RGUI, KC_RCTL \
        ),

    /* FN0 Layer, HHKB standard FN layer with right pinky FN
     * ,-----------------------------------------------------------------------------------------.
     * |     | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 | Ins | Del |
     * |-----------------------------------------------------------------------------------------+
     * |  CAPS  |     |     |     |     |     |     |     | Psc | Slck| Paus| Up  |     |        |
     * |-----------------------------------------------------------------------------------------+
     * |         | Vol-| Vol+| Mute|     |     | *   | /   | Home| PgUp| Left|Right|             |
     * |-----------------------------------------------------------------------------------------+
     * |           | Prev| Play| Next|     |     | +   | -   | End  |PgDn| Down|           |     |
     * |-----------------------------------------------------------------------------------------+
     *         |       |       |                                 | Stop  |       |
     *         `-----------------------------------------------------------------'
     */
    [_FN0] = KEYMAP_HHKB( /* Layer 1 */
        ______,   KC_F1,  KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12, KC_INS,  KC_DEL, \
        KC_CAPS, ______,  ______,  ______,  ______, ______, ______,  ______,  KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,  ______, ______,  \
        ______,  KC_VOLD, KC_VOLU, KC_MUTE, ______, ______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT,______,   \
        ______,  KC_MPRV, KC_MPLY, KC_MNXT, ______, ______, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN, ______, ______,  \
        ______,  ______,  ______,                   ______,                   ______,  KC_MSTP, ______,  ______ \
        ),

    /* FN1 Layer: extra FN layer using right thumb, includes media
     * ,-----------------------------------------------------------------------------------------.
     * |     | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 | Ins | Del |
     * |-----------------------------------------------------------------------------------------+
     * |  CAPS  |RClck| MsUp|LClck|     |     |     |     |     | Prev|Pause| Next|     |  Del   |
     * |-----------------------------------------------------------------------------------------+
     * |         |MsLft| MsDn|MsRgt|     |     |     |     |     | Vol-| Vol+| Mute|             |
     * |-----------------------------------------------------------------------------------------+
     * |           |     |     |     |     |     |     |     |     |     |     |           |     |
     * |-----------------------------------------------------------------------------------------+
     *         |       |       |                                 |       |       |
     *         `-----------------------------------------------------------------'
     */
    [_FN1] = KEYMAP_HHKB( /* Layer 2 */
        ______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,   KC_F7,   KC_F8,  KC_F9,   KC_F10, KC_F11,  KC_F12, KC_INS,  KC_DEL, \
        ______,  KC_BTN2,  KC_MS_U,  KC_BTN1,  ______, ______, ______,  ______,  ______, KC_MPRV, KC_MPLY,KC_MNXT,  ______, KC_DEL,  \
        ______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  ______, ______, ______,  ______,  ______, KC_VOLD,KC_VOLU, KC_MUTE, ______,   \
        ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______,______, ______,______,  ______,  \
        ______,  ______,  ______,                   ______,                   ______, ______,  ______, ______ \
        ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  return MACRO_NONE;
};
