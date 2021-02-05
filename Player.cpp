#include "Player.h"

Player::Player()
{
	m_sprite = nullptr;
	m_movement = new PlayerMovement(*this, 5.0f);
}

Player::~Player()
{
	delete m_sprite;
	delete m_movement;
}

void Player::Draw()
{
	using namespace DirectX;
	XMMATRIX worldMatrix = XMMatrixRotationRollPitchYaw(m_rot.x, m_rot.y, m_rot.z) * XMMatrixTranslation(m_pos.x, m_pos.y, m_pos.z);

	XMMATRIX camera = XMMatrixIdentity();
	//XMMATRIX worldMatrix = XMMatrixIdentity();
	m_sprite->Draw(worldMatrix, camera);
}

void Player::Update(float dt)
{
	m_movement->Update(dt);
}

void Player::AssignSprite(Graphics& gfx, const wchar_t* spritePath, int width, int height)
{
	m_sprite = new Sprite(gfx, spritePath, width, height);
}