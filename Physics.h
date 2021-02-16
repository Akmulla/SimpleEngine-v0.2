#pragma once
#include "PhysicalGameObject.h"
#include <vector>

class Physics
{
public:
	Physics() = delete;
	void GenerateCollisionPairs(const std::vector<PhysicalGameObject*>);
};