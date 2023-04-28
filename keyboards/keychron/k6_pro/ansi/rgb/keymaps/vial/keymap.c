/* Copyright 2021 @ Keychron (https://www.keychron.com)
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


#include "features/select_word.h"

// clang-format off
enum layers{
  MAC_BASE,
  WIN_BASE,
  MAC_FN1,
  WIN_FN1,
  FN2
};
enum custom_keycodes {
    SELWORD = SAFE_RANGE,
    SELLINE,
    UPDIR,
    ONEPWD,
    BRACES,
    // ALT_TAB,
    // Other custom keys...
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAC_BASE] = LAYOUT_ansi_68(
     KC_GESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, KC_RCTL,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_HOME,
     LT(2, KC_ESC),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,  KC_PGUP,
     KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_PGDN,
     KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                       KC_RCMMD,MO(MAC_FN1),MO(FN2), KC_LEFT,  KC_DOWN, KC_RGHT),

[WIN_BASE] = LAYOUT_ansi_68(
     KC_GESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, KC_RCTL,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_HOME,
     LT(2, KC_ESC),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,  KC_PGUP,
     KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_PGDN,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                       KC_RALT, MO(WIN_FN1),MO(FN2), KC_LEFT,  KC_DOWN, KC_RGHT),

[MAC_FN1] = LAYOUT_ansi_68(
     KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_TRNS,  RGB_MOD,
     KC_TRNS,  UPDIR, KC_UP,   SELWORD,   SELLINE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  DM_RSTP,  DM_REC1,  DM_PLY1,  DM_REC2,  DM_PLY2,  ONEPWD,  KC_END,
     RGB_TOG,  KC_LEFT, KC_DOWN, KC_RGHT, BRACES,  KC_TRNS,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_BTN1,  KC_BTN2,            KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_VOLD, KC_VOLU,  KC_MUTE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_WH_D,  KC_WH_U,  KC_INSERT,  KC_DELETE,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[WIN_FN1] = LAYOUT_ansi_68(
     KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_TRNS,  RGB_MOD,
     KC_TRNS,  UPDIR, KC_UP,   SELWORD,   SELLINE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  DM_RSTP,  DM_REC1,  DM_PLY1,  DM_REC2,  DM_PLY2,  ONEPWD,  KC_END,
     RGB_TOG,  KC_LEFT, KC_DOWN, KC_RGHT, BRACES,  KC_TRNS,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_BTN1,  KC_BTN2,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  KC_VOLD, KC_VOLU,  KC_MUTE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_WH_D,  KC_WH_U,  KC_INSERT,  KC_DELETE,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[FN2] = LAYOUT_ansi_68(
     KC_TILD,  BT_HST1,    BT_HST2,    BT_HST3,    BAT_LVL,    KC_TRNS,    KC_TRNS,    KC_TRNS,    RGB_RMOD,    RGB_TOG,    RGB_MOD,   RGB_VAD,   RGB_VAI,  KC_TRNS,  RGB_RMOD,
     KC_TRNS,  MI_TOG,  MI_Cs_1,  MI_Ds_1,  KC_TRNS,      MI_Fs_1,     MI_Gs_1,     MI_As_1,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_END,
     KC_TRNS,  MI_C_1,     MI_D_1,     MI_E_1,     MI_F_1,    MI_G_1,     MI_A_1,  MI_B_1,  MI_C_2,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
     KC_TRNS,  MI_OCTD,  MI_OCTU,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_VOLU,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_VOLD,  KC_MNXT),
};
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_select_word(keycode, record, SELWORD)) {
        return false;
    }

    const uint8_t mods         = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();

    switch (keycode) {
          case UPDIR: // Types ../ to go up a directory on the shell.
            if (record->event.pressed) {
                SEND_STRING("../");
            }
            return false;
        case ONEPWD:
            if (record->event.pressed) {
                SEND_STRING("oops");
            }
            return false;
        case BRACES: // Types [], {}, or <> and puts cursor between braces.
            if (record->event.pressed) {
                clear_oneshot_mods(); // Temporarily disable mods.
                unregister_mods(MOD_MASK_CSAG);
                if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
                    SEND_STRING("{}");
                } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
                    SEND_STRING("()");
                } else {
                    SEND_STRING("[]");
                }
                tap_code(KC_LEFT);   // Move cursor between braces.
                register_mods(mods); // Restore mods.
            }
            return false;
        case SELLINE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
            }
            return false;
            // case ALT_TAB:
            //     if (record->event.pressed) {
            //         if (!is_alt_tab_active) {
            //             is_alt_tab_active = true;
            //             register_code(KC_LALT);
            //         }
            //         alt_tab_timer = timer_read();
            //         register_code(KC_TAB);
            //     } else {
            //         unregister_code(KC_TAB);
            //     }
            //     break;
    }
    return true;
}

// void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     for (uint8_t i = led_min; i < led_max; i++) {
//         switch(get_highest_layer(layer_state|default_layer_state)) {
//             case MAC_FN1:
//                 rgb_matrix_set_color(i, RGB_TURQUOISE);
//                 break;
//             case WIN_FN1:
//                 rgb_matrix_set_color(i, RGB_MAGENTA);
//                 break;
//             case FN2:
//                 rgb_matrix_set_color(i, RGB_YELLOW);
//                 break;
//             default:
//                 rgb_matrix_set_color(i, RGB_OFF);
//                 break;
//         }
//     }
// }


void matrix_scan_user(void) {
    select_word_task();
}
