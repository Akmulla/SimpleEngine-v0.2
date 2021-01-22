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
	void Draw(DirectX::XMFLOAT2) override;
	void AssignSprite(Graphics& gfx, const wchar_t* spritePath, int width, int height);
private:
	Sprite* sprite;
};