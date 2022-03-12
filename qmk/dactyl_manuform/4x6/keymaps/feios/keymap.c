/*
 * @Author: feiosme
 * @LastEditors: Please set LastEditors
 * @Description: 
 */
#include QMK_KEYBOARD_H

#define _BASE 0
#define _RAISE 1
#define _LOWER 2
#define _ADJUST 3

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2
#define MS_WHU KC_MS_WH_UP
#define MS_WHD KC_MS_WH_DOWN

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define ADJUST MO(_ADJUST)

#define SCREEN4 LSG(KC_4)
#define SRN4_S G(C(S(KC_4)))
#define SCREENU KC_BRIGHTNESS_UP
#define SCREEND KC_BRIGHTNESS_DOWN
#define CTRL_U LCTL(KC_UP)
#define CTRL_D LCTL(KC_DOWN)
#define CTRL_L LCTL(KC_LEFT)
#define CTRL_R LCTL(KC_RIGHT)

#define PAGE_L LCTL(S(KC_TAB))
#define PAGE_R LCTL(KC_TAB)

enum my_keycodes {
  LSPC,
  RSPC,
};

bool is_space_active = false;
bool is_lspc_active = false;
bool is_rspc_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LSPC:
        if (record->event.pressed) {
            if (!is_space_active) {
                is_space_active = true;
                register_code(KC_SPC);
            }
            is_lspc_active = true;
        } 
        else {
            if (is_space_active && !is_rspc_active) {
                unregister_code(KC_SPC);
                is_space_active = false;
            }
            is_lspc_active = false;
        }
        return false; // Skip all further processing of this key
    case RSPC:
        if (record->event.pressed) {
            if (!is_space_active) {
                is_space_active = true;
                register_code(KC_SPC);
            }
            is_rspc_active = true;
        } 
        else {
            if (is_space_active && !is_lspc_active) {
                unregister_code(KC_SPC);
                is_space_active = false;
            }
            is_rspc_active = false;
        }
        return false; // Skip all further processing of this key
    default:
      return true; // Process all other keys normally
     }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     * +-----------------------------------------+                             +-----------------------------------------+
     * | ESC  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |      |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | TAB  |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |      |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | SHFT |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |      |
     * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
     *               |  [   |   ]  |                                                         |      |      |
     *               +-------------+-------------+                             +-------------+-------------+
     *                             |      |      |                             |      |      |
     *                             |------+------|                             |------+------|
     *                             |      |      |                             |      |      |
     *                             +-------------+                             +-------------+
     *                                           +-------------+ +-------------+
     *                                           |      |      | |      |      |
     *                                           |------+------| |------+------|
     *                                           |      |      | |      |      |
     *                                           +-------------+ +-------------+
     */
    [_BASE] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                          KC_LBRC, KC_RBRC,                                                KC_BSPC, KC_EQL,
                                            RAISE,   LSPC,               RSPC,  LOWER,
                                            KC_TAB,  KC_LGUI,            KC_RGUI, KC_ENT,
                                            KC_BSPC, KC_GRV,             KC_LCTL, KC_LALT
    ),

    [_LOWER] = LAYOUT(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_LBRC,             KC_RBRC, KC_P7,   KC_P8,   KC_P9,   RESET,   KC_PLUS,
        _______, KC_5,    KC_6,    KC_7,    KC_8,    KC_LPRN,             KC_RPRN, KC_P4,   KC_P5,   KC_P6,   KC_MINS, KC_PIPE,
        _______, KC_9,    KC_0,    _______, _______, _______,             _______, KC_P1,   KC_P2,   KC_P3,   KC_EQL,  KC_UNDS,
                          _______, _______,                                                 ADJUST , KC_P0,
                                            _______, _______,             _______, _______,
                                            _______, _______,             _______, _______,
                                            KC_DEL,  _______,             _______, _______
    ),

    [_RAISE] = LAYOUT(
        _______, _______, SRN4_S,  KC_UP,   SCREEN4, KC_LBRC,             KC_RBRC, _______, KC_MU  , KC_INS , KC_NLCK, KC_MUTE,
        RESET,   _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_LPRN,             KC_RPRN, KC_ML  , KC_MD  , KC_MR  , MS_WHU , KC_VOLU,
        _______, PAGE_L,  CTRL_L,  CTRL_U,  CTRL_R,  PAGE_R,              _______, KC_MPRV, KC_MPLY, KC_MNXT, MS_WHD , KC_VOLD,
                          _______, CTRL_D,                                                  SCREEND, SCREENU,
                                            _______, _______,             KC_MB1 , KC_MB2 ,
                                            _______, _______,             _______, _______,
                                            BL_TOGG, BL_STEP,             _______, _______
    ),

    [_ADJUST] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,    _______,            _______, _______, _______, _______, _______, _______,
        _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,    _______,            _______, _______, _______, _______, _______, _______,
        _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______,            _______, _______, _______, _______, _______, _______,
                          _______, _______,                                                 _______, _______,
                                            _______, _______,             _______, _______,
                                            _______, _______,             _______, _______,
                                            _______, _______,             _______, _______
    )
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}
