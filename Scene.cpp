#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
	for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		delete (*it);
	}
}

void Scene::DoUpdate(float dt)
{
}
