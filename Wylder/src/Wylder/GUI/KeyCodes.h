#pragma once
 /*! @defgroup keys Keyboard keys
  *  @brief Keyboard key IDs.
  *
  *  See [key input](@ref input_key) for how these are used.
  *
  *  These key codes are inspired by the _USB HID Usage Tables v1.12_ (p. 53-60),
  *  but re-arranged to map to 7-bit ASCII for printable keys (function keys are
  *  put in the 256+ range).
  *
  *  The naming of the key codes follow these rules:
  *   - The US keyboard layout is used
  *   - Names of printable alphanumeric characters are used (e.g. "A", "R",
  *     "3", etc.)
  *   - For non-alphanumeric characters, Unicode:ish names are used (e.g.
  *     "COMMA", "LEFT_SQUARE_BRACKET", etc.). Note that some names do not
  *     correspond to the Unicode standard (usually for brevity)
  *   - Keys that lack a clear US mapping are named "WORLD_x"
  *   - For non-printable keys, custom names are used (e.g. "F4",
  *     "BACKSPACE", etc.)
  *
  *  @ingroup input
  *  @{
  */

  /* The unknown key */
#define WY_KEY_UNKNOWN            -1

/* Printable keys */
#define WY_KEY_SPACE              32
#define WY_KEY_APOSTROPHE         39  /* ' */
#define WY_KEY_COMMA              44  /* , */
#define WY_KEY_MINUS              45  /* - */
#define WY_KEY_PERIOD             46  /* . */
#define WY_KEY_SLASH              47  /* / */
#define WY_KEY_0                  48
#define WY_KEY_1                  49
#define WY_KEY_2                  50
#define WY_KEY_3                  51
#define WY_KEY_4                  52
#define WY_KEY_5                  53
#define WY_KEY_6                  54
#define WY_KEY_7                  55
#define WY_KEY_8                  56
#define WY_KEY_9                  57
#define WY_KEY_SEMICOLON          59  /* ; */
#define WY_KEY_EQUAL              61  /* = */
#define WY_KEY_A                  65
#define WY_KEY_B                  66
#define WY_KEY_C                  67
#define WY_KEY_D                  68
#define WY_KEY_E                  69
#define WY_KEY_F                  70
#define WY_KEY_G                  71
#define WY_KEY_H                  72
#define WY_KEY_I                  73
#define WY_KEY_J                  74
#define WY_KEY_K                  75
#define WY_KEY_L                  76
#define WY_KEY_M                  77
#define WY_KEY_N                  78
#define WY_KEY_O                  79
#define WY_KEY_P                  80
#define WY_KEY_Q                  81
#define WY_KEY_R                  82
#define WY_KEY_S                  83
#define WY_KEY_T                  84
#define WY_KEY_U                  85
#define WY_KEY_V                  86
#define WY_KEY_W                  87
#define WY_KEY_X                  88
#define WY_KEY_Y                  89
#define WY_KEY_Z                  90
#define WY_KEY_LEFT_BRACKET       91  /* [ */
#define WY_KEY_BACKSLASH          92  /* \ */
#define WY_KEY_RIGHT_BRACKET      93  /* ] */
#define WY_KEY_GRAVE_ACCENT       96  /* ` */
#define WY_KEY_WORLD_1            161 /* non-US #1 */
#define WY_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define WY_KEY_ESCAPE             256
#define WY_KEY_ENTER              257
#define WY_KEY_TAB                258
#define WY_KEY_BACKSPACE          259
#define WY_KEY_INSERT             260
#define WY_KEY_DELETE             261
#define WY_KEY_RIGHT              262
#define WY_KEY_LEFT               263
#define WY_KEY_DOWN               264
#define WY_KEY_UP                 265
#define WY_KEY_PAGE_UP            266
#define WY_KEY_PAGE_DOWN          267
#define WY_KEY_HOME               268
#define WY_KEY_END                269
#define WY_KEY_CAPS_LOCK          280
#define WY_KEY_SCROLL_LOCK        281
#define WY_KEY_NUM_LOCK           282
#define WY_KEY_PRINT_SCREEN       283
#define WY_KEY_PAUSE              284
#define WY_KEY_F1                 290
#define WY_KEY_F2                 291
#define WY_KEY_F3                 292
#define WY_KEY_F4                 293
#define WY_KEY_F5                 294
#define WY_KEY_F6                 295
#define WY_KEY_F7                 296
#define WY_KEY_F8                 297
#define WY_KEY_F9                 298
#define WY_KEY_F10                299
#define WY_KEY_F11                300
#define WY_KEY_F12                301
#define WY_KEY_F13                302
#define WY_KEY_F14                303
#define WY_KEY_F15                304
#define WY_KEY_F16                305
#define WY_KEY_F17                306
#define WY_KEY_F18                307
#define WY_KEY_F19                308
#define WY_KEY_F20                309
#define WY_KEY_F21                310
#define WY_KEY_F22                311
#define WY_KEY_F23                312
#define WY_KEY_F24                313
#define WY_KEY_F25                314
#define WY_KEY_KP_0               320
#define WY_KEY_KP_1               321
#define WY_KEY_KP_2               322
#define WY_KEY_KP_3               323
#define WY_KEY_KP_4               324
#define WY_KEY_KP_5               325
#define WY_KEY_KP_6               326
#define WY_KEY_KP_7               327
#define WY_KEY_KP_8               328
#define WY_KEY_KP_9               329
#define WY_KEY_KP_DECIMAL         330
#define WY_KEY_KP_DIVIDE          331
#define WY_KEY_KP_MULTIPLY        332
#define WY_KEY_KP_SUBTRACT        333
#define WY_KEY_KP_ADD             334
#define WY_KEY_KP_ENTER           335
#define WY_KEY_KP_EQUAL           336
#define WY_KEY_LEFT_SHIFT         340
#define WY_KEY_LEFT_CONTROL       341
#define WY_KEY_LEFT_ALT           342
#define WY_KEY_LEFT_SUPER         343
#define WY_KEY_RIGHT_SHIFT        344
#define WY_KEY_RIGHT_CONTROL      345
#define WY_KEY_RIGHT_ALT          346
#define WY_KEY_RIGHT_SUPER        347
#define WY_KEY_MENU               348

