#include "application.hpp"
#include "sde/core/logger.hpp"

namespace sd
{

Application::Application()
{
	init_window_module();
	m_window = Window::create();
}

Application::~Application()
{

}

void Application::run()
{
	while(!m_window->should_close())
	{

	}
}

} // namespace sd