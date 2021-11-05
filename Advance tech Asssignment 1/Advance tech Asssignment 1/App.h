#pragma once
#include "Window.h"
#include "Timer.h"
#include "Mouse.h"
#include "Graphics.h"
#include <fstream>

class App
{
public:
	App();
	int Go();
	Mouse mouse;
private:
	void DoFrame();
private:
	Window wnd;
	Timer timer;
};
