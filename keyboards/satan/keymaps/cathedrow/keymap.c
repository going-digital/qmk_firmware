/* Peter's customisations */

#include "satan.h"
//#include "txbolt.h"
#include "gemini_pr.h"
#include "virtser.h"

// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _BLC 1
#define _BLW 2
#define _BTB 3
#define _FL 4
#define _TB 5 // Plover TX Bolt

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |CAPS   |  A|  S|  D| _F|  G|  H| _J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt |Gui |Ctrl|FN   |
   * `-----------------------------------------------------------'
   */
[_BL] = KEYMAP_ANSI(
  F(0),    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS, \
  KC_CAPS, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,  \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,         KC_RSFT, \
  KC_LCTL, KC_LGUI,KC_LALT,                KC_SPC,                                 KC_RALT,KC_RGUI, KC_RCTL,MO(_FL)),

  /* Keymap _BLC: (Base Layer) Colemak Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  F|  P|  G|  J|  L|  U|  Y|  ;|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |Backsp |  A|  R|  S| _T|  D|  H| _N|  E|  I|  O|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  K|  M|  ,|  .|  /|Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt |Gui |Ctrl|FN   |
   * `-----------------------------------------------------------'
   */
[_BLC] = KEYMAP_ANSI(
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
  _______,KC_Q,   KC_W,   KC_F,   KC_P,   KC_G,   KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,_______,_______,_______, \
  KC_BSPC,KC_A,   KC_R,   KC_S,   KC_T,   KC_D,   KC_H,   KC_N,   KC_E,   KC_I,   KC_O,   _______,        _______, \
  _______,        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_K,   KC_M,   _______,_______,_______,        _______, \
  _______,_______,_______,                _______,                                _______,_______,_______,_______),

  /* Keymap _BLW: (Base Layer) Workman Layer
   * (In Workman-P, numbers default shifted, and unshift)
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  D|  R|  W|  B|  J|  F|  U|  P|  ;|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |Backsp |  A|  S|  H| _T|  G|  Y| _N|  E|  O|  I|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  M|  C|  V|  K|  L|  ,|  .|  /|Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt |Gui |Ctrl|FN   |
   * `-----------------------------------------------------------'
   */
