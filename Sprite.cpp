#include "Sprite.h"

Sprite::Sprite(Graphics* gfx, const wchar_t* spritePath, float width, float height)
{
	using namespace Microsoft::WRL;
	using namespace DirectX;

	device = gfx->GetDevice();
	context = gfx->GetContext();
	
	spriteBatch = std::make_unique<SpriteBatch>(context);
	ComPtr<ID3D11Resource> resource;
	CreateWICTextureFromFile(device, spritePath,resource.GetAddressOf(), shaderResource.ReleaseAndGetAddressOf());

	ComPtr<ID3D11Texture2D> texture;
	resource.As(&texture);

	CD3D11_TEXTURE2D_DESC texDesc;
	texture->GetDesc(&texDesc);
}

void Sprite::Draw(DirectX::XMFLOAT2 pos)
{
	spriteBatch->Begin();

	spriteBatch->Draw(shaderResource.Get(), pos);

	spriteBatch->End();
}
