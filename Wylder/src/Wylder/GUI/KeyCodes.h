#pragma once

namespace Wylder {
	//typedef int WylderKey;					// -> enum WylderKey_				// Enum: A key identifier
	//typedef int WylderModifier;             // -> enum WylderModifier_          // Enum: A key identifier
	//typedef int WylderMouseButton;          // -> enum WylderMouseButton_       // Enum: A key identifier
	//typedef int WylderGamepadButton;        // -> enum WylderGamepadButton_     // Enum: A key identifier
	//typedef int WylderGamepadAxis;          // -> enum WylderGamepadAxis_       // Enum: A key identifier
	//typedef int WylderJoysticks;            // -> enum WylderJoysticks_         // Enum: A key identifier

	// Key Codes Pulled from GLFW Library - 2022-08-20

	/* Printable & Function Keys */
	enum WylderKey
	{
		WY_KEY_UNKOWN = -1,

		/* Printable keys */
		WY_KEY_SPACE = 32, WY_KEY_APOSTROPHE = 39 /* ' */, WY_KEY_COMMA = 44 /* , */, WY_KEY_MINUS = 45 /* - */, WY_KEY_PERIOD = 46 /* . */, WY_KEY_SLASH = 47 /* / */,
		WY_KEY_0 = 48, WY_KEY_1 = 49, WY_KEY_2 = 50, WY_KEY_3 = 51, WY_KEY_4 = 52, WY_KEY_5 = 53, WY_KEY_6 = 54, WY_KEY_7 = 55, WY_KEY_8 = 56, WY_KEY_9 = 57,
		WY_KEY_SEMICOLON = 59 /* ; */, WY_KEY_EQUAL = 61 /* = */,
		WY_KEY_A = 65, WY_KEY_B = 66, WY_KEY_C = 67, WY_KEY_D = 68, WY_KEY_E = 69, WY_KEY_F = 70, WY_KEY_G = 71, WY_KEY_H = 72, WY_KEY_I = 73, WY_KEY_J = 74,
		WY_KEY_K = 75, WY_KEY_L = 76, WY_KEY_M = 77, WY_KEY_N = 78, WY_KEY_O = 79, WY_KEY_P = 80, WY_KEY_Q = 81, WY_KEY_R = 82, WY_KEY_S = 83, WY_KEY_T = 84,
		WY_KEY_U = 85, WY_KEY_V = 86, WY_KEY_W = 87, WY_KEY_X = 88, WY_KEY_Y = 89, WY_KEY_Z = 90,
		WY_KEY_LEFT_BRACKET = 91 /* [ */, WY_KEY_BACKSLASH = 92 /* \ */, WY_KEY_RIGHT_BRACKET = 93 /* ] */, WY_KEY_GRAVE_ACCENT = 96 /* ` */,
		WY_KEY_WORLD_1 = 161 /* non-US #1 */, WY_KEY_WORLD_2 = 162 /* non-US #2 */,

		/* Function keys */
		WY_KEY_ESCAPE = 256, WY_KEY_ENTER = 257, WY_KEY_TAB = 258, WY_KEY_BACKSPACE = 259, WY_KEY_INSERT = 260, WY_KEY_DELETE = 261,
		WY_KEY_RIGHT = 262, WY_KEY_LEFT = 263, WY_KEY_DOWN = 264, WY_KEY_UP = 265,
		WY_KEY_PAGE_UP = 266, WY_KEY_PAGE_DOWN = 267, WY_KEY_HOME = 268, WY_KEY_END = 269,
		WY_KEY_CAPS_LOCK = 280, WY_KEY_SCROLL_LOCK = 281, WY_KEY_NUM_LOCK = 282, WY_KEY_PRINT_SCREEN = 283, WY_KEY_PAUSE = 284,

		WY_KEY_F1 = 290, WY_KEY_F2 = 291, WY_KEY_F3 = 292, WY_KEY_F4 = 293, WY_KEY_F5 = 294, WY_KEY_F6 = 295, WY_KEY_F7 = 296, WY_KEY_F8 = 297, WY_KEY_F9 = 298,
		WY_KEY_F10 = 299, WY_KEY_F11 = 300, WY_KEY_F12 = 301, WY_KEY_F13 = 302, WY_KEY_F14 = 303, WY_KEY_F15 = 304, WY_KEY_F16 = 305, WY_KEY_F17 = 306,
		WY_KEY_F18 = 307, WY_KEY_F19 = 308, WY_KEY_F20 = 309, WY_KEY_F21 = 310, WY_KEY_F22 = 311, WY_KEY_F23 = 312, WY_KEY_F24 = 313, WY_KEY_F25 = 314,

