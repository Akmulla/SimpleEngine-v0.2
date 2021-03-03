#pragma once
#include "PhysicalGameObject.h"
#include "Sprite.h"

class Enemy : public PhysicalGameObject
{
public :
	Enemy();
	~Enemy();
	void Draw() override;
	void Update(float dt) override;
	void AssignSprite(Graphics& gfx, const wchar_t* spritePath, int width, int height);
private:
	Sprite* m_sprite;
};