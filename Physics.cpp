#include "Physics.h"

std::vector<CollisionData> Physics::GenerateCollisionPairs(const std::vector<Rigidbody*>& physicalObjects)
{
	std::vector<CollisionData> result;

	for (auto it = physicalObjects.begin(); it != physicalObjects.end(); ++it)
	{
		AABB box = (*it)->m_AABB;

	}

	return result;
}

bool Physics::CheckAABBtoAABB(AABB& a, AABB& b)
{
	// Exit with no intersection if found separated along an axis
	if (a.rightTop.x < b.leftBot.x || a.leftBot.x > b.rightTop.x)
		return false;

	if (a.rightTop.y < b.leftBot.y || a.leftBot.y > b.rightTop.y)
		return false;

	// No separating axis found, therefor there is at least one overlapping axis
	return true;
}
