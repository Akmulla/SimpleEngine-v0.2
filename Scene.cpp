#include "Scene.h"
#include "GameObject.h"

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
	for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		(*it)->Update(dt);
	}
}
