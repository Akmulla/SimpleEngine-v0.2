#pragma once
#include <DirectXMath.h>
#include "CollisionData.h"
#include <functional>

struct AABB
{
public:
	DirectX::XMFLOAT2 leftBot;
	DirectX::XMFLOAT2 rightTop;

	AABB() : leftBot({ -1,-1 }), rightTop({ 1,1 }) {}

	AABB(DirectX::XMFLOAT2 leftBot, DirectX::XMFLOAT2 rightTop) : leftBot(leftBot), rightTop(rightTop)  {}

	AABB(DirectX::XMFLOAT2 center, float width, float height)
	{
		leftBot = { center.x - width / 2.0f, center.y - height / 2.0f };
		rightTop = { center.x + width / 2.0f, center.y + height / 2.0f };
	}

	float GetWidth()
	{
		return rightTop.x - leftBot.x;
	}

	float GetHeight()
	{
		return rightTop.y - leftBot.y;
	}
};

class Rigidbody
{
public:
	DirectX::XMFLOAT2 m_velocity;
	float m_mass;

	std::function<void(CollisionData)> collisionCallback;

	Rigidbody();
	~Rigidbody();
	Rigidbody(AABB box);
	void OnCollision(CollisionData);
	AABB m_AABB;
};

