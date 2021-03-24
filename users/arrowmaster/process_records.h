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

#if defined(KEYMAP_SAFE_RANGE)
#    define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum userspace_custom_keycodes {
    VRSN = PLACEHOLDER_SAFE_RANGE,  // Prints QMK Firmware and board info
    KC_QWERTY,                      // Sets default layer to QWERTY
    KC_COLEMAK,                     // Sets default layer to COLEMAK
    KC_DVORAK,                      // Sets default layer to DVORAK
    KC_WORKMAN,                     // Sets default layer to WORKMAN
    KC_DIABLO_CLEAR,                // Clears all Diablo Timers
    KC_MAKE,                        // Run keyboard's customized make command
    KC_RGB_T,                       // Toggles RGB Layer Indication mode
    RGB_IDL,                        // RGB Idling animations
    KC_SECRET_1,                    // test1
    KC_SECRET_2,                    // test2
    KC_SECRET_3,                    // test3
    KC_SECRET_4,                    // test4
    KC_SECRET_5,                    // test5
    KC_CCCV,                        // Hold to copy, tap to paste
    KC_NUKE,                        // NUCLEAR LAUNCH DETECTED!!!
    UC_FLIP,                        // (ಠ痊ಠ)┻━┻
    UC_TABL,                        // ┬─┬ノ( º _ ºノ)
    UC_SHRG,                        // ¯\_(ツ)_/¯
    UC_DISA,                        // ಠ_ಠ
    NEW_SAFE_RANGE                  // use "NEWPLACEHOLDER for keymap specific codes
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

#define _______ KC_TRNS
#define ___X___ KC_NO
#define XXXXXXX KC_NO
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define ADJUST  MO(_ADJUST)
#define TG_GAME TG(_GAMEPAD)
#define TG_NUM  TG(_NUM)
#define MO_NAV  MO(_NAV)

#define KC_SEC1 KC_SECRET_1
#define KC_SEC2 KC_SECRET_2
#define KC_SEC3 KC_SECRET_3
#define KC_SEC4 KC_SECRET_4
#define KC_SEC5 KC_SECRET_5

#define QWERTY  KC_QWERTY
#define DVORAK  KC_DVORAK
#define COLEMAK KC_COLEMAK
#define WORKMAN KC_WORKMAN

#define KC_GAMEPAD DF(_GAMEPAD)
#define GAMEPAD KC_GAMEPAD
#define KC_TARMAK1A DF(_TARMAK1A)
#define TARMAK1A KC_TARMAK1A
#define KC_TARMAK1B DF(_TARMAK1B)
#define TARMAK1B KC_TARMAK1B
#define KC_TARMAK2A DF(_TARMAK2A)
#define TARMAK2A KC_TARMAK2A
#define KC_TARMAK2B DF(_TARMAK2B)
#define TARMAK2B KC_TARMAK2B
#define KC_TARMAK3 DF(_TARMAK3)
#define TARMAK3 KC_TARMAK3
#define KC_TARMAK4 DF(_TARMAK4)
#define TARMAK4 KC_TARMAK4

#define KC_RESET RESET
#define KC_RST   KC_RESET

#ifdef SWAP_HANDS_ENABLE
#    define KC_C1R3 SH_T(KC_TAB)
#elif defined(DRASHNA_LP)
#    define KC_C1R3 TG(_GAMEPAD)
#else  // SWAP_HANDS_ENABLE
#    define KC_C1R3 KC_TAB
#endif  // SWAP_HANDS_ENABLE

#define BK_LWER LT(_LOWER, KC_BSPC)
#define SP_LWER LT(_LOWER, KC_SPC)
#define DL_RAIS LT(_RAISE, KC_DEL)
#define ET_RAIS LT(_RAISE, KC_ENTER)
#define SP_NAV LT(_NAV, KC_SPC)

/* OSM keycodes, to keep things clean and easy to change */
#define KC_MLSF OSM(MOD_LSFT)
#define KC_MRSF OSM(MOD_RSFT)

#define OS_LGUI OSM(MOD_LGUI)
#define OS_RGUI OSM(MOD_RGUI)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define OS_MEH  OSM(MOD_MEH)
#define OS_HYPR OSM(MOD_HYPR)

#define ALT_APP ALT_T(KC_APP)

#define MG_NKRO MAGIC_TOGGLE_NKRO

#define CTL_ESC CTL_T(KC_ESC)   // Tap for Escape, hold for Control
#define GUI_KCL LGUI(KC_L)

#define UC_IRNY UC(0x2E2E)
#define UC_CLUE UC(0x203D)
