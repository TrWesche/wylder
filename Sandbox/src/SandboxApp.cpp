// In order to allow includes without specifying relative directories the solution is configured with "Additional Include Directories" - Configuration Properties/ C\C++ /General
#include <Wylder.h>

class ExampleLayer : public Wylder::Layer {

public:
	ExampleLayer() : Layer("ExampleLayer") {}

	void OnUpdate() override {
		WY_INFO("Example Layer: Update");
	}

	void OnEvent(Wylder::Event& event) override {
		WY_TRACE("{0}", event);
	}
};

class Sandbox : public Wylder::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Wylder::Application* Wylder::CreateApplication()
{
	return new Sandbox();
};