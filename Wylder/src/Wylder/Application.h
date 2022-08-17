#pragma once

#include "Core.h"
#include "Window.h"
#include "Wylder/Events/Event.h"
#include "Wylder/Events/WindowEvent.h"
#include "LayerStack.h"
#include "Layer.h"


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

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() {
			return *sInstance;
		}

		inline Window& GetWindow() { return *mWindow; }
	private:
		static Application* sInstance;

		std::unique_ptr<Window> mWindow;

		bool mRunning = true;

		// Event Functions
		bool OnWindowClose(WindowCloseEvent& e);

		// Application Layer Stack
		LayerStack mLayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}