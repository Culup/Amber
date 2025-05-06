#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Amber {

	class AMBER_API Log
	{
	public:
		static void Init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		
	};

}

// Core log macros
#define AB_CORE_TRACE(...) ::Amber::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AB_CORE_INFO(...)  ::Amber::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AB_CORE_WARN(...)  ::Amber::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AB_CORE_ERROR(...) ::Amber::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AB_CORE_FATAL(...) ::Amber::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define AB_TRACE(...)      ::Amber::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AB_INFO(...)       ::Amber::Log::GetClientLogger()->info(__VA_ARGS__)
#define AB_WARN(...)       ::Amber::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AB_ERROR(...)      ::Amber::Log::GetClientLogger()->error(__VA_ARGS__)
#define AB_FATAL(...)      ::Amber::Log::GetClientLogger()->critical(__VA_ARGS__)

