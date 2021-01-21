#pragma once
#include "Graphics.h"

class IRenderable
{
public:
	virtual void Draw(DirectX::XMMATRIX) = 0;
};