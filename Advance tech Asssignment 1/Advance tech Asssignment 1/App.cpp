#include "App.h"
#include <sstream>

App::App()
	:
	wnd(800,600,"Callum Bloys: Project Window")
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
	wnd.Gfx().ClearBuffer(.2f, .2f, .255f);

	/*wnd.Gfx().DrawTestTriangle(
		-timer.Peek(),
		0.0f,
		0.0f
	);
	wnd.Gfx().DrawTestTriangle(
		timer.Peek(), 
		wnd.mouse.GetPosX() / 400.0f - 1.0f, 
		~wnd.mouse.GetPosY() / 300.0f + 1.0f
	);*/


	std::ifstream map;
	map.open("Level1.txt");
	char wall = '#';
	int row = 0;
	int column = 0;

	while (!map.eof())
	{
		row++;
		if (row == 37)
		{
			column--;
			row = 0;
		}

		if (map.get() == wall)
		{
			wnd.Gfx().DrawTestTriangle(0, row * 1.9f - 8.0f, column * 2 + 3.0f, 5.0f);
			wnd.Gfx().DrawTestTriangle(0, row * 1.9f - 8.0f, column * 2 + 3.0f, 6.9f);
		}
	}



	wnd.Gfx().EndFrame();
}