		WY_KEY_KP_0 = 320, WY_KEY_KP_1 = 321, WY_KEY_KP_2 = 322, WY_KEY_KP_3 = 323, WY_KEY_KP_4 = 324, WY_KEY_KP_5 = 325, WY_KEY_KP_6 = 326, WY_KEY_KP_7 = 327, WY_KEY_KP_8 = 328, WY_KEY_KP_9 = 329, WY_KEY_KP_DECIMAL = 330,
		WY_KEY_KP_DIVIDE = 331, WY_KEY_KP_MULTIPLY = 332, WY_KEY_KP_SUBTRACT = 333, WY_KEY_KP_ADD = 334, WY_KEY_KP_ENTER = 335, WY_KEY_KP_EQUAL = 336,

		WY_KEY_LEFT_SHIFT = 340, WY_KEY_LEFT_CONTROL = 341, WY_KEY_LEFT_ALT = 342, WY_KEY_LEFT_SUPER = 343, WY_KEY_RIGHT_SHIFT = 344, WY_KEY_RIGHT_CONTROL = 345, WY_KEY_RIGHT_ALT = 346, WY_KEY_RIGHT_SUPER = 347, WY_KEY_MENU = 348
	};

	/* Modifier Keys */
	enum WylderModifier
	{
		WY_MOD_NONE = 0x0000,

		WY_MOD_SHIFT = 0x0001,
		WY_MOD_CONTROL = 0x0002,
		WY_MOD_ALT = 0x0004,
		WY_MOD_SUPER = 0x0008,
		/*! @brief If this bit is set the Caps Lock key is enabled.
		*
		*  If this bit is set the Caps Lock key is enabled and the @ref
		*  WY_LOCK_KEY_MODS input mode is set.
		*/
		WY_MOD_CAPS_LOCK = 0x0010,
		/*! @brief If this bit is set the Num Lock key is enabled.
		*
		*  If this bit is set the Num Lock key is enabled and the @ref
		*  WY_LOCK_KEY_MODS input mode is set.
		*/
		WY_MOD_NUM_LOCK = 0x0020,


		WY_MOD_LEFT_SHIFT = 0x1000,
		WY_MOD_LEFT_CONTROL = 0x2000,
		WY_MOD_LEFT_ALT = 0x4000,

		WY_MOD_RIGHT_SHIFT = 0x0100,
		WY_MOD_RIGHT_CONTROL = 0x0200,
		WY_MOD_RIGHT_ALT = 0x0400
	};

	/* Mouse KeyCodes */
	enum WylderMouseButton
	{
		WY_MOUSE_BUTTON_1 = 0,
		WY_MOUSE_BUTTON_2 = 1,
		WY_MOUSE_BUTTON_3 = 2,
		WY_MOUSE_BUTTON_4 = 3,
		WY_MOUSE_BUTTON_5 = 4,
		WY_MOUSE_BUTTON_6 = 5,
		WY_MOUSE_BUTTON_7 = 6,
		WY_MOUSE_BUTTON_8 = 7,
		WY_MOUSE_BUTTON_LAST = WY_MOUSE_BUTTON_8,
		WY_MOUSE_BUTTON_LEFT = WY_MOUSE_BUTTON_1,
		WY_MOUSE_BUTTON_RIGHT = WY_MOUSE_BUTTON_2,
		WY_MOUSE_BUTTON_MIDDLE = WY_MOUSE_BUTTON_3,

		WY_MOUSE_BUTTON_UNKNOWN = -1
	};

	/* Gamepad Button Mappings */
	enum WylderGamepadButton
	{
		WY_GAMEPAD_BUTTON_A = 0, WY_GAMEPAD_BUTTON_B = 1, WY_GAMEPAD_BUTTON_X = 2, WY_GAMEPAD_BUTTON_Y = 3,
		WY_GAMEPAD_BUTTON_LEFT_BUMPER = 4, WY_GAMEPAD_BUTTON_RIGHT_BUMPER = 5,
		WY_GAMEPAD_BUTTON_BACK = 6, WY_GAMEPAD_BUTTON_START = 7, WY_GAMEPAD_BUTTON_GUIDE = 8,
		WY_GAMEPAD_BUTTON_LEFT_THUMB = 9, WY_GAMEPAD_BUTTON_RIGHT_THUMB = 10,
		WY_GAMEPAD_BUTTON_DPAD_UP = 11, WY_GAMEPAD_BUTTON_DPAD_RIGHT = 12, WY_GAMEPAD_BUTTON_DPAD_DOWN = 13, WY_GAMEPAD_BUTTON_DPAD_LEFT = 14,

		WY_GAMEPAD_BUTTON_LAST = WY_GAMEPAD_BUTTON_DPAD_LEFT,

