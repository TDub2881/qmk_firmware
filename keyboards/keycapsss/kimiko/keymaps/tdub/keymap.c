/* Copyright 2019 Leo Batyuk
 * Copyright 2020 Drashna Jaelre <@drashna>
 * Copyright 2020 @ben_roe (keycapsss.com)
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

/**
enum custom_keycodes {
    ULT_ALT = SAFE_RANGE,
    ULT_WIN,
    ULT_CTRL,
    UML_A,
    UML_U,
    UML_O,
    MAC_TOGGLE,
};
**/

const key_override_t shft_spc_override = ko_make_basic(MOD_MASK_SHIFT, KC_SPACE, KC_TAB);
const key_override_t shft_ent_override = ko_make_basic(MOD_MASK_SHIFT, KC_ENT, KC_LALT);
const key_override_t shft_comm_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCOLON);
const key_override_t shft_dot_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLON);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &shft_spc_override,
    &shft_ent_override,
    &shft_comm_override,
    &shft_dot_override,
    NULL // Null terminate the array of overrides!
};
/**
const uint16_t PROGMEM shft_spc_to_tab[] = {KC_RSFT, KC_SPC, COMBO_END};
const uint16_t PROGMEM shft_spc_ent_to_alt_tab[] = {KC_RSFT, KC_SPC, KC_ENT, COMBO_END};
const uint16_t PROGMEM shft_comm_to_scolon[] = {KC_RSFT, KC_COMM, COMBO_END};
const uint16_t PROGMEM shft_dot_to_colon[] = {KC_LSFT, KC_DOT, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(shft_spc_to_tab, KC_TAB),
    COMBO(shft_spc_ent_to_alt_tab, LALT(KC_TAB)), // keycodes with modifiers are possible too!
    COMBO(shft_comm_to_scolon, KC_SCOLON),
    COMBO(shft_dot_to_colon, KC_COLON),
};
**/



enum layers {
    _QWERTY,
    _ARROWS,
    _LOWER,
    _MAC,
    _MAC_ARROWS
 //   _RAISE,
 //   _ADJUST,
};

#define QWERTY DF(_QWERTY)
#define ARROWS MO(_ARROWS)
//#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define MAC DF(_MAC)
#define MARROWS MO(_MAC_ARROWS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,--------------------------------------------.                    ,----------------------------------------------.
 * |   WIN   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  BSP      |
 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
 * |   Tab   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  RCTR     |
 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
 * |  LShift |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '        |
 * |---------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+-----------|
 * |  LCTRL  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | RShift    |
 * `-------------------------------------------|       /     \      \-----------------------------------------------'
 *                 | LALT| LGUI | ESC |LOWER|   Space /       \Enter \ |RAISE |BackSP| RGUI | RALT |
 *                 `----------------------------------'       '------------------------------------'
 */

 [_QWERTY] = LAYOUT(
    KC_LGUI,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_LCTL,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RCTL,
    ARROWS,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_RSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,   KC_LBRC,    KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
                      KC_LALT, KC_LGUI, KC_ESC, LOWER,   KC_SPC,     KC_SPC,   ARROWS,   KC_RCTL, KC_RGUI, KC_RALT
),
/* ARROWS
 * ,-------------------------------------------.                    ,-----------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | DEL  |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |        |      | HOME |  UP  |  END | PGUP |                    |      |      |      |      |      |      |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |        |      | LEFT | DOWN | RIGHT| PGDN |-------.    ,-------|      |      |      |      |      |      |
 * |--------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |        |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-------------------------------------------|       /     \      \-----------------------------------------------'
 *                 | LCTRL| LGUI | LALT |LOWER| Space /       \Enter \  |RAISE |BackSP| RGUI | RALT |
 *                 `----------------------------------'       '------------------------------------'
 */

