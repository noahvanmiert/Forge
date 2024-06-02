#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>


namespace Forge {

	class Logger
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()   { return s_CoreLogger;   }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}


/* for logging from the engine itself */
#define FG_CORE_ERROR(...)    ::Forge::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define FG_CORE_WARN(...)     ::Forge::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define FG_CORE_INFO(...)     ::Forge::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define FG_CORE_TRACE(...)    ::Forge::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define FG_CORE_FATAL(...)    ::Forge::Logger::GetCoreLogger()->critical(__VA_ARGS__)


/* for logging from the client app */
#define FG_ERROR(...)		  ::Forge::Logger::GetClientLogger()->error(__VA_ARGS__)
#define FG_WARN(...)		  ::Forge::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define FG_INFO(...)		  ::Forge::Logger::GetClientLogger()->info(__VA_ARGS__)
#define FG_TRACE(...)		  ::Forge::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define FG_FATAL(...)		  ::Forge::Logger::GetClientLogger()->critical(__VA_ARGS__)