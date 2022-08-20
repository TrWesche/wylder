#pragma once

#include "wypch.h"
#include "Wylder/Core.h"
#include "Wylder/Input.h"

namespace Wylder {
	class WindowsInput : public Input {
	public:

	protected:
		// This function will return true if the queried key is pressed and false if it is not
		bool IsKeyPressedImpl(const int keycode) override;

		// This function will return true if the queried mouse button is pressed and false if it is not
		bool IsMouseButtonPressedImpl(const int button) override;

		std::pair<float, float> GetMousePositionImpl() override;

		float GetMousePosXImpl() override;

		float GetMousePosYImpl() override;
	};
}