[_ARROWS] = LAYOUT(
    _______,   KC_F1,  KC_F2,    KC_F3,   KC_F4,    KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DELETE,
    _______, XXXXXXX,  KC_HOME,  KC_UP,   KC_END,   KC_PGUP,                          KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX,  KC_LEFT,  KC_DOWN, KC_RIGHT, KC_PGDN,                          KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, MAC,      XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, KC_LBRC,        KC_RBRC, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                       _______, _______, _______, _______,   KC_COMM,        KC_DOT,  _______, _______, _______, _______
),
/* LOWER
 * ,-------------------------------------------.                    ,-----------------------------------------.
 * |        |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |        |      |  (   |  {   |  [   |   '  |                    |   "  |   ]  |  }   |  )   |      |      |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |        |  !   |   +  |   =  |   *  |   `  |-------.    ,-------|   ~  |   /  |   _  |   -  |   ?  |      |
 * |--------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |        |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-------------------------------------------|       /     \      \-----------------------------------------------'
 *                 | LCTRL| LGUI | LALT |LOWER| Space /       \Enter \  |RAISE |BackSP| RGUI | RALT |
 *                 `----------------------------------'       '------------------------------------'
 */

[_LOWER] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, XXXXXXX, KC_LPRN, KC_LCBR, KC_LBRC, KC_QUOTE,                  KC_DQUO, KC_RBRC, KC_RCBR, KC_RPRN, XXXXXXX, _______,
    _______, KC_EXLM, KC_PLUS, KC_EQL,  KC_ASTR, KC_GRV,                    KC_TILD, KC_SLSH, KC_UNDS, KC_MINS, KC_QUES, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//),
),
/* MAC
 * ,--------------------------------------------.                    ,----------------------------------------------.
 * |   WIN   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  BSP      |
 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
 * |   Tab   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  RCTR     |
 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
 * |  LShift |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '        |
 * |---------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+-----------|
 * |  LCTRL  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | RShift    |
 * `-------------------------------------------|       /     \      \-----------------------------------------------'
 *                 | LALT| LGUI | ESC |LOWER|   Space /       \Enter \ |RAISE |BackSP| RGUI | RALT |
 *                 `----------------------------------'       '------------------------------------'
 */

 [_MAC] = LAYOUT(
    KC_LALT,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_LGUI,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RGUI,
    MARROWS,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_RSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,   KC_LBRC,    KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
                      KC_LCTL, KC_LGUI, KC_ESC, LOWER,   KC_SPC,     KC_SPC,   ARROWS,   KC_RALT, KC_RGUI, KC_RCTL
),
/* MAC
 * ,--------------------------------------------.                    ,----------------------------------------------.
 * |   WIN   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  BSP      |
 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
 * |   Tab   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  RCTR     |
 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
 * |  LShift |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '        |
 * |---------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+-----------|
 * |  LCTRL  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | RShift    |
 * `-------------------------------------------|       /     \      \-----------------------------------------------'
 *                 | LALT| LGUI | ESC |LOWER|   Space /       \Enter \ |RAISE |BackSP| RGUI | RALT |
 *                 `----------------------------------'       '------------------------------------'
 */

[_MAC_ARROWS] = LAYOUT(
    _______,   KC_F1,  KC_F2,    KC_F3,   KC_F4,    KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DELETE,
    _______, XXXXXXX,LGUI(KC_HOME),KC_UP,LGUI(KC_END),LGUI(KC_PGUP),                  KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, KC_LEFT,  KC_DOWN, KC_RIGHT, LGUI(KC_PGDN),                    KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, QWERTY,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, KC_LBRC,        KC_RBRC, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                       _______, _______, _______, _______,   KC_COMM,        KC_DOT,  _______, _______, _______, _______
)



/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                 | LCTRL| LGUI | LALT |LOWER| Space /       \Enter \  |RAISE |BackSP| RGUI | RALT |
 *                 `----------------------------------'       '------------------------------------'


[_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                       XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                      _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______
),
 */
/* ADJUST (Press LOWER and RAISE together)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |RESET |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGB ON| HUE+ | SAT+ | VAL+ |      |      |                    | PREV | PLAY | NEXT |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | MODE | HUE- | SAT- | VAL- |      |      |-------.    ,-------| VOL+ | MUTE | VOL- |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                 |LCTRL| LGUI | LALT |LOWER| Space /       \Enter \  |RAISE |BackSP| RGUI | RALT |
 *                 `----------------------------------'       '------------------------------------'


[_ADJUST] = LAYOUT(
    RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                   KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX,
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                   KC_VOLU, KC_MUTE, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______
  )
  */
};

