#pragma once
#include "BoxCollider.h"
#include "Sprite.h"
#include "IRenderable.h"
#include "IPhysical.h"

class Player : GameObject, IRenderable, IPhysical
{
public:
	Player();
	~Player();
private:
	Sprite sprite;
};