#pragma once
#include "Window.h"
#include "Timer.h"
#include "Mouse.h"
#include "Graphics.h"
#include <fstream>
#include "Camera.h"
//#include "Graphics.h"
//#include "Drawable.h"
#include "Cube.h"

class App
{
public:
	App();
	int Go();
	Mouse mouse;
private:
	void DoFrame();
	void HandleInput(float dt);
private:
	Window wnd;
	Timer timer;
	Camera cam;

	std::vector<std::unique_ptr<Drawable>> cubes; 
	float speed_factor = 1.0f;
};
