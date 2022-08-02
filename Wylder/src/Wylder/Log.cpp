#include "Log.h"

namespace Wylder {
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$"); // This pattern can be modified by referencing the spdlog library documentation %T = Timestamp, %n = Logger Name, %v = Message
		s_CoreLogger = spdlog::stdout_color_mt("WYLDER");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stderr_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
	/*Log::Log() {

	}
	Log::~Log() {

	}*/
}