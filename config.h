/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ONESHOT_TAP_TOGGLE 3

#define RGB_DISABLE_WHEN_USB_SUSPENDED true

#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
#define DISABLE_RGB_MATRIX_ALPHAS_MODS
#define EECONFIG_RGB_MATRIX (uint32_t *)16
#define NO_ACTION_MACRO true
#undef NO_ACTION_TAPPING