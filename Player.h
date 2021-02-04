#pragma once
#include "GameObject.h"
#include "BoxCollider.h"
#include "Sprite.h"
#include "PlayerMovement.h"
#include <string>

class Player : public GameObject
{
public:
	Player();
	~Player();
	void Draw() override;
	void Update(float dt) override;
	void AssignSprite(Graphics& gfx, const wchar_t* spritePath, int width, int height);
private:
	Sprite* sprite;
	PlayerMovement* m_movement;
};