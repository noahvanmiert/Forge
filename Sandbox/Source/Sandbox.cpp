#include <Forge.h>


class Sandbox : public Forge::Application
{
public:
	Sandbox()
	{
		FG_TRACE("Hello, World!");
	}

	~Sandbox()
	{

	}

};


Forge::Application* Forge::CreateApplication()
{
	return new Sandbox();
}