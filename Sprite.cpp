#include "Sprite.h"

Sprite::Sprite(Graphics* gfx, std::string spritePath, float width, float height)
{
	device = gfx->GetDevice();
	context = gfx->GetContext();
}
