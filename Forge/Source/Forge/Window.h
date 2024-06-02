#pragma once

#include "Forge/Events/Event.h"

#include <string>
#include <functional>


namespace Forge {

	struct WindowProperties
	{
		std::string Title;
		uint32_t Height;
		uint32_t Width;

		WindowProperties(const std::string& title = "Forge Engine",
			uint32_t width = 1280,
			uint32_t height = 720)
			: Title(title), Width(width), Height(height) 
		{
		}
	};


	class Window
	{
	public:
		using CallbackFunction = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void SetEventCallback(const CallbackFunction& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProperties& props = WindowProperties());
	};

}