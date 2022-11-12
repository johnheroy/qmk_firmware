/* Copyright 2019
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

enum layers {
  _BASE = 0,
  _FN1,
};

// For kristy's numpad kylin 19
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_4x4(
    KC_P0,    KC_PAST,  KC_PSLS,  KC_PENT,
    KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
    KC_P4,    KC_P5,    KC_P6,    KC_PMNS,
    LT(_FN1, KC_P1),    KC_P2,    KC_P3,    KC_PDOT
  ),
  [_FN1] = LAYOUT_ortho_4x4(
    QK_BOOT,  _______,  _______,  KC_PEQL,
    BL_TOGG,  BL_DEC,   BL_INC,   _______,
    RGB_TOG,  RGB_MOD,  RGB_HUI,  KC_BSPC,
    RGB_SAI,  RGB_SAD,  BL_STEP,  RGB_HUD
  )
};
