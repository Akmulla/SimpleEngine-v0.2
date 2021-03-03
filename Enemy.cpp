#include "Enemy.h"

Enemy::Enemy()
{
	m_sprite = nullptr;
}

Enemy::~Enemy()
{
	delete m_sprite;
}

void Enemy::Draw()
{
	using namespace DirectX;
	XMMATRIX worldMatrix = XMMatrixScaling(m_scale.x, m_scale.y, 1.0f) *
		XMMatrixRotationRollPitchYaw(m_rot.x, m_rot.y, m_rot.z) *
		XMMatrixTranslation(m_pos.x, m_pos.y, m_pos.z);

	XMMATRIX camera = XMMatrixIdentity();

	m_sprite->Draw(worldMatrix, camera);
}

void Enemy::Update(float dt)
{

}

void Enemy::AssignSprite(Graphics& gfx, const wchar_t* spritePath, int width, int height)
{
	m_sprite = new Sprite(gfx, spritePath, width, height);
}
