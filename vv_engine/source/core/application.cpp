#include "vv3d/core/application.hpp"
#include "vv3d/core/logger.hpp"

namespace vv
{

Application::Application()
{
	m_window = Scope<Window>(new Window());
	m_window->set_event_callback( 
		[this](const Event &event)
		{
			this->on_event(event);
		}
	);

}

Application::~Application()
{

}

void Application::on_event(const Event &e)
{
	if(e.get_type() == EventType::winclose)
		m_running = false;
}

void Application::run()
{
	while(m_running)
	{
		m_window->update();
	}
}

} // namespace sd