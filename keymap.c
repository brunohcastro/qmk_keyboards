// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.
#include "planck.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_br.h"

extern keymap_config_t keymap_config;

// Keycodes
enum planck_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  GAME,
  LOWER,
  RAISE,
};

enum tapdace_keycodes {
  TD_ESC_CAPS
};

enum funcs_keycodes {
  FN_TGGL_NUMPD,
  FN_SWAP_HANDS,
  FN_SWAP_HDOFF,
};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DVORAK       0
#define _QWERTY       1
#define _GAMING       2
#define _ONEHAND      3
#define _LOWER        5
#define _RAISE        6
#define _TOUCHCURSOR  7
#define _MOUSECURSOR  8
#define _LFTMCURSOR   9
#define _NUMPAD       10
#define _UTIL         11
#define _NEXUS        12

// Fillers to make layering more clear
#define _______       KC_TRNS
#define XXXXXXX       KC_NO

/*
 * Layer Navigation Aliases
 */

// Toggle Layer
#define TG_TC         TG(_TOUCHCURSOR)
#define TG_MC         TG(_MOUSECURSOR)
#define TG_NP         TG(_NUMPAD)
#define TG_OH         TG(_ONEHAND)

// Layer while holding
#define TCURSOR       MO(_TOUCHCURSOR)
#define MCURSOR       MO(_MOUSECURSOR)
#define LMCURSR       MO(_LFTMCURSOR)
#define NUMPAD        MO(_NUMPAD)
#define UTIL          MO(_UTIL)

#define TC_SPC        LT(_TOUCHCURSOR, KC_SPC)

/*
 * Key Aliases
 */

// DeadKeys MokeyPatch
#define LV_QUOT       RALT(KC_QUOT)          //Avoid DeadKey on Quote
#define LV_CIRC       RALT(KC_CIRC)          //Avoid DeadKey on Circunflex

// Cedilla character on each platform
#define LN_CEDL       RALT(KC_COMM)          //Linux implementation of Ç

// TapDancing
#define ESC_CPL       TD(TD_ESC_CAPS)        //Tap once for ESC, twice for Caps Lock

// Tap and Hold keys
#define SFT_ENT       SFT_T(KC_ENT)          //Tap to ENTER, hold to SHIFT

#define CTL_TAB       CTL_T(KC_TAB)          //Tap to tab, hold to Ctrl
#define CTL_MNS       CTL_T(KC_MINS)         //Tap to minus, hold to Ctrl
#define CTL_QUT       CTL_T(KC_QUOT)         //Tap to quote, hold to Ctrl
#define CTL_ENT       CTL_T(KC_ENT)          //Tap to enter, hold to Ctrl

