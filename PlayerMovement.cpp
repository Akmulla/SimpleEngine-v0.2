#include "PlayerMovement.h"

PlayerMovement::PlayerMovement(GameObject& owner, float movementSpeed) : m_owner(&owner), m_speed(movementSpeed) {}

void PlayerMovement::Update(float dt)
{
	float h = Input::GetInput().horizontal;
	float v = Input::GetInput().vertical;

	DirectX::XMFLOAT3 movement = DirectX::XMFLOAT3(h * dt, v * dt, 0.0f);
	m_owner->Move(movement);
}
