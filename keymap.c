// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.
#include "planck.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Keycodes
enum planck_keycodes {
  DVORAK = SAFE_RANGE,
  LOWER,
  RAISE,
  QWERTY,
};

enum tapdace_keycodes {
  KC_ESC_CAPS
};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY       0
#define _DVORAK       1
#define _LOWER        2
#define _RAISE        3
#define _TOUCHCURSOR  4
#define _MOUSECURSOR  5
#define _NUMPAD       7
#define _OSL          8
#define _GAMING       9
#define _NEXUS        16

// Fillers to make layering more clear
#define _______       KC_TRNS
#define XXXXXXX       KC_NO

// Layer Navigation

// Toggle Layer
#define TG_TC         TG(_TOUCHCURSOR)
#define TG_MC         TG(_MOUSECURSOR)
#define TG_NP         TG(_NUMPAD)
#define TG_OSL        OSL(_OSL)

// Layer on hold, Kc on Tap
#define LT_TC(kc)     LT(_TOUCHCURSOR, kc)
#define LT_MC(kc)     LT(_MOUSECURSOR, kc)
#define LT_NP(kc)     LT(_NUMPAD, kc)

// Layer while holding
#define TCURSOR       MO(_TOUCHCURSOR)       //Hold for TOUCHCURSOR
#define MCURSOR       MO(_MOUSECURSOR)       //Hold for MOUSECURSOR
#define NUMPAD        MO(_NUMPAD)            //Hold for NUMPAD

#define TC_SPC        LT_TC(KC_SPC)          //Tap to Space, hold for TouchCursor

// Composite Keys
#define LV_QUOT       RALT(KC_QUOT)          //Avoid DeadKey on Quote
#define LV_TILD       RALT(KC_TILD)          //Avoid DeadKey on Tilde
#define LV_CIRC       RALT(KC_CIRC)          //Avoid DeadKey on Circunflex
#define LV_GRV        RALT(KC_GRV)           //Avoid DeadKey on Grave

#define LN_CEDL       RALT(KC_COMM)          //Linux implementation of Ç

#define ESC_CPL       TD(KC_ESC_CAPS)        //Tap once for ESC, twice for Caps Lock

#define SFT_ENT       SFT_T(KC_ENT)          //Tap to ENTER, hold to SHIFT
#define SFT_F1        SFT_T(KC_F1)           //Tap to F1, hold to SHIFT
#define SFT_F12       SFT_T(KC_F12)          //Tap to F12, hold to SHIFT

#define CTL_TAB       CTL_T(KC_TAB)          //Tap to tab, hold to Ctrl
#define CTL_MNS       CTL_T(KC_MINS)         //Tap to minus, hold to Ctrl
#define CTL_QUT       CTL_T(KC_QUOT)         //Tap to quote, hold to Ctrl
#define CTL_ENT       CTL_T(KC_ENT)          //Tap to enter, hold to Ctrl

