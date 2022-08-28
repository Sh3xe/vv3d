#ifndef VV_ENTRY_POINT_INCLUDED
#define VV_ENTRY_POINT_INCLUDED

#include "vv3d/vv3d.hpp"

#define VV_START(AppType) \
int main(int argc, char *argv[]) \
{ \
	if(vv::init()) \
	{ \
		AppType *app = new AppType; \
		app->run(); \
		delete app; \
		vv::shutdown(); \
	} \
	return 0; \
}

#endif