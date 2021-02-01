#include "Player.h"

Player::Player()
{
	sprite = nullptr;
}

Player::~Player()
{
	delete sprite;
}

void Player::Draw()
{
	using namespace DirectX;
	XMMATRIX worldMatrix = XMMatrixRotationRollPitchYaw(m_rot.x, m_rot.y, m_rot.z) * 
		XMMatrixTranslation(m_pos.x, m_pos.y, m_pos.z);

	XMMATRIX camera = XMMatrixIdentity();

	sprite->Draw(worldMatrix, camera);
}

void Player::Update(float dt)
{
}

void Player::AssignSprite(Graphics& gfx, const wchar_t* spritePath, int width, int height)
{
	sprite = new Sprite(gfx, spritePath, width, height);
}