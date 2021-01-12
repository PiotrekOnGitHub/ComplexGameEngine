#include "Log.h"

namespace ComplexEngine {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
	
	void Log::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_CoreLogger = spdlog::stderr_color_mt("ComplexEngine");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stderr_color_mt("App");
		s_CoreLogger->set_level(spdlog::level::trace);
	}
}