#define DEL_GUI       GUI_T(KC_DEL)          //Tap to quote, hold to Ctrl

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Dvorak
   * +========+========+========+========+========+========+========+========+========+========+========+========+
   * | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
   * +========+========+========+========+========+========+========+========+========+========+========+========+
   * | Esc.Cl | '      | ,      | .      | P      | Y      | F      | G      | C      | R      | L      | Bksp   |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   * | Tb/Ctl | A      | O      | E      | U      | I      | D      | H      | T      | N      | S      | -/Ctl  |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   * | Shift  | ;      | Q      | J      | K      | X      | B      | M      | W      | V      | Z      | En/Sh  |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   * | Ctrl   | Gui    | Num    | Alt    | Lower  | SpcNav | SpcNav | Raise  | Alt    | OSL    | Dl/Gui | En/Ctl |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   */
  [_DVORAK] = {
    {  ESC_CPL, LV_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   , KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_BSPC},
    {  CTL_TAB, KC_A   , KC_O   , KC_E   , KC_U   , KC_I   , KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , CTL_MNS},
    {  KC_LSFT, KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   , KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , SFT_ENT},
    {  KC_LCTL, KC_LGUI, NUMPAD , KC_LALT, LOWER  , TC_SPC , TC_SPC , RAISE  , KC_RALT, NUMPAD , DEL_GUI, CTL_ENT}
  },

  /* Lower
   * +========+========+========+========+========+========+========+========+========+========+========+========+
   * | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
   * +========+========+========+========+========+========+========+========+========+========+========+========+
   * | Home   | Left   | Down   | Up     | Right  | End    | _      | {      | }      | ?      | +      | Del    |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   * | `      | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | \      |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   * |        | Mute   | Vol+   | Vol-   | Prev   | Play   | Next   | PgUp   | PgDown | Insert | PScr   |        |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   * |        |        |        |        | >>><<< | MouseC | MouseC |        |        |        |        |        |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   */
  [_LOWER] = {
    {  KC_HOME, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_END , KC_UNDS, KC_LCBR, KC_RCBR, KC_QUES, KC_PLUS, KC_DEL },
    {  LV_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSLS},
    {  _______, KC_MUTE, KC_VOLU, KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, KC_PGUP, KC_PGDN, KC_INS , KC_PSCR, _______},
    {  _______, _______, _______, _______, _______, MCURSOR, MCURSOR, _______, _______, _______, _______, _______}
  },

  /* Raise
   * +========+========+========+========+========+========+========+========+========+========+========+========+
   * | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
   * +========+========+========+========+========+========+========+========+========+========+========+========+
   * |        | "      | `      | ~      | ^      | '      | Ç      | [      | ]      | /      | =      | Del    |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   * | ~      | !      | @      | #      | $      | %      | ^      | &      | *      | (      | )      | ¦      |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   * | F1/Sh  | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12/Sh |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   * |        |        |        |        |        | MouseC | MouseC | >>><<< |        |        |        |        |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   */
  [_RAISE] = {
    {  _______, KC_DQT , KC_GRV , KC_TILD, KC_CIRC, KC_QUOT, LN_CEDL, KC_LBRC, KC_RBRC, KC_SLSH, KC_EQL , KC_DEL },
    {  LV_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, LV_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE},
    {  SFT_F1 , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , SFT_F12},
    {  _______, _______, _______, _______, _______, MCURSOR, MCURSOR, _______, _______, _______, _______, _______}
  },

  /* TouchCursor
   * +========+========+========+========+========+========+========+========+========+========+========+========+
   * | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
   * +========+========+========+========+========+========+========+========+========+========+========+========+
   * |        |        |        |        |        |        | Insert | Home   | Up     | End    | Bksp   |        |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   * |        |        |        |        |        |        | PgUp   | Left   | Down   | Right  | CtlShf | Spc    |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   * |        |        |        |        |        |        | PgDown | Del    | CtlAlt | AltShf |        |        |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   * |        |        |        |        |        | >>><<< | >>><<< |        |        |        |        |        |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   */
  [_TOUCHCURSOR] = {
    {  _______, _______, _______, _______, _______, _______, KC_INS , KC_HOME, KC_UP  , KC_END , KC_BSPC, _______},
    {  _______, _______, _______, _______, _______, _______, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_SPC },
    {  _______, _______, _______, _______, _______, _______, KC_PGDN, KC_DEL , XXXXXXX, XXXXXXX, _______, _______},
    {  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  },

  /* Mouse Layer
   * +========+========+========+========+========+========+========+========+========+========+========+========+
   * | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
   * +========+========+========+========+========+========+========+========+========+========+========+========+
   * |        |        |        | Accl0  |        |        |        | WhlLft | Up     | WhlRgt | Btn2   |        |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   * |        |        | Accl2  | Btn2   | Btn1   | Accl1  | WhlUp  | Left   | Down   | Right  | Btn4   | Btn5   |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   * |        |        |        |        | Btn3   |        | WhlDwn | Btn1   |        |        | Btn3   |        |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   * |        |        |        |        |        | >>><<< | >>><<< |        |        |        |        |        |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   */

  [_MOUSECURSOR] = {
    {  _______, _______, _______, KC_ACL0, _______, _______, _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_BTN2, _______},
    {  _______, _______, KC_ACL2, KC_BTN2, KC_BTN1, KC_ACL1, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN4, KC_BTN5},
    {  _______, _______, _______, _______, KC_BTN3, _______, KC_WH_D, KC_BTN1, _______, _______, KC_BTN3, _______},
    {  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  },

  /* Numpad Layer
   * +========+========+========+========+========+========+========+========+========+========+========+========+
   * | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
   * +========+========+========+========+========+========+========+========+========+========+========+========+
   * | ^      | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | Bksp   |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   * | Esc    | @      | A      | B      | C      | (      | )      | 4      | 5      | 6      | ¦      | Enter  |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   * | &      | #      | D      | E      | F      | [      | ]      | 1      | 2      | 3      | /      | *      |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   * |        |        | >>><<< |        | X      |        |        | 0      | .      | ,      | +      | -      |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   */

  [_NUMPAD] = {
    {  LV_TILD, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______},
    {  KC_ESC , KC_AT  , KC_A   , KC_B   , KC_C   , KC_RPRN, KC_LPRN, KC_4   , KC_5   , KC_6   , KC_PIPE, KC_ENT },
    {  KC_AMPR, KC_HASH, KC_D   , KC_E   , KC_F   , KC_RBRC, KC_LBRC, KC_1   , KC_2   , KC_3   , KC_SLSH, KC_ASTR},
    {  _______, _______, _______, _______, KC_X   , _______, _______, KC_0   , KC_DOT , KC_COMM, KC_PLUS, KC_MINS}
  },


  /* Qwerty
   * +========+========+========+========+========+========+========+========+========+========+========+========+
   * | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
   * +========+========+========+========+========+========+========+========+========+========+========+========+
   * | Esc.Cl | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | Bksp   |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   * | Tb/Ctl | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '/Ctl  |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   * | Shift  | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | En/Sh  |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   * | Ctrl   | Gui    | Num    | Alt    | Lower  | SpcNav | SpcNav | Raise  | Alt    | OSL    | Dl/Gui | En/Ctl |
   * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   */
  [_QWERTY] = {
    {  ESC_CPL, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC},
    {  CTL_TAB, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, CTL_QUT},
    {  KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, SFT_ENT},
    {  KC_LCTL, KC_LGUI, NUMPAD , KC_LALT, LOWER  , TC_SPC , TC_SPC , RAISE  , KC_RALT, NUMPAD , DEL_GUI, CTL_ENT}
  },

  /* Nexus (Lower + Raise)
   * ,-----------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |      |      |      |      |  Del |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |Dvorak|      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      |Reset |
   * `-----------------------------------------------------------------------------------'
   */
  [_NEXUS] = {
    {_______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL },
    {_______, _______,  _______, AU_ON  , AU_OFF , AG_NORM, AG_SWAP, QWERTY , _______, DVORAK , _______, _______},
    {_______, MUV_DE ,  MUV_IN , MU_ON  , MU_OFF , MI_ON  , MI_OFF , _______, _______, _______, _______, _______},
    {_______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET  }
  }

};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Process KeyPress
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _NEXUS);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _NEXUS);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _NEXUS);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _NEXUS);
      }
      return false;
      break;
  }
  return true;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [KC_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
};