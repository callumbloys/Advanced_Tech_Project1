#pragma once
#include "Window.h"
#include "Timer.h"
#include "Mouse.h"
#include "Graphics.h"
#include <fstream>
#include "Camera.h"
#include "Graphics.h"

class Game
{
public:
	Game();
	int Go();
	Mouse mouse;
private:
	void DoFrame();
	void HandleInput(float dt);
private:
	Window wnd;
	Timer timer;
	Camera cam;
	float speed_factor = 1.0f;
};
