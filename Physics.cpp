#include "Physics.h"

std::vector<CollisionData> Physics::GenerateCollisionPairs(const std::vector<Rigidbody*>& physicalObjects)
{
	std::vector<CollisionData> result;

	for (auto i = physicalObjects.begin(); i != physicalObjects.end(); ++i)
	{
		for (auto j = physicalObjects.begin(); j != physicalObjects.end(); ++j)
		{
			if (i == j)
				continue;

			AABB a = (*i)->m_AABB;
			AABB b = (*j)->m_AABB;

			if (CheckAABBtoAABB(a, b))
			{
				CollisionData data;
				data.A = *i;
				data.B = *j;
				result.push_back(data);
			}
		}
		

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

bool Physics::SortPairs(CollisionData lhs, CollisionData rhs)
{
	if (lhs.A < rhs.A)
		return true;

	if (lhs.A == rhs.A)
		return lhs.B < rhs.B;

	return false;
}
