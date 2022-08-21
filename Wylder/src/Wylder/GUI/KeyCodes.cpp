#pragma once

#include "wypch.h"
#include "KeyCodes.h"
#include "GLFW/glfw3.h"

namespace Wylder {
	#ifdef WY_OPENGL_USE_GLFW
	WylderKey ExtKeyToWylderKey(int extKeycode)
	{
        switch (extKeycode)
        {
            case GLFW_KEY_TAB:              return WY_KEY_TAB;
            case GLFW_KEY_LEFT:             return WY_KEY_LEFT;
            case GLFW_KEY_RIGHT:            return WY_KEY_RIGHT;
            case GLFW_KEY_UP:               return WY_KEY_UP;
            case GLFW_KEY_DOWN:             return WY_KEY_DOWN;
            case GLFW_KEY_PAGE_UP:          return WY_KEY_PAGE_UP;
            case GLFW_KEY_PAGE_DOWN:        return WY_KEY_PAGE_DOWN;
            case GLFW_KEY_HOME:             return WY_KEY_HOME;
            case GLFW_KEY_END:              return WY_KEY_END;
            case GLFW_KEY_INSERT:           return WY_KEY_INSERT;
            case GLFW_KEY_DELETE:           return WY_KEY_DELETE;
            case GLFW_KEY_BACKSPACE:        return WY_KEY_BACKSPACE;
            case GLFW_KEY_SPACE:            return WY_KEY_SPACE;
            case GLFW_KEY_ENTER:            return WY_KEY_ENTER;
            case GLFW_KEY_ESCAPE:           return WY_KEY_ESCAPE;
            case GLFW_KEY_APOSTROPHE:       return WY_KEY_APOSTROPHE;
            case GLFW_KEY_COMMA:            return WY_KEY_COMMA;
            case GLFW_KEY_MINUS:            return WY_KEY_MINUS;
            case GLFW_KEY_PERIOD:           return WY_KEY_PERIOD;
            case GLFW_KEY_SLASH:            return WY_KEY_SLASH;
            case GLFW_KEY_SEMICOLON:        return WY_KEY_SEMICOLON;
            case GLFW_KEY_EQUAL:            return WY_KEY_EQUAL;
            case GLFW_KEY_LEFT_BRACKET:     return WY_KEY_LEFT_BRACKET;
            case GLFW_KEY_BACKSLASH:        return WY_KEY_BACKSLASH;
            case GLFW_KEY_RIGHT_BRACKET:    return WY_KEY_RIGHT_BRACKET;
            case GLFW_KEY_GRAVE_ACCENT:     return WY_KEY_GRAVE_ACCENT;
            case GLFW_KEY_CAPS_LOCK:        return WY_KEY_CAPS_LOCK;
            case GLFW_KEY_SCROLL_LOCK:      return WY_KEY_SCROLL_LOCK;
            case GLFW_KEY_NUM_LOCK:         return WY_KEY_NUM_LOCK;
            case GLFW_KEY_PRINT_SCREEN:     return WY_KEY_PRINT_SCREEN;
            case GLFW_KEY_PAUSE:            return WY_KEY_PAUSE;
            case GLFW_KEY_KP_0:             return WY_KEY_KP_0;
            case GLFW_KEY_KP_1:             return WY_KEY_KP_1;
            case GLFW_KEY_KP_2:             return WY_KEY_KP_2;
            case GLFW_KEY_KP_3:             return WY_KEY_KP_3;
            case GLFW_KEY_KP_4:             return WY_KEY_KP_4;
            case GLFW_KEY_KP_5:             return WY_KEY_KP_5;
            case GLFW_KEY_KP_6:             return WY_KEY_KP_6;
            case GLFW_KEY_KP_7:             return WY_KEY_KP_7;
            case GLFW_KEY_KP_8:             return WY_KEY_KP_8;
            case GLFW_KEY_KP_9:             return WY_KEY_KP_9;
            case GLFW_KEY_KP_DECIMAL:       return WY_KEY_KP_DECIMAL;
            case GLFW_KEY_KP_DIVIDE:        return WY_KEY_KP_DIVIDE;
            case GLFW_KEY_KP_MULTIPLY:      return WY_KEY_KP_MULTIPLY;
            case GLFW_KEY_KP_SUBTRACT:      return WY_KEY_KP_SUBTRACT;
            case GLFW_KEY_KP_ADD:           return WY_KEY_KP_ADD;
            case GLFW_KEY_KP_ENTER:         return WY_KEY_KP_ENTER;
            case GLFW_KEY_KP_EQUAL:         return WY_KEY_KP_EQUAL;
            case GLFW_KEY_LEFT_SHIFT:       return WY_KEY_LEFT_SHIFT;
            case GLFW_KEY_LEFT_CONTROL:     return WY_KEY_LEFT_CONTROL;
            case GLFW_KEY_LEFT_ALT:         return WY_KEY_LEFT_ALT;
            case GLFW_KEY_LEFT_SUPER:       return WY_KEY_LEFT_SUPER;
            case GLFW_KEY_RIGHT_SHIFT:      return WY_KEY_RIGHT_SHIFT;
            case GLFW_KEY_RIGHT_CONTROL:    return WY_KEY_RIGHT_CONTROL;
            case GLFW_KEY_RIGHT_ALT:        return WY_KEY_RIGHT_ALT;
            case GLFW_KEY_RIGHT_SUPER:      return WY_KEY_RIGHT_SUPER;
            case GLFW_KEY_MENU:             return WY_KEY_MENU;
            case GLFW_KEY_0:                return WY_KEY_0;
            case GLFW_KEY_1:                return WY_KEY_1;
            case GLFW_KEY_2:                return WY_KEY_2;
            case GLFW_KEY_3:                return WY_KEY_3;
            case GLFW_KEY_4:                return WY_KEY_4;
            case GLFW_KEY_5:                return WY_KEY_5;
            case GLFW_KEY_6:                return WY_KEY_6;
            case GLFW_KEY_7:                return WY_KEY_7;
            case GLFW_KEY_8:                return WY_KEY_8;
            case GLFW_KEY_9:                return WY_KEY_9;
            case GLFW_KEY_A:                return WY_KEY_A;
            case GLFW_KEY_B:                return WY_KEY_B;
            case GLFW_KEY_C:                return WY_KEY_C;
            case GLFW_KEY_D:                return WY_KEY_D;
            case GLFW_KEY_E:                return WY_KEY_E;
            case GLFW_KEY_F:                return WY_KEY_F;
            case GLFW_KEY_G:                return WY_KEY_G;
            case GLFW_KEY_H:                return WY_KEY_H;
            case GLFW_KEY_I:                return WY_KEY_I;
            case GLFW_KEY_J:                return WY_KEY_J;
            case GLFW_KEY_K:                return WY_KEY_K;
            case GLFW_KEY_L:                return WY_KEY_L;
            case GLFW_KEY_M:                return WY_KEY_M;
            case GLFW_KEY_N:                return WY_KEY_N;
            case GLFW_KEY_O:                return WY_KEY_O;
            case GLFW_KEY_P:                return WY_KEY_P;
            case GLFW_KEY_Q:                return WY_KEY_Q;
            case GLFW_KEY_R:                return WY_KEY_R;
            case GLFW_KEY_S:                return WY_KEY_S;
            case GLFW_KEY_T:                return WY_KEY_T;
            case GLFW_KEY_U:                return WY_KEY_U;
            case GLFW_KEY_V:                return WY_KEY_V;
            case GLFW_KEY_W:                return WY_KEY_W;
            case GLFW_KEY_X:                return WY_KEY_X;
            case GLFW_KEY_Y:                return WY_KEY_Y;
            case GLFW_KEY_Z:                return WY_KEY_Z;
            case GLFW_KEY_F1:               return WY_KEY_F1;
            case GLFW_KEY_F2:               return WY_KEY_F2;
            case GLFW_KEY_F3:               return WY_KEY_F3;
            case GLFW_KEY_F4:               return WY_KEY_F4;
            case GLFW_KEY_F5:               return WY_KEY_F5;
            case GLFW_KEY_F6:               return WY_KEY_F6;
            case GLFW_KEY_F7:               return WY_KEY_F7;
            case GLFW_KEY_F8:               return WY_KEY_F8;
            case GLFW_KEY_F9:               return WY_KEY_F9;
            case GLFW_KEY_F10:              return WY_KEY_F10;
            case GLFW_KEY_F11:              return WY_KEY_F11;
            case GLFW_KEY_F12:              return WY_KEY_F12;
            case GLFW_KEY_F13:              return WY_KEY_F13;
            case GLFW_KEY_F14:              return WY_KEY_F14;
            case GLFW_KEY_F15:              return WY_KEY_F15;
            case GLFW_KEY_F16:              return WY_KEY_F16;
            case GLFW_KEY_F17:              return WY_KEY_F17;
            case GLFW_KEY_F18:              return WY_KEY_F18;
            case GLFW_KEY_F19:              return WY_KEY_F19;
            case GLFW_KEY_F20:              return WY_KEY_F20;
            case GLFW_KEY_F21:              return WY_KEY_F21;
            case GLFW_KEY_F22:              return WY_KEY_F22;
            case GLFW_KEY_F23:              return WY_KEY_F23;
            case GLFW_KEY_F24:              return WY_KEY_F24;

            default: return WY_KEY_UNKOWN;
        }
	}