[_BLW] = KEYMAP_ANSI(
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
  _______,KC_Q,   KC_D,   KC_R,   KC_W,   KC_B,   KC_J,   KC_F,   KC_U,   KC_P,   KC_SCLN,_______,_______,_______, \
  KC_BSPC,KC_A,   KC_S,   KC_H,   KC_T,   KC_G,   KC_Y,   KC_N,   KC_E,   KC_O,   KC_I,   _______,        _______, \
  _______,        KC_Z,   KC_X,   KC_M,   KC_C,   KC_V,   KC_K,   KC_L,   _______,_______,_______,        _______, \
  _______,_______,_______,                _______,                                _______,_______,_______,_______),

  /* Keymap _TB: Function Layer, Gemini PR Steno layer. Compatible with Plover.
     * ,-----------------------------------------------------------.
     * | #1 |#2 |#3 |#4 |#5 |#6 |#7 |#8 |#9 |#A |#B |#C |   |      |
     * |-----------------------------------------------------------|
     * |  Fn | S1| T | P | H | *1| *3| F | P | L | T | D |   |     |
     * |-----------------------------------------------------------|
     * |      | S2| K | W | R | *2| *4| R | B | G | S | Z |        |
     * |-----------------------------------------------------------|
     * |        |   |   | A | O |   | E | U |   |   |    |         |
     * |-----------------------------------------------------------|
     * | Pwr|Res1|Res2|                        |    |    |    |FN  |
     * `-----------------------------------------------------------'
     */
  [_BTB] = KEYMAP_ANSI(
    M(GE_N1),M(GE_N2),M(GE_N3)  ,M(GE_N4),M(GE_N5),M(GE_N6),M(GE_N7),M(GE_N8),M(GE_N9),M(GE_NA),M(GE_NB),M(GE_NC),KC_NO  ,KC_NO,  \
    M(GE_FN),M(GE_S1),M(GE_Tl)  ,M(GE_Pl),M(GE_Hl),M(GE_X1),M(GE_X3),M(GE_Fr),M(GE_Pr),M(GE_Lr),M(GE_Tr),M(GE_Dr),KC_NO  ,KC_NO,  \
    KC_NO   ,M(GE_S2),M(GE_Kl)  ,M(GE_Wl),M(GE_Rl),M(GE_X2),M(GE_X4),M(GE_Rr),M(GE_Br),M(GE_Gr),M(GE_Sr),M(GE_Zr),        KC_NO,  \
    KC_NO   ,KC_NO     ,KC_NO     ,M(GE_Al),M(GE_Ol),KC_NO   ,M(GE_Er),M(GE_Ur),KC_NO   ,KC_NO   ,KC_NO  ,                KC_NO,\
    M(GE_pw),M(GE_r1),M(GE_r2),                KC_NO  ,                                KC_NO  ,KC_NO  ,KC_NO  ,_______),

  /* Keymap _FL: Function Layer
   * ,-----------------------------------------------------------.
   * | `  |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|DELETE|
   * |-----------------------------------------------------------|
   * |CAPLK|MbL|MUp|MbR|MWU|MA0|MA1|MA2|   |Ins|Hme|PgU|   |NUBS |
   * |-----------------------------------------------------------|
   * |      |MLt|MDn|MRt|MWD|QWE|COL|WMN|RST|Del|End|PgD| Pg Up  |
   * |-----------------------------------------------------------|
   * |        |Vl-|VL+|MWL|MWR|PLV|   ||> ||<<|>>|| /\ | Pg Down |
   * |-----------------------------------------------------------|
   * |    |    |    |                        | <- | \/ | -> |FN  |
   * `-----------------------------------------------------------'
   */
[_FL] = KEYMAP_ANSI(
  KC_GRV, KC_FN1,    KC_FN2,    KC_FN3,     KC_FN4, KC_FN5, KC_FN6, KC_FN7, KC_FN8 ,KC_FN9 ,KC_FN10,KC_FN11,KC_FN12,KC_DELT,  \
  KC_CAPS,KC_MS_BTN1,KC_MS_UP,  KC_MS_BTN2, KC_WH_U,KC_ACL0,KC_ACL1,KC_ACL2,_______,KC_INS ,KC_HOME,KC_PGUP,_______,KC_NUBS,  \
  _______,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_WH_D,TO(_BL),TO(_BLC),TO(_BLW),RESET,KC_DEL ,KC_END ,KC_PGDN,        KC_PGUP,  \
  _______,KC_VOLD,   KC_VOLU,   KC_WH_L,    KC_WH_R,TO(_BTB),_______,KC_MPLY,KC_MPRV,KC_MNXT,KC_UP  ,                KC_PGDOWN,\
  _______,_______,   _______,               _______,                                KC_LEFT,KC_DOWN,KC_RIGHT,_______),



};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
        } else {
          add_key(KC_ESC);
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
        } else {
          del_key(KC_ESC);
        }
      }
      send_keyboard_report();
      break;
  }
}

uint8_t chord[6] = {0};
uint8_t pressed_count = 0;

void send_chord(void) {
  chord[0] |= 0x80;
  for (uint8_t i=0; i<6; i++) {
    virtser_send(chord[i]);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    pressed_count++;
  } else {
    pressed_count--;
  }
  return true;
}
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
    uint8_t grp = (id & 0xf0) >> 4;
    chord[grp] |= 1 << (id & 0x0f);
  } else {
    if (pressed_count == 0) {
      send_chord();
      for (uint8_t i=0; i<6; i++) chord[i]=0;
    }
  }
  return MACRO_NONE;
}
