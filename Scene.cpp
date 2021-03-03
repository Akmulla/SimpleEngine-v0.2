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


	//probably move to physics class from here
	std::vector<CollisionData> pairs = Physics::GenerateCollisionPairs(rigidbodies);

	std::vector<CollisionData> unique_pairs = Physics::RemoveDuplicates(pairs);

	for (auto it = unique_pairs.begin(); it != unique_pairs.end(); ++it)
	{
		it->A->OnCollision(*it);
		it->B->OnCollision(*it);
	}

}
