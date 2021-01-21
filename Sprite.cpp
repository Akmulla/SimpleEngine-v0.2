#include "Sprite.h"

Sprite::Sprite(Graphics* gfx, const wchar_t* spritePath, float width, float height)
{
	using namespace Microsoft::WRL;
	using namespace DirectX;

	device = gfx->GetDevice();
	context = gfx->GetContext();

	spriteBatch = std::make_unique<SpriteBatch>(context);
	ComPtr<ID3D11Resource> resource;
	CreateWICTextureFromFile(device, spritePath,resource.GetAddressOf(), texture.ReleaseAndGetAddressOf());
}
