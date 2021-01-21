#pragma once
#include "BoxCollider.h"
#include "Sprite.h"
#include "IRenderable.h"
#include "IPhysical.h"
#include <string>

class Player : GameObject, IRenderable, IPhysical
{
public:
	Player();
	~Player();
	void Draw(DirectX::XMMATRIX) override;
	void AssignSprite(Graphics& gfx, std::string spritePath);
private:
	Sprite* sprite;
};