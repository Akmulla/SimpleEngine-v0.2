#include "Player.h"

Player::Player()
{
	sprite = nullptr;
}

Player::~Player()
{
	delete sprite;
}

void Player::Draw(DirectX::XMFLOAT2 pos)
{
	sprite->Draw(pos);
}

void Player::AssignSprite(Graphics& gfx, const wchar_t* spritePath, int width, int height)
{
	sprite = new Sprite(gfx, spritePath, width, height);
}