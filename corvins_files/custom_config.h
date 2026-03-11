// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

//#undef MASTER_RIGHT 
//#define MASTER_LEFT
#define POINTING_DEVICE_RIGHT

#define MIRYOKU_LAYER_LIST \
MIRYOKU_X(BASE,   "Base") \
MIRYOKU_X(FUN,    "Fun") \
MIRYOKU_X(NAV,    "Nav") \
MIRYOKU_X(MOUSE,  "Mouse") 

#define U_BUTTON U_NAV
#define U_MEDIA U_FUN
#define U_NUM U_NAV
#define U_SYM U_MOUSE
#define U_EXTRA U_NAV
#define U_TAP U NAV




#define MIRYOKU_LAYER_BASE \
KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,              \
LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      KC_G,              KC_H,              LSFT_T(KC_J),      LCTL_T(KC_K),      LALT_T(KC_L),      LGUI_T(KC_QUOT),   \
LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_SLSH),\
U_NP,              U_NP,              LT(U_FUN,KC_ESC),  LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_FUN,KC_ENT),  LT(U_NAV,KC_BSPC), U_NP,              U_NP,              U_NP





#define MIRYOKU_LAYER_FUN \
KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,           KC_LCTL,           RALT(KC_Y),        RALT(KC_Q),        RALT(KC_P),        RALT(KC_S),        \
KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SCRL,           U_NU,              KC_MPRV,           KC_VOLU,           KC_VOLD,           KC_MNXT,           \
KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,           TSS,               QNR,               TXT,               SRCH,              EXT,               \
U_NP,              U_NP,              KC_ESC,            KC_SPC,            KC_TAB,            KC_MUTE,           KC_DEL,            U_NP,              U_NP,              U_NP




#define MIRYOKU_LAYER_NAV \
KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,           KC_LCTL,           RALT(KC_Y),        RALT(KC_Q),        RALT(KC_P),        RALT(KC_S),        \
KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_EQL,            CW_TOGG,           KC_LEFT,           KC_UP,             KC_DOWN,           KC_RGHT,           \
KC_GRV,            KC_1,              KC_2,              KC_3,              KC_BSLS,           KC_INS,            KC_HOME,           KC_PGUP,           KC_PGDN,           KC_END,            \
U_NP,              U_NP,              KC_LSFT,           KC_0,              KC_MINS,           KC_LCTL,           RCTL(KC_BSPC),     U_NP,              U_NP,              U_NP	




#define MIRYOKU_LAYER_MOUSE \
KC_LCBR,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_RCBR,           KC_LCTL,           RALT(KC_Y),        RALT(KC_Q),        RALT(KC_P),        RALT(KC_S),        \
KC_COLN,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_PLUS,           CW_TOGG,           KC_BTN3,           KC_BTN2,           KC_BTN1,           DRGSCRL,           \
KC_TILD,           KC_EXLM,           KC_AT,             KC_HASH,           KC_PIPE,           U_NU,              KC_WH_L,           KC_WH_U,           KC_WH_D,           KC_WH_R,           \
U_NP,              U_NP,              U_NU,              DRGSCRL,           KC_BTN1,           KC_BTN2,           KC_ENT,           U_NP,              U_NP,              U_NP


#define BILATERAL_COMBINATIONS 500



/* QMK */
#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT /* for rolling on mod-tap keys */

/* Miryoku */
#define BILATERAL_COMBINATIONS_LIMIT_CHORD_TO_N_KEYS 4 /* GUI, Alt, Ctrl, Shift */
#define BILATERAL_COMBINATIONS_DELAY_MODS_THAT_MATCH MOD_MASK_GUI
#define BILATERAL_COMBINATIONS_DELAY_MATCHED_MODS_BY 120  /* ms */
#define BILATERAL_COMBINATIONS_ALLOW_CROSSOVER_AFTER 80   /* ms */
#define BILATERAL_COMBINATIONS_ALLOW_SAMESIDED_AFTER 3000 /* ms */
#define BILATERAL_COMBINATIONS_TYPING_STREAK_TIMEOUT 160  /* ms */
#define BILATERAL_COMBINATIONS_TYPING_STREAK_MODMASK (~MOD_MASK_SHIFT)




