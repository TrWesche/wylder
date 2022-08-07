#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"


namespace Wylder {
	class WYLDER_API Log
	{
	public:
		/*Log();
		~Log();*/

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


// In the future this macro code will be updated such that they will be stripped out of distribution builds
// Core Log Macros
#define WY_CORE_TRACE(...) ::Wylder::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define WY_CORE_INFO(...)  ::Wylder::Log::GetCoreLogger()->info(__VA_ARGS__)
#define WY_CORE_WARN(...)  ::Wylder::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define WY_CORE_ERROR(...) ::Wylder::Log::GetCoreLogger()->error(__VA_ARGS__)
#define WY_CORE_FATAL(...) ::Wylder::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros
#define WY_TRACE(...) ::Wylder::Log::GetClientLogger()->trace(__VA_ARGS__)
#define WY_INFO(...)  ::Wylder::Log::GetClientLogger()->info(__VA_ARGS__)
#define WY_WARN(...)  ::Wylder::Log::GetClientLogger()->warn(__VA_ARGS__)
#define WY_ERROR(...) ::Wylder::Log::GetClientLogger()->error(__VA_ARGS__)
#define WY_FATAL(...) ::Wylder::Log::GetClientLogger()->critical(__VA_ARGS__)