		WY_GAMEPAD_BUTTON_CROSS = WY_GAMEPAD_BUTTON_A,
		WY_GAMEPAD_BUTTON_CIRCLE = WY_GAMEPAD_BUTTON_B,
		WY_GAMEPAD_BUTTON_SQUARE = WY_GAMEPAD_BUTTON_X,
		WY_GAMEPAD_BUTTON_TRIANGLE = WY_GAMEPAD_BUTTON_Y
	};

	/* Gamepad Axis Mappings */
	enum WylderGamepadAxis
	{
		WY_GAMEPAD_AXIS_LEFT_X = 0, WY_GAMEPAD_AXIS_LEFT_Y = 1,
		WY_GAMEPAD_AXIS_RIGHT_X = 2, WY_GAMEPAD_AXIS_RIGHT_Y = 3,
		WY_GAMEPAD_AXIS_LEFT_TRIGGER = 4, WY_GAMEPAD_AXIS_RIGHT_TRIGGER = 5,
		WY_GAMEPAD_AXIS_LAST = WY_GAMEPAD_AXIS_RIGHT_TRIGGER
	};

	/* Gamepad Joystick Mappings */
	enum WylderJoysticks
	{
		WY_JOYSTICK_1 = 0,
		WY_JOYSTICK_2 = 1,
		WY_JOYSTICK_3 = 2,
		WY_JOYSTICK_4 = 3,
		WY_JOYSTICK_5 = 4,
		WY_JOYSTICK_6 = 5,
		WY_JOYSTICK_7 = 6,
		WY_JOYSTICK_8 = 7,
		WY_JOYSTICK_9 = 8,
		WY_JOYSTICK_10 = 9,
		WY_JOYSTICK_11 = 10,
		WY_JOYSTICK_12 = 11,
		WY_JOYSTICK_13 = 12,
		WY_JOYSTICK_14 = 13,
		WY_JOYSTICK_15 = 14,
		WY_JOYSTICK_16 = 15,
		WY_JOYSTICK_LAST = WY_JOYSTICK_16
	};

	static WylderKey ExtKeyToWylderKey(int glfwKeycode);
	static WylderModifier ExtModifierToWylderModifier(int glfwModifier);
	static WylderMouseButton ExtMouseButtonToWylderMouseButton(int glfwMouseButton);
	static WylderGamepadButton ExtGamepadButtonToWylderGamepadButton(int glfwGPButton);
	static WylderGamepadAxis ExtGamepadAxisToWylderGamepadAxis(int glfwGPAxis);
	static WylderJoysticks ExtJoysticksToWylderJoysticks(int glfwJoystick);
}


