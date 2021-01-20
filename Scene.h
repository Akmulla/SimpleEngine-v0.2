#pragma once

#include <vector>

class GameObject;

class Scene
{
public:
	Scene();
	~Scene();
	void DoUpdate(float dt);
	std::vector<GameObject*> gameObjects;
};