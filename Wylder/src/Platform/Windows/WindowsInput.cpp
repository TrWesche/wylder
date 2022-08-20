#include "WindowsInput.h"
#include "WindowsWindow.h"
#include "Wylder/Application.h"
#include <GLFW/glfw3.h>

namespace Wylder {
	Input* Input::sInstance = new WindowsInput();

	bool WindowsInput::IsKeyPressedImpl(const int keycode)
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		WY_ASSERT(!window, "Windows Input - Key Pressed Failed to retrieve GLFW window");

		return glfwGetKey(window, keycode);
	}

	bool WindowsInput::IsMouseButtonPressedImpl(const int button)
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		WY_ASSERT(!window, "Windows Input - Mouse Button Pressed Failed to retrieve GLFW window");
		
		return glfwGetMouseButton(window, button);
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		WY_ASSERT(!window, "Windows Input - Mouse Button Pressed Failed to retrieve GLFW window");

		double XPosition, YPosition;

		glfwGetCursorPos(window, &XPosition, &YPosition);

		return std::pair<float, float>((float)XPosition, (float)YPosition);
	}

}


