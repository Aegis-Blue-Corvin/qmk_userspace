// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H


#define CHARYBDIS_AUTO_SNIPING_ON_LAYER 3 //Mouse Layer


#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER


enum custom_keycodes {
    QNR = SAFE_RANGE,
    TSS,
    TXT,
    EXT,
    SRCH,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case QNR:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("qxz15fg");
        } else {
            // when keycode QMKBEST is released
        }
        break;
	case TSS:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("2TitBpoCBhaietmobar");
        } else {
            // when keycode QMKBEST is released
        }
        break;
	case TXT:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("= \"= \"\"\" & TEXTVERKETTEN(\"\"\" or = \"\"\"; WAHR;<>) & \"\"\" ");
        } else {
            // when keycode QMKBEST is released
        }
        break;
	case SRCH:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_TAP(X_S) SS_UP(X_LCTL) SS_UP(X_LALT));
        } else {
            // when keycode QMKBEST is released
        }
        break;
	case EXT:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING(SS_DOWN(X_RCTL) SS_DOWN(X_RALT) SS_TAP(X_PAUS) SS_UP(X_RCTL) SS_UP(X_RALT) SS_DELAY(300) SS_TAP(X_DOWN) SS_TAP(X_ENT));
        } else {
            // when keycode QMKBEST is released
        }
        break;

    }
    return true;
};