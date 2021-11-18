#include "App.h"
#include <sstream>
#include <memory>
#include <algorithm>
#include <DirectXMath.h>
#include "Bindable.h"

namespace dx = DirectX;

App::App()
	:
	//AddBind(std::make_unique<Texture>(Rnd, L"Bricks.jpg"));
	//AddBind(std::make_unique<TextureSampler>(Rnd));

	wnd(800,600,"Callum Bloys: Project Window")
{
	wnd.Gfx().SetProjection( dx::XMMatrixPerspectiveLH( 1.0f,9.0f / 16.0f,0.5f,40.0f ) );

	std::ifstream map;
	map.open("Level1.txt");
	char wall = '#';
	int row = 0;
	int column = 0;

	while (!map.eof())
	{
		row++;
		if (row == 31)
		{
			column--;
			row = 0;
		}

		if (map.get() == wall)
		{

			cubes.push_back(std::make_unique<Cube>(wnd.Gfx(), 1.0f, 1.0f, 1.0f, row * 1.9f - 30.0f, 0.0f, column * 1.9f + 11.0f));

		}
		else
		{
			cubes.push_back(std::make_unique<Cube>(wnd.Gfx(), 1.0f, 1.0f, 1.0f, row * 1.9f - 30.0f, 2.0f, column * 1.9 + 11.0f));
			cubes.push_back(std::make_unique<Cube>(wnd.Gfx(), 1.0f, 1.0f, 1.0f, row * 1.9f - 30.0f, -2.0f, column * 1.9f + 11.0f));
		}
	}
	/*for
	{
		DrawAnimatedRects(v.x, v.y, v.z)
	}*/

	map.close();
	//std::vector<DirectX::XMFLOAT3>; 

}

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
	const auto dt = timer.Mark() * speed_factor;
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(.2f, .2f, .255f);
	wnd.Gfx().SetCamera(cam.GetMatrix());

	if (wnd.kbd.KeyIsPressed('W'))
	{
		cam.Translate({ 0.0f,0.0f,dt });
	}
	if (wnd.kbd.KeyIsPressed('A'))
	{
		cam.Translate({ -dt,0.0f,0.0f });
	}
	if (wnd.kbd.KeyIsPressed('S'))
	{
		cam.Translate({ 0.0f,0.0f,-dt });
	}
	if (wnd.kbd.KeyIsPressed('D'))
	{
		cam.Translate({ dt,0.0f,0.0f });
	}
	if (wnd.kbd.KeyIsPressed('R'))
	{
		cam.Translate({ 0.0f,dt,0.0f });
	}
	if (wnd.kbd.KeyIsPressed('F'))
	{
		cam.Translate({ 0.0f,-dt,0.0f });
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		cam.Rotate(dt,0.0f);
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		cam.Rotate(-dt, 0.0f);
	}

	for (auto& drawable : cubes)
	{
		drawable->Draw(wnd.Gfx());
	}

	wnd.Gfx().EndFrame();
}