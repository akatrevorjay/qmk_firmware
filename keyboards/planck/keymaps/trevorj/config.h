#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

#undef VENDOR_ID
#undef PRODUCT_ID
#define VENDOR_ID 0xDEAF // defines your VID, and for most DIY projects, can be whatever you want
#define PRODUCT_ID 0xBEEF // defines your PID, and for most DIY projects, can be whatever you want  

#undef MANUFACTURER
#undef PRODUCT
#define MANUFACTURER SkyWWW // generally who/whatever brand produced the board
#define PRODUCT Trevplanck+light // the name of the keyboard
/* #define DESCRIPTION a keyboard // a short description of what the keyboard is */

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

#endif
