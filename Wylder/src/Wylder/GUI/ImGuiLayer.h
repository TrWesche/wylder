#pragma once

#include "Wylder/Layer.h"
#include "Wylder/Events/KeyEvent.h"
#include "Wylder/Events/MouseEvent.h"

namespace Wylder {
	class Event;

	class WYLDER_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;

		void OnDetach() override;

		void OnUpdate() override;

		void OnEvent(Event& event) override;

		bool OnKeyPressed(KeyPressedEvent& event);

		bool OnKeyReleased(KeyReleasedEvent& event);

		bool OnMouseButtonPressed(MouseButtonPressedEvent& event);

		bool OnMouseButtonReleased(MouseButtonReleasedEvent& event);

		bool OnMouseMovedEvent(MouseMovedEvent& event);

		bool OnMouseScrolledEvent(MouseScrolledEvent& event);
	private:
		float mTime = 0.0f;

	protected:

	};
}



