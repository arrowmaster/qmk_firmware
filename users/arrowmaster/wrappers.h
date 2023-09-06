/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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

#pragma once
#include "arrowmaster.h"
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

// clang-format off
#define LAYOUT_ergodox_wrapper(...)          LAYOUT_ergodox(__VA_ARGS__)
#define LAYOUT_ergodox_pretty_wrapper(...)   LAYOUT_ergodox_pretty(__VA_ARGS__)
#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_ortho_5x12_wrapper(...)       LAYOUT_ortho_5x12(__VA_ARGS__)
#define LAYOUT_gergo_wrapper(...)            LAYOUT_gergo(__VA_ARGS__)
#define LAYOUT_split_3x6_3_wrapper(...)      LAYOUT_split_3x6_3(__VA_ARGS__)

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/

#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH


#define _________________TARMAK1A_L1_______________        KC_Q,    KC_W,    KC_J,    KC_R,    KC_T
#define _________________TARMAK1A_L2_______________        _________________QWERTY_L2_________________
#define _________________TARMAK1A_L3_______________        _________________QWERTY_L3_________________

#define _________________TARMAK1A_R1_______________        _________________QWERTY_R1_________________
#define _________________TARMAK1A_R2_______________        KC_H,    KC_N,    KC_E,    KC_L,    KC_SCLN
#define _________________TARMAK1A_R3_______________        KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define _________________TARMAK1B_L1_______________        _________________TARMAK1A_L1_______________
#define _________________TARMAK1B_L2_______________        _________________TARMAK1A_L2_______________
#define _________________TARMAK1B_L3_______________        _________________TARMAK1A_L3_______________

#define _________________TARMAK1B_R1_______________        _________________TARMAK1A_R1_______________
#define _________________TARMAK1B_R2_______________        KC_M,    KC_N,    KC_E,    KC_L,    KC_SCLN
#define _________________TARMAK1B_R3_______________        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH

#define _________________TARMAK2A_L1_______________        _________________TARMAK1B_L1_______________
#define _________________TARMAK2A_L2_______________        _________________TARMAK1B_L2_______________
#define _________________TARMAK2A_L3_______________        KC_Z,    KC_X,    KC_C,    KC_B,    KC_V

#define _________________TARMAK2A_R1_______________        _________________TARMAK1B_R1_______________
#define _________________TARMAK2A_R2_______________        _________________TARMAK1B_R2_______________
#define _________________TARMAK2A_R3_______________        _________________TARMAK1B_R3_______________

#define _________________TARMAK2B_L1_______________        KC_Q,    KC_W,    KC_F,    KC_R,    KC_B
#define _________________TARMAK2B_L2_______________        KC_A,    KC_S,    KC_D,    KC_T,    KC_G
#define _________________TARMAK2B_L3_______________        KC_Z,    KC_X,    KC_C,    KC_J,    KC_V

#define _________________TARMAK2B_R1_______________        _________________TARMAK2A_R1_______________
#define _________________TARMAK2B_R2_______________        _________________TARMAK2A_R2_______________
#define _________________TARMAK2B_R3_______________        _________________TARMAK2A_R3_______________

#define _________________TARMAK3_L1________________        KC_Q,    KC_W,    KC_F,    KC_J,    KC_B
#define _________________TARMAK3_L2________________        KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define _________________TARMAK3_L3________________        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define _________________TARMAK3_R1________________        _________________TARMAK2B_R1_______________
#define _________________TARMAK3_R2________________        _________________TARMAK2B_R2_______________
#define _________________TARMAK3_R3________________        _________________TARMAK2B_R3_______________

#define _________________TARMAK4_L1________________        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define _________________TARMAK4_L2________________        _________________TARMAK3_L2________________
#define _________________TARMAK4_L3________________        _________________TARMAK3_L3________________

#define _________________TARMAK4_R1________________        KC_J,    KC_U,    KC_I,    KC_Y,    KC_SCLN
#define _________________TARMAK4_R2________________        KC_M,    KC_N,    KC_E,    KC_L,    KC_O
#define _________________TARMAK4_R3________________        _________________TARMAK3_R3________________

#define _________________TARMAK5_L1________________        _________________TARMAK4_L1________________
#define _________________TARMAK5_L2________________        _________________TARMAK4_L2________________
#define _________________TARMAK5_L3________________        _________________TARMAK4_L3________________

#define _________________TARMAK5_R1________________        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________TARMAK5_R2________________        KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define _________________TARMAK5_R3________________        _________________TARMAK4_R3________________


