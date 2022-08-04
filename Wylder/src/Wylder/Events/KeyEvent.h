#pragma once

#include "Event.h"


namespace Wylder {
	class WYLDER_API KeyEvent : public Event {
	public:
		// Macro Functions
		EVENT_CATEGORY_FLAGS(EventCategoryInput, EventCategoryKeyboard);

		// Instance Functions
		inline int GetKeyCode() { return mKeyCode; }
	protected:
		// Constructor
		KeyEvent(int keycode) : mKeyCode(keycode) {}
		int mKeyCode;
	};


	class WYLDER_API KeyPressedEvent : public KeyEvent {
	public:
		// Constructor
		KeyPressedEvent(int keycode, int repeatcount) : KeyEvent(keycode), mRepeatCount(repeatcount) {}

		// Macro Functions
		EVENT_CLASS_TYPE(KeyPressed);

		// Instance Functions
		inline int GetRepetCount() const { return mRepeatCount; }

		virtual std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << mKeyCode << " x " << mRepeatCount;
			return ss.str();
		}
	private:
		int mRepeatCount;
	};


	class WYLDER_API KeyReleasedEvent : public KeyEvent {
	public:
		// Constructor
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

		// Macro Functions
		EVENT_CLASS_TYPE(KeyPressed);

		// Instance Functions
		virtual std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << mKeyCode;
			return ss.str();
		}
	private:
		
	};
}