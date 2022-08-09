#include "wypch.h"
#include "LayerStack.h"

namespace Wylder {
	LayerStack::LayerStack() {
		// On Construct set the Insert Location to the Layer Stack Beginning
		mLayerInsert = mLayers.begin();
	}

	LayerStack::~LayerStack() {
		for (Layer* layer : mLayers)
		{
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer) {
		// Adds value to the start of the Vector
		mLayerInsert = mLayers.emplace(mLayerInsert, layer);
	}

	void LayerStack::PopLayer(Layer* layer) {
		for (std::vector<Layer*>::iterator it = mLayers.begin(); it != mLayers.end();) {
			if (*it == layer) {
				it = mLayers.erase(it);
				break;
			}
		}
		mLayerInsert = mLayers.begin();
	}

	void LayerStack::PushOverlay(Layer* layer) {
		// Adds value to the end of the Vector
		mLayers.emplace_back(layer);
		mLayerInsert = mLayers.begin();
	}

	void LayerStack::PopOverlay(Layer* layer) {
		for (std::vector<Layer*>::iterator it = mLayers.end(); it != mLayers.begin();) {
			if (*--it == layer) {
				it = mLayers.erase(it);
				break;
			}
		}
		mLayerInsert = mLayers.begin();
	}
}