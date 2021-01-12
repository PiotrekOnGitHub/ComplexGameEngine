#pragma once

#ifdef CE_PLATFORM_WINDOWS

extern ComplexEngine::Application* ComplexEngine::CreateApplication();

int main(int argc, char* argv[]) {
	ComplexEngine::Log::Init();

	COMPLEX_CORE_WARN("Initialized log!");
	COMPLEX_CLIENT_WARN("Initialized log!");

	auto app = ComplexEngine::CreateApplication();
	app->Run();
	delete app;
}
#endif
