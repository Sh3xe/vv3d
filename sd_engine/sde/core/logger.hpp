#pragma once

#include "sde/defines.hpp"
#include <sstream>
#include <initializer_list>
#include <string>
#include <iostream>
#include <mutex>

namespace sd
{

SD_API class Logger
{
public:
	// make the class a singleton
	Logger(const Logger&)            = delete;
	Logger &operator=(const Logger&) = delete;

	static Logger &get()
	{
		static Logger l;
		return l;
	}

	// logging functions
	template <typename ...Args>
	void log( Args &&...args )
	{
		send_to_stream( {to_str(args)...} );
	}

private:
	Logger()
	{
		m_out_stream = &(std::cout);
		std::cout.sync_with_stdio(false);
	}

	template<typename T>
	std::string to_str(const T &val)
	{
		std::stringstream ss;
		ss << val;
		return ss.str();
	}

	void send_to_stream(const std::initializer_list<std::string> &init_list)
	{
		m_mutex.lock();
		for(auto &el: init_list)
			(*m_out_stream) << el;
		(*m_out_stream) << '\n';
		m_mutex.unlock();
	}

private:
	std::ostream *m_out_stream;
	std::mutex m_mutex;

};

} // namespace sd

#ifndef NDEBUG
	#define SD_TRACE(...) sd::Logger::get().log("TRACE: ", __VA_ARGS__)
	#define SD_DEBUG(...) sd::Logger::get().log("DEBUG: ", __VA_ARGS__)
	#define SD_INFO(...)  sd::Logger::get().log("INFO : ", __VA_ARGS__)
#else
	#define SD_TRACE(...)
	#define SD_DEBUG(...)
	#define SD_INFO(...)
#endif

#define SD_WARN(...)  sd::Logger::get().log("WARN : ", __FILE__, __LINE__, __VA_ARGS__)
#define SD_ERROR(...) sd::Logger::get().log("ERROR: ", __FILE__, __LINE__, __VA_ARGS__)
#define SD_FATAL(...) sd::Logger::get().log("FATAL: ", __FILE__, __LINE__, __VA_ARGS__)