// In order to allow includes without specifying relative directories the solution is configured with "Additional Include Directories" - Configuration Properties/ C\C++ /General
#include <Wylder.h>

class Sandbox : public Wylder::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Wylder::Application* Wylder::CreateApplication()
{
	return new Sandbox();
};