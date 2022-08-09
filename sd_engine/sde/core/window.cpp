#include "window.hpp"
#include <cassert>

namespace sd
{

void init_window_module()
{
	int status = glfwInit();
	assert( status == GLFW_TRUE );
}

void Window::size_callback(GLFWwindow *win, int width, int height)
{
	WindowData *d = (WindowData*)glfwGetWindowUserPointer(win);
	d->width = width;
	d->height = height;
}

void Window::mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{

}

void Window::cursor_pos_callback(GLFWwindow *window, double xpos, double ypos)
{

}

void Window::cursor_enter_callback(GLFWwindow *window, int entered)
{

}

void Window::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{

}

void Window::char_callback(GLFWwindow *window, unsigned int codepoint)
{

}

void Window::char_mods_callback(GLFWwindow *window, unsigned int codepoint, int mods)
{

}

void Window::scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{

}

void Window::drop_path_callback(GLFWwindow* window, int path_count, const char* paths[])
{
	
}


Scope<Window> Window::create(u32 width, u32 height, bool fullscreen)
{
	Scope<Window> ptr {new Window};

	ptr->m_window = glfwCreateWindow(width, height, "SDE", nullptr, nullptr);
	ptr->m_window_data.width = width;
	ptr->m_window_data.height = height;

	glfwSetWindowUserPointer(ptr->m_window, &ptr->m_window_data);

	glfwSetWindowSizeCallback(ptr->m_window, size_callback);
	glfwSetKeyCallback (ptr->m_window, key_callback);
 	glfwSetCharCallback (ptr->m_window, char_callback);
	glfwSetCharModsCallback (ptr->m_window, char_mods_callback);
 	glfwSetMouseButtonCallback (ptr->m_window, mouse_button_callback);
 	glfwSetCursorPosCallback (ptr->m_window, cursor_pos_callback);
 	glfwSetCursorEnterCallback (ptr->m_window, cursor_enter_callback);
	glfwSetScrollCallback (ptr->m_window, scroll_callback);

	return ptr;
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

void Window::resize(u32 w, u32 h)
{
	glfwSetWindowSize(m_window, w, h);
}

void Window::close()
{
	glfwSetWindowShouldClose(m_window, GLFW_TRUE);
}

} // namespace sd
