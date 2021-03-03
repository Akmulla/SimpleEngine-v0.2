#include <Windows.h>
#include "Window.h"
#include "Timer.h"
#include "Scene.h"
#include "Player.h"
#include "Enemy.h"

void InitScene(Scene& scene)
{
	Player* player = new Player();
	player->AssignSprite(*Window::GetMainWindow()->GetGraphics(), L"mario.png", 100,100);
	player->SetPosition({ 0.1f,0.2f,0.0f });
	scene.gameObjects.push_back(player);

	Enemy* enemy = new Enemy();
	enemy->AssignSprite(*Window::GetMainWindow()->GetGraphics(), L"enemy.png", 100, 100);
	player->SetPosition({ 0.5f,0.2f,0.0f });
	scene.gameObjects.push_back(enemy);
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

		mainScene.ResolvePhysics();

		mainScene.DoUpdate(dt);

		window.DrawWindow(mainScene);
	}

	return 0;
}