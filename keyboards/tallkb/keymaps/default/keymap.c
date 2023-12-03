/*
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


enum custom_keycodes {
    F______ = SAFE_RANGE,
    WIN_HOME
};


// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN1,
    _FN2
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
               KC_NO,         KC_NO,                 KC_NO,          KC_NO, KC_NO,      KC_F9, KC_F10, KC_F11, KC_F12,      KC_NO, KC_MUTE, KC_VOLD,  KC_VOLU, \
               KC_NO,         KC_NO,           KC_MS_WH_UP,     KC_MS_BTN3, KC_NO,      KC_F5,  KC_F6,  KC_F7,  KC_F8,      KC_NO,   KC_NO,   KC_UP,    KC_NO, \
               TG(_FN2),      KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_NO,      KC_F1,  KC_F2,  KC_F3,  KC_F4,      KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, \
               \
               KC_GRAVE,                       KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,              KC_MINUS,    KC_EQUAL, KC_BSPACE, \
               \
               KC_TAB,                           KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,         KC_LBRACKET, KC_RBRACKET, KC_BSLASH, \
               KC_ESCAPE,                          KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L,               KC_SCOLON,    KC_QUOTE,  KC_ENTER, \
               KC_LSHIFT,                             KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M,            KC_COMMA,      KC_DOT,    KC_SLASH, KC_RSHIFT, \
    MO(_FN1),  KC_LALT, KC_LGUI, KC_LCTRL,                          KC_SPACE,                             KC_RCTRL,     KC_RGUI,     KC_RALT,    KC_F24  \
    ),
    [_FN1] = LAYOUT(
               RESET,      _______, _______, _______, _______,        _______, _______, _______, _______,        _______, _______, _______, _______, \
             _______,      _______, _______, _______, _______,        _______, _______, _______, _______,        _______, _______, _______, _______, \
             _______,      _______, _______, _______, _______,        _______, _______, _______, _______,        _______, _______, _______, _______, \
             \
             WIN_HOME,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______, _______, KC_DELETE, \
             \
             _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______,   _______, \
             _______,          _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,            _______, _______,   _______, \
             _______,            _______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______,   _______, \
    _______, _______, _______, _______,                          _______,                                        _______, _______, _______,   _______  \
    ),
    [_FN2] = LAYOUT(
             _______,      _______, _______, _______, _______,        _______, _______, _______, _______,        _______, _______, _______, _______, \
             _______,      _______, _______, _______, _______,        _______, _______, _______, _______,        _______, _______, _______, _______, \
             TG(_FN2),     _______, _______, _______, _______,        _______, _______, _______, _______,        _______, _______, _______, _______, \
             \
             F______,    F______, F______, F______, F______, F______, F______, F______, F______, F______, F______,             F______, F______, F______, \
             \
             F______,       F______, KC_WH_U, KC_BTN3, F______, F______, F______, F______, F______, F______, F______,          F______, F______, F______, \
             TG(_FN2),          KC_WH_L, KC_WH_D, KC_WH_R, F______, F______, F______, F______, F______, F______,               F______, F______, _______, \
             F______,            F______, F______, F______, F______, F______, F______, F______,                       F______, F______, F______, F______, \
    F______, F______, F______, F______,                                 F______,                                      F______, F______, F______, _______  \
    )
};


layer_state_t layer_state_set_user(layer_state_t state) {
    switch(biton32(state)) {
        case _FN2:
            writePinHigh(E1);
            break;
        default:
            writePinLow(E1);
            break;
    }
    return state;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case F______:
            if (record->event.pressed) {
                register_code(_______);
                layer_off(_FN2);
            } else {
                unregister_code(_______);
            }
            break;
        case WIN_HOME:
            if (record->event.pressed) {
                SEND_STRING("\%UserProfile\%");
            } else {
            }
    }
    return true;
}


/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/

/*
             _______,      _______, _______, _______, _______,        _______, _______, _______, _______,        _______, _______, _______, _______, \
             _______,      _______, _______, _______, _______,        _______, _______, _______, _______,        _______, _______, _______, _______, \
             _______,      _______, _______, _______, _______,        _______, _______, _______, _______,        _______, _______, _______, _______, \
             \
             _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, \
             _______,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, \
             _______,               _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, \
             _______,                 _______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, \
    _______, _______, _______, _______,                             _______,                                          _______, _______, _______, _______  \
*/
