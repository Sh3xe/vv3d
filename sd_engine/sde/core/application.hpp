#pragma once

#include "sde/core/window.hpp"

namespace sd
{

SD_API class Application
{
public:
	Application();
	~Application();
	void run();
	
protected:
	Scope<Window> m_window;
};

} // namespace sd