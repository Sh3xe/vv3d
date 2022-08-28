#include "GLFW/glfw3.h"

namespace vv
{
	bool init()
	{
		// logging
		std::cout.sync_with_stdio(false);

		// windowing
		u32 init_status = glfwInit();
		if (init_status != GLFW_TRUE)
		{
			VV_FATAL("impossible d'initialiser glfw");
			return false;
		}

		return true;
	}

	void shutdown()
	{
		glfwTerminate();
	}
}