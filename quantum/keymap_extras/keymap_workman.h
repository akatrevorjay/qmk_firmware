#ifndef KEYMAP_WORKMAN_H
#define KEYMAP_WORKMAN_H

#include "keymap.h"
// For software implementation of workman
#define WM_Q    KC_Q
#define WM_D    KC_W
#define WM_R    KC_E
#define WM_W    KC_R
#define WM_B    KC_T
#define WM_J    KC_Y
#define WM_F    KC_U
#define WM_U    KC_I
#define WM_P    KC_O
#define WM_SCLN KC_P

#define WM_A    KC_A
#define WM_S    KC_S
#define WM_H    KC_D
#define WM_T    KC_F
#define WM_G    KC_G
#define WM_Y    KC_H
#define WM_N    KC_J
#define WM_E    KC_K
#define WM_O    KC_L
#define WM_I    KC_SCLN
#define WM_QUOT KC_QUOT

#define WM_Z    KC_Z
#define WM_X    KC_X
#define WM_M    KC_C
#define WM_C    KC_V
#define WM_V    KC_B
#define WM_K    KC_N
#define WM_L    KC_M
#define WM_COMM KC_COMM
#define WM_DOT  KC_DOT
#define WM_SLSH KC_SLSH

// Make it easy to support these in macros
// TODO: change macro implementation so these aren't needed
#define KC_WM_Q    WM_Q
#define KC_WM_W    WM_W
#define KC_WM_E    WM_E
#define KC_WM_R    WM_R
#define KC_WM_T    WM_T
#define KC_WM_Y    WM_Y
#define KC_WM_U    WM_U
#define KC_WM_I    WM_I
#define KC_WM_O    WM_O
#define KC_WM_P    WM_P

#define KC_WM_A    WM_A
#define KC_WM_S    WM_S
#define KC_WM_D    WM_D
#define KC_WM_F    WM_F
#define KC_WM_G    WM_G
#define KC_WM_H    WM_H
#define KC_WM_J    WM_J
#define KC_WM_K    WM_K
#define KC_WM_L    WM_L
#define KC_WM_SCLN WM_SCLN
#define KC_WM_QUOT WM_QUOT

#define KC_WM_Z    WM_Z
#define KC_WM_X    WM_X
#define KC_WM_C    WM_C
#define KC_WM_V    WM_V
#define KC_WM_B    WM_B
#define KC_WM_N    WM_N
#define KC_WM_M    WM_M
#define KC_WM_COMM WM_COMM
#define KC_WM_DOT  WM_DOT
#define KC_WM_SLSH WM_SLSH

#endif
