#pragma once

#include <vector>
#include "IRenderable.h"

class GameObject;

class Scene
{
public:
	Scene();
	~Scene();
	void DoUpdate(float dt);
	std::vector<GameObject*> gameObjects;
	std::vector<IRenderable*> renderableObjects;
};