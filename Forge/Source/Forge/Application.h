#pragma once


namespace Forge {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};


	/* to be defined in client */
	Application* CreateApplication();

}