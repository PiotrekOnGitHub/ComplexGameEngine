#pragma once

#include <memory>

#include "Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace ComplexEngine {
	class COMPLEX_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log defines
#define COMPLEX_CORE_TRACE(...)		::ComplexEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define COMPLEX_CORE_INFO(...)		::ComplexEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define COMPLEX_CORE_WARN(...)		::ComplexEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define COMPLEX_CORE_FATAL(...)		::ComplexEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log defines
#define COMPLEX_CLIENT_TRACE(...)		::ComplexEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define COMPLEX_CLIENT_INFO(...)		::ComplexEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define COMPLEX_CLIENT_WARN(...)		::ComplexEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define COMPLEX_CLIENT_FATAL(...)		::ComplexEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)