#pragma once
#include <DirectXMath.h>

struct AABB
{
public:
	DirectX::XMFLOAT2 leftBot;
	DirectX::XMFLOAT2 rightTop;

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

struct PhysicalParameters
{
	float mass;
};

class Rigidbody
{
public:
	DirectX::XMFLOAT2 velocity;
	PhysicalParameters parameters;

	Rigidbody(PhysicalParameters);
private:
	AABB m_AABB;
};

