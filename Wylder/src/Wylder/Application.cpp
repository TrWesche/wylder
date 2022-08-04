#include "Application.h"
#include "Wylder/Events/WindowEvent.h"
#include "Wylder/Log.h"

namespace Wylder {
	// Constructor Definition
	Application::Application() {

	}

	// Destructor Definition
	Application::~Application() {

	}

	// Root Application Loop Definition
	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.CheckEventCategory(EventCategoryApplication)) {
			WY_TRACE(e);
		}
		if (e.CheckEventCategory(EventCategoryInput)) {
			WY_TRACE(e);
		}

		while (true)
		{

		}
	}

}