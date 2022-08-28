#pragma once

#include "vv3d/defines.hpp"
#include <sstream>
#include <initializer_list>
#include <string>
#include <iostream>
#include <mutex>

namespace vv
{

class Logger
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
		(*m_out_stream) << std::endl;

		m_mutex.unlock();
	}

private:
	std::ostream *m_out_stream;
	std::mutex m_mutex;

};

} // namespace vv

#ifndef NDEBUG
	#define VV_TRACE(...) vv::Logger::get().log("TRACE: ", __VA_ARGS__)
	#define VV_DEBUG(...) vv::Logger::get().log("DEBUG: ", __VA_ARGS__)
	#define VV_INFO(...)  vv::Logger::get().log("INFO : ", __VA_ARGS__)
#else
	#define VV_TRACE(...)
	#define VV_DEBUG(...)
	#define VV_INFO(...)
#endif

#define VV_WARN(...)  vv::Logger::get().log("WARN : ", __FILE__, __LINE__, __VA_ARGS__)
#define VV_ERROR(...) vv::Logger::get().log("ERROR: ", __FILE__, __LINE__, __VA_ARGS__)
#define VV_FATAL(...) vv::Logger::get().log("FATAL: ", __FILE__, __LINE__, __VA_ARGS__)