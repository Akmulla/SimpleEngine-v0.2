#include <Windows.h>
#include "Window.h"

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_  HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	Window window(hInstance);

	while (true)
	{
		window.DrawWindow();
	}

	return 0;
}