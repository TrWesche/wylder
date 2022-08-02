#pragma once

#ifdef WY_PLATFORM_WINDOWS
// To make sure the way the engine is run is consistent the main function will be defined in the engine to be used by other applications built with the engine.

extern Wylder::Application* Wylder::CreateApplication();

int main(int argc, char** argv) {
	/*printf("Wylder Engine Launching");*/
	Wylder::Log::Init();
	/*Wylder::Log::GetCoreLogger()->warn("Initialized Core Logger");
	Wylder::Log::GetClientLogger()->info("Client Logger Up");*/

	WY_CORE_WARN("Initialized Core Logger");
	double a = 5.12;
	WY_INFO("Client Logger Up Var={0}", a);

	auto app = Wylder::CreateApplication();
	app->Run();
	delete app;
}

#endif