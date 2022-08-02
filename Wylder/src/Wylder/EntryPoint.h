#pragma once

#ifdef WY_PLATFORM_WINDOWS
// To make sure the way the engine is run is consistent the main function will be defined in the engine to be used by other applications built with the engine.

extern Wylder::Application* Wylder::CreateApplication();

int main(int argc, char** argv) {
	printf("Wylder Engine Launching");
	auto app = Wylder::CreateApplication();
	app->Run();
	delete app;
}

#endif