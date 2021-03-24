#include "arrowmaster.h"

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;
#endif

#ifdef BACKLIGHT_ENABLE
enum planck_keycodes {
    BACKLIT = NEW_SAFE_RANGE,
    TH_LVL,
};

#else
#    define BACKLIT OSM(MOD_LSFT)
enum planck_keycodes {
    TH_LVL = NEW_SAFE_RANGE,
};
#endif

#ifdef KEYBOARD_planck_ez
#    define PLNK_1 BK_LWER
#    define PLNK_2 SP_LWER
#    define PLNK_3 KC_NO
#    define PLNK_4 ET_RAIS
#else
#    define PLNK_1 SP_LWER
#    define PLNK_2 BK_LWER
#    define PLNK_3 DL_RAIS
#    define PLNK_4 ET_RAIS
#endif

/*
 * The `LAYOUT_ortho_4x12_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */
// clang-format off
#define LAYOUT_ortho_4x12_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_ortho_4x12_wrapper( \
    KC_TAB,  K01,     K02,     K03,     K04,     K05,     K06,     K07,     K08,     K09,     K0A,     KC_BSPC, \
    KC_LCTL, K11,     K12,     K13,     K14,     K15,     K16,     K17,     K18,     K19,     K1A,     KC_QUOT, \
    SFTCAP,  K21,     K22,     K23,     K24,     K25,     K26,     K27,     K28,     K29,     K2A,     KC_SFTENT, \
    BACKLIT, KC_LGUI, KC_LALT, MO(_NUM),LOWER,   KC_SPC,  SP_NAV,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  )
#define LAYOUT_ortho_4x12_base_wrapper(...)       LAYOUT_ortho_4x12_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_ortho_4x12_base_wrapper(
    _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
    _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
    _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
  ),

  [_COLEMAK] = LAYOUT_ortho_4x12_base_wrapper(
    _____________COLEMAK_MOD_DHM_L1____________, _____________COLEMAK_MOD_DHM_R1____________,
    _____________COLEMAK_MOD_DHM_L2____________, _____________COLEMAK_MOD_DHM_R2____________,
    _____________COLEMAK_MOD_DHM_L3____________, _____________COLEMAK_MOD_DHM_R3____________
  ),

  [_NAV] = LAYOUT_ortho_4x12_wrapper(
    _______, ___________________BLANK___________________, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
    _______, ___________________BLANK___________________, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, ___________________BLANK___________________, _______, _______, _______, _______, _______, _______,
    _______, ___________________BLANK___________________, _______, _______, KC_NO,   KC_RALT, KC_RGUI, KC_RCTL
  ),

  [_NUM] = LAYOUT_ortho_4x12_wrapper(
    _______, ___________________BLANK___________________, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
    _______, ___________________BLANK___________________, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
    _______, ___________________BLANK___________________, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
    _______, ___________________BLANK___________________, _______, KC_P0,   KC_P0,   KC_PDOT, KC_PENT, KC_NO
  ),

  [_LOWER] = LAYOUT_ortho_4x12_wrapper(
    KC_TILD, _________________LOWER_L1__________________, _________________LOWER_R1__________________, KC_BSPC,
    KC_DEL,  _________________LOWER_L2__________________, _________________LOWER_R2__________________, KC_PIPE,
    _______, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______,
    GUI_KCL, _______, _______, _______, KC_TRNS, GUI_KCL, _______, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
  ),

  [_RAISE] = LAYOUT_ortho_4x12_wrapper(
    KC_GRV,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, KC_BSPC,
    KC_DEL,  _________________RAISE_L2__________________, _________________RAISE_R2__________________, KC_BSLS,
    _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______,
    _______, _______, _______, _______, KC_TRNS, _______, _______, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
  ),

  [_ADJUST] = LAYOUT_ortho_4x12_wrapper(
    KC_MAKE, _________________ADJUST_L1_________________, _________________ADJUST_R1_________________, KC_RST,
    VRSN,    _________________ADJUST_L2_________________, _________________ADJUST_R2_________________, EEP_RST,
    _______, _________________ADJUST_L3_________________, _________________ADJUST_R3_________________, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )

};
// clang-format on

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#ifdef BACKLIGHT_ENABLE
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
#    ifdef BACKLIGHT_ENABLE
                backlight_step();
