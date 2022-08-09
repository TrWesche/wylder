#pragma once
#include "Events/Event.h"

namespace Wylder {

	class WYLDER_API Layer
	{
	public:
		Layer(const std::string& debugName = "Layer");
		virtual ~Layer();
		
		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate() {};
		virtual void OnEvent(Event& event) {};

		inline const std::string& GetName() const { return mDebugName; }

	protected:
		std::string mDebugName;
	};
}


