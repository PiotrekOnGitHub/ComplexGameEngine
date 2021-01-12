#pragma once

#include "Core.h"

#include <iostream>
#include <string>
namespace ComplexEngine {
	class COMPLEX_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run();
	};

	Application* CreateApplication();
}