#    endif
            } else {
                unregister_code(KC_RSFT);
            }
            break;
#endif
#ifdef KEYBOARD_planck_ez
        case TH_LVL:
            if (record->event.pressed) {
                keyboard_config.led_level++;
                if (keyboard_config.led_level > 4) {
                    keyboard_config.led_level = 0;
                }
                planck_ez_right_led_level((uint8_t)keyboard_config.led_level * 255 / 4);
                planck_ez_left_led_level((uint8_t)keyboard_config.led_level * 255 / 4);
                eeconfig_update_kb(keyboard_config.raw);
                layer_state_set_kb(layer_state);
            }
            break;
#endif
    }
    return true;
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
        case BK_LWER:
        case SP_LWER:
        case DL_RAIS:
        case ET_RAIS:
            return false;
        default:
            return true;
    }
}

#ifdef RGB_MATRIX_ENABLE

#    ifdef KEYBOARD_planck_rev6
// clang-format off
led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        { NO_LED,   6,    NO_LED, NO_LED,   5,    NO_LED },
        { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
        { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED,   0    },
        { NO_LED,   7,    NO_LED, NO_LED,   2,    NO_LED },
        { NO_LED,   4,    NO_LED, NO_LED,   3,    NO_LED },
        { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
        { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
        { NO_LED,   1,    NO_LED, NO_LED,   8,    NO_LED }
    }, {
        // LED Index to Physical Position
        {112, 39}, {148, 60}, {206, 53}, {206, 3}, {150, 3}, {74, 3}, {18, 3}, {18, 54}, {77, 60}
    }, {
        // LED Index to Flag
        LED_FLAG_ALL, LED_FLAG_ALL, LED_FLAG_ALL, LED_FLAG_ALL, LED_FLAG_ALL,
        LED_FLAG_ALL, LED_FLAG_ALL, LED_FLAG_ALL, LED_FLAG_ALL
    }
};
// clange-format on
#    endif

// clang-format off
void suspend_power_down_keymap(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_keymap(void) {
    rgb_matrix_set_suspend_state(false);
}
// clang-format on

void rgb_matrix_indicators_user(void) {
    uint8_t this_mod = get_mods();
    uint8_t this_led = host_keyboard_leds();
    uint8_t this_osm = get_oneshot_mods();
    bool    is_ez;
#    ifdef KEYBOARD_planck_ez
    is_ez = true;
#    endif

    if (g_suspend_state || !rgb_matrix_config.enable) return;

#    if defined(RGBLIGHT_ENABLE)
    if (!userspace_config.rgb_layer_change)
#    else
    if (userspace_config.rgb_layer_change)
#    endif
    {
        switch (get_highest_layer(layer_state)) {
            case _GAMEPAD:
                rgb_matrix_layer_helper(HSV_ORANGE, 1, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                break;
            case _DIABLO:
                rgb_matrix_layer_helper(HSV_RED, 1, rgb_matrix_config.speed * 8, LED_FLAG_MODIFIER);
                break;
            case _RAISE:
                rgb_matrix_layer_helper(HSV_YELLOW, 1, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                break;
            case _LOWER:
                rgb_matrix_layer_helper(HSV_GREEN, 1, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                break;
            case _ADJUST:
                rgb_matrix_layer_helper(HSV_RED, 1, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                break;
            default: {
                bool mods_enabled = IS_LAYER_ON(_MODS);
                switch (get_highest_layer(default_layer_state)) {
                    case _QWERTY:
                        rgb_matrix_layer_helper(HSV_CYAN, mods_enabled, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                        break;
                    case _COLEMAK:
                        rgb_matrix_layer_helper(HSV_MAGENTA, mods_enabled, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                        break;
                    case _DVORAK:
                        rgb_matrix_layer_helper(HSV_SPRINGGREEN, mods_enabled, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                        break;
                    case _WORKMAN:
                        rgb_matrix_layer_helper(HSV_GOLDENROD, mods_enabled, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                        break;
                    case _NORMAN:
                        rgb_matrix_layer_helper(HSV_CORAL, mods_enabled, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                        break;
                    case _MALTRON:
                        rgb_matrix_layer_helper(HSV_YELLOW, mods_enabled, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                        break;
                    case _EUCALYN:
                        rgb_matrix_layer_helper(HSV_PINK, mods_enabled, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                        break;
                    case _CARPLAX:
                        rgb_matrix_layer_helper(HSV_BLUE, mods_enabled, rgb_matrix_config.speed, LED_FLAG_MODIFIER);
                        break;
                }
                break;
            }
        }
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            rgb_matrix_set_color(is_ez ? 41 : 42, 0x00, 0xFF, 0xFF);
            break;
        case _COLEMAK:
            rgb_matrix_set_color(is_ez ? 41 : 42, 0xFF, 0x00, 0xFF);
            break;
        case _DVORAK:
            rgb_matrix_set_color(is_ez ? 41 : 42, 0x00, 0xFF, 0x00);
            break;
        case _WORKMAN:
            rgb_matrix_set_color(is_ez ? 41 : 42, 0xD9, 0xA5, 0x21);
            break;
    }

    if ((this_mod | this_osm) & MOD_MASK_SHIFT || this_led & (1 << USB_LED_CAPS_LOCK)) {
        if (!layer_state_cmp(layer_state, _ADJUST)) {
            rgb_matrix_set_color(24, 0x00, 0xFF, 0x00);
        }
        rgb_matrix_set_color(36, 0x00, 0xFF, 0x00);
    }
    if ((this_mod | this_osm) & MOD_MASK_CTRL) {
        rgb_matrix_set_color(25, 0xFF, 0x00, 0x00);
        rgb_matrix_set_color(34, 0xFF, 0x00, 0x00);
        rgb_matrix_set_color(37, 0xFF, 0x00, 0x00);
    }
    if ((this_mod | this_osm) & MOD_MASK_GUI) {
        rgb_matrix_set_color(39, 0xFF, 0xD9, 0x00);
    }
    if ((this_mod | this_osm) & MOD_MASK_ALT) {
        rgb_matrix_set_color(38, 0x00, 0x00, 0xFF);
    }
}

void matrix_init_keymap(void) {
#    ifdef KEYBOARD_planck_light
    writePinLow(D6);
#    endif
    // rgblight_mode(RGB_MATRIX_MULTISPLASH);
}
#else  // RGB_MATRIX_INIT

void matrix_init_keymap(void) {
#    if !defined(CONVERT_TO_PROTON_C) && !defined(KEYBOARD_planck)
    setPinOutput(D5);
    writePinHigh(D5);

    setPinOutput(B0);
    writePinHigh(B0);
#    endif
}
#endif  // RGB_MATRIX_INIT

#ifdef ENCODER_ENABLE
void encoder_update(bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _RAISE:
            clockwise ? tap_code(KC_VOLD) : tap_code(KC_VOLU);
            break;
        case _LOWER:
#    ifdef RGB_MATRIX_ENABLE
            clockwise ? rgb_matrix_step() : rgb_matrix_step_reverse();
#    else
            clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
#    endif
            break;
        case _ADJUST:
#    ifdef AUDIO_CLICKY
            clockwise ? clicky_freq_up() : clicky_freq_down();
#    endif
            break;
        default:
            clockwise ? tap_code(KC_DOWN) : tap_code(KC_UP);
    }
#    ifdef AUDIO_CLICKY
    clicky_play();
#    endif
}
#endif  // ENCODER_ENABLE

#ifdef KEYBOARD_planck_rev6
void dip_update(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                audio_on();
            } else {
                audio_off();
            }
            break;
        case 1:
            if (active) {
                clicky_on();
            } else {
                clicky_off();
            }
            break;
        case 2:
            keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = active;
            break;
        case 3:
            userspace_config.nuke_switch = active;
            break;
    }
}
#endif  // KEYBOARD_planck_rev6

#ifdef KEYBOARD_planck_ez
layer_state_t layer_state_set_keymap(layer_state_t state) {
    planck_ez_left_led_off();
    planck_ez_right_led_off();
    switch (get_highest_layer(state)) {
        case _LOWER:
            planck_ez_left_led_on();
            break;
        case _RAISE:
            planck_ez_right_led_on();
            break;
        case _ADJUST:
            planck_ez_right_led_on();
            planck_ez_left_led_on();
            break;
        default:
            break;
    }
    return state;
}
#endif
