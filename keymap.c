#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_DELETE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           TG(3),          
    KC_TAB,         KC_Q,           KC_G,           KC_M,           KC_L,           KC_W,                                           KC_Y,           KC_F,           KC_U,           KC_B,           KC_QUOTE,       KC_BSLS,        
    KC_ESCAPE,      MT(MOD_LGUI, KC_D),MT(MOD_LALT, KC_S),MT(MOD_LCTL, KC_T),MT(MOD_LSFT, KC_N),KC_R,                                           KC_I,           MT(MOD_RSFT, KC_A),MT(MOD_RCTL, KC_E),MT(MOD_RALT, KC_O),MT(MOD_RGUI, KC_H),KC_SCLN,        
    CW_TOGG,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_J,                                           KC_K,           KC_P,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_CAPS,
                                                    LT(1, KC_SPACE),LT(2, KC_ENTER),                                ST_MACRO_0,     KC_BSPC
  ),
  [1] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_GRAVE,       KC_LPRN,        KC_CIRC,        KC_RPRN,        KC_HASH,                                        KC_DLR,         KC_LCBR,        KC_PIPE,        KC_RCBR,        KC_TILD,        KC_NO,          
    KC_EXLM,        KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,       KC_PLUS,                                        KC_MINUS,       RALT(KC_H),     RALT(KC_J),     RALT(KC_K),     RALT(KC_L),     KC_AT,          
    KC_NO,          KC_AMPR,        KC_LBRC,        KC_EQUAL,       KC_RBRC,        KC_ASTR,                                        KC_PERC,        KC_LABK,        KC_UNDS,        KC_RABK,        KC_QUES,        KC_NO,          
                                                    KC_TRANSPARENT, KC_NO,                                          KC_NO,          KC_NO
  ),
  [2] = LAYOUT_voyager(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         
    KC_NO,          KC_NO,          KC_7,           KC_8,           KC_9,           KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_BSPC,        KC_4,           KC_5,           KC_6,           KC_DOT,                                         KC_NO,          RCTL(KC_H),     RCTL(KC_J),     RCTL(KC_K),     RCTL(KC_L),     KC_NO,          
    KC_NO,          KC_NO,          KC_1,           KC_2,           KC_3,           KC_0,                                           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_NO,          KC_TRANSPARENT,                                 KC_NO,          KC_NO
  ),
  [3] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT, 
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_NO,          
    KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_NO,          KC_NO,          
    KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_SPACE,       ST_MACRO_1,                                     KC_NO,          KC_NO
  ),
};









bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_TAP(X_TAB)));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_TAP(X_TAB)));
    }
    break;

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

static bool scroll_lock_state = false;
void matrix_scan_user(void) {
    bool current_scroll_lock = host_keyboard_led_state().scroll_lock;
    if (current_scroll_lock != scroll_lock_state) {
        scroll_lock_state = current_scroll_lock;
        if (current_scroll_lock) {
            layer_on(3);
        } else {
            layer_off(3);
        }
    }
}
