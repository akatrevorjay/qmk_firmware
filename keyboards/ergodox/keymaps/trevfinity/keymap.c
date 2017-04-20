#include "action_layer.h"
#include "debug.h"
#include "ergodox.h"
#include "version.h"

#include "action_util.h"
#include "led.h"

#include <keymap_workman.h>

#ifdef SUBPROJECT_infinity
#include "visualizer/lcd_backlight.h"
#endif

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here
    EPRM,
    VRSN,
    RGB_SLD
};

enum keymap_consts {
    BASE = 0,
    WM,
    // function mouse and media keys
    FNMM,
    // Navigation
    NAV,
    // Symbols
    SYMB,
    // Media
    MDIA,
    // ErgoDox EZ
    EZ,
    // Default
    DEFAULT,
    KM_NULL,
};

// Tap Dance Declarations
enum {
    TD_ESC_CAPS = 0,
    /*TD_LTOG,*/
};

/*void dance_flsh_each(qk_tap_dance_state_t *state, void *user_data) {*/
/*    uint8_t next_state = state->count;                              */
/*    if (next_state >= KM_NULL) {                                    */
/*        layer_clear();                                              */
/*    } else {                                                        */
/*        layer_switch(next_state);                                   */
/*    }                                                               */
/*}                                                                   */

// Tap Dance Definitions
/*qk_tap_dance_action_t tap_dance_actions[] = {                     */
/*    [>[TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),<]*/
/*    [>[TD_LTOG] = ACTION_LAYER_TAP_TOGGLE<]                       */
/*    [>[TD_BUF_PREV] = ACTION_TAP<]                                */
/*};                                                                */

/*//In Layer declaration, add tap dance item in place of a key code         */
/*[>TD(TD_ESC_CAPS)<]                                                       */

const uint16_t PROGMEM fn_actions[] = {
	[1] = ACTION_LAYER_TAP_KEY(FNMM, KC_GRV), // FN0 - Momentary Layer 1 or tap for grave/tilde
	[2] = ACTION_LAYER_TAP_TOGGLE(FNMM),      // FN1 - Momentary Layer 1 or tap to toggle
	[3] = ACTION_BACKLIGHT_INCREASE(),	// FN3
	[4] = ACTION_BACKLIGHT_DECREASE(),	// FN4

	[5] = ACTION_LAYER_TAP_TOGGLE(SYMB), // FN1 - Momentary Layer 1 (Symbols)

    /*ACTION_MODS_TAP_KEY(MOD_LSFT, KC_LBRC),*/
    /*ACTION_MODS_TAP_KEY(MOD_RSFT, KC_RBRC),*/

    /*ACTION_MODS_TAP_KEY(MOD_LGUI, KC_ESC), */
    /*ACTION_MODS_TAP_KEY(MOD_LCTL, KC_TAB), */

    /*ACTION_LAYER_TAP_TOGGLE(EZ),           */
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Fn `/~ |   1  |   2  |   3  |   4  |   5  |   6  |           |Fn `/~|   7  |   8  |   9  |   0  |  = + |   \ |  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | left |           |  up  |   Y  |   U  |   I  |   O  |   P  |  - _   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  ' "   |
 * |--------+------+------+------+------+------| right|           | down |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  / ? | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Tg Fn |WinCmd|  *   |   &  | Alt  |                                       |   (  |  )   |  [   |   ]  | Ctrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Home | Ins  |       | PgUp |  End   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Del  |       | PgDn |        |      |
 *                                 | Space| Bksp |------|       |------|  Bksp  |Enter |
 *                                 |      |      | Esc  |       | Comp |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
    // left hand
    KC_FN0,         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
    CTL_T(KC_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_DOWN,
    GUI_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    KC_LSFT,    CTL_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,    ALL_T(KC_NO),
    TT(FNMM),       KC_LGUI, KC_LGUI, KC_LALT, KC_LCTL,
    KC_HOME,        KC_END,
    TT(EZ),
    GUI_T(KC_BSPC), ALT_T(KC_DEL),  CTL_T(KC_ESC),
    // right hand
    KC_FN0,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSLS,
    KC_EQL,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_MINS,
    KC_H,           KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    MEH_T(KC_NO),   KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_T(KC_SLSH), KC_RSFT,
    KC_LPRN,        KC_RPRN, KC_LBRC, KC_RBRC, KC_RCTL,
    KC_PGUP,        KC_LEAD,
    KC_PGDN,
    TT(NAV),        ALT_T(KC_ENT), GUI_T(KC_SPC)
),

[WM] = KEYMAP(  // layer 0 : default
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,    WM_Q,    WM_W,    WM_E,    WM_R,    WM_T, KC_TRNS,
    KC_TRNS,    WM_A,    WM_S,    WM_D,    WM_F,    WM_G,
    KC_TRNS,    WM_Z,    WM_X,    WM_C,    WM_V,    WM_B, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,    WM_Y,    WM_U,    WM_I,    WM_O, KC_P, KC_TRNS,
       WM_H,    WM_J,    WM_K,    WM_K,    WM_SCLN, WM_QUOT,
    KC_TRNS,    WM_N,    WM_M, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_COMM, KC_DOT, KC_SLSH,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Function, media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  euro  |  F1  |  F2  |  F3  |  F4  |  F5  | euro |           |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

// FUNCTION MEDIA AND MOUSE
[FNMM] = KEYMAP(
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_HOME,
    KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_END,
    KC_TRNS, KC_TRNS, KC_AT, KC_EXLM, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
    RESET,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
    KC_PGUP, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE, KC_MPLY,
    KC_TRNS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_TRNS,
    KC_PGDN, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_UP, KC_TRNS,
    KC_BTN1, KC_BTN2, KC_LEFT, KC_DOWN, KC_RGHT,
    KC_PSCR, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
),

[NAV] = KEYMAP(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_PGUP, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
          EPRM,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       RGB_MOD,KC_TRNS,
                                               KC_TRNS,
                               RGB_VAD,RGB_VAI,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_TRNS, RGB_HUD, RGB_HUI
),

/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),

/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `/~  |   1  |   2  |   3  |   4  |   5  |   up |           |  down|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | |\     |   Q  |   W  |   F  |   P  |   G  |  L1  |           |  L1  |   J  |   L  |   U  |   Y  |; / L2|   +    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  |   '"   |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |   (  |  )   |  [   |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[EZ] = KEYMAP(  // layer 0 : default
    // left hand
    KC_GRV,        KC_1, KC_2, KC_3, KC_4, KC_5, KC_UP,
    KC_BSLS,       KC_Q, KC_W, KC_F, KC_P, KC_G, KC_TRNS,
    CTL_T(KC_ESC), KC_A, KC_R, KC_S, KC_T, KC_D,
    KC_LSFT,       KC_Z, KC_X, KC_C, KC_V, KC_B, ALL_T(KC_NO),
    KC_FN1,        KC_LGUI, KC_LEFT, KC_RGHT, KC_TRNS,
    KC_HOME,       KC_INS,
    KC_DEL,
    KC_SPC,        KC_BSPC, KC_LALT,
    // right hand
    KC_DOWN,       KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL,
    KC_TRNS,       KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_MINS,
    KC_H,          KC_N, KC_E, KC_I, KC_O, KC_QUOT,
    MEH_T(KC_NO),  KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_LPRN,       KC_RPRN, KC_LBRC, KC_RBRC, KC_FN1,
    KC_PGUP,       KC_END,
    KC_PGDN,
    KC_RALT,       KC_TAB, KC_ENT
),

/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[DEFAULT] = KEYMAP(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,
        KC_DELT,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(SYMB),
        KC_BSPC,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        CTL_T(KC_Z),  KC_X,   KC_C,   KC_V,   KC_B,   ALL_T(KC_NO),
        LT(SYMB,KC_GRV),KC_QUOT,      LALT(KC_LSFT),  KC_LEFT,KC_RGHT,
                                              ALT_T(KC_APP),  KC_LGUI,
                                                              KC_HOME,
                                               KC_SPC,KC_BSPC,KC_END,
        // right hand
             KC_RGHT,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(SYMB),    KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLS,
                          KC_H,   KC_J,  KC_K,   KC_L,   LT(MDIA, KC_SCLN),GUI_T(KC_QUOT),
             MEH_T(KC_NO),KC_N,   KC_M,  KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
                                  KC_UP, KC_DOWN,KC_LBRC,KC_RBRC,          KC_FN1,
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_TAB, KC_ENT
    ),

};
// clang-format on

/*const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)*/
/*{                                                                            */
/*  // MACRODOWN only works in this function                                   */
/*      switch(id) {                                                           */
/*        case 0:                                                              */
/*        if (record->event.pressed) {                                         */
/*          register_code(KC_RSFT);                                            */
/*        } else {                                                             */
/*          unregister_code(KC_RSFT);                                          */
/*        }                                                                    */
/*        break;                                                               */
/*      }                                                                      */
/*    return MACRO_NONE;                                                       */
/*};                                                                           */

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    // MACRODOWN only works in this function
    switch (id) {
    case 0:
	if (record->event.pressed) {
	    SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
	}
	break;
    case 1:
	if (record->event.pressed) { // For resetting EEPROM
	    eeconfig_init();
	}
	break;
    }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    // dynamically generate these.
    case EPRM:
	if (record->event.pressed) {
	    eeconfig_init();
	}
	return false;
	break;
    case VRSN:
	if (record->event.pressed) {
	    SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
	}
	return false;
	break;
    case RGB_SLD:
	if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
	    rgblight_mode(1);
#endif
	}
	return false;
	break;
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) { lcd_backlight_hal_init(); };

LEADER_EXTERNS();

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    switch (layer) {
    case BASE:
	ergodox_board_led_off();
	ergodox_right_led_1_off();
	ergodox_right_led_2_off();
	ergodox_right_led_3_off();
#ifdef SUBPROJECT_infinity
	lcd_backlight_hal_color(5000, 5000, 5000);
#endif
	break;

    case FNMM:
	ergodox_right_led_3_on(); // blue

	ergodox_board_led_off();
	ergodox_right_led_2_off();
	ergodox_right_led_3_off();
#ifdef SUBPROJECT_infinity
	lcd_backlight_hal_color(2500, 1000, 5000);
#endif
	break;

    case NAV:
	ergodox_right_led_2_on(); // green

	ergodox_board_led_off();
	ergodox_right_led_1_off();
	ergodox_right_led_3_off();
#ifdef SUBPROJECT_infinity
	lcd_backlight_hal_color(0, 5000, 1000);
#endif
	break;

    case EZ:
	ergodox_right_led_1_on(); // red

	ergodox_board_led_off();
	ergodox_right_led_2_off();
	ergodox_right_led_3_off();
#ifdef SUBPROJECT_infinity
	lcd_backlight_hal_color(5000, 2500, 2500);
#endif
	break;

    case WM:
	ergodox_board_led_off();
	ergodox_right_led_1_off();
	ergodox_right_led_2_off();
	ergodox_right_led_3_off();
#ifdef SUBPROJECT_infinity
	lcd_backlight_hal_color(5000, 2500, 2500);
#endif
	break;

    case SYMB:
	ergodox_right_led_1_on();

	ergodox_board_led_off();
	ergodox_right_led_2_off();
	ergodox_right_led_3_off();

#ifdef SUBPROJECT_infinity
	lcd_backlight_hal_color(5000, 0, 0);
#endif
	break;

    case DEFAULT:
	ergodox_right_led_2_on();

	ergodox_board_led_off();
	ergodox_right_led_1_off();
	ergodox_right_led_3_off();

#ifdef SUBPROJECT_infinity
	/*lcd_backlight_hal_color(0, 5000, 0);*/
	lcd_backlight_hal_color(0, 0, 0);
#endif
	break;

    default:
	// none
	ergodox_board_led_on();

	ergodox_right_led_1_off();
	ergodox_right_led_2_off();
	ergodox_right_led_3_off();
#ifdef SUBPROJECT_infinity
	lcd_backlight_hal_color(0, 5000, 0);
#endif
	break;
    }

    // Leader is KC_LEAD
    LEADER_DICTIONARY() {
	leading = false;
	leader_end();

	SEQ_ONE_KEY(KC_F) {
	    register_code(KC_S);
	    unregister_code(KC_S);
	}
	SEQ_TWO_KEYS(KC_A, KC_S) {
	    register_code(KC_H);
	    unregister_code(KC_H);
	}
	SEQ_THREE_KEYS(KC_A, KC_S, KC_D) {
	    register_code(KC_LGUI);
	    register_code(KC_S);
	    unregister_code(KC_S);
	    unregister_code(KC_LGUI);
	}
    }
};

/*// Runs constantly in the background, in a loop.    */
/*void matrix_scan_user(void) {                       */

/*    uint8_t layer = biton32(layer_state);           */

/*    ergodox_board_led_off();                        */
/*    ergodox_right_led_1_off();                      */
/*    ergodox_right_led_2_off();                      */
/*    ergodox_right_led_3_off();                      */
/*    switch (layer) {                                */
/*      // TODO: Make this relevant to the ErgoDox EZ.*/
/*        case 1:                                     */
/*            ergodox_right_led_1_on();               */
/*            break;                                  */
/*        case 2:                                     */
/*            ergodox_right_led_2_on();               */
/*            break;                                  */
/*        default:                                    */
/*            // none                                 */
/*            break;                                  */
/*    }                                               */

/*};                                                  */
