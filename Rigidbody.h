#pragma once
#include <DirectXMath.h>

struct AABB
{
public:
	DirectX::XMFLOAT2 leftBot;
	DirectX::XMFLOAT2 rightTop;
};

class Rigidbody
{


private:
	AABB m_AABB;
};

