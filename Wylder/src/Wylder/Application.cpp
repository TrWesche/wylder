#include "wypch.h"
#include "Application.h"

#include <glad/glad.h>


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

	// Root Application Loop Definition
	void Application::Run() {
		while (mRunning)
		{
			glClearColor(0, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			mWindow->OnUpdate();
			
			for (Layer* layer : mLayerStack) {
				layer->OnUpdate();
			}
		}
	}

	// Event Handling Functions & Callbacks
	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		//WY_CORE_TRACE("{0}", e);
		
		for (std::vector<Layer*>::iterator it = mLayerStack.end(); it != mLayerStack.begin();) {
			(*--it)->OnEvent(e);
			if (e.Handled) break;
		}
	}


	bool Application::OnWindowClose(WindowCloseEvent& e) {
		mRunning = false;
		return true;
	}
	
	// Layer Handling
	void Application::PushLayer(Layer* layer) {
		mLayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer) {
		mLayerStack.PushOverlay(layer);
	}
}