//
///* The unknown key */
//#define WY_KEY_UNKNOWN            -1
//
///* Printable keys */
//#define WY_KEY_SPACE              32
//#define WY_KEY_APOSTROPHE         39  /* ' */
//#define WY_KEY_COMMA              44  /* , */
//#define WY_KEY_MINUS              45  /* - */
//#define WY_KEY_PERIOD             46  /* . */
//#define WY_KEY_SLASH              47  /* / */
//#define WY_KEY_0                  48
//#define WY_KEY_1                  49
//#define WY_KEY_2                  50
//#define WY_KEY_3                  51
//#define WY_KEY_4                  52
//#define WY_KEY_5                  53
//#define WY_KEY_6                  54
//#define WY_KEY_7                  55
//#define WY_KEY_8                  56
//#define WY_KEY_9                  57
//#define WY_KEY_SEMICOLON          59  /* ; */
//#define WY_KEY_EQUAL              61  /* = */
//#define WY_KEY_A                  65
//#define WY_KEY_B                  66
//#define WY_KEY_C                  67
//#define WY_KEY_D                  68
//#define WY_KEY_E                  69
//#define WY_KEY_F                  70
//#define WY_KEY_G                  71
//#define WY_KEY_H                  72
//#define WY_KEY_I                  73
//#define WY_KEY_J                  74
//#define WY_KEY_K                  75
//#define WY_KEY_L                  76
//#define WY_KEY_M                  77
//#define WY_KEY_N                  78
//#define WY_KEY_O                  79
//#define WY_KEY_P                  80
//#define WY_KEY_Q                  81
//#define WY_KEY_R                  82
//#define WY_KEY_S                  83
//#define WY_KEY_T                  84
//#define WY_KEY_U                  85
//#define WY_KEY_V                  86
//#define WY_KEY_W                  87
//#define WY_KEY_X                  88
//#define WY_KEY_Y                  89
//#define WY_KEY_Z                  90
//#define WY_KEY_LEFT_BRACKET       91  /* [ */
//#define WY_KEY_BACKSLASH          92  /* \ */
//#define WY_KEY_RIGHT_BRACKET      93  /* ] */
//#define WY_KEY_GRAVE_ACCENT       96  /* ` */
//#define WY_KEY_WORLD_1            161 /* non-US #1 */
//#define WY_KEY_WORLD_2            162 /* non-US #2 */
//
///* Function keys */
//#define WY_KEY_ESCAPE             256
//#define WY_KEY_ENTER              257
//#define WY_KEY_TAB                258
//#define WY_KEY_BACKSPACE          259
//#define WY_KEY_INSERT             260
//#define WY_KEY_DELETE             261
//#define WY_KEY_RIGHT              262
//#define WY_KEY_LEFT               263
//#define WY_KEY_DOWN               264
//#define WY_KEY_UP                 265
//#define WY_KEY_PAGE_UP            266
//#define WY_KEY_PAGE_DOWN          267
//#define WY_KEY_HOME               268
//#define WY_KEY_END                269
//#define WY_KEY_CAPS_LOCK          280
//#define WY_KEY_SCROLL_LOCK        281
//#define WY_KEY_NUM_LOCK           282
//#define WY_KEY_PRINT_SCREEN       283
//#define WY_KEY_PAUSE              284
//#define WY_KEY_F1                 290
//#define WY_KEY_F2                 291
//#define WY_KEY_F3                 292
//#define WY_KEY_F4                 293
//#define WY_KEY_F5                 294
//#define WY_KEY_F6                 295
//#define WY_KEY_F7                 296
//#define WY_KEY_F8                 297
//#define WY_KEY_F9                 298
//#define WY_KEY_F10                299
//#define WY_KEY_F11                300
//#define WY_KEY_F12                301
//#define WY_KEY_F13                302
//#define WY_KEY_F14                303
//#define WY_KEY_F15                304
//#define WY_KEY_F16                305
//#define WY_KEY_F17                306
//#define WY_KEY_F18                307
//#define WY_KEY_F19                308
//#define WY_KEY_F20                309
//#define WY_KEY_F21                310
//#define WY_KEY_F22                311
//#define WY_KEY_F23                312
//#define WY_KEY_F24                313
//#define WY_KEY_F25                314
//#define WY_KEY_KP_0               320
//#define WY_KEY_KP_1               321
//#define WY_KEY_KP_2               322
//#define WY_KEY_KP_3               323
//#define WY_KEY_KP_4               324
//#define WY_KEY_KP_5               325
//#define WY_KEY_KP_6               326
//#define WY_KEY_KP_7               327
//#define WY_KEY_KP_8               328
//#define WY_KEY_KP_9               329
//#define WY_KEY_KP_DECIMAL         330
//#define WY_KEY_KP_DIVIDE          331
//#define WY_KEY_KP_MULTIPLY        332
//#define WY_KEY_KP_SUBTRACT        333
//#define WY_KEY_KP_ADD             334
//#define WY_KEY_KP_ENTER           335
//#define WY_KEY_KP_EQUAL           336
//#define WY_KEY_LEFT_SHIFT         340
//#define WY_KEY_LEFT_CONTROL       341
//#define WY_KEY_LEFT_ALT           342
//#define WY_KEY_LEFT_SUPER         343
//#define WY_KEY_RIGHT_SHIFT        344
//#define WY_KEY_RIGHT_CONTROL      345
//#define WY_KEY_RIGHT_ALT          346
//#define WY_KEY_RIGHT_SUPER        347
//#define WY_KEY_MENU               348
//
//#define WY_KEY_LAST               WY_KEY_MENU
//
//
///* Modifier Keys */
//#define WY_MOD_SHIFT           0x0001
//#define WY_MOD_CONTROL         0x0002
//#define WY_MOD_ALT             0x0004
//#define WY_MOD_SUPER           0x0008
///*! @brief If this bit is set the Caps Lock key is enabled.
//*
//*  If this bit is set the Caps Lock key is enabled and the @ref
//*  WY_LOCK_KEY_MODS input mode is set.
//*/
//#define WY_MOD_CAPS_LOCK       0x0010
///*! @brief If this bit is set the Num Lock key is enabled.
//*
//*  If this bit is set the Num Lock key is enabled and the @ref
//*  WY_LOCK_KEY_MODS input mode is set.
//*/
//#define WY_MOD_NUM_LOCK        0x0020
//
//
//#define WY_MOD_LEFT_SHIFT		0x1000
//#define WY_MOD_LEFT_CONTROL		0x2000
//#define WY_MOD_LEFT_ALT			0x4000
//
//#define WY_MOD_RIGHT_SHIFT		0x0100
//#define WY_MOD_RIGHT_CONTROL	0x0200
//#define WY_MOD_RIGHT_ALT		0x0400
