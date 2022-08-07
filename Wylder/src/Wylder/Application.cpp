#include "wypch.h"
#include "Application.h"

#include <GLFW/glfw3.h>


namespace Wylder {

	#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	// Constructor Definition
	Application::Application() {
		// Explicit constructors require the full definition
		mWindow = std::unique_ptr<Window>(Window::Create());
		mWindow->SetEventCallback(BIND_EVENT_FN(OnEvent)); // This results in a function call like this: Application:OnEvent(_1) where _1 is replaced with the 1st parameter used in the calling statement
	}

	// Destructor Definition
	Application::~Application() {

	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		WY_CORE_TRACE("{0}", e);
	}

	// Root Application Loop Definition
	void Application::Run() {
		while (mRunning)
		{
			glClearColor(0, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			mWindow->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		mRunning = false;
		return true;
	}
}