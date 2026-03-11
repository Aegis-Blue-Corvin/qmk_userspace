/**
 * Corvin's custom keymap for the Charybdis Nano (3x5).
 *
 * 4-layer layout based on Miryoku principles:
 *   BASE  - QWERTY with GACS home row mods
 *   FUN   - Function keys (left), German chars + media (right)
 *   NAV   - Numbers (left), navigation (right)
 *   MOUSE - Shifted symbols (left), mouse/scroll (right)
 *
 * Auto-sniping enabled on the MOUSE layer.
 */
#include QMK_KEYBOARD_H

enum layers {
    LAYER_BASE = 0,
    LAYER_FUN,
    LAYER_NAV,
    LAYER_MOUSE,
};

#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_MOUSE

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif

enum custom_keycodes {
    QNR = SAFE_RANGE,
    TSS,
    TXT,
    EXT,
    SRCH,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
    KC_Q,               KC_W,               KC_E,               KC_R,               KC_T,               KC_Y,               KC_U,               KC_I,               KC_O,               KC_P,
    LGUI_T(KC_A),       LALT_T(KC_S),       LCTL_T(KC_D),       LSFT_T(KC_F),       KC_G,               KC_H,               LSFT_T(KC_J),       LCTL_T(KC_K),       LALT_T(KC_L),       LGUI_T(KC_QUOT),
    LT(LAYER_NAV,KC_Z), ALGR_T(KC_X),       KC_C,               KC_V,               KC_B,               KC_N,               KC_M,               KC_COMM,            ALGR_T(KC_DOT),     LT(LAYER_NAV,KC_SLSH),
                    LT(LAYER_FUN,KC_ESC), LT(LAYER_NAV,KC_SPC), LT(LAYER_MOUSE,KC_TAB), LT(LAYER_FUN,KC_ENT), LT(LAYER_NAV,KC_BSPC)
  ),
  [LAYER_FUN] = LAYOUT(
    KC_F12,             KC_F7,              KC_F8,              KC_F9,              KC_PSCR,            KC_LCTL,            RALT(KC_Y),         RALT(KC_Q),         RALT(KC_P),         RALT(KC_S),
    KC_F11,             KC_F4,              KC_F5,              KC_F6,              KC_SCRL,            XXXXXXX,            KC_MPRV,            KC_VOLU,            KC_VOLD,            KC_MNXT,
    KC_F10,             KC_F1,              KC_F2,              KC_F3,              KC_PAUS,            TSS,                QNR,                TXT,                SRCH,               EXT,
                                            KC_ESC,             KC_SPC,             KC_TAB,             KC_MUTE,            KC_DEL
  ),
  [LAYER_NAV] = LAYOUT(
    KC_LBRC,            KC_7,               KC_8,               KC_9,               KC_RBRC,            KC_LCTL,            RALT(KC_Y),         RALT(KC_Q),         RALT(KC_P),         RALT(KC_S),
    KC_SCLN,            KC_4,               KC_5,               KC_6,               KC_EQL,             CW_TOGG,            KC_LEFT,            KC_UP,              KC_DOWN,            KC_RGHT,
    KC_GRV,             KC_1,               KC_2,               KC_3,               KC_BSLS,            KC_INS,             KC_HOME,            KC_PGUP,            KC_PGDN,            KC_END,
                                            KC_LSFT,            KC_0,               KC_MINS,            KC_LCTL,            RCTL(KC_BSPC)
  ),
  [LAYER_MOUSE] = LAYOUT(
    KC_LCBR,            KC_AMPR,            KC_ASTR,            KC_LPRN,            KC_RCBR,            KC_LCTL,            RALT(KC_Y),         RALT(KC_Q),         RALT(KC_P),         RALT(KC_S),
    KC_COLN,            KC_DLR,             KC_PERC,            KC_CIRC,            KC_PLUS,            CW_TOGG,            KC_BTN3,            KC_BTN2,            KC_BTN1,            DRGSCRL,
    KC_TILD,            KC_EXLM,            KC_AT,              KC_HASH,            KC_PIPE,            XXXXXXX,            KC_WH_L,            KC_WH_U,            KC_WH_D,            KC_WH_R,
                                            XXXXXXX,            DRGSCRL,            KC_BTN1,            KC_BTN2,            KC_ENT
  ),
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case QNR:
        if (record->event.pressed) {
            SEND_STRING("qxz15fg");
        }
        break;
    case TSS:
        if (record->event.pressed) {
            SEND_STRING("2TitBpoCBhaietmobar");
        }
        break;
    case TXT:
        if (record->event.pressed) {
            SEND_STRING("= \"= \"\"\" & TEXTVERKETTEN(\"\"\" or = \"\"\"; WAHR;<>) & \"\"\" ");
        }
        break;
    case SRCH:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_TAP(X_S) SS_UP(X_LCTL) SS_UP(X_LALT));
        }
        break;
    case EXT:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_RCTL) SS_DOWN(X_RALT) SS_TAP(X_PAUS) SS_UP(X_RCTL) SS_UP(X_RALT) SS_DELAY(300) SS_TAP(X_DOWN) SS_TAP(X_ENT));
        }
        break;
    }
    return true;
}
