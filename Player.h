#pragma once
#include "PhysicalGameObject.h"
#include "Sprite.h"
#include "PlayerMovement.h"
#include <string>
#include <functional>

class Player : public PhysicalGameObject
{
public:
	Player();
	~Player();
	void Draw() override;
	void Update(float dt) override;
	void AssignSprite(Graphics& gfx, const wchar_t* spritePath, int width, int height);
	void OnCollision(CollisionData) override;
private:
	Sprite* m_sprite;
	PlayerMovement* m_movement;
};