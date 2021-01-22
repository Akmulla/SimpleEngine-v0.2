#pragma once
#include "BoxCollider.h"
#include "Sprite.h"
#include "IRenderable.h"
#include "IPhysical.h"
#include <string>

class Player : public GameObject, IRenderable, IPhysical
{
public:
	Player();
	~Player();
	void Draw();
	void Update(float dt) override;
	void AssignSprite(Graphics& gfx, const wchar_t* spritePath, int width, int height);
private:
	Sprite* sprite;
};