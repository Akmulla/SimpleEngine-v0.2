#pragma once
#include "Graphics.h"

class IRenderable
{
public:
	virtual void Draw(Graphics& gfx) = 0;};