#pragma once

#include "Event.h"

namespace Wylder {
	class WYLDER_API WindowCloseEvent : public Event {
	public:
		// Constructor
		WindowCloseEvent() {}
		
		// Macro Functions
		EVENT_CLASS_TYPE(WindowClose);
		EVENT_CATEGORY_FLAGS(EventCategoryApplication);
	};


	class WYLDER_API WindowResizeEvent : public Event {
	public:
		// Constructor
		WindowResizeEvent(long sizex, long sizey) : mSizeX(sizex), mSizeY(sizey) {}

		// Macro Functions
		EVENT_CLASS_TYPE(WindowResize);
		EVENT_CATEGORY_FLAGS(EventCategoryApplication);

		// Instance Functions
		inline long GetSizeX() { return mSizeX; }
		inline long GetSizeY() { return mSizeY; }

		virtual std::string ToString() const override {
			std::stringstream ss;
			ss << "Window Resized: " << mSizeX << "x " << mSizeY << "y";
			return ss.str();
		}
	private:
		long mSizeX;
		long mSizeY;
	};


	class WYLDER_API WindowFocusEvent : public Event {
	public:
		// Constructor
		WindowFocusEvent() {}

		// Macro Functions
		EVENT_CLASS_TYPE(WindowFocus);
		EVENT_CATEGORY_FLAGS(EventCategoryApplication);
	};


	class WYLDER_API WindowLostFocusEvent : public Event {
	public:
		// Constructor
		WindowLostFocusEvent() {}

		// Macro Functions
		EVENT_CLASS_TYPE(WindowLostFocus);
		EVENT_CATEGORY_FLAGS(EventCategoryApplication);
	};


	class WYLDER_API WindowMovedEvent : public Event {
	public:
		// Constructor
		WindowMovedEvent() {}

		// Macro Functions
		EVENT_CLASS_TYPE(WindowMoved);
		EVENT_CATEGORY_FLAGS(EventCategoryApplication);
	};
}