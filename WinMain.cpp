#include <Windows.h>
#include "Window.h"
#include "Timer.h"
#include "Scene.h"

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_  HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	Timer timer;
	Scene mainScene;
	Window window(hInstance);

	while (true)
	{
		float dt = timer.Mark();

		window.UpdateWindowsMessages();

		mainScene.DoUpdate(dt);

		window.DrawWindow();
	}

	return 0;
}