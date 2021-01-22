#include <Windows.h>
#include "Window.h"
#include "Timer.h"
#include "Scene.h"
#include "Player.h"

void InitScene(Scene& scene)
{
	Player* player = new Player();
	player->AssignSprite(*Window::GetMainWindow()->GetGraphics(), L"player.png", 100,100);
}

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_  HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	Timer timer;
	Scene mainScene;
	Window window(hInstance);

	InitScene(mainScene);

	while (true)
	{
		float dt = timer.Mark();

		window.UpdateWindowsMessages();

		mainScene.DoUpdate(dt);

		window.DrawWindow(mainScene);
	}

	return 0;
}