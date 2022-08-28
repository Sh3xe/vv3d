#ifndef VV_APPLICATION_INCLUDED
#define VV_APPLICATION_INCLUDED

#include "vv3d/core/window.hpp"

namespace vv
{

class Application
{
public:
	Application();
	~Application();
	
	void run();
	void on_event(const Event &e);
	
protected:
	Scope<Window> m_window;

private:

	bool m_running {true};

};

} // namespace sd

#endif