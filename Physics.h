#pragma once
#include "PhysicalGameObject.h"
#include <vector>

class Physics
{
public:
	Physics() = delete;
	void GenerateCollisionPairs(const std::vector<PhysicalGameObject*>);
	bool CheckAABBtoAABB(AABB& a, AABB& b);
};