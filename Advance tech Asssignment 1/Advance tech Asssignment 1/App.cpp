#include "App.h"
#include <sstream>
#include "Mouse.h"

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
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(.051f, .087f, .255f);
	wnd.Gfx().DrawTestTriangle(
		timer.Peek(),
		wnd.mouse.GetPosX() / 800.0f,
		wnd.mouse.GetPosY() / 600.0f
	);
	wnd.Gfx().EndFrame();
}