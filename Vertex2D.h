#pragma once
#include <DirectXMath.h>

struct Vertex2D
{
	Vertex2D() 
	{
		pos = DirectX::XMFLOAT3();
	}

	Vertex2D(float x, float y, float z)
		: pos(x, y, z) {}

	DirectX::XMFLOAT3 pos;
};