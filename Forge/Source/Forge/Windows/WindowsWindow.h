#pragma once

#include "Forge/Window.h"
#include <GLFW/glfw3.h>


namespace Forge {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperties& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline uint32_t GetWidth()  const override { return m_Data.Width;  }
		inline uint32_t GetHeight() const override { return m_Data.Height; }

		inline void SetEventCallback(const CallbackFunction& callback) override
		{
			m_Data.EventCallback = callback;
		}

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline virtual void* GetNativeWindow() const { return m_Window; }

	private:
		virtual void Init(const WindowProperties& props);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;

		struct WindowData 
		{
			std::string Title;
			uint32_t Width, Height;
			bool VSync;

			CallbackFunction EventCallback;
		};

		WindowData m_Data;
	};

}