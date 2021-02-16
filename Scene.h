#pragma once

#include <vector>

class GameObject;

class Scene
{
public:
	Scene();
	~Scene();
	void DoUpdate(float dt);
	void ResolvePhysics();
	std::vector<GameObject*> gameObjects;
	//add scene camera here?
};