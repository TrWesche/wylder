#pragma once

#include "wypch.h"
#include "Core.h"
#include "Events/Event.h"

namespace Wylder {

	struct WindowProps {
		// Define Window Variables
		std::string Title;
		unsigned int Height;
		unsigned int Width;
		//xxxx FullScreenMonitor; // TODO: Target Monitor(s) for Full Screen - likely will require data type abstraction based on the api being used
		
		// Construct & Initialize the Window Struct with Default Values
		WindowProps(
			const std::string& title = "Wylder Engine", 
			unsigned int height = 720, 
			unsigned int width = 1280,
			bool fullscreen = false) 
			:
			Title(title), Height(height), Width(width) {}
	};

	// Desktop Window Interface
	class WYLDER_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() = 0;
		virtual unsigned int GetHeight() = 0;
		//virtual xxxx GetFullScreenMonitor() = 0;

		// Window Attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};

}