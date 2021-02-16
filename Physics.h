#pragma once
#include "PhysicalGameObject.h"
#include "CollisionData.h"
#include <vector>

class Physics
{
public:
	Physics() = delete;
	static std::vector<CollisionData> GenerateCollisionPairs(const std::vector<Rigidbody*>&);
	static bool CheckAABBtoAABB(AABB& a, AABB& b);
	static bool SortPairs(CollisionData lhs, CollisionData rhs);
};