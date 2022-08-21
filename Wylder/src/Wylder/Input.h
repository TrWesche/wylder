#pragma once
#include "wypch.h"
#include "Wylder/Core.h"

namespace Wylder {
	class WYLDER_API Input {
	private:
		// We are creating a static instance when constructed - instantiation with static makes this act as a singleton
		static Input* sInstance;
		
	public:
		inline static bool IsKeyPressed(const int keycode) { return sInstance->IsKeyPressedImpl(keycode); }

		inline static bool IsMouseButtonPressed(const int button) { return sInstance->IsMouseButtonPressedImpl(button); }
		inline static std::pair<float, float> GetMousePosition() { return sInstance->GetMousePositionImpl(); }
		inline static float GetMousePosX() { return sInstance->GetMousePosXImpl(); }
		inline static float GetMousePosY() { return sInstance->GetMousePosYImpl(); }

	protected:
		// The protetected functions will be implemented per platform to allow for abstraction between the function 
		// available for the rest of the code base and the functions called on a per-platform basis.

		// This function will return true if the queried key is pressed and false if it is not
		virtual bool IsKeyPressedImpl(const int keycode) = 0;

		// This function will return true if the queried mouse button is pressed and false if it is not
		virtual bool IsMouseButtonPressedImpl(const int button) = 0;

		virtual std::pair<float, float> GetMousePositionImpl() = 0;

		virtual float GetMousePosXImpl() = 0;

		virtual float GetMousePosYImpl() = 0;
	};
}