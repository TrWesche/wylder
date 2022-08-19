#pragma once

#include "Wylder/Core.h"

namespace Wylder {

	// Events in Wylder are currently blocking.  A buffer for events is likely a better long term
	// handling solution for most cases such that events can be batched and handled during a single stage
	// of the engine update cycle rather then having them act like interrupts. 

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyInputChar,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

#define EVENT_CLASS_TYPE(type)	static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetEventName() const override { return #type; }

#define EVENT_CATEGORY_FLAGS(categories) virtual int GetEventCategoryFlags() const override { return categories; }


	class WYLDER_API Event {
		friend class EventDispatcher;
	public:
		// GetEventType and GetEventName are pure virtual functions which must be implemented in the child class.
		// A default configuration for these virtual methods is defined by macro EVENT_CLASS_TYPE(type).
		virtual EventType GetEventType() const = 0;
		virtual const char* GetEventName() const = 0;

		// GetEventCategoryFlags is a pure virutal function which must be implemented in the child class.
		// A default configuration for this virtual method is defined by macro EVENT_CATEGORY_FLAGS(categories).
		virtual int GetEventCategoryFlags() const = 0;

		virtual std::string ToString() const { return GetEventName(); }

		inline bool CheckEventCategory(EventCategory category) {
			return GetEventCategoryFlags() & category;
		}

		// This boolean will allow for engine layers filter events as they propogate through the program rather than performing full event functionality on each layer
		bool Handled = false;
	};


	class EventDispatcher {
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		// Constructor
		EventDispatcher(Event& event) : mEvent(event) {}

		// Instance Functions
		template<typename T>
		bool Dispatch(EventFn<T> func) {
			if (mEvent.GetEventType() == T::GetStaticType()) {
				mEvent.Handled = func(*(T*)&mEvent);
				return true;
			}
			return false;
		}


	private:
		Event& mEvent;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}
}