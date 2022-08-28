#pragma once

#include "vv3d/defines.hpp"
#include "vv3d/events/event.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <functional>

namespace vv
{
	
struct WindowProp
{
	int width {1280};
	int height {720};
	std::string title {""};
};

class Window
{
public:
	using EventCallback = std::function<void(const Event&)>;

	Window(const WindowProp &props = WindowProp());
	~Window();

	u32 get_width();
	u32 get_height();
	bool should_close();
	void update();
	void set_event_callback(const EventCallback &callback) {m_window_data.event_callback = callback;}

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
	static void close_callback(GLFWwindow *window);

	struct WindowData
	{
		u32 width;
		u32 height;
		EventCallback event_callback;
	};

	GLFWwindow *m_window;
	WindowData m_window_data;
};


} // namespace sd