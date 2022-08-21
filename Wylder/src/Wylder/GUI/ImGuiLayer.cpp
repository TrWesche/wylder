#include "wypch.h"
#include "ImGuiLayer.h"
#include "Wylder/Events/Event.h"
#include "Wylder/Application.h"

#include "GraphicsAPI/OpenGL/ImGuiOpenGLRenderer.h"
#include "imgui.h"
#include "Wylder/GUI/ImGuiGLFWImpl.h"

// Temporary Includes
#include "KeyCodes.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Wylder {
    // The ImGui Key Handling Technique has changed significantly since tutorial was created and is run through callback functions now
	ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::OnAttach()
	{
		Application& app = Application::Get();
		GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());

		//IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		//ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach()
	{
	}

	void ImGuiLayer::OnUpdate()
	{	
		Application& app = Application::Get();
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = (mTime > 0.0f ? (time - mTime) : (1.0f / 60.0f));
		mTime = time;


        //ImGui_ImplGlfw_NewFrame();
		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		// Demo Window for Testing
		static bool show_demo_window = true;
		ImGui::ShowDemoWindow(&show_demo_window);


		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnEvent(Event& event)
	{
		//WY_INFO("ImGui Layer: Event Received {0}", event.GetEventName());
        EventDispatcher Dispatcher(event);

        Dispatcher.Dispatch<KeyPressedEvent>(WY_EVENT_FN_BIND(ImGuiLayer::OnKeyPressed));
        Dispatcher.Dispatch<KeyReleasedEvent>(WY_EVENT_FN_BIND(ImGuiLayer::OnKeyReleased));
        Dispatcher.Dispatch<KeyInputCharEvent>(WY_EVENT_FN_BIND(ImGuiLayer::OnKeyInputChar));

        Dispatcher.Dispatch<MouseButtonPressedEvent>(WY_EVENT_FN_BIND(ImGuiLayer::OnMouseButtonPressed));
        Dispatcher.Dispatch<MouseButtonReleasedEvent>(WY_EVENT_FN_BIND(ImGuiLayer::OnMouseButtonReleased));
        Dispatcher.Dispatch<MouseMovedEvent>(WY_EVENT_FN_BIND(ImGuiLayer::OnMouseMovedEvent));
        Dispatcher.Dispatch<MouseScrolledEvent>(WY_EVENT_FN_BIND(ImGuiLayer::OnMouseScrolledEvent));
        
        Dispatcher.Dispatch<WindowFocusEvent>(WY_EVENT_FN_BIND(ImGuiLayer::OnWindowFocusEvent));
        Dispatcher.Dispatch<WindowLostFocusEvent>(WY_EVENT_FN_BIND(ImGuiLayer::OnWindowLostFocusEvent));
        Dispatcher.Dispatch<WindowResizeEvent>(WY_EVENT_FN_BIND(ImGuiLayer::OnWindowResizeEvent));
	}


    static ImGuiKey TranslateWylderKeytoImGuiKey(int key) {
        switch (key)
        {
        case WY_KEY_TAB: return ImGuiKey_Tab;
        case WY_KEY_LEFT: return ImGuiKey_LeftArrow;
        case WY_KEY_RIGHT: return ImGuiKey_RightArrow;
        case WY_KEY_UP: return ImGuiKey_UpArrow;
        case WY_KEY_DOWN: return ImGuiKey_DownArrow;
        case WY_KEY_PAGE_UP: return ImGuiKey_PageUp;
        case WY_KEY_PAGE_DOWN: return ImGuiKey_PageDown;
        case WY_KEY_HOME: return ImGuiKey_Home;
        case WY_KEY_END: return ImGuiKey_End;
        case WY_KEY_INSERT: return ImGuiKey_Insert;
        case WY_KEY_DELETE: return ImGuiKey_Delete;
        case WY_KEY_BACKSPACE: return ImGuiKey_Backspace;
        case WY_KEY_SPACE: return ImGuiKey_Space;
        case WY_KEY_ENTER: return ImGuiKey_Enter;
        case WY_KEY_ESCAPE: return ImGuiKey_Escape;
        case WY_KEY_APOSTROPHE: return ImGuiKey_Apostrophe;
        case WY_KEY_COMMA: return ImGuiKey_Comma;
        case WY_KEY_MINUS: return ImGuiKey_Minus;
        case WY_KEY_PERIOD: return ImGuiKey_Period;
        case WY_KEY_SLASH: return ImGuiKey_Slash;
        case WY_KEY_SEMICOLON: return ImGuiKey_Semicolon;
        case WY_KEY_EQUAL: return ImGuiKey_Equal;
        case WY_KEY_LEFT_BRACKET: return ImGuiKey_LeftBracket;
        case WY_KEY_BACKSLASH: return ImGuiKey_Backslash;
        case WY_KEY_RIGHT_BRACKET: return ImGuiKey_RightBracket;
        case WY_KEY_GRAVE_ACCENT: return ImGuiKey_GraveAccent;
        case WY_KEY_CAPS_LOCK: return ImGuiKey_CapsLock;
        case WY_KEY_SCROLL_LOCK: return ImGuiKey_ScrollLock;
        case WY_KEY_NUM_LOCK: return ImGuiKey_NumLock;
        case WY_KEY_PRINT_SCREEN: return ImGuiKey_PrintScreen;
        case WY_KEY_PAUSE: return ImGuiKey_Pause;
        case WY_KEY_KP_0: return ImGuiKey_Keypad0;
        case WY_KEY_KP_1: return ImGuiKey_Keypad1;
        case WY_KEY_KP_2: return ImGuiKey_Keypad2;
        case WY_KEY_KP_3: return ImGuiKey_Keypad3;
        case WY_KEY_KP_4: return ImGuiKey_Keypad4;
        case WY_KEY_KP_5: return ImGuiKey_Keypad5;
        case WY_KEY_KP_6: return ImGuiKey_Keypad6;
        case WY_KEY_KP_7: return ImGuiKey_Keypad7;
        case WY_KEY_KP_8: return ImGuiKey_Keypad8;
        case WY_KEY_KP_9: return ImGuiKey_Keypad9;
        case WY_KEY_KP_DECIMAL: return ImGuiKey_KeypadDecimal;
        case WY_KEY_KP_DIVIDE: return ImGuiKey_KeypadDivide;
        case WY_KEY_KP_MULTIPLY: return ImGuiKey_KeypadMultiply;
        case WY_KEY_KP_SUBTRACT: return ImGuiKey_KeypadSubtract;
        case WY_KEY_KP_ADD: return ImGuiKey_KeypadAdd;
        case WY_KEY_KP_ENTER: return ImGuiKey_KeypadEnter;
        case WY_KEY_KP_EQUAL: return ImGuiKey_KeypadEqual;
        case WY_KEY_LEFT_SHIFT: return ImGuiKey_LeftShift;
        case WY_KEY_LEFT_CONTROL: return ImGuiKey_LeftCtrl;
        case WY_KEY_LEFT_ALT: return ImGuiKey_LeftAlt;
        case WY_KEY_LEFT_SUPER: return ImGuiKey_LeftSuper;
        case WY_KEY_RIGHT_SHIFT: return ImGuiKey_RightShift;
        case WY_KEY_RIGHT_CONTROL: return ImGuiKey_RightCtrl;
        case WY_KEY_RIGHT_ALT: return ImGuiKey_RightAlt;
        case WY_KEY_RIGHT_SUPER: return ImGuiKey_RightSuper;
        case WY_KEY_MENU: return ImGuiKey_Menu;
        case WY_KEY_0: return ImGuiKey_0;
        case WY_KEY_1: return ImGuiKey_1;
        case WY_KEY_2: return ImGuiKey_2;
        case WY_KEY_3: return ImGuiKey_3;
        case WY_KEY_4: return ImGuiKey_4;
        case WY_KEY_5: return ImGuiKey_5;
        case WY_KEY_6: return ImGuiKey_6;
        case WY_KEY_7: return ImGuiKey_7;
        case WY_KEY_8: return ImGuiKey_8;
        case WY_KEY_9: return ImGuiKey_9;
        case WY_KEY_A: return ImGuiKey_A;
        case WY_KEY_B: return ImGuiKey_B;
        case WY_KEY_C: return ImGuiKey_C;
        case WY_KEY_D: return ImGuiKey_D;
        case WY_KEY_E: return ImGuiKey_E;
        case WY_KEY_F: return ImGuiKey_F;
        case WY_KEY_G: return ImGuiKey_G;
        case WY_KEY_H: return ImGuiKey_H;
        case WY_KEY_I: return ImGuiKey_I;
        case WY_KEY_J: return ImGuiKey_J;
        case WY_KEY_K: return ImGuiKey_K;
        case WY_KEY_L: return ImGuiKey_L;
        case WY_KEY_M: return ImGuiKey_M;
        case WY_KEY_N: return ImGuiKey_N;
        case WY_KEY_O: return ImGuiKey_O;
        case WY_KEY_P: return ImGuiKey_P;
        case WY_KEY_Q: return ImGuiKey_Q;
        case WY_KEY_R: return ImGuiKey_R;
        case WY_KEY_S: return ImGuiKey_S;
        case WY_KEY_T: return ImGuiKey_T;
        case WY_KEY_U: return ImGuiKey_U;
        case WY_KEY_V: return ImGuiKey_V;
        case WY_KEY_W: return ImGuiKey_W;
        case WY_KEY_X: return ImGuiKey_X;
        case WY_KEY_Y: return ImGuiKey_Y;
        case WY_KEY_Z: return ImGuiKey_Z;
        case WY_KEY_F1: return ImGuiKey_F1;
        case WY_KEY_F2: return ImGuiKey_F2;
        case WY_KEY_F3: return ImGuiKey_F3;
        case WY_KEY_F4: return ImGuiKey_F4;
        case WY_KEY_F5: return ImGuiKey_F5;
        case WY_KEY_F6: return ImGuiKey_F6;
        case WY_KEY_F7: return ImGuiKey_F7;
        case WY_KEY_F8: return ImGuiKey_F8;
        case WY_KEY_F9: return ImGuiKey_F9;
        case WY_KEY_F10: return ImGuiKey_F10;
        case WY_KEY_F11: return ImGuiKey_F11;
        case WY_KEY_F12: return ImGuiKey_F12;
        default: return ImGuiKey_None;
        }
    }

    static int HandleWylderKeyToModifier(int key)
    {
        if (key == WY_KEY_LEFT_CONTROL || key == WY_KEY_RIGHT_CONTROL)
            return WY_MOD_CONTROL;
        if (key == WY_KEY_LEFT_SHIFT || key == WY_KEY_RIGHT_SHIFT)
            return WY_MOD_SHIFT;
        if (key == WY_KEY_LEFT_ALT || key == WY_KEY_RIGHT_ALT)
            return WY_MOD_ALT;
        if (key == WY_KEY_LEFT_SUPER || key == WY_KEY_RIGHT_SUPER)
            return WY_MOD_SUPER;
        return 0;
    }


    static void ImGuiUpdateKeyModifiers(int mods, bool down)
    {
        ImGuiIO& io = ImGui::GetIO();

        // Translate ImGui Modifier Codes to Wylder Modifier Codes
        int ioKeyMods = 0;
        if (io.KeyMods & ImGuiKeyModFlags_Ctrl)                 // ImGui Control = 0x0001 while WYLDER Control = 0x0002
            ioKeyMods = ioKeyMods | WY_MOD_CONTROL;
        if (io.KeyMods & ImGuiKeyModFlags_Shift)                // ImGui Shift = 0x0002 while WYLDER Shift = 0x0001
            ioKeyMods = ioKeyMods | WY_MOD_SHIFT;
        if (io.KeyMods & ImGuiKeyModFlags_Alt)
            ioKeyMods = ioKeyMods | WY_MOD_ALT;
        if (io.KeyMods & ImGuiKeyModFlags_Super)
            ioKeyMods = ioKeyMods | WY_MOD_SUPER;

        // Handle for Pressed / Released.  If pressed we want to accumulate the newly pressed key.
        // If released we want to retain the previous pressed key and toggle the released key off.
        int accMods = mods;
        if (down) {
            accMods = mods | ioKeyMods;
        }
        else {
            accMods = ioKeyMods ^ mods;
        }

        io.AddKeyEvent(ImGuiKey_ModCtrl, (accMods & WY_MOD_CONTROL) != 0);
        io.AddKeyEvent(ImGuiKey_ModShift, (accMods & WY_MOD_SHIFT) != 0);
        io.AddKeyEvent(ImGuiKey_ModAlt, (accMods & WY_MOD_ALT) != 0);
        io.AddKeyEvent(ImGuiKey_ModSuper, (accMods & WY_MOD_SUPER) != 0);
    }

    void ImGui_ImplGlfw_CharCallback(GLFWwindow* window, unsigned int c)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.AddInputCharacter(c);
    }

    bool ImGuiLayer::OnKeyPressed(KeyPressedEvent& event)
    {
        int keycode_to_mod = HandleWylderKeyToModifier( ExtKeyToWylderKey(event.GetKeyCode()) );
        if (keycode_to_mod) {
            ImGuiUpdateKeyModifiers(keycode_to_mod, WY_PRESS);
        }

        ImGuiKey eventKey = TranslateWylderKeytoImGuiKey( ExtKeyToWylderKey(event.GetKeyCode()) );
        ImGuiIO& io = ImGui::GetIO();
        io.AddKeyEvent(eventKey, WY_PRESS);

        return true;
    }

    bool ImGuiLayer::OnKeyReleased(KeyReleasedEvent& event)
    {
        int keycode_to_mod = HandleWylderKeyToModifier( ExtKeyToWylderKey(event.GetKeyCode()) );
        if (keycode_to_mod) {
            ImGuiUpdateKeyModifiers(keycode_to_mod, WY_RELEASE);
        }

        ImGuiKey eventKey = TranslateWylderKeytoImGuiKey( ExtKeyToWylderKey(event.GetKeyCode()) );
        ImGuiIO& io = ImGui::GetIO();
        io.AddKeyEvent(eventKey, WY_RELEASE);

        return true;
    }

    bool ImGuiLayer::OnKeyInputChar(KeyInputCharEvent& event)
    {
        WY_INFO("Character Input Event Triggered {0}", event.GetKeyCode());
        ImGuiIO& io = ImGui::GetIO();
        io.AddInputCharacter(event.GetKeyCode());

        return false;
    }

    bool ImGuiLayer::OnMouseButtonPressed(MouseButtonPressedEvent& event)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.AddMouseButtonEvent( ExtMouseButtonToWylderMouseButton(event.GetButtonIdentifier()), WY_PRESS);
        return true;
    }

    bool ImGuiLayer::OnMouseButtonReleased(MouseButtonReleasedEvent& event)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.AddMouseButtonEvent( ExtMouseButtonToWylderMouseButton(event.GetButtonIdentifier()), WY_RELEASE);

        return true;
    }

    bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& event)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.AddMousePosEvent(event.GetPositionX(), event.GetPositionY());
        return true;
    }

    bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& event)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.AddMouseWheelEvent(event.GetOffsetX(), event.GetOffsetY());
        return true;
    }

    bool ImGuiLayer::OnWindowFocusEvent(WindowFocusEvent& event) 
    {
        WY_INFO("ImGui Window Focus Event Captured: True");
        ImGuiIO& io = ImGui::GetIO();
        io.AddFocusEvent(true);
        return true;
    }

    bool ImGuiLayer::OnWindowLostFocusEvent(WindowLostFocusEvent& event)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.AddFocusEvent(false);
        return true;
    }

    bool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent& event)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2(event.GetSizeX(), event.GetSizeY());
        io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
        // TODO:: Temporary
        glViewport(0, 0, event.GetSizeX(), event.GetSizeY());

        return true;
    }
}