/**
layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}
*/
/**
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ULT_ALT:
      if (record->event.pressed) {
        // Do something when pressed
      } else {
        // Do something else when release
      }
      return false; // Skip all further processing of this key
    case KC_ENTER:
      // Play a tone when enter is pressed
      if (record->event.pressed) {
        PLAY_SONG(tone_qwerty);
      }
      return true; // Let QMK send the enter press/release events
    default:
      return true; // Process all other keycodes normally
  }
}**/

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_270;
    }
}

void render_space(void) {
    oled_write_P(PSTR("     "), false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_logo(void) {
    static const char PROGMEM corne_logo[] = {
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0};
    oled_write_P(corne_logo, false);
    // oled_write_P(PSTR("Kimiko"), false);
}

void render_layer_state(void) {
    static const char PROGMEM default_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
        /**
    static const char PROGMEM raise_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
        */
    static const char PROGMEM lower_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
        /**
    static const char PROGMEM adjust_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbe, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
        */
/**
    if(layer_state_is(_ADJUST)) {
        oled_write_P(adjust_layer, false);
    } else
    */
    if(layer_state_is(_LOWER)) {
        oled_write_P(lower_layer, false);
    }
    /**
    else if(layer_state_is(_RAISE)) {
        oled_write_P(raise_layer, false);
    }*/
    else {
        oled_write_P(default_layer, false);
    }
}

void render_status_main(void) {
    render_space();
    render_space();
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
}

void render_status_secondary(void) {
    render_space();
    render_space();
    render_logo();
    render_space();
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();
    }
}

#endif


#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    // Encoder on master side
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            // If the Default (QWERTY) layer is active
            case _QWERTY:
                // Arrow Up/Down
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
                break;

            case _ARROWS:
                // Cycle through windows
                if (clockwise) {
                    tap_code16(LALT(KC_TAB));
                } else {
                    tap_code16(LSA(KC_TAB));
                }
                break;
            // If the RAISE layer is active
            case _LOWER:
                // Switch browser tabs
                if (clockwise) {
                    tap_code16(LCTL(KC_TAB));
                } else {
                    tap_code16(RCS(KC_TAB));
                }
                break;
            case _MAC:
                // Arrow Up/Down
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
                break;
            case _MAC_ARROWS:
               // Cycle through windows
                if (clockwise) {
                    tap_code16(LALT(KC_TAB));
                } else {
                    tap_code16(LSA(KC_TAB));
                }
                break;
            // If the ADJUST layer is active
            /**
            case _ADJUST:
                // RGB brightness up/down
                if (clockwise) {
                    rgblight_decrease_val(); // tap_code(RGB_VAD);
                } else {
                    rgblight_increase_val(); // tap_code(RGB_VAI);
                }
                break;
                */
        }
    }
    // Encoder on slave side
    else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            // If the Default (QWERTY) layer is active
            case _QWERTY:
                // Scroll by Word
                if (clockwise) {
                    tap_code16(LCTL(KC_RGHT));
                } else {
                    tap_code16(LCTL(KC_LEFT));
                }
                break;

            case _ARROWS:
                //Left/Right
                if (clockwise) {
                    tap_code(KC_RGHT);
                } else {
                    tap_code(KC_LEFT);
                }
                break;
            // If the LOWER layer is active
            case _LOWER:
                // Volume up/down
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case _MAC:
                // Scroll by Word MAC edition
                if (clockwise) {
                    tap_code16(LALT(KC_RGHT));
                } else {
                    tap_code16(LALT(KC_LEFT));
                }
                break;
            case _MAC_ARROWS:
                //Left/Right
                if (clockwise) {
                    tap_code(KC_RGHT);
                } else {
                    tap_code(KC_LEFT);
                }
                break;
            /**
            // If the ADJUST layer is active
            case _ADJUST:
                // RGB hue up/down
                if (clockwise) {
                    // tap_code(RGB_HUI);
                    rgblight_increase_hue();
                } else {
                    // tap_code(RGB_HUD);
                    rgblight_decrease_hue();
                }
                break;
                */
        }
    }
    return true;
}
#endif // ENCODER_ENABLE