// Function keys
#define SWP_HND       F(FN_SWAP_HANDS)
#define SWP_OFF       F(FN_SWAP_HDOFF)
#define TPTG_NP       F(FN_TGGL_NUMPD)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Dvorak
    +========+========+========+========+========+========+========+========+========+========+========+========+
    | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
    +========+========+========+========+========+========+========+========+========+========+========+========+
    | Esc.Cl | '      | ,      | .      | P      | Y      | F      | G      | C      | R      | L      | Bksp   |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    | Tb/Ctl | A      | O      | E      | U      | I      | D      | H      | T      | N      | S      | -/Ctl  |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    | Shift  | ;      | Q      | J      | K      | X      | B      | M      | W      | V      | Z      | En/Sh  |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    | Ctrl   | Gui    | Num    | Alt    | Lower  | SpcNav | SpcNav | Raise  | Alt    | Util   | Esc    | En/Ctl |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   */
  [_DVORAK] = {
    { ESC_CPL, BR_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   , KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_BSPC},
    { CTL_TAB, KC_A   , KC_O   , KC_E   , KC_U   , KC_I   , KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , CTL_MNS},
    { KC_LSFT, BR_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   , KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , SFT_ENT},
    { KC_LCTL, KC_LGUI, TPTG_NP, KC_LALT, LOWER  , TC_SPC , TC_SPC , RAISE  , KC_RALT, UTIL   , KC_ESC , CTL_ENT}
  },

  /* Qwerty
    +========+========+========+========+========+========+========+========+========+========+========+========+
    | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
    +========+========+========+========+========+========+========+========+========+========+========+========+
    | Esc.Cl | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | Bksp   |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    | Tb/Ctl | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '/Ctl  |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    | Shift  | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | En/Sh  |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    | Ctrl   | Gui    | Num    | Alt    | Lower  | SpcNav | SpcNav | Raise  | Alt    | OneHnd | Esc/Ut | En/Ctl |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   */
  [_QWERTY] = {
    { ESC_CPL, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC},
    { CTL_TAB, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , BR_SCLN, CTL_QUT},
    { KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , BR_SLSH, SFT_ENT},
    { KC_LCTL, KC_LGUI, TPTG_NP, KC_LALT, LOWER  , TC_SPC , TC_SPC , RAISE  , KC_RALT, UTIL   , KC_ESC , CTL_ENT}
  },


  /* Gaming
    +========+========+========+========+========+========+========+========+========+========+========+========+
    | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
    +========+========+========+========+========+========+========+========+========+========+========+========+
    | Esc.Cl | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | Bksp   |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    | Tb/Ctl | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '/Ctl  |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    | Shift  | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | En/Sh  |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    | Ctrl   | Gui    | Num    | Alt    | Lower  | SpcNav | SpcNav | Raise  | Alt    | OneHnd | Esc/Ut | En/Ctl |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   */
  [_GAMING] = {
    { ESC_CPL, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC},
    { CTL_TAB, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , BR_SCLN, CTL_QUT},
    { KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , BR_SLSH, SFT_ENT},
    { KC_LCTL, KC_LGUI, TPTG_NP, KC_LALT, LOWER  , TC_SPC , TC_SPC , RAISE  , KC_RALT, UTIL   , KC_ESC , CTL_ENT}
  },

  /* One Hand Layer - Dvorak
    +========+========+========+========+========+========+========+========+========+========+========+========+
    | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
    +========+========+========+========+========+========+========+========+========+========+========+========+
    | Bksp   |        |        |        |        |        |        |        |        |        |        |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        |        |        |        |        |        |        |        |        |        |        |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        |        |        |        |        |        |        |        |        |        |        |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        |        | Raise  | Swap   |        |        |        |        | Swap   | Lower  | Alt    |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   */
  [_ONEHAND] = {
    { KC_BSPC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    { _______, _______, RAISE  , SWP_HND, _______, _______, _______, _______, SWP_HND, LOWER  , KC_LALT, _______}
  },

  /* Lower
    +========+========+========+========+========+========+========+========+========+========+========+========+
    | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
    +========+========+========+========+========+========+========+========+========+========+========+========+
    |        | 6      | 7      | 8      | 9      | 0      | `      | +      | ?      | {      | }      | Del    |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        | 1      | 2      | 3      | 4      | 5      | ^      | &      | *      | (      | )      | \      |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        | ¹      | ²      | ³      | £      | ¨      | Ç      | ´      | ^      | `      | ~      |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        |        |        |        | >>><<< | MouseC | MouseC |        |        |        |        |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   */
  [_LOWER] = {
    { _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , BR_NDGV, KC_PLUS, BR_QUES, BR_LCBR, BR_RCBR, KC_DEL },
    { _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , BR_NDCR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, BR_BSLS},
    { _______, BR_1UP , BR_2UP , BR_3UP , BR_PND , BR_TRMA, BR_CCDL, BR_ACUT, BR_CIRC, BR_GRAV, BR_TILD, _______},
    { _______, _______, _______, _______, _______, MCURSOR, MCURSOR, _______, _______, _______, _______, _______}
  },

  /* Raise
    +========+========+========+========+========+========+========+========+========+========+========+========+
    | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
    +========+========+========+========+========+========+========+========+========+========+========+========+
    |        | [      | ]      | /      | =      | ~      | 1      | 2      | 3      | 4      | 5      | Del    |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        | !      | @      | #      | $      | %      | 6      | 7      | 8      | 9      | 0      | ¦      |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        | ª      | º      | °      | ¢      | ¬      | Play   | Next   | Vol-   | Vol+   | Mute   |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        |        |        |        |        | MouseC | MouseC | >>><<< |        |        |        |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   */
  [_RAISE] = {
    { _______, BR_LBRC, BR_RBRC, BR_SLSH, KC_EQL , BR_NDTD, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_DEL },
    { _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , BR_PIPE},
    { _______, BR_FORD, BR_MORD, BR_DGRE, BR_CENT, BR_NOT , KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU, KC_MUTE, _______},
    { _______, _______, _______, _______, _______, MCURSOR, MCURSOR, _______, _______, _______, _______, _______}
  },

  /* TouchCursor
    +========+========+========+========+========+========+========+========+========+========+========+========+
    | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
    +========+========+========+========+========+========+========+========+========+========+========+========+
    |        | Bksp   | Home   | Up     | End    | Insert | Insert | Home   | Up     | End    | Bksp   |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        | Spc    | Right  | Down   | Left   | PgUp   | PgUp   | Left   | Down   | Right  | Spc    | Tb/Ctl |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        |        |        |        | Del    | PgDown | PgDown | Del    |        |        |        |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        |        |        |        |        | >>><<< | >>><<< |        |        |        |        |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   */
  [_TOUCHCURSOR] = {
    { _______, KC_BSPC, KC_HOME, KC_UP  , KC_END , KC_INS , KC_INS , KC_HOME, KC_UP  , KC_END , KC_BSPC, _______},
    { _______, KC_SPC , KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC , CTL_TAB},
    { _______, _______, XXXXXXX, XXXXXXX, KC_DEL , KC_PGDN, KC_PGDN, KC_DEL , XXXXXXX, XXXXXXX, _______, _______},
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  },

  /* Default Mouse Layer
    +========+========+========+========+========+========+========+========+========+========+========+========+
    | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
    +========+========+========+========+========+========+========+========+========+========+========+========+
    |        |        |        | Accl0  |        |        |        | WhlLft | Up     | WhlRgt | Btn2   |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        | LftMos | Accl2  | Btn2   | Btn1   | Accl1  | WhlUp  | Left   | Down   | Right  | Btn4   | Btn5   |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        |        |        |        | Btn3   |        | WhlDwn | Btn1   |        |        | Btn3   |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        |        |        |        |        | >>><<< | >>><<< |        |        |        |        |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   */
  [_MOUSECURSOR] = {
    { _______, _______, _______, KC_ACL0, _______, _______, _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_BTN2, _______},
    { _______, LMCURSR, KC_ACL2, KC_BTN2, KC_BTN1, KC_ACL1, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN4, KC_BTN5},
    { _______, _______, _______, _______, KC_BTN3, _______, KC_WH_D, KC_BTN1, _______, _______, KC_BTN3, _______},
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  },

  /* Left Mouse Layer
    +========+========+========+========+========+========+========+========+========+========+========+========+
    | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
    +========+========+========+========+========+========+========+========+========+========+========+========+
    |        |        | WhlLft | Up     | WhlRgt | Btn2   |        |        |        |        |        |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        | >>><<< | Left   | Down   | Right  | WhlUp  |        |        |        |        |        |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        |        |        | Btn3   | Btn1   | WhlDwn |        |        |        |        |        |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        |        |        |        |        | >>><<< | >>><<< |        |        |        |        |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   */
  [_LFTMCURSOR] = {
    { _______, _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_BTN2, _______, _______, _______, _______, _______, _______},
    { _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, _______, _______, _______, _______, _______, _______},
    { _______, _______, _______, KC_BTN3, KC_BTN1, KC_WH_D, _______, _______, _______, _______, _______, _______},
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  },

  /* Numpad Layer
    +========+========+========+========+========+========+========+========+========+========+========+========+
    | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
    +========+========+========+========+========+========+========+========+========+========+========+========+
    |        | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | Bksp   |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    | ^      | @      | A      | B      | C      | (      | )      | 4      | 5      | 6      | ¦      | Enter  |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    | &      | #      | D      | E      | F      | [      | ]      | 1      | 2      | 3      | /      | *      |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        |        | >>><<< |        | X      |        |        | 0      | .      | ,      | +      | -      |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   */
  [_NUMPAD] = {
    { _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______},
    { BR_NDTD, KC_AT  , KC_A   , KC_B   , KC_C   , KC_RPRN, KC_LPRN, KC_4   , KC_5   , KC_6   , BR_PIPE, KC_ENT },
    { KC_AMPR, KC_HASH, KC_D   , KC_E   , KC_F   , BR_RBRC, BR_LBRC, KC_1   , KC_2   , KC_3   , BR_SLSH, KC_ASTR},
    { _______, _______, TG_NP  , _______, KC_X   , _______, _______, KC_0   , KC_DOT , KC_COMM, KC_PLUS, KC_MINS}
  },

  /* Util layer
    +========+========+========+========+========+========+========+========+========+========+========+========+
    | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
    +========+========+========+========+========+========+========+========+========+========+========+========+
    |        |        | Calc   | MyComp |        |        |        |        | WebRfr | WebFav |        |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        | WebBck | WebHom | Cut    | Copy   | Paste  | Undo   | Find   | Mail   | WebStp | WebFwd |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        | Power  |        |        |        |        |        |        |        |        |        |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        | Sleep  | Wake   |        |        |        |        |        |        | >>><<< |        |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   */
  [_UTIL] = {
    { XXXXXXX, XXXXXXX, KC_CALC, KC_MYCM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WREF, KC_WFAV, XXXXXXX, XXXXXXX},
    { XXXXXXX, KC_WBAK, KC_WHOM, KC_CUT , KC_COPY, KC_PAST, KC_UNDO, KC_FIND, KC_MAIL, KC_WSTP, KC_WFWD, XXXXXXX},
    { XXXXXXX, KC_PWR , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
    { XXXXXXX, KC_SLEP, KC_WAKE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX}
  },

  /* Nexus (Lower + Raise)
    +========+========+========+========+========+========+========+========+========+========+========+========+
    | __01__ | __02__ | __03__ | __04__ | __05__ | __06__ | __07__ | __08__ | __09__ | __10__ | __11__ | __12__ |
    +========+========+========+========+========+========+========+========+========+========+========+========+
    | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        | Mute   | Vol -  | Vol +  | Prev   | QWERTY | DVORAK | Next   | Play   | Rwd    | Fwd    |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        |        | Intl   |        | CGnorm | AGnorm | AGswap | CGswap |        | Game   |        |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |        |        | Reset  |        | >>><<< | OnHnd  | OnHnd  | >>><<< |        |        |        |        |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   */
  [_NEXUS] = {
    { KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 },
    { _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, QWERTY , DVORAK , KC_MNXT, KC_MPLY, KC_MRWD, KC_MFFD, _______},
    { _______, XXXXXXX, XXXXXXX, XXXXXXX, SWP_OFF, AG_NORM, AG_SWAP, SWP_OFF, XXXXXXX, GAME   , XXXXXXX, _______},
    { _______, _______, RESET  , _______, _______, TG_OH  , TG_OH  , _______, _______, _______, _______, _______}
  }

};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

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
    case GAME:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_GAMING);
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

const uint16_t PROGMEM fn_actions[] = {
  [FN_SWAP_HANDS] = ACTION_SWAP_HANDS(),
  [FN_SWAP_HDOFF] = ACTION_SWAP_HANDS_OFF(),
  [FN_TGGL_NUMPD] = ACTION_LAYER_TAP_TOGGLE(_NUMPAD),
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
};