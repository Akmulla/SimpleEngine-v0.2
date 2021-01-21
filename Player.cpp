#include "Player.h"

Player::Player()
{
	sprite = nullptr;
}

Player::~Player()
{
	delete sprite;
}

void Player::Draw(DirectX::XMMATRIX orthoMatrix)
{

}

void Player::AssignSprite(Graphics& gfx, std::string spritePath)
{

}