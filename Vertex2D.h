#pragma once
#include <DirectXMath.h>

struct Vertex2D
{
	Vertex2D() 
	{
		pos = DirectX::XMFLOAT3();
		texCoord = DirectX::XMFLOAT2();
	}

	Vertex2D(float x, float y, float z, float u, float v)
		: pos(x, y, z), texCoord(u,v) {}

	DirectX::XMFLOAT3 pos;
	DirectX::XMFLOAT2 texCoord;
};