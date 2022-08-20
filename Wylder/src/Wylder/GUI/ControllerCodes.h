#pragma once
/*! @defgroup hat_state Joystick hat states
 *  @brief Joystick hat states.
 *
 *  See [joystick hat input](@ref joystick_hat) for how these are used.
 *
 *  @ingroup input
 *  @{ */
#define WY_HAT_CENTERED           0
#define WY_HAT_UP                 1
#define WY_HAT_RIGHT              2
#define WY_HAT_DOWN               4
#define WY_HAT_LEFT               8
#define WY_HAT_RIGHT_UP           (WY_HAT_RIGHT | WY_HAT_UP)
#define WY_HAT_RIGHT_DOWN         (WY_HAT_RIGHT | WY_HAT_DOWN)
#define WY_HAT_LEFT_UP            (WY_HAT_LEFT  | WY_HAT_UP)
#define WY_HAT_LEFT_DOWN          (WY_HAT_LEFT  | WY_HAT_DOWN)
 /*! @} */


/*! @defgroup joysticks Joysticks
*  @brief Joystick IDs.
*
*  See [joystick input](@ref joystick) for how these are used.
*
*  @ingroup input
*  @{ */
#define WY_JOYSTICK_1             0
#define WY_JOYSTICK_2             1
#define WY_JOYSTICK_3             2
#define WY_JOYSTICK_4             3
#define WY_JOYSTICK_5             4
#define WY_JOYSTICK_6             5
#define WY_JOYSTICK_7             6
#define WY_JOYSTICK_8             7
#define WY_JOYSTICK_9             8
#define WY_JOYSTICK_10            9
#define WY_JOYSTICK_11            10
#define WY_JOYSTICK_12            11
#define WY_JOYSTICK_13            12
#define WY_JOYSTICK_14            13
#define WY_JOYSTICK_15            14
#define WY_JOYSTICK_16            15
#define WY_JOYSTICK_LAST          WY_JOYSTICK_16
/*! @} */


/*! @defgroup gamepad_buttons Gamepad buttons
*  @brief Gamepad buttons.
*
*  See @ref gamepad for how these are used.
*
*  @ingroup input
*  @{ */
#define WY_GAMEPAD_BUTTON_A               0
#define WY_GAMEPAD_BUTTON_B               1
#define WY_GAMEPAD_BUTTON_X               2
#define WY_GAMEPAD_BUTTON_Y               3
#define WY_GAMEPAD_BUTTON_LEFT_BUMPER     4
#define WY_GAMEPAD_BUTTON_RIGHT_BUMPER    5
#define WY_GAMEPAD_BUTTON_BACK            6
#define WY_GAMEPAD_BUTTON_START           7
#define WY_GAMEPAD_BUTTON_GUIDE           8
#define WY_GAMEPAD_BUTTON_LEFT_THUMB      9
#define WY_GAMEPAD_BUTTON_RIGHT_THUMB     10
#define WY_GAMEPAD_BUTTON_DPAD_UP         11
#define WY_GAMEPAD_BUTTON_DPAD_RIGHT      12
#define WY_GAMEPAD_BUTTON_DPAD_DOWN       13
#define WY_GAMEPAD_BUTTON_DPAD_LEFT       14
#define WY_GAMEPAD_BUTTON_LAST            WY_GAMEPAD_BUTTON_DPAD_LEFT

#define WY_GAMEPAD_BUTTON_CROSS       WY_GAMEPAD_BUTTON_A
#define WY_GAMEPAD_BUTTON_CIRCLE      WY_GAMEPAD_BUTTON_B
#define WY_GAMEPAD_BUTTON_SQUARE      WY_GAMEPAD_BUTTON_X
#define WY_GAMEPAD_BUTTON_TRIANGLE    WY_GAMEPAD_BUTTON_Y
/*! @} */


/*! @defgroup gamepad_axes Gamepad axes
*  @brief Gamepad axes.
*
*  See @ref gamepad for how these are used.
*
*  @ingroup input
*  @{ */
#define WY_GAMEPAD_AXIS_LEFT_X        0
#define WY_GAMEPAD_AXIS_LEFT_Y        1
#define WY_GAMEPAD_AXIS_RIGHT_X       2
#define WY_GAMEPAD_AXIS_RIGHT_Y       3
#define WY_GAMEPAD_AXIS_LEFT_TRIGGER  4
#define WY_GAMEPAD_AXIS_RIGHT_TRIGGER 5
#define WY_GAMEPAD_AXIS_LAST          WY_GAMEPAD_AXIS_RIGHT_TRIGGER
/*! @} */