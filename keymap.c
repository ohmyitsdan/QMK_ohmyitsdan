/* Copyright 2015-2017 Jack Humbert
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
#include "keymap_uk.h"

enum planck_layers {
    _QWERTY,
    _WORK,
    _COLEMAK,
    _COLEMAKDH,
    _DVORAK,
    _GAME,
    _LOWER,
    _RAISE,
    _PLOVER,
    _ADJUST
};

enum planck_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    COLEMAKDH,
    GAME,
    DVORAK,
    PLOVER,
    LOWER,
    RAISE,
    BACKLIT,
    WORK,
    EXT_PLV
};

enum custom_macros { ALTF4 };

enum tap_dance {
    TD_DEL_ESC,
    TD_PIPE_BS,
    TD_PRN,
    TD_CBR,
    TD_BRC
};

// #define UK_PIPE S(KC_NUBS) // |
// #define UK_SLSH KC_SLSH    // /

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_PIPE_BS] = ACTION_TAP_DANCE_DOUBLE(UK_PIPE, KC_NUBS),
    [TD_PRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_CBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_BRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Del  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |   |  | GUI  |  Alt |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_planck_mit(
        KC_TAB,  KC_Q,           KC_W,    KC_E,    KC_R,   KC_T,  KC_Y,  KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_DEL,  KC_A,           KC_S,    KC_D,    KC_F,   KC_G,  KC_H,  KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,           KC_X,    KC_C,    KC_V,   KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, TD(TD_PIPE_BS), KC_LGUI, KC_LALT, LOWER,     KC_SPC,    RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT),
    
    /* WORK
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Del  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |   |  | GUI  |  Alt |Lower |    Space    |Raise |   =  |   _  |   -  |  +   |
     * `-----------------------------------------------------------------------------------'
     */
    [_WORK] = LAYOUT_planck_mit(
        KC_TAB,  KC_Q,           KC_W,    KC_E,    KC_R,   KC_T,  KC_Y,  KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_DEL,  KC_A,           KC_S,    KC_D,    KC_F,   KC_G,  KC_H,  KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,           KC_X,    KC_C,    KC_V,   KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, TD(TD_PIPE_BS), KC_LGUI, KC_LALT, LOWER,     KC_SPC,    RAISE, KC_UNDS, KC_EQL,  KC_MINS, KC_PLUS),

    /* Colemak
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Del  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |   \  | GUI  |  Alt |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_planck_mit(KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC, KC_DEL, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_LCTL, KC_NUBS, KC_LGUI, KC_LALT, LOWER, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
    /* Colemak DH
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Del  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  "   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |   \  | GUI  |  Alt |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAKDH] = LAYOUT_planck_mit(
        KC_TAB,  KC_Q,           KC_W,    KC_F,    KC_P,  KC_B, KC_J, KC_L,  KC_U,    KC_Y,    KC_SCLN,  KC_BSPC,
        KC_DEL,  KC_A,           KC_R,    KC_S,    KC_T,  KC_G, KC_M, KC_N,  KC_E,    KC_I,    KC_O,     KC_QUOT,
        KC_LSFT, KC_Z,           KC_X,    KC_C,    KC_D,  KC_V, KC_K, KC_H,  KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT,
        KC_LCTL, TD(TD_PIPE_BS), KC_LGUI, KC_LALT, LOWER,    KC_SPC,  RAISE, KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT
        ),

    /* Dvorak
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Del  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |   \  | GUI  |  Alt |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_DVORAK] = LAYOUT_planck_mit(
        KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSPC,
        KC_DEL, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_SLSH,
        KC_LSFT, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_ENT,
        KC_LCTL, KC_NUBS, KC_LGUI, KC_LALT, LOWER, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),

    /* Game
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Del  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |   |  | GUI  |  Alt |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */

    [_GAME] = LAYOUT_planck_mit(
        KC_TAB,  KC_Q,           KC_W,    KC_E,    KC_R,   KC_T,  KC_Y,  KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_DEL,  KC_A,           KC_S,    KC_D,    KC_F,   KC_G,  KC_H,  KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,           KC_X,    KC_C,    KC_V,   KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, TD(TD_PIPE_BS), KC_LGUI, KC_LALT, RAISE,     KC_SPC,    LOWER, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   £  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Esc  |   `  |Pg Up | Home |      |   ~  |   |  |   -  |   +  |   {  |   }  |   ~  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |Shift |ALTF4 |Pg Dn | End  |      |      |      |   _  |   =  |   [  |   ]  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |      |      |      |      |             |      |  Up  | Down | Left | Right|
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_planck_mit(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC,    KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        KC_ESC,  KC_GRV,  KC_PGUP, KC_HOME, _______, S(KC_NUHS), S(KC_NUBS), KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
        KC_LSFT, ALTF4,   KC_PGDN, KC_END,  _______, _______,    UK_HASH,    KC_UNDS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
        KC_LCTL, _______, _______, _______, _______,        _______,         _______, KC_DOWN, KC_UP,KC_LEFT,  KC_RGHT),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   4  |      |   6  |      |  \   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |Shift |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |   .  |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_mit(
        KC_GRV,  KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_ESC,
        KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_F5, KC_F6, KC_KP_4, _______, KC_KP_6, _______, KC_BSLS,
        KC_LSFT, KC_F7,   KC_F8,   KC_F9, KC_F10, KC_F11, KC_F12, _______, _______, KC_DOT, _______, _______,
        KC_LCTL, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
        ),

    /* Plover layer (http://opensteno.org)
     * ,-----------------------------------------------------------------------------------.
     * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */

    [_PLOVER] = LAYOUT_planck_mit(KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, XXXXXXX, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, XXXXXXX, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, EXT_PLV, XXXXXXX, XXXXXXX, KC_C, KC_V, XXXXXXX, KC_N, KC_M, XXXXXXX, XXXXXXX, XXXXXXX),

    /* Adjust (Lower + Raise)
     * ,-----------------------------------------------------------------------------------.
     * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof| Game | Work |CmakDH|      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_mit(
        _______, RESET,   DEBUG,  RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,
        KC_ESC,  KC_ESC,  MU_MOD, AU_ON, AU_OFF, AG_NORM, AG_SWAP, QWERTY, COLEMAK, DVORAK, PLOVER, _______,
        _______, MUV_DE,  MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, GAME, WORK, COLEMAKDH, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)

};

#ifdef AUDIO_ENABLE
float plover_song[][2] = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
    case QWERTY:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
        }
        return false;
        break;

    case COLEMAK:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
        }
        return false;
        break;

    case WORK:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_WORK);
        }
        return false;
        break;

    case COLEMAKDH:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAKDH);
        }
        return false;
        break;

    case DVORAK:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
        }
        return false;
        break;

    case LOWER:
        if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        return false;
        break;

    case RAISE:
        if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        return false;
        break;

    case BACKLIT:
        if (record->event.pressed) {
            register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
            backlight_step();
#endif
        }
        else {
            unregister_code(KC_RSFT);
        }
        return false;
        break;

    case PLOVER:
        if (record->event.pressed) {
#ifdef AUDIO_ENABLE
            stop_all_notes();
            PLAY_SONG(plover_song);
#endif
            layer_off(_RAISE);
            layer_off(_LOWER);
            layer_off(_ADJUST);
            layer_on(_PLOVER);
            if (!eeconfig_is_enabled()) {
                eeconfig_init();
            }
            keymap_config.raw = eeconfig_read_keymap();
            keymap_config.nkro = 1;
            eeconfig_update_keymap(keymap_config.raw);
        }
        return false;
        break;

    case EXT_PLV:
        if (record->event.pressed) {
#ifdef AUDIO_ENABLE
            PLAY_SONG(plover_gb_song);
#endif
            layer_off(_PLOVER);
        }
        return false;
        break;

    case ALTF4:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT(SS_TAP(X_F4)));
        }
        return false;
        break;
    }
    return true;
}
