#pragma once

#include "Window.h"
#include <memory>

namespace Forge {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};


	/* to be defined in client */
	Application* CreateApplication();

}