    WylderModifier ExtModifierToWylderModifier(int extModifier)
	{
        switch (extModifier)
        {
            case GLFW_MOD_SHIFT:            return WY_MOD_SHIFT;
            case GLFW_MOD_CONTROL:          return WY_MOD_CONTROL;
            case GLFW_MOD_ALT:              return WY_MOD_ALT;
            case GLFW_MOD_SUPER:            return WY_MOD_SUPER;
            case GLFW_MOD_CAPS_LOCK:        return WY_MOD_CAPS_LOCK;
            case GLFW_MOD_NUM_LOCK:         return WY_MOD_NUM_LOCK;

            default: return WY_MOD_NONE;
        }
	}


    WylderMouseButton ExtMouseButtonToWylderMouseButton(int extMouseButton)
	{
        switch (extMouseButton)
        {
        case GLFW_MOUSE_BUTTON_1:       return WY_MOUSE_BUTTON_1;
        case GLFW_MOUSE_BUTTON_2:       return WY_MOUSE_BUTTON_2;
        case GLFW_MOUSE_BUTTON_3:       return WY_MOUSE_BUTTON_3;
        case GLFW_MOUSE_BUTTON_4:       return WY_MOUSE_BUTTON_4;
        case GLFW_MOUSE_BUTTON_5:       return WY_MOUSE_BUTTON_5;
        case GLFW_MOUSE_BUTTON_6:       return WY_MOUSE_BUTTON_6;
        case GLFW_MOUSE_BUTTON_7:       return WY_MOUSE_BUTTON_7;
        case GLFW_MOUSE_BUTTON_8:       return WY_MOUSE_BUTTON_8;

        default: return WY_MOUSE_BUTTON_UNKNOWN;
        }
	}


    WylderGamepadButton ExtGamepadButtonToWylderGamepadButton(int extGPButton)
	{
		return WY_GAMEPAD_BUTTON_A;
	}

    WylderGamepadAxis ExtGamepadAxisToWylderGamepadAxis(int extGPAxis)
	{
		return WY_GAMEPAD_AXIS_LEFT_X;
	}

    WylderJoysticks ExtJoysticksToWylderJoysticks(int extJoystick)
	{
		return WY_JOYSTICK_1;
	}
	#endif
}