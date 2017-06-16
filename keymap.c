// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16
#define _NUMPAD 17
#define _EXIT_L M(10)
#define _GSHLLREL M(15)


enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT,
  NUMPAD,
  EXIT_L,
  TFINSAL,
  TSKMNGR,
  TERMINL,
  W_WKSUP,
  W_WKSDN,
  U_WKSUP,
  U_WKSDN,
  GSHLLREL

};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define TFINSAL LCTL(LALT(KC_DEL))    //three finger salute
#define TSKMNGR LCTL(S(KC_ESC))       //windows taskmanager
#define TERMINL LCTL(LALT(KC_T))      //Ubuntu terminal
#define W_WKSUP LGUI(LCTL(KC_LEFT))  //Windows Workstation up
#define W_WKSDN LGUI(LCTL(KC_RIGHT))   //Windows Workstation down
#define U_WKSUP LGUI(KC_PGUP)         //Ubuntu Workstation up
#define U_WKSDN LGUI(KC_PGDN)         //Ubuntu Workstation down


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Numpad| GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,  KC_Q,       KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,  KC_A,       KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN, KC_ENT},
  {KC_LSFT, KC_Z,       KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, KC_QUOT },
  {KC_LCTL, MO(_NUMPAD), KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT,  KC_DOWN, KC_UP,   KC_RIGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Home | End  | Play |   |  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Prev | Stop | Next |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL},
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HOME, KC_END,  KC_MPLY, KC_PIPE, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MSTP, KC_MNXT, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Ins  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |Pg Up | Pg Dn|      |  \   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Vol- | Vol+ | Mute |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_INS},
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______},
  {KC_CAPS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PGUP, KC_PGDN, XXXXXXX, KC_BSLS, XXXXXXX},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______}
},


/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  _______, _______,  _______,  _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |NumLoc|3finSl|gshlrl|W_Wup |W_Wdn |      |  /   |  7   |  8   |  9   | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Scrloc|TskMgr|Termnl|U_Wup |U_Wdn |      |Bcklit|  4   |  5   |  6   |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Calc |      |      |      |      |      |      |  1   |  2   |  3   |  *   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |  0   |  .   |  +   |  -   |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = {
  {_______, KC_NLCK,  TFINSAL, _GSHLLREL, W_WKSUP,  W_WKSDN,  _______, KC_PSLS, KC_P7,   KC_P8,    KC_P9,  KC_BSPC},
  {_______, KC_SLCK,  TSKMNGR, TERMINL,   U_WKSUP,  U_WKSDN,  _______, BACKLIT, KC_P4,   KC_P5,    KC_P6,  KC_PENT},
  {_______, KC_CALC,  _______, _______,   _______,  _______,  _______, _______, KC_P1,   KC_P2,    KC_P3,  KC_PAST},
  {_______, _______,  _______, _______,   _______,  _______,  _______, _______, KC_P0,   KC_PDOT,  KC_PPLS, KC_PMNS}
}

};

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
    /*case NUMPAD:
      if (record->event.pressed) {
        #ifdef BACKLIGHT_ENABLE
          breathing_speed_dec(0);
          breathing_enable();
        #endif

        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_NUMPAD);
      }
      return false;
      break;
    case EXIT_L:
      if (record->event.pressed) {
        #ifdef BACKLIGHT_ENABLE
          breathing_disable();
        #endif

        layer_off(_NUMPAD);
      }
      return false;
      break;*/
  }
  return true;
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {  
  switch (id) {
    case 15: // Gnome Shell Reload
      if (record->event.pressed) {
        return MACRO(D(LALT), T(F2), U(LALT), W(255), T(R), T(ENT), END);
      }
      break;
  }

  return MACRO_NONE;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
