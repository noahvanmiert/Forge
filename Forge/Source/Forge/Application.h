#pragma once

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

#include "Window.h"

#include <memory>


namespace Forge {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

	private:
		bool OnWindowCloseEvent(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};


	/* to be defined in client */
	Application* CreateApplication();

}