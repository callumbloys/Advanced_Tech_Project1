#include <Windows.h>
#include "Window.h"
#include "App.h"

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     IpCmdLine,
	int       nCmdShow)
{
	return App{}.Go();
}