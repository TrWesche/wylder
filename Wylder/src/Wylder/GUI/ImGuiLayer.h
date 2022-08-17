#pragma once

#include "Wylder/Layer.h"

namespace Wylder {
	class Event;

	class WYLDER_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();

		void OnDetach();

		void OnUpdate();

		void OnEvent(Event& event);
	private:
		float mTime = 0.0f;

	protected:

	};
}