#define _________________COLEMAK_L1________________        KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define _________________COLEMAK_L2________________        KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define _________________COLEMAK_L3________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________COLEMAK_R1________________        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________        KC_H,    KC_N,    KC_E,    KC_I,    KC_O
#define _________________COLEMAK_R3________________        KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define _____________COLEMAK_MOD_DH_L1_____________        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define _____________COLEMAK_MOD_DH_L2_____________        KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define _____________COLEMAK_MOD_DH_L3_____________        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define _____________COLEMAK_MOD_DH_R1_____________        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _____________COLEMAK_MOD_DH_R2_____________        KC_K,    KC_N,    KC_E,    KC_I,    KC_O
#define _____________COLEMAK_MOD_DH_R3_____________        KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH

#define _____________COLEMAK_MOD_DHM_L1____________        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define _____________COLEMAK_MOD_DHM_L2____________        KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define _____________COLEMAK_MOD_DHM_L3____________        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define _____________COLEMAK_MOD_DHM_R1____________        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _____________COLEMAK_MOD_DHM_R2____________        KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define _____________COLEMAK_MOD_DHM_R3____________        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH


#define _________________DVORAK_L1_________________        KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y
#define _________________DVORAK_L2_________________        KC_A,    KC_O,    KC_E,   KC_U,     KC_I
#define _________________DVORAK_L3_________________        KC_SCLN, KC_Q,    KC_J,   KC_K,     KC_X

#define _________________DVORAK_R1_________________        KC_F,    KC_G,    KC_C,    KC_R,    KC_L
#define _________________DVORAK_R2_________________        KC_D,    KC_H,    KC_T,    KC_N,    KC_S
#define _________________DVORAK_R3_________________        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z

#define _________________WORKMAN_L1________________       KC_Q,    KC_D,    KC_R,   KC_W,     KC_B
#define _________________WORKMAN_L2________________       KC_A,    KC_S,    KC_H,   KC_T,     KC_G
#define _________________WORKMAN_L3________________       KC_Z,    KC_X,    KC_M,   KC_C,     KC_V

#define _________________WORKMAN_R1________________       KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN
#define _________________WORKMAN_R2________________       KC_Y,    KC_N,    KC_E,    KC_O,    KC_I
#define _________________WORKMAN_R3________________       KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLASH


#define _________________NORMAN_L1_________________       KC_Q,    KC_W,    KC_D,    KC_F,    KC_K
#define _________________NORMAN_L2_________________       KC_A,    KC_S,    KC_E,    KC_T,    KC_G
#define _________________NORMAN_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________NORMAN_R1_________________       KC_J,    KC_U,    KC_R,    KC_L,    KC_SCLN
#define _________________NORMAN_R2_________________       KC_Y,    KC_N,    KC_I,    KC_O,    KC_U
#define _________________NORMAN_R3_________________       KC_P,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define ________________NUMBER_LEFT________________        KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________        KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define __________________LONG_FUNC_LEFT___________________       KC_F1,  KC_F2,  KC_F3, KC_F4,  KC_F5,  KC_F6
#define __________________LONG_FUNC_RIGHT__________________       KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12

#define ___________________BLANK___________________        _______, _______, _______, _______, _______
#define _____________________X_____________________        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO



#define _________________LOWER_L1__________________        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________LOWER_L2__________________        _________________FUNC_LEFT_________________
#define _________________LOWER_L3__________________        _________________FUNC_RIGHT________________

#define _________________LOWER_R1__________________        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
#define _________________LOWER_R2__________________        _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR
#define _________________LOWER_R3__________________        _______, _______, _______, KC_HOME, KC_END



#define _________________RAISE_L1__________________        ________________NUMBER_LEFT________________
#define _________________RAISE_L2__________________        KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15
#define _________________RAISE_L3__________________        KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20

#define _________________RAISE_R1__________________        ________________NUMBER_RIGHT_______________
#define _________________RAISE_R2__________________        _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC
#define _________________RAISE_R3__________________        _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END



#define _________________ADJUST_L1_________________        RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG
#define _________________ADJUST_L2_________________        MU_TOG , CK_TOGG, AU_ON,   AU_OFF,  CG_NORM
#define _________________ADJUST_L3_________________        RGB_RMOD,RGB_HUD,RGB_SAD, RGB_VAD, KC_RGB_T

#define _________________ADJUST_R1_________________        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
#define _________________ADJUST_R2_________________        CG_SWAP, QWERTY,  COLEMAK, KC_NO,   KC_NO
#define _________________ADJUST_R3_________________        MG_NKRO, KC_MUTE, KC_VOLD, KC_VOLU, KC_MNXT

// clang-format on
