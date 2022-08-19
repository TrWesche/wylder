#include "wypch.h"
#include "WindowsWindow.h"

//#include <GLFW/glfw3.h>
#include "Wylder/Events/WindowEvent.h"
#include "Wylder/Events/ApplicationEvent.h"
#include "Wylder/Events/KeyEvent.h"
#include "Wylder/Events/MouseEvent.h"

#include <glad/glad.h>

namespace Wylder {
	static bool sGLFWInitialized = false;

	static void GLFWErrorCallback(int error_code, const char* description) {
		WY_CORE_ERROR("GLFW Error: {0}: {1}", error_code, description);
	};

	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		WindowsWindow::Init(props);
	}

	WindowsWindow::~WindowsWindow() {
		Shutdown();
		// glfwTerminate(); // Need to determine proper way to handle termination, do necessarily want to call terminate on every window being closed, could have a multi-window application
	}

	void WindowsWindow::Init(const WindowProps& props) {
		mData.Title = props.Title;
		mData.Height = props.Height;
		mData.Width = props.Width;
		//mData.FullScreen = props.FullScreen;

		WY_CORE_INFO("Creating Window '{0}' : Dimensions ({1}, {2}) - Platform: Windows | API: OpenGL GLFW", props.Title, props.Width, props.Height);

		if (!sGLFWInitialized) {
			static int InitStatus = glfwInit();
			WY_ASSERT(InitStatus, "OpenGL GLFW - Initialization Failure");
			glfwSetErrorCallback(GLFWErrorCallback);
			
			sGLFWInitialized = true;
		}

		mWindow = glfwCreateWindow((int)mData.Width, (int)mData.Height, mData.Title.c_str(), nullptr, nullptr);

		if (!mWindow) { WY_CORE_ERROR("OpenGL GLFW - Create Window Failed"); } // Probably want to capture more data here

		glfwMakeContextCurrent(mWindow);
		
		int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
		WY_CORE_ASSERT(status, "GLAD LoadGLLoad Failed to Initialize OpenGL context");

		glfwSetWindowUserPointer(mWindow, &mData);  // Setting the window to reference the mData struct
		SetVSync(true);

		// Set GLFW Callbacks

		// Window Size Callback
		glfwSetWindowSizeCallback(mWindow, [](GLFWwindow* window, int width, int height) { // [] is a lamba definition
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);  // Retrieve the mData struct for the target window and cast it to the correct data type
			data.Width = width;
			data.Height = height; 

			WindowResizeEvent event(width, height);
			data.EventCallback(event);
		});

		// Window Close Callback
		glfwSetWindowCloseCallback(mWindow, [](GLFWwindow* window) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;

			data.EventCallback(event);
		});

		// Key Press Callback
		glfwSetKeyCallback(mWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			if (action == GLFW_RELEASE) {
				KeyReleasedEvent event(key);
				data.EventCallback(event);
			}
			else if (action == GLFW_REPEAT) {
				KeyPressedEvent event(key, 1);
				data.EventCallback(event);
			}
			else {
				KeyPressedEvent event(key, 0);
				data.EventCallback(event);
			}
		});

		// Char Input Callback
		glfwSetCharCallback(mWindow, [](GLFWwindow* window, unsigned int keycode) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			KeyInputCharEvent event(keycode);
			data.EventCallback(event);
		});

		// Mouse Button Callback
		glfwSetMouseButtonCallback(mWindow, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
				case GLFW_RELEASE: {
					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_PRESS: {
					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
			}
		});

		// Mouse Scoll Callback
		glfwSetScrollCallback(mWindow, [](GLFWwindow* window, double xoffset, double yoffset) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent event((float)xoffset, (float)yoffset);

			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(mWindow, [](GLFWwindow* window, double xpos, double ypos) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseMovedEvent event((float)xpos, (float)ypos);

			data.EventCallback(event);
		});
	}

	void WindowsWindow::Shutdown() {
		glfwDestroyWindow(mWindow);
	}

	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(mWindow); // This appears to be what tells the GPU to update what is rendered on the screen
	}

	void WindowsWindow::SetVSync(bool enabled) {
		if (enabled) {
			glfwSwapInterval(1);
		}
		else {
			glfwSwapInterval(0);
		}

		mData.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const { 
		return mData.VSync; 
	}
}

