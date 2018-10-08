# project specific files
SRC =	matrix.c \
	led.c \
	$(CHIBIOS)/os/various/syscalls.c

TAP_DANCE_ENABLE = yes
# KEY_LOCK_ENABLE = yes

BACKLIGHT_ENABLE = yes  # Enable keyboard backlight functionality
VISUALIZER_ENABLE = yes

LCD_BACKLIGHT_ENABLE = yes
LCD_ENABLE = yes
LED_ENABLE = yes

SLEEP_LED_ENABLE = yes  # Breathing sleep LED during USB suspend
# RGBLIGHT_ENABLE  = yes  # Enable WS2812 RGB underlight.  Do not enable this with audio at the same time.

SERIAL_LINK_ENABLE = yes

BOOTMAGIC_ENABLE = yes  # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE  = yes  # Mouse keys(+4700)
EXTRAKEY_ENABLE  = yes # Audio control and System control(+450)
CONSOLE_ENABLE   = yes# Console for debug(+400)
COMMAND_ENABLE   = yes  # Commands for debug and configuration
NKRO_ENABLE      = yes # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ # nkro-doesnt-work
MIDI_ENABLE      = yes  # MIDI controls
MIDI_ADVANCED    = yes
MUSIC_MODE       = yes
AUDIO_ENABLE     = no  # Audio output on port C6

UNICODE_ENABLE   = yes  # Unicode
# BLUETOOTH_ENABLE = yes  # Enable Bluetooth with the Adafruit EZ-Key HID
LEADER_ENABLE    = yes

