#pragma once
#include "GameObject.h"
#include "Input.h"

class PlayerMovement
{
public:
	PlayerMovement(GameObject& owner, float movementSpeed);
	void Update(float dt);
private:
	GameObject* m_owner;
	float m_speed;
};