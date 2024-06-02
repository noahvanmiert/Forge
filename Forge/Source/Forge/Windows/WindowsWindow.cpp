#include "fgpch.h"

#include "WindowsWindow.h"

#include <GLFW/glfw3.h>


namespace Forge {

	static bool s_GLFWInitialized = false;


	static void GLFWErrorCallBack(int error, const char* description)
	{
		FG_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}


	Window* Window::Create(const WindowProperties& props)
	{
		return new WindowsWindow(props);
	}


	WindowsWindow::WindowsWindow(const WindowProperties& props)
	{
		Init(props);
	}


	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}


	void WindowsWindow::Init(const WindowProperties& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		FG_CORE_TRACE("Creating window `{0}` ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			int succes = glfwInit();

			if (!succes)
				FG_CORE_FATAL("Could not initialize GLFW!");

			glfwSetErrorCallback(GLFWErrorCallBack);

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(props.Width, props.Height, props.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}


	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}


	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}


	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}


	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}