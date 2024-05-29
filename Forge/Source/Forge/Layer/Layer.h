#pragma once

#include "Forge/Core.h"
#include "Forge/Core/DeltaTime.h"

#include "Forge/Events/Event.h"

#include <string>


namespace Forge {

	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(DeltaTime deltaTime) {}
		virtual void OnImguiRender() {}
		virtual void OnEvent(Event& e) {}

		inline const std::string& GetName() const { return m_DebugName; }
	private:
		std::string m_DebugName;
	};

}