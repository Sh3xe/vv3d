#pragma once

#include "sde/defines.hpp"
#include <GLFW/glfw3.h>

namespace sd
{

void init_window_module();

SD_API class Window
{
public:
	~Window();
	static Scope<Window> create(u32 width = 1280, u32 height = 720, bool fullscreen = false);

	u32 get_width();
	u32 get_height();
	bool should_close();

	void resize(u32 w, u32 h);
	void close();

private:
	static void size_callback(GLFWwindow *win, int width, int height);
	static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
	static void cursor_pos_callback(GLFWwindow *window, double xpos, double ypos);
	static void cursor_enter_callback(GLFWwindow *window, int entered);
	static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
	static void char_callback(GLFWwindow *window, unsigned int codepoint);
	static void char_mods_callback(GLFWwindow *window, unsigned int codepoint, int mods);
	static void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);
	static void drop_path_callback(GLFWwindow* window, int path_count, const char* paths[]);

	struct WindowData
	{
		u32 width;
		u32 height;
	};

	GLFWwindow *m_window;
	WindowData m_window_data;
};


} // namespace sd