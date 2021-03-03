#pragma once
#include "GameObject.h"
#include "Rigidbody.h"


class PhysicalGameObject : public GameObject
{
protected:
	virtual void OnCollision(CollisionData);
	Rigidbody* m_rb;
public:
	Rigidbody* GetRigidbody();

	PhysicalGameObject();
	~PhysicalGameObject();

	//OnCollisionEnter()
};