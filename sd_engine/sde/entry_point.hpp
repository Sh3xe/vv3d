#pragma once

#define SD_START(AppType) \
int main(int argc, char *argv[]) \
{ \
	AppType *app = new AppType; \
	app->run(); \
	delete app; \
	return 0; \
}
