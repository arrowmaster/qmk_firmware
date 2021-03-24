#include QMK_KEYBOARD_H
#include "arrowmaster.h"

#define LAYOUT_atreus62_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
    KC_GRV,  ________________NUMBER_LEFT________________,                            ________________NUMBER_RIGHT_______________, KC_MINS, \
    KC_TAB,  K01,     K02,     K03,     K04,     K05,                                K06,     K07,     K08,     K09,     K0A,     KC_BSPC, \
    KC_LCTL, K11,     K12,     K13,     K14,     K15,                                K16,     K17,     K18,     K19,     K1A,     KC_QUOT, \
    KC_LSFT, K21,     K22,     K23,     K24,     K25,                                K26,     K27,     K28,     K29,     K2A,     KC_SFTENT, \
    KC_ESC,  KC_LGUI, KC_LALT, MO(_NUM),LOWER,   KC_SPC,  MO(_NAV),         KC_DEL,  SP_NAV,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  )
#define LAYOUT_atreus62_base_wrapper(...)       LAYOUT_atreus62_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_atreus62_base_wrapper(
  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
  _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
  _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
),
#ifdef _TARMAK1A
[_TARMAK1A] = LAYOUT_atreus62_base_wrapper(
  _________________TARMAK1A_L1_______________, _________________TARMAK1A_R1_______________,
  _________________TARMAK1A_L2_______________, _________________TARMAK1A_R2_______________,
  _________________TARMAK1A_L3_______________, _________________TARMAK1A_R3_______________
),
#endif //_TARMAK1A
#ifdef _TARMAK1B
[_TARMAK1B] = LAYOUT_atreus62_base_wrapper(
  _________________TARMAK1B_L1_______________, _________________TARMAK1B_R1_______________,
  _________________TARMAK1B_L2_______________, _________________TARMAK1B_R2_______________,
  _________________TARMAK1B_L3_______________, _________________TARMAK1B_R3_______________
),
#endif //_TARMAK1B
#ifdef _TARMAK2A
[_TARMAK2A] = LAYOUT_atreus62_base_wrapper(
  _________________TARMAK2A_L1_______________, _________________TARMAK2A_R1_______________,
  _________________TARMAK2A_L2_______________, _________________TARMAK2A_R2_______________,
  _________________TARMAK2A_L3_______________, _________________TARMAK2A_R3_______________
),
#endif //_TARMAK2A
#ifdef _TARMAK2B
[_TARMAK2B] = LAYOUT_atreus62_base_wrapper(
  _________________TARMAK2B_L1_______________, _________________TARMAK2B_R1_______________,
  _________________TARMAK2B_L2_______________, _________________TARMAK2B_R2_______________,
  _________________TARMAK2B_L3_______________, _________________TARMAK2B_R3_______________
),
#endif //_TARMAK2B
#ifdef _TARMAK3
[_TARMAK3] = LAYOUT_atreus62_base_wrapper(
  _________________TARMAK3_L1________________, _________________TARMAK3_R1________________,
  _________________TARMAK3_L2________________, _________________TARMAK3_R2________________,
  _________________TARMAK3_L3________________, _________________TARMAK3_R3________________
),
#endif //_TARMAK3
#ifdef _TARMAK4
[_TARMAK4] = LAYOUT_atreus62_base_wrapper(
  _________________TARMAK4_L1________________, _________________TARMAK4_R1________________,
  _________________TARMAK4_L2________________, _________________TARMAK4_R2________________,
  _________________TARMAK4_L3________________, _________________TARMAK4_R3________________
),
#endif //_TARMAK4
#ifdef _COLEMAK
[_COLEMAK] = LAYOUT_atreus62_base_wrapper(
  _____________COLEMAK_MOD_DHM_L1____________, _____________COLEMAK_MOD_DHM_R1____________,
  _____________COLEMAK_MOD_DHM_L2____________, _____________COLEMAK_MOD_DHM_R2____________,
  _____________COLEMAK_MOD_DHM_L3____________, _____________COLEMAK_MOD_DHM_R3____________
),
#endif //_COLEMAK
#ifdef _DVORAK
[_DVORAK] = LAYOUT_atreus62_base_wrapper(
  _________________DVORAK_L1_________________, _________________DVORAK_R1_________________,
  _________________DVORAK_L2_________________, _________________DVORAK_R2_________________,
  _________________DVORAK_L3_________________, _________________DVORAK_R3_________________
),
#endif //_DVORAK
#ifdef _WORKMAN
[_WORKMAN] = LAYOUT_atreus62_base_wrapper(
  _________________WORKMAN_L1________________, _________________WORKMAN_R1________________,
  _________________WORKMAN_L2________________, _________________WORKMAN_R2________________,
  _________________WORKMAN_L3________________, _________________WORKMAN_R3________________
),
#endif //_WORKMAN

