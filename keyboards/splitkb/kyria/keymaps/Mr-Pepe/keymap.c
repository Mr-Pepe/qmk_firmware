/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 */

/* ########### INSTRUCTIONS ###########

- Create venv
- pip install qmk
- qmk compile -kb splitkb/kyria/rev1 -km Mr-Pepe
- sudo qmk flash -kb splitkb/kyria/rev1 -km Mr-Pepe -bl dfu
*/

#include QMK_KEYBOARD_H
#include "process_key_override.h"


enum layers {
    _NEO = 0,
    _ARROWS,
    _WINDOWING,
    _NUMBERS,
    _SYMBOLS,
    _FN
};

enum custom_keycodes {
    OCB = SAFE_RANGE, // open curly brace
    CCB, // close curly brace
    OSB, // open square brace
    CSB, // close square brace
    BS,  // backslash
    TIL, // tilde
    PIP, // pipe
    AT,  // @
    EUR, // €
    SQR, // ²
    QUB, // ³
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  //  * ,-------------------------------------------.                              ,-------------------------------------------.
  //  * |        |   Ü  |  Ö   |   Y  |  P   |  W   |                              |   K  |   H  |  G   |   F  |   Q  |   Ä    |
  //  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  //  * |        |   U  |  I   |   A  |  E   |  O   |                              |   S  |   N  |  R   |   T  |   ,  |   -    |
  //  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  //  * |        |   X  |  V   |   J  |  C   |   Z  |      |      |  |      |      |   B  |   M  |  L   |   D  |   .  |   ß    |
  //  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  //  *                        |      |      |      |      |      |  |      |      |      |      |      |
  //  *                        |      |      |      |      |      |  |      |      |      |      |      |
  //  *                        `----------------------------------'  `----------------------------------'
    [_NEO] = LAYOUT(
      KC_ESC,                KC_LBRC,      KC_SCLN,  KC_Z,           KC_P,       KC_W,                                                                                                   KC_K,       KC_H,       KC_G,    KC_F,    KC_Q,     KC_QUOT,
      KC_TAB,    MT(MOD_LSFT, KC_U),  LT(_SYMBOLS, KC_I),       MT(MOD_LSFT, KC_A),           KC_E,       KC_O,                                                                KC_S,       KC_N, MT(MOD_LSFT, KC_R),    LT(_SYMBOLS, KC_T),    KC_COMM,  KC_SLSH,
      S(KC_TAB), MT(MOD_LCTL, KC_X),  KC_V,   KC_J,   KC_C,   KC_Y,    KC_PSCR,            KC_VOLD,            KC_VOLU,            KC_MPLY,            KC_B,       KC_M,       KC_L, KC_D,  KC_DOT, KC_MINS,
                                                        C(KC_S),        LT(_WINDOWING, KC_LGUI),   MT(MOD_LCTL, KC_ENT),   MT(MOD_LALT, KC_SPC), LT(_FN, KC_ESC),   LT(_FN, KC_ESC), LT(_NUMBERS, KC_SPC), LT(_ARROWS, KC_ENT),     KC_LSFT,    KC_RALT
    ),
    [_ARROWS] = LAYOUT(
      _______, _______, _______, _______, _______,    _______,                                     _______, _______, KC_UP,   _______,    _______,    _______,
      _______, _______, _______, KC_LSFT, KC_LCTL,    _______,                                     KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, _______,
      _______, _______, _______, _______, A(S(KC_C)), _______, _______, _______, _______, _______, _______, KC_BSPC, _______, KC_DEL, _______, _______,
                                 _______, _______,    KC_LCTL, KC_LALT, _______, _______, _______, _______, _______, _______
    ),
    [_WINDOWING] = LAYOUT(
    A(KC_F4), _______, G(KC_Q), G(KC_W), G(KC_E), _______,                                       _______, G(KC_1), G(KC_2), G(KC_3), _______, _______,
      _______, _______, G(KC_A), G(KC_S), G(KC_D), G(KC_G),                                     _______, G(KC_4), G(KC_5), G(KC_6), _______, _______,
      _______, _______, G(KC_R), G(KC_Z), G(KC_X), _______, _______, _______, _______, _______, _______, G(KC_7), G(KC_8), G(KC_9), _______, _______,
                                 _______, _______, G(KC_ENT), _______, _______, _______, _______, _______, _______, _______
    ),
    [_NUMBERS] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, KC_7,    KC_8,    KC_9, _______, _______,
      _______, _______, _______, SQR,     QUB,     _______,                                     KC_0,    KC_4,    KC_5,    KC_6, C(KC_P), A(S(KC_P)),
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3, _______, _______,
                                 _______, _______, KC_LCTL, KC_LALT, _______, _______, _______, _______, _______, _______
    ),
     [_SYMBOLS] = LAYOUT(
      _______, S(KC_GRV), EUR, S(KC_4), S(KC_5), S(KC_6),                                     S(KC_RBRC), OSB,     CSB,     S(KC_0),    KC_NUHS, KC_EQL,
      _______, KC_GRV,    AT, S(KC_1), S(KC_2), S(KC_3),                                     S(KC_7),    S(KC_8), S(KC_9), S(KC_DOT),  S(KC_NUHS), S(KC_EQL),
      _______, _______,   PIP,     KC_NUBS, S(KC_NUBS), _______, _______, _______, _______, _______, BS,         OCB,     CCB,     KC_RBRC,    TIL, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_FN] = LAYOUT(
      _______, KC_F11, KC_F12, _______, _______,    _______,                                                         _______, _______, _______, _______, _______, _______,
      _______, KC_F6,  KC_F7,  KC_F8,   KC_F9,      KC_F10,                                                          _______, _______, KC_LSFT, _______, _______, _______,
      _______, KC_F1,  KC_F2,  KC_F3,   KC_F4,      KC_F5, _______, KC_BRIGHTNESS_DOWN,  KC_BRIGHTNESS_UP,  KC_MUTE, _______, _______, _______, _______, _______, _______,
                                 _______, KC_MPRV,    KC_MNXT, _______, _______,                            _______, _______, _______, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case OCB:
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_7) SS_UP(X_CAPS));
        return false;
        break;
      case CCB:
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_0) SS_UP(X_CAPS));
        return false;
        break;
      case OSB:
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_8) SS_UP(X_CAPS));
        return false;
        break;
      case CSB:
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_9) SS_UP(X_CAPS));
        return false;
        break;
      case BS:
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_MINS) SS_UP(X_CAPS));
        return false;
        break;
      case TIL:
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_RBRC) SS_UP(X_CAPS));
        return false;
        break;
      case PIP:
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_NUBS) SS_UP(X_CAPS));
        return false;
        break;
      case AT:
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_Q) SS_UP(X_CAPS));
        return false;
        break;
      case EUR:
        SEND_STRING(SS_DOWN(X_CAPS) SS_TAP(X_E) SS_UP(X_CAPS));
        return false;
        break;
    }
  }
  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_NUMBERS, KC_SPC):
            return 180;
        case MT(MOD_LCTL, KC_ENT):
            return 180;
        default:
            return TAPPING_TERM;
    }
}


// const key_override_t ctrl_p = ko_make_basic(MOD_MASK_CTRL, KC_F, LCTL(KC_P));
// const key_override_t ctrl_s = ko_make_basic(MOD_MASK_CTRL, KC_A, KC_S);

// // This globally defines all key overrides to be used
// const key_override_t **key_overrides = (const key_override_t *[]){
// 	&ctrl_s,
//   &ctrl_p,
// 	NULL // Null terminate the array of overrides!
// };


// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _ARROWS);
// }

