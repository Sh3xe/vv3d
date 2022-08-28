#include "vv3d/core/window.hpp"
#include "vv3d/core/logger.hpp"

namespace vv
{
	
void Window::size_callback(GLFWwindow *window, int width, int height)
{
	WindowData &d = *(WindowData*)glfwGetWindowUserPointer(window);
	d.width = width;
	d.height = height;
}

void Window::mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{
	WindowData &d = *(WindowData*)glfwGetWindowUserPointer(window);
	
}

void Window::cursor_pos_callback(GLFWwindow *window, double xpos, double ypos)
{
	WindowData &d = *(WindowData*)glfwGetWindowUserPointer(window);

}

void Window::cursor_enter_callback(GLFWwindow *window, int entered)
{
	WindowData &d = *(WindowData*)glfwGetWindowUserPointer(window);

}

void Window::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	WindowData &d = *(WindowData*)glfwGetWindowUserPointer(window);

}

void Window::char_callback(GLFWwindow *window, unsigned int codepoint)
{
	WindowData &d = *(WindowData*)glfwGetWindowUserPointer(window);

}

void Window::char_mods_callback(GLFWwindow *window, unsigned int codepoint, int mods)
{
	WindowData &d = *(WindowData*)glfwGetWindowUserPointer(window);

}

void Window::scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
	WindowData &d = *(WindowData*)glfwGetWindowUserPointer(window);

}

void Window::drop_path_callback(GLFWwindow* window, int path_count, const char* paths[])
{
	WindowData &d = *(WindowData*)glfwGetWindowUserPointer(window);
	
}

void Window::close_callback(GLFWwindow *window)
{
	WindowData &d = *(WindowData*)glfwGetWindowUserPointer(window);
	WindowCloseEvent event;
	d.event_callback(event);
}

void Window::update()
{
	glfwPollEvents();
	glfwSwapBuffers(m_window);
}

Window::Window(const WindowProp &prop)
{
	m_window = glfwCreateWindow(prop.width, prop.height, prop.title.c_str(), nullptr, nullptr);
	m_window_data.width = prop.width;
	m_window_data.height = prop.height;

	glfwSetWindowUserPointer(m_window, &m_window_data);
	glfwMakeContextCurrent(m_window);

	glfwSetWindowSizeCallback(m_window, size_callback);
	glfwSetKeyCallback(m_window, key_callback);
 	glfwSetCharCallback(m_window, char_callback);
	glfwSetCharModsCallback(m_window, char_mods_callback);
 	glfwSetMouseButtonCallback(m_window, mouse_button_callback);
 	glfwSetCursorPosCallback(m_window, cursor_pos_callback);
 	glfwSetCursorEnterCallback(m_window, cursor_enter_callback);
	glfwSetScrollCallback(m_window, scroll_callback);
	glfwSetWindowCloseCallback(m_window, close_callback);

	// load opengl
	u32 load_status = gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress );
	assert(load_status);
}

Window::~Window()
{
	glfwDestroyWindow(m_window);
}

u32 Window::get_width()
{
	return m_window_data.width;
}

u32 Window::get_height()
{
	return m_window_data.height;
}

bool Window::should_close()
{
	return glfwWindowShouldClose(m_window);
}

void Window::close()
{
	glfwSetWindowShouldClose(m_window, GLFW_TRUE);
}

} // namespace sd
