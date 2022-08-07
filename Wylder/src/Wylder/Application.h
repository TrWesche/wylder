#pragma once

#include "Core.h"
#include "Window.h"
#include "Wylder/Events/WindowEvent.h"

namespace Wylder {

	class WYLDER_API Application
	{
	public:
		// Constructor
		Application();

		// Destructor
		virtual ~Application();

		// Root Application Loop
		void Run();

		void OnEvent(Event& e);
	private:
		std::unique_ptr<Window> mWindow;
		bool mRunning = true;

		// Event Functions
		bool OnWindowClose(WindowCloseEvent& e);
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}