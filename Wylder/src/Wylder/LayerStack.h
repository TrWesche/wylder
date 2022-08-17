#pragma once

#include "Layer.h"

namespace Wylder {
	class LayerStack
	{
	public:
		LayerStack() = default;
		~LayerStack();

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);

		void PushOverlay(Layer* layer);
		void PopOverlay(Layer* layer);

		// These return the location of the beginning of the Layer Vector & End of the Layer Vector
		std::vector<Layer*>::iterator begin() { return mLayers.begin(); }
		std::vector<Layer*>::iterator end() { return mLayers.end(); }

	private:
		std::vector<Layer*> mLayers;
		//std::vector<Layer*>::iterator mLayerInsert;

		unsigned int m_LayerInsertIndex = 0;
	};
}

