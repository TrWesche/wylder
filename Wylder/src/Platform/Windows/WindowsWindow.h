#pragma once

#include <GLFW/glfw3.h>
#include "Wylder/Window.h"
#include "Wylder/Events/Event.h"

namespace Wylder {
	class WindowsWindow : public Window
	{
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	public:
		WindowsWindow(const WindowProps& props);
		virtual~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetHeight() override { return mData.Height; }
		inline unsigned int GetWidth() override { return mData.Width; }
		//inline bool GetFullScreenMonitor() override { return mData.FullScreenMonitor; }

		// Window Attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) override { mData.EventCallback = callback; }
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override;

		virtual void* GetNativeWindow() const { return mWindow; }
	private:
		GLFWwindow* mWindow;

		struct WindowData {
			std::string Title;
			unsigned int Height;
			unsigned int Width;
			bool VSync;
			//GLFWmonitor* FullScreenMonitor; 

			EventCallbackFn EventCallback;
		};

		WindowData mData;
	};
}


