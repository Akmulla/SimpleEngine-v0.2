#pragma once
#include "GameObject.h"
#include "Rigidbody.h"


class PhysicalGameObject : public GameObject
{
private:
	Rigidbody* m_rb;
public:
	Rigidbody* GetRigidbody();

	PhysicalGameObject();
	~PhysicalGameObject();

	//OnCollisionEnter()
};