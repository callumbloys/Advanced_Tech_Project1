#include <Windows.h>
#include "Window.h"
#include "Game.h"

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     IpCmdLine,
	int       nCmdShow)
{
	return Game{}.Go();
}