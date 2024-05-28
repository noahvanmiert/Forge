#pragma once

#include "Application.h"
#include "Logging/Logger.h"


#ifdef FG_PLATFORM_WINDOWS

extern Forge::Application* Forge::CreateApplication();

int main(int argc, int** argv)
{
	Forge::Logger::Init();

	auto app = Forge::CreateApplication();
	app->Run();
	delete app;
}

#endif