[_GAMEPAD] = LAYOUT_wrapper(
  KC_GRV,  ________________NUMBER_LEFT________________,                            ________________NUMBER_RIGHT_______________, KC_MINS,
  KC_TAB,  _________________QWERTY_L1_________________,                            _________________QWERTY_R1_________________, KC_BSPC,
  KC_LCTL, _________________QWERTY_L2_________________,                            _________________QWERTY_R2_________________, KC_QUOT,
  KC_LSFT, _________________QWERTY_L3_________________,                            _________________QWERTY_R3_________________, KC_SFTENT,
  KC_ESC,  KC_NO,   KC_LALT, MO(_NUM),LOWER,   KC_SPC,  MO(_NAV),         KC_DEL,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_NAV] = LAYOUT_wrapper(
  _______, ___________________BLANK___________________,                            ___________________BLANK___________________, _______,
  _______, ___________________BLANK___________________,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
  _______, ___________________BLANK___________________,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, ___________________BLANK___________________,                            _______, _______, _______, _______, _______, _______,
  _______, ___________________BLANK___________________, _______,          _______, _______, _______, KC_NO,   KC_RALT, KC_RGUI, KC_RCTL
),

[_NUM] = LAYOUT_wrapper(
  _______, ___________________BLANK___________________,                            _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, _______,
  _______, ___________________BLANK___________________,                            _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
  _______, ___________________BLANK___________________,                            _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
  _______, ___________________BLANK___________________,                            _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
  _______, ___________________BLANK___________________, _______,          _______, _______, KC_P0,   KC_P0,   KC_PDOT, KC_PENT, KC_NO
),

[_LOWER] = LAYOUT_wrapper(
  KC_ESC,  _________________LOWER_L1__________________,                            _________________LOWER_R1__________________, KC_DEL,
  KC_GRV,  _________________LOWER_L1__________________,                            _________________LOWER_R1__________________, KC_BSPC,
  KC_DEL,  _________________LOWER_L2__________________,                            _________________LOWER_R2__________________, KC_PIPE,
  _______, _________________LOWER_L3__________________,                            _________________LOWER_R3__________________, _______,
  GUI_KCL, _______, _______, _______, KC_TRNS, GUI_KCL, _______,          _______, _______, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO
),

[_RAISE] = LAYOUT_wrapper(
  KC_ESC,  ________________NUMBER_LEFT________________,                            ________________NUMBER_RIGHT_______________, KC_DEL,
  KC_TILD, _________________RAISE_L1__________________,                            _________________RAISE_R1__________________, KC_BSPC,
  KC_DEL,  _________________RAISE_L2__________________,                            _________________RAISE_R2__________________, KC_BSLS,
  _______, _________________RAISE_L3__________________,                            _________________RAISE_R3__________________, _______,
  _______, _______, _______, _______, KC_TRNS, _______, _______,          _______, _______, KC_TRNS, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_wrapper(
  KC_NO  , TARMAK1A,TARMAK1B,TARMAK2A,TARMAK2B,TARMAK3,                            TARMAK4, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO,
  KC_MAKE, _________________ADJUST_L1_________________,                            _________________ADJUST_R1_________________, KC_RST,
  VRSN   , _________________ADJUST_L2_________________,                            _________________ADJUST_R2_________________, EEP_RST,
  KC_NO  , _________________ADJUST_L3_________________,                            _________________ADJUST_R3_________________, KC_NO,
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , _______, KC_NO  , KC_NO  ,          KC_NO  , KC_NO  , _______, KC_NO  , KC_NO  , KC_NO  , KC_NO
)

};

// Runs just one time when the keyboard initializes.
void matrix_init_keymap(void) {
    set_unicode_input_mode(UC_LNX);
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
};
