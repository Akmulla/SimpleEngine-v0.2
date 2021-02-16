#include "Scene.h"
#include "GameObject.h"
#include "PhysicalGameObject.h"
#include "Physics.h"

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

void Scene::ResolvePhysics()
{
	std::vector<Rigidbody*> rigidbodies;

	for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		PhysicalGameObject* obj = dynamic_cast<PhysicalGameObject*>(*it);
		if (obj)
		{
			rigidbodies.push_back(obj->GetRigidbody());
		}
	}

	std::vector<CollisionData> pairs = Physics::GenerateCollisionPairs(rigidbodies);
}
