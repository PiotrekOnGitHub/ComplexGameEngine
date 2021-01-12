#include <ComplexEngine.h>

using namespace ComplexEngine;

class SandboxApp : public Application {
public:
	SandboxApp()
	{

	}

	~SandboxApp() 
	{

	}
};

ComplexEngine::Application* ComplexEngine::CreateApplication() {
	return new SandboxApp();	
}