#include "Player.h"

Player::Player()
{
	m_sprite = nullptr;
	m_movement = new PlayerMovement(*this, 5.0f);
	//m_rb->m_AABB = {{ -100,-100 }, { -99,-99 }};
	m_rb->collisionCallback = std::bind(&Player::OnCollision, this, std::placeholders::_1);
}

Player::~Player()
{
	delete m_sprite;
	delete m_movement;
}

void Player::Draw()
{
	using namespace DirectX;
	XMMATRIX worldMatrix = XMMatrixScaling(m_scale.x, m_scale.y, 1.0f) * 
		XMMatrixRotationRollPitchYaw(m_rot.x, m_rot.y, m_rot.z) * 
		XMMatrixTranslation(m_pos.x, m_pos.y , m_pos.z);

	XMMATRIX camera = XMMatrixIdentity();
	
	m_sprite->Draw(worldMatrix, camera);


	//XMMatrixTranslation(m_pos.x + m_scale.x / 2.0f, m_pos.y + m_scale.y / 2.0f, m_pos.z);
}

void Player::Update(float dt)
{
	m_movement->Update(dt);
}

void Player::AssignSprite(Graphics& gfx, const wchar_t* spritePath, int width, int height)
{
	m_sprite = new Sprite(gfx, spritePath, width, height);
}

void Player::OnCollision(CollisionData)
{
	OutputDebugString("\nPlayer collided\n\n");
}
