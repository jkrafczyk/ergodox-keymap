#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  RGB_SLD,
  COPY,
  PASTE,

  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

#define TAP_MACRO 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Keymap 0: Basic layer
 *
 * ,------------------------------------------------------.        ,---------------------------------------------------------.
 * | ESC    |   1  |   2  |   3   |   4  |   5  |    =    |        |         |   6  |   7  |   8  |   9  |   0   |  - _      |
 * |--------+------+------+-------+------+----------------|        |---------+------+------+------+------+-------+-----------|
 * | Tab    |   Q  |   W  |   E   |   R  |   T  |  COPY   |        |  LT1    |   Y  |   U  |   I  |   O  |   P   |   \ |     |
 * |--------+------+------+-------+------+------|         |        |         |------+------+------+------+-------+-----------|
 * | CTRL   |   A  |   S  |   D   |   F  |   G  |---------|        |---------|   H  |   J  |   K  |   L  | ;(LT2)|   "       |
 * |--------+------+------+-------+------+------| PASTE   |        |  MACRO  |------+------+------+------+-------+-----------|
 * | SHIFT  |   z  |   X  |   C   |   V  |   B  |         |        |         |   N  |   M  |   ,  |   .  |/?     |  SHIFT    |
 * `--------+------+------+-------+------+----------------'        `----------------+------+------+------+-------+-----------'
 *   |  `~  |  ALT | GUI  |  LEFT | RIGHT|                                          | UP   | DWN  |  [{  |  ]}   |  MO1 |
 *   |  LT1 |      |      |       |      |                                          |      |      |      |       |      |
 *   `-----------------------------------'                                          `-----------------------------------'
 *                                        ,--------------.       ,---------------.
 *                                        |  APP  | MO(2)|       | GUI  |        |
 *                                        |       |      |       |      |        |
 *                                 ,------|-------|------|       |------+--------+------.
 *                                 |      |       | HOME |       | PgUp |        |      |
 *                                 |  SPC | BSPC  |------|       |------|  DEL   |Enter |
 *                                 |      |       |END   |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
  [0] = LAYOUT_ergodox(KC_ESCAPE,KC_1,KC_2,KC_3,KC_4,KC_5,KC_EQL,
                       KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,COPY,
                       KC_LCTL,KC_A,KC_S,KC_D,KC_F,KC_G,
                       KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,PASTE,
                       LT(1,KC_GRAVE),KC_LALT,KC_LCMD,KC_LEFT,KC_RIGHT,
                       
                       KC_APP,MO(2),
                       KC_HOME,KC_SPACE,KC_BSPACE,KC_END,
                       
                       KC_NO,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINUS,
                       TG(1),KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSLASH,
                       KC_H,KC_J,KC_K,KC_L,LT(2,KC_SCOLON), KC_QUOTE,
                       TD(TAP_MACRO),KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_RSHIFT,
                       KC_UP,KC_DOWN,KC_LBRACKET,KC_RBRACKET,MO(1),
                       
                       KC_RCMD, KC_RCTL,
                       KC_PGUP,KC_PGDOWN,KC_DEL,KC_ENTER),

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   0  |   .  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [1] = LAYOUT_ergodox(KC_TRANSPARENT,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRANSPARENT,
                       KC_TRANSPARENT,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_PIPE,KC_TRANSPARENT,
                       KC_TRANSPARENT,KC_HASH,KC_DLR,KC_LPRN,KC_RPRN,KC_GRAVE,
                       KC_TRANSPARENT,KC_PERC,KC_CIRC,KC_LBRACKET,KC_RBRACKET,KC_TILD,KC_TRANSPARENT,
                       KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

                       RGB_MOD,KC_TRANSPARENT,
                       KC_TRANSPARENT,RGB_VAD,RGB_VAI,KC_TRANSPARENT,
                       
                       KC_TRANSPARENT,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_TRANSPARENT,
                       KC_UP,KC_7,KC_8,KC_9,KC_ASTR,KC_F12,
                       KC_DOWN,KC_4,KC_5,KC_6,KC_PLUS,KC_TRANSPARENT,
                       KC_TRANSPARENT,KC_AMPR,KC_1,KC_2,KC_3,KC_BSLASH,KC_TRANSPARENT,
                       KC_0,KC_0,KC_DOT,KC_EQUAL,KC_TRANSPARENT,
                       
                       RGB_TOG,RGB_SLD,KC_TRANSPARENT,
                       KC_TRANSPARENT,RGB_HUD,RGB_HUI),

