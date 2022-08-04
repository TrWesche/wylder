#pragma once

#include "Event.h"

namespace Wylder {
	class WYLDER_API MouseMovedEvent : public Event {
	public:
		// Constructor
		MouseMovedEvent(const float x, const float y) : mPositionX(x), mPositionY(y) {}

		// Macro Functions
		EVENT_CLASS_TYPE(MouseMoved);
		EVENT_CATEGORY_FLAGS(EventCategoryInput | EventCategoryMouse);

		// Instance Functions
		inline float GetPositionX() const { return mPositionX; }
		inline float GetPositionY() const { return mPositionY; }

		virtual std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMoved x:" << mPositionX << " y:" << mPositionX;
			return ss.str();
		}
	private:
		float mPositionX;
		float mPositionY;
	};


	class WYLDER_API MouseScrolledEvent : public Event {
	public:
		// Constructor
		MouseScrolledEvent(const float OffsetX, const float OffsetY) : mOffsetX(OffsetX), mOffsetY(OffsetY) {}

		// Macro Functions
		EVENT_CLASS_TYPE(MouseScrolled);
		EVENT_CATEGORY_FLAGS(EventCategoryInput | EventCategoryMouse);

		// Instance Functions
		inline float GetOffsetX() const { return mOffsetX; }
		inline float GetOffsetY() const { return mOffsetY; }

		virtual std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolled x:" << mOffsetX << " y:" << mOffsetY;
			return ss.str();
		}
	private:
		float mOffsetX;
		float mOffsetY;
	};




	class WYLDER_API MouseButtonEvent : public Event {
	public:
		// Macro Functions
		EVENT_CATEGORY_FLAGS(EventCategoryInput | EventCategoryMouse | EventCategoryMouseButton);

		// Instance Functions
		inline unsigned int GetButtonIdentifier() const { return mButton; }
	protected:
		// Constructor
		MouseButtonEvent(int button) : mButton(button) {};
		unsigned int mButton;
	};



	class WYLDER_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		// Constructor
		MouseButtonPressedEvent(const unsigned int button) : MouseButtonEvent(button) {}

		// Macro Functions
		EVENT_CLASS_TYPE(MouseButtonPressed);

		// Instance Functions
		virtual std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressed: " << mButton;
			return ss.str();
		}
	};


	class WYLDER_API MouseButtonReleasedEvent : public MouseButtonEvent {

	public:
		// Constructor
		MouseButtonReleasedEvent(const unsigned int button) : MouseButtonEvent(button) {}

		// Macro Functions
		EVENT_CLASS_TYPE(MouseButtonReleased);

		// Instance Functions
		virtual std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleased: " << mButton;
			return ss.str();
		}
	};

}