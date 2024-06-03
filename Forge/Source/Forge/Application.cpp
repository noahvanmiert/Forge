#include "fgpch.h"

#include "Application.h"


namespace Forge {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}


	Application::~Application()
	{

	}


	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowCloseEvent));
	}


	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}


	bool Application::OnWindowCloseEvent(WindowCloseEvent& e)
	{
		m_Running = false;

		return true;
	}

}