/*
 * Keymap 2: Mouse/Media layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      | MwUp |           |      |      |      |  UP  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      | LEFT | DOWN | RIGHT|      |        |
 * |--------+------+------+------+------+------| MWdn |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | PREV | NEXT | PLAY |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | VOL+ | VOL- | MUTE |       |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |Brwser|Brwser|
 *                                 | Lclk | Rclk |------|       |------| Back | Fwd  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [2] = LAYOUT_ergodox(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
                       KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_U,KC_TRANSPARENT,KC_WH_U,KC_WH_U,
                       KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_L,KC_MS_D,KC_MS_R,KC_TRANSPARENT,
                       KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_WH_D,
                       KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
                       
                       KC_TRANSPARENT,KC_TRANSPARENT,
                       KC_TRANSPARENT,KC_BTN1,KC_BTN2,KC_TRANSPARENT,
                       
                       KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
                       KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
                       KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,
                       KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MPRV,KC_MNXT,KC_MPLY,KC_TRANSPARENT,
                       KC_VOLU,KC_VOLD,KC_MUTE,KC_TRANSPARENT,KC_TRANSPARENT,
                       
                       KC_TRANSPARENT,KC_TRANSPARENT,
                       KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),
};

bool suspended = false;
rgb_config_t rgb_matrix_config;
static bool is_macro1_recording = false;
static uint32_t current_layer_state = 0;


#define CLR_L1 {35,255,127}
#define CLR_L1_BASE {0,0,0}
#define CLR_L1_NUMB {35,255,255}
#define CLR_L1_BRCE {50,255,255}
#define CLR_L1_BRAK {100,255,255}
#define CLR_L1_PARN {150,255,255}
#define CLR_L2_BASE {0,0,0}
#define CLR_L2_MOUS {200,255,255}
#define CLR_L2_MEDI {75,255,255}
#define CLR_L2_ARRW {225,255,255}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { //RIGHT
            CLR_L1,CLR_L1,CLR_L1,CLR_L1,CLR_L1, 
            CLR_L1,CLR_L1,CLR_L1,CLR_L1,CLR_L1, 
            CLR_L1,CLR_L1,CLR_L1,CLR_L1,CLR_L1, 
            CLR_L1,CLR_L1,CLR_L1,CLR_L1,CLR_L1, 
            CLR_L1,CLR_L1,CLR_L1,CLR_L1, 

            //LEFT
            CLR_L1,CLR_L1,CLR_L1,CLR_L1,CLR_L1, 
            CLR_L1,CLR_L1,CLR_L1,CLR_L1,CLR_L1, 
            CLR_L1,CLR_L1,CLR_L1,CLR_L1,CLR_L1, 
            CLR_L1,CLR_L1,CLR_L1,CLR_L1,CLR_L1, 
            CLR_L1,CLR_L1,CLR_L1,CLR_L1, 
          },

    [1] = { 
            //RIGHT
            CLR_L1_BASE,CLR_L1_BASE,CLR_L1_BASE,CLR_L1_BASE,CLR_L1_BASE, 
            CLR_L1_BASE,CLR_L1_NUMB,CLR_L1_NUMB,CLR_L1_NUMB,CLR_L1_BASE, 
            CLR_L1_BASE,CLR_L1_NUMB,CLR_L1_NUMB,CLR_L1_NUMB,CLR_L1_BASE, 
            CLR_L1_BASE,CLR_L1_NUMB,CLR_L1_NUMB,CLR_L1_NUMB,CLR_L1_BASE, 
            CLR_L1_NUMB,CLR_L1_NUMB,CLR_L1_BASE,CLR_L1_BASE,

            //LEFT
            CLR_L1_BASE,CLR_L1_BASE,CLR_L1_BASE,CLR_L1_BASE,CLR_L1_BASE, 
            CLR_L1_BASE,CLR_L1_BRCE,CLR_L1_BRCE,CLR_L1_BASE,CLR_L1_BASE, 
            CLR_L1_BASE,CLR_L1_PARN,CLR_L1_PARN,CLR_L1_BASE,CLR_L1_BASE, 
            CLR_L1_BASE,CLR_L1_BRAK,CLR_L1_BRAK,CLR_L1_BASE,CLR_L1_BASE, 
            CLR_L1_BASE,CLR_L1_BASE,CLR_L1_BASE,CLR_L1_BASE,  
      },


    [2] = {
            //RIGHT
            CLR_L2_BASE,CLR_L2_BASE,CLR_L2_BASE,CLR_L2_BASE,CLR_L2_BASE,
            CLR_L2_BASE,CLR_L2_BASE,CLR_L2_ARRW,CLR_L2_BASE,CLR_L2_BASE,
            CLR_L2_BASE,CLR_L2_ARRW,CLR_L2_ARRW,CLR_L2_ARRW,CLR_L2_BASE,
            CLR_L2_BASE,CLR_L2_BASE,CLR_L2_MEDI,CLR_L2_MEDI,CLR_L2_MEDI,
            CLR_L2_MEDI,CLR_L2_MEDI,CLR_L2_MEDI,CLR_L2_BASE,

            //LEFT
            CLR_L2_BASE,CLR_L2_BASE,CLR_L2_BASE,CLR_L2_BASE,CLR_L2_BASE,
            CLR_L2_BASE,CLR_L2_BASE,CLR_L2_MOUS,CLR_L2_BASE,CLR_L2_BASE,
            CLR_L2_BASE,CLR_L2_MOUS,CLR_L2_MOUS,CLR_L2_MOUS,CLR_L2_BASE,
            CLR_L2_BASE,CLR_L2_BASE,CLR_L2_BASE,CLR_L2_BASE,CLR_L2_BASE,
            CLR_L2_BASE,CLR_L2_BASE,CLR_L2_BASE,CLR_L2_BASE,
      },

    
};

void set_leds_color( int layer) {
  rgb_matrix_mode_noeeprom(1);
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    uint8_t val = pgm_read_byte(&ledmap[layer][i][2]);
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = val == 0 ? 0 : rgb_matrix_config.val
    };
    RGB rgb = hsv_to_rgb( hsv );
    rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
  }
}

void rgb_matrix_indicators_user(void) {
  if(suspended == false) {
    uint8_t layer = biton32(layer_state);
    switch (layer) {
      case 0:
        rgb_matrix_config.raw = eeprom_read_dword(EECONFIG_RGB_MATRIX);
        rgb_matrix_mode_noeeprom(rgb_matrix_config.mode);
        if(rgb_matrix_config.mode != 1) {
          rgb_matrix_sethsv_noeeprom(rgb_matrix_config.hue, rgb_matrix_config.sat, rgb_matrix_config.val);
        }
        set_leds_color(0);
        break;
      case 1:
        set_leds_color(1);
        break;
      case 2:
        set_leds_color(2);
        break;
      case 3:
        set_leds_color(3);
        break;
    }
  }
}
const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode != TD(TAP_MACRO)) {
    if (!process_record_dynamic_macro(keycode, record)) {
      return false;
    }

    switch (keycode) {
      // dynamically generate these.
      case EPRM:
        if (record->event.pressed) {
          eeconfig_init();
        }
        return false;
        break;
        
      case RGB_SLD:
        if (record->event.pressed) {
          rgblight_mode(1);
        }
        return false;
        break;

      case COPY:
        if (record->event.pressed) {
          SEND_STRING(SS_LCMD("c"));
        }
        return false;
        break;

      case PASTE:
        if (record->event.pressed) {
          SEND_STRING(SS_LCMD("v"));
        }
        return false;
        break;  

    }
  }  
  return true;
}

// Method called at the end of the tap dance on the TAP_MACRO key. That key is
// used to start recording a macro (double tap or more), to stop recording (any
// number of tap), or to play the recorded macro (1 tap).
void macro_tapdance_fn(qk_tap_dance_state_t *state, void *user_data) {
  uint16_t keycode;
  keyrecord_t record;
  if (is_macro1_recording) {
    keycode = DYN_REC_STOP;
    is_macro1_recording = false;
    layer_state_set_user(current_layer_state);
  } else if (state->count == 1) {
    keycode = DYN_MACRO_PLAY1;
  } else {
    keycode = DYN_REC_START1;
    is_macro1_recording = true;
    layer_state_set_user(current_layer_state);
  }

  record.event.pressed = true;
  process_record_dynamic_macro(keycode, &record);
  record.event.pressed = false;
  process_record_dynamic_macro(keycode, &record);
  
}

// The definition of the tap dance actions:
qk_tap_dance_action_t tap_dance_actions[] = {
  // This Tap dance plays the macro 1 on TAP and records it on double tap.
  [TAP_MACRO] = ACTION_TAP_DANCE_FN(macro_tapdance_fn)
};

uint32_t layer_state_set_user(uint32_t state) {
    current_layer_state = state;
    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;

};