#define WY_KEY_LAST               WY_KEY_MENU
/*! @} */



/*! @defgroup mods Modifier key flags
*  @brief Modifier key flags.
*
*  See [key input](@ref input_key) for how these are used.
*
*  @ingroup input
*  @{ */

/*! @brief If this bit is set one or more Shift keys were held down.
*
*  If this bit is set one or more Shift keys were held down.
*/
#define WY_MOD_SHIFT           0x0001
/*! @brief If this bit is set one or more Control keys were held down.
*
*  If this bit is set one or more Control keys were held down.
*/
#define WY_MOD_CONTROL         0x0002
/*! @brief If this bit is set one or more Alt keys were held down.
*
*  If this bit is set one or more Alt keys were held down.
*/
#define WY_MOD_ALT             0x0004
/*! @brief If this bit is set one or more Super keys were held down.
*
*  If this bit is set one or more Super keys were held down.
*/
#define WY_MOD_SUPER           0x0008
/*! @brief If this bit is set the Caps Lock key is enabled.
*
*  If this bit is set the Caps Lock key is enabled and the @ref
*  WY_LOCK_KEY_MODS input mode is set.
*/
#define WY_MOD_CAPS_LOCK       0x0010
/*! @brief If this bit is set the Num Lock key is enabled.
*
*  If this bit is set the Num Lock key is enabled and the @ref
*  WY_LOCK_KEY_MODS input mode is set.
*/
#define WY_MOD_NUM_LOCK        0x0020


#define WY_MOD_LEFT_SHIFT		0x1000
#define WY_MOD_LEFT_CONTROL		0x2000
#define WY_MOD_LEFT_ALT			0x4000

#define WY_MOD_RIGHT_SHIFT		0x0100
#define WY_MOD_RIGHT_CONTROL	0x0200
#define WY_MOD_RIGHT_ALT		0x0400

/*! @} */