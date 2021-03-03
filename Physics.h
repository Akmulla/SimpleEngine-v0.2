#pragma once
#include "PhysicalGameObject.h"
#include "CollisionData.h"
#include <vector>
#include <algorithm>
#include <list>

class Physics
{
public:
	Physics() = delete;
	static std::vector<CollisionData> GenerateCollisionPairs(const std::vector<Rigidbody*>&);
	static std::vector<CollisionData> RemoveDuplicates(std::vector<CollisionData> collisionData);
	static bool CheckAABBtoAABB(AABB& a, AABB& b);
	//static bool SortPairs(CollisionData lhs, CollisionData rhs);
};