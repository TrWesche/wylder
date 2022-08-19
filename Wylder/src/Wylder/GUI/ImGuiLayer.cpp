#include "wypch.h"
#include "ImGuiLayer.h"
#include "Wylder/Events/Event.h"
#include "Wylder/Application.h"

#include "GraphicsAPI/OpenGL/ImGuiOpenGLRenderer.h"
#include "imgui.h"
#include "Wylder/GUI/ImGuiGLFWImpl.h"

// Temporary Includes
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


	static ImGuiKey TranslateGLFWKeytoImGuiKey(int key) {
        switch (key)
        {
            case GLFW_KEY_TAB: return ImGuiKey_Tab;
            case GLFW_KEY_LEFT: return ImGuiKey_LeftArrow;
            case GLFW_KEY_RIGHT: return ImGuiKey_RightArrow;
            case GLFW_KEY_UP: return ImGuiKey_UpArrow;
            case GLFW_KEY_DOWN: return ImGuiKey_DownArrow;
            case GLFW_KEY_PAGE_UP: return ImGuiKey_PageUp;
            case GLFW_KEY_PAGE_DOWN: return ImGuiKey_PageDown;
            case GLFW_KEY_HOME: return ImGuiKey_Home;
            case GLFW_KEY_END: return ImGuiKey_End;
            case GLFW_KEY_INSERT: return ImGuiKey_Insert;
            case GLFW_KEY_DELETE: return ImGuiKey_Delete;
            case GLFW_KEY_BACKSPACE: return ImGuiKey_Backspace;
            case GLFW_KEY_SPACE: return ImGuiKey_Space;
            case GLFW_KEY_ENTER: return ImGuiKey_Enter;
            case GLFW_KEY_ESCAPE: return ImGuiKey_Escape;
            case GLFW_KEY_APOSTROPHE: return ImGuiKey_Apostrophe;
            case GLFW_KEY_COMMA: return ImGuiKey_Comma;
            case GLFW_KEY_MINUS: return ImGuiKey_Minus;
            case GLFW_KEY_PERIOD: return ImGuiKey_Period;
            case GLFW_KEY_SLASH: return ImGuiKey_Slash;
            case GLFW_KEY_SEMICOLON: return ImGuiKey_Semicolon;
            case GLFW_KEY_EQUAL: return ImGuiKey_Equal;
            case GLFW_KEY_LEFT_BRACKET: return ImGuiKey_LeftBracket;
            case GLFW_KEY_BACKSLASH: return ImGuiKey_Backslash;
            case GLFW_KEY_RIGHT_BRACKET: return ImGuiKey_RightBracket;
            case GLFW_KEY_GRAVE_ACCENT: return ImGuiKey_GraveAccent;
            case GLFW_KEY_CAPS_LOCK: return ImGuiKey_CapsLock;
            case GLFW_KEY_SCROLL_LOCK: return ImGuiKey_ScrollLock;
            case GLFW_KEY_NUM_LOCK: return ImGuiKey_NumLock;
            case GLFW_KEY_PRINT_SCREEN: return ImGuiKey_PrintScreen;
            case GLFW_KEY_PAUSE: return ImGuiKey_Pause;
            case GLFW_KEY_KP_0: return ImGuiKey_Keypad0;
            case GLFW_KEY_KP_1: return ImGuiKey_Keypad1;
            case GLFW_KEY_KP_2: return ImGuiKey_Keypad2;
            case GLFW_KEY_KP_3: return ImGuiKey_Keypad3;
            case GLFW_KEY_KP_4: return ImGuiKey_Keypad4;
            case GLFW_KEY_KP_5: return ImGuiKey_Keypad5;
            case GLFW_KEY_KP_6: return ImGuiKey_Keypad6;
            case GLFW_KEY_KP_7: return ImGuiKey_Keypad7;
            case GLFW_KEY_KP_8: return ImGuiKey_Keypad8;
            case GLFW_KEY_KP_9: return ImGuiKey_Keypad9;
            case GLFW_KEY_KP_DECIMAL: return ImGuiKey_KeypadDecimal;
            case GLFW_KEY_KP_DIVIDE: return ImGuiKey_KeypadDivide;
            case GLFW_KEY_KP_MULTIPLY: return ImGuiKey_KeypadMultiply;
            case GLFW_KEY_KP_SUBTRACT: return ImGuiKey_KeypadSubtract;
            case GLFW_KEY_KP_ADD: return ImGuiKey_KeypadAdd;
            case GLFW_KEY_KP_ENTER: return ImGuiKey_KeypadEnter;
            case GLFW_KEY_KP_EQUAL: return ImGuiKey_KeypadEqual;
            case GLFW_KEY_LEFT_SHIFT: return ImGuiKey_LeftShift;
            case GLFW_KEY_LEFT_CONTROL: return ImGuiKey_LeftCtrl;
            case GLFW_KEY_LEFT_ALT: return ImGuiKey_LeftAlt;
            case GLFW_KEY_LEFT_SUPER: return ImGuiKey_LeftSuper;
            case GLFW_KEY_RIGHT_SHIFT: return ImGuiKey_RightShift;
            case GLFW_KEY_RIGHT_CONTROL: return ImGuiKey_RightCtrl;
            case GLFW_KEY_RIGHT_ALT: return ImGuiKey_RightAlt;
            case GLFW_KEY_RIGHT_SUPER: return ImGuiKey_RightSuper;
            case GLFW_KEY_MENU: return ImGuiKey_Menu;
            case GLFW_KEY_0: return ImGuiKey_0;
            case GLFW_KEY_1: return ImGuiKey_1;
            case GLFW_KEY_2: return ImGuiKey_2;
            case GLFW_KEY_3: return ImGuiKey_3;
            case GLFW_KEY_4: return ImGuiKey_4;
            case GLFW_KEY_5: return ImGuiKey_5;
            case GLFW_KEY_6: return ImGuiKey_6;
            case GLFW_KEY_7: return ImGuiKey_7;
            case GLFW_KEY_8: return ImGuiKey_8;
            case GLFW_KEY_9: return ImGuiKey_9;
            case GLFW_KEY_A: return ImGuiKey_A;
            case GLFW_KEY_B: return ImGuiKey_B;
            case GLFW_KEY_C: return ImGuiKey_C;
            case GLFW_KEY_D: return ImGuiKey_D;
            case GLFW_KEY_E: return ImGuiKey_E;
            case GLFW_KEY_F: return ImGuiKey_F;
            case GLFW_KEY_G: return ImGuiKey_G;
            case GLFW_KEY_H: return ImGuiKey_H;
            case GLFW_KEY_I: return ImGuiKey_I;
            case GLFW_KEY_J: return ImGuiKey_J;
            case GLFW_KEY_K: return ImGuiKey_K;
            case GLFW_KEY_L: return ImGuiKey_L;
            case GLFW_KEY_M: return ImGuiKey_M;
            case GLFW_KEY_N: return ImGuiKey_N;
            case GLFW_KEY_O: return ImGuiKey_O;
            case GLFW_KEY_P: return ImGuiKey_P;
            case GLFW_KEY_Q: return ImGuiKey_Q;
            case GLFW_KEY_R: return ImGuiKey_R;
            case GLFW_KEY_S: return ImGuiKey_S;
            case GLFW_KEY_T: return ImGuiKey_T;
            case GLFW_KEY_U: return ImGuiKey_U;
            case GLFW_KEY_V: return ImGuiKey_V;
            case GLFW_KEY_W: return ImGuiKey_W;
            case GLFW_KEY_X: return ImGuiKey_X;
            case GLFW_KEY_Y: return ImGuiKey_Y;
            case GLFW_KEY_Z: return ImGuiKey_Z;
            case GLFW_KEY_F1: return ImGuiKey_F1;
            case GLFW_KEY_F2: return ImGuiKey_F2;
            case GLFW_KEY_F3: return ImGuiKey_F3;
            case GLFW_KEY_F4: return ImGuiKey_F4;
            case GLFW_KEY_F5: return ImGuiKey_F5;
            case GLFW_KEY_F6: return ImGuiKey_F6;
            case GLFW_KEY_F7: return ImGuiKey_F7;
            case GLFW_KEY_F8: return ImGuiKey_F8;
            case GLFW_KEY_F9: return ImGuiKey_F9;
            case GLFW_KEY_F10: return ImGuiKey_F10;
            case GLFW_KEY_F11: return ImGuiKey_F11;
            case GLFW_KEY_F12: return ImGuiKey_F12;
            default: return ImGuiKey_None;
        }
	}

    static int HandleGlfwKeyToModifier(int key)
    {
        if (key == GLFW_KEY_LEFT_CONTROL || key == GLFW_KEY_RIGHT_CONTROL)
            return GLFW_MOD_CONTROL;
        if (key == GLFW_KEY_LEFT_SHIFT || key == GLFW_KEY_RIGHT_SHIFT)
            return GLFW_MOD_SHIFT;
        if (key == GLFW_KEY_LEFT_ALT || key == GLFW_KEY_RIGHT_ALT)
            return GLFW_MOD_ALT;
        if (key == GLFW_KEY_LEFT_SUPER || key == GLFW_KEY_RIGHT_SUPER)
            return GLFW_MOD_SUPER;
        return 0;
    }

    // Will need to be able to handle multiple modifiers being pressed at once in the future
    static void ImGuiUpdateKeyModifiers(int mods, bool down)
    {
        ImGuiIO& io = ImGui::GetIO();
        
        int ioKeyMods = 0;
        if (io.KeyMods & 0x0001)                // ImGui Control = 0x0001 while GLFW Control = 0x0002
            ioKeyMods = ioKeyMods | 0x0002;
        if (io.KeyMods & 0x0002)                // ImGui Shift = 0x0002 while GLFW Shift = 0x0001
            ioKeyMods = ioKeyMods | 0x0001;
        if (io.KeyMods & 0x0004)
            ioKeyMods = ioKeyMods | 0x0004;
        if (io.KeyMods & 0x0008)
            ioKeyMods = ioKeyMods | 0x0008;

        int accMods = mods;
        //WY_INFO("Modifier Key Pressed {0}, io.KeyMods {1}, ioKeyMods {2}", mods, io.KeyMods, ioKeyMods);
        if (down) {
            accMods = mods | ioKeyMods;
            //WY_INFO("Accumulated Modifiers: {0}", accMods);
        }
            

        io.AddKeyEvent(ImGuiKey_ModCtrl, (accMods & GLFW_MOD_CONTROL) != 0 && down);
        io.AddKeyEvent(ImGuiKey_ModShift, (accMods & GLFW_MOD_SHIFT) != 0 && down);
        io.AddKeyEvent(ImGuiKey_ModAlt, (accMods & GLFW_MOD_ALT) != 0 && down);
        io.AddKeyEvent(ImGuiKey_ModSuper, (accMods & GLFW_MOD_SUPER) != 0 && down);
    }

    void ImGui_ImplGlfw_CharCallback(GLFWwindow* window, unsigned int c)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.AddInputCharacter(c);
    }

    bool ImGuiLayer::OnKeyPressed(KeyPressedEvent& event)
    {
        //WY_INFO("ImGui Layer Key Pressed Event Captured: GLFW Key = {0}, ImGuiKey = {1}", event.GetKeyCode(), TranslateGLFWKeytoImGuiKey(event.GetKeyCode()) );
        int keycode_to_mod = HandleGlfwKeyToModifier(event.GetKeyCode());
        if (keycode_to_mod) {
            //WY_INFO("ImGui Modifier Key Pressed, update key modifiers: Key {0}", keycode_to_mod);
            ImGuiUpdateKeyModifiers(keycode_to_mod, GLFW_PRESS);
        }

        ImGuiKey eventKey = TranslateGLFWKeytoImGuiKey(event.GetKeyCode());
        ImGuiIO& io = ImGui::GetIO();
        io.AddKeyEvent(eventKey, GLFW_PRESS);


        //WY_INFO("Modifier Keys Pressed {0}", io.KeyMods);
        return true;
    }

    bool ImGuiLayer::OnKeyReleased(KeyReleasedEvent& event)
    {
        //WY_INFO("ImGui Layer Key Released Event Captured: GLFW Key = {0}, ImGuiKey = {1}", event.GetKeyCode(), TranslateGLFWKeytoImGuiKey(event.GetKeyCode()));
        int keycode_to_mod = HandleGlfwKeyToModifier(event.GetKeyCode());
        if (keycode_to_mod) {
            //WY_INFO("ImGui Modifier Key Released, update key modifiers: Key {0}", keycode_to_mod);
            ImGuiUpdateKeyModifiers(keycode_to_mod, GLFW_RELEASE);
        }

        ImGuiKey eventKey = TranslateGLFWKeytoImGuiKey(event.GetKeyCode());
        ImGuiIO& io = ImGui::GetIO();
        io.AddKeyEvent(eventKey, GLFW_RELEASE);

        //WY_INFO("Modifier Keys Released {0}", io.KeyMods);
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
        //WY_INFO("ImGui Layer Mouse Button Pressed Event Captured: GLFW Key = {0}", event.GetButtonIdentifier());
        ImGuiIO& io = ImGui::GetIO();
        io.AddMouseButtonEvent(event.GetButtonIdentifier(), GLFW_PRESS);
        return true;
    }

    bool ImGuiLayer::OnMouseButtonReleased(MouseButtonReleasedEvent& event)
    {
        //WY_INFO("ImGui Layer Mouse Button Released Event Captured: GLFW Key = {0}", event.GetButtonIdentifier());
        ImGuiIO& io = ImGui::GetIO();
        io.AddMouseButtonEvent(event.GetButtonIdentifier(), GLFW_RELEASE);
        return true;
    }

    bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& event)
    {
        //WY_INFO("ImGui Layer Mouse Move Event Captured: X: {0}, Y: {1}", event.GetPositionX(), event.GetPositionY());
        ImGuiIO& io = ImGui::GetIO();
        io.AddMousePosEvent(event.GetPositionX(), event.GetPositionY());
        return true;
    }

    bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& event)
    {
        //WY_INFO("ImGui Layer Mouse Scroll Event Captured: OffsetX: {0}, OffsetY: {1}", event.GetOffsetX(), event.GetOffsetY());
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
        WY_INFO("ImGui Window Focus Event Captured: False");
        ImGuiIO& io = ImGui::GetIO();
        io.AddFocusEvent(false);
        return true;
    }

    bool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent& event)
    {
        WY_INFO("ImGui Window Resize Event Captured: Dimension X={0}, Dimension Y={1}", event.GetSizeX(), event.GetSizeY());
        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2(event.GetSizeX(), event.GetSizeY());
        io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
        // Temporary
        glViewport(0, 0, event.GetSizeX(), event.GetSizeY());

        return true;
    }
}

