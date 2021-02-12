#pragma once
#include "GameObject.h"
#include "Rigidbody.h"



class PhysicalGameObject : public GameObject
{
public:
	Rigidbody* m_rb;

	PhysicalGameObject(PhysicalParameters parameters);
	~PhysicalGameObject();
};