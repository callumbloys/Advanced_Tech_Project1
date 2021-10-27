#include "App.h"
#include <sstream>

App::App()
	:
	wnd(800,600,"Project Window")
{}

int App::Go()
{
	while(true)
	{
		if (const auto ecode = Window::ProcessMessages())
		{
			return *ecode;
		}
		DoFrame(); 
	}
}

void App::DoFrame()
{
	wnd.Gfx().DrawTestTriangle();
	wnd.Gfx().EndFrame();
}