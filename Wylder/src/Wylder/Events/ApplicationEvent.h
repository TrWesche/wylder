#pragma once

#include "Event.h"

namespace Wylder {
	class WYLDER_API AppTickEvent : public Event {
	public:
		// Constructor
		AppTickEvent() {}

		// Macro Functions
		EVENT_CLASS_TYPE(AppTick);
		EVENT_CATEGORY_FLAGS(EventCategoryApplication);
	};


	class WYLDER_API AppUpdateEvent : public Event {
	public:
		// Constructor
		AppUpdateEvent() {}

		// Macro Functions
		EVENT_CLASS_TYPE(AppUpdate);
		EVENT_CATEGORY_FLAGS(EventCategoryApplication);
	};


	class WYLDER_API AppRenderEvent : public Event {
	public:
		// Constructor
		AppRenderEvent() {}

		// Macro Functions
		EVENT_CLASS_TYPE(AppRender);
		EVENT_CATEGORY_FLAGS(EventCategoryApplication);
	};
}