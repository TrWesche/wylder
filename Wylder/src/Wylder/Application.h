#pragma once

#include "Core.h"

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
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}