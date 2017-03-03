#include "ergodox.h"
#include "led.h"
#include "debug.h"
#include "action_layer.h"
#include "action_util.h"

/*#include <keymap_workman.h>*/

#ifdef SUBPROJECT_infinity
#include "visualizer/lcd_backlight.h"
#endif

#define BASE 0 // default layer
#define FNMM 1 // function mouse and media keys
#define NAV 2

/*//Tap Dance Declarations                                                  */
/*enum {                                                                    */
/*  TD_ESC_CAPS = 0                                                         */
/*};                                                                        */

/*//Tap Dance Definitions                                                   */
/*qk_tap_dance_action_t tap_dance_actions[] = {                             */
/*  //Tap once for Esc, twice for Caps Lock                                 */
/*  [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)               */
/*// Other declarations would go here, separated by commas, if you have them*/
/*};                                                                        */

/*//In Layer declaration, add tap dance item in place of a key code         */
/*[>TD(TD_ESC_CAPS)<]                                                       */

const uint16_t PROGMEM fn_actions[] = {
    ACTION_LAYER_TAP_KEY(FNMM, KC_GRV),          // FN0 - Momentary Layer 1 or tap for grave/tilde
    ACTION_LAYER_TAP_TOGGLE(FNMM),               // FN1 - Momentary Layer 1 or tap to toggle
    ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),       // FN2 - Control key if held, Esc key if tapped
    ACTION_BACKLIGHT_INCREASE(),                 // FN3
    ACTION_BACKLIGHT_DECREASE(),                 // FN4

    ACTION_MODS_TAP_KEY(MOD_LGUI, KC_BSPC),
    ACTION_MODS_TAP_KEY(MOD_LALT, KC_DEL),
    ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),

    ACTION_MODS_TAP_KEY(MOD_RGUI, KC_SPC),
    ACTION_MODS_TAP_KEY(MOD_RALT, KC_ENT),
    /*ACTION_LAYER_TAP_KEY(NAV, KC_LEAD),*/
    ACTION_LAYER_TAP_TOGGLE(NAV),

    ACTION_MODS_TAP_KEY(MOD_LSFT, KC_LBRC),
    ACTION_MODS_TAP_KEY(MOD_RSFT, KC_RBRC),

    ACTION_MODS_TAP_KEY(MOD_LGUI, KC_ESC),
    ACTION_MODS_TAP_KEY(MOD_LCTL, KC_TAB),

    /*ACTION_MODS_KEY(MOD_LCTL | MOD_LGUI, KC_F4),    // FN6  - close current virtual desktop*/
    /*ACTION_MODS_KEY(MOD_LCTL | MOD_LGUI, KC_D),     // FN7  - create new virtual desktop   */
    /*ACTION_MODS_KEY(MOD_LGUI, KC_TAB),              // FN8  - enter task view              */
    /*ACTION_MODS_KEY(MOD_LCTL | MOD_LGUI, KC_LEFT),  // FN9  - Switch virtual desktop left  */
    /*ACTION_MODS_KEY(MOD_LCTL | MOD_LGUI, KC_RGHT),  // FN10 - Switch virtual desktop right */
};

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
    KC_FN0,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
    KC_FN14,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LEFT,
    KC_FN13,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    KC_FN12, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_RGHT,
    KC_FN1,  KC_LGUI, KC_LALT, KC_LALT, KC_LCTL,
    KC_HOME, KC_END,
    KC_DEL,
    KC_FN5,  KC_FN6, KC_FN7,
    // right hand
    KC_FN0,   KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,  KC_BSLS,
    KC_UP,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_DOWN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_FN11,
    KC_FN10, KC_RPRN, KC_LPRN, KC_RPRN, KC_RCTL,
    KC_PGUP, KC_END,
    KC_PGDN,
    KC_FN10, KC_FN9, KC_FN8
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
       RESET, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_HOME,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END,
       KC_TRNS, KC_TRNS, KC_AT,   KC_EXLM, KC_TRNS,
                                           KC_FN3, KC_FN4,
                                                    KC_TRNS,
                                  KC_BTN1, KC_BTN2, KC_SLCK,
    // right hand
       RESET,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
       KC_PGUP, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE, KC_MPLY,
                KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
       KC_PGDN,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_UP,   KC_TRNS,
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
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
    ),

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    lcd_backlight_hal_init();
};

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
            lcd_backlight_hal_color(1000, 1000, 5000);
        #endif
        break;

    case NAV:
        ergodox_right_led_2_on(); // green

        ergodox_board_led_off();
        ergodox_right_led_1_off();
        ergodox_right_led_3_off();
        #ifdef SUBPROJECT_infinity
            lcd_backlight_hal_color(0, 5000, 0);
        #endif
        break;

    case 3:
        ergodox_right_led_1_on(); // red
        break;

    default:
        // none
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
