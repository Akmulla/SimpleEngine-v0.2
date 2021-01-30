#include "Sprite.h"

Sprite::Sprite(Graphics& gfx, const wchar_t* spritePath, float width, float height)
{
	using namespace Microsoft::WRL;
	using namespace DirectX;

	device = gfx.GetDevice();
	context = gfx.GetContext();
	
	std::vector<Vertex2D> vertexData =
	{
		Vertex2D(-0.5f, -0.5f, 0.0f, 0.0f, 0.0f), //TopLeft
		Vertex2D(0.5f, -0.5f, 0.0f, 1.0f, 0.0f), //TopRight
		Vertex2D(-0.5, 0.5, 0.0f, 0.0f, 1.0f), //Bottom Left
		Vertex2D(0.5, 0.5, 0.0f, 1.0f, 1.0f), //Bottom Right
	};

	std::vector<DWORD> indexData =
	{
		0, 1, 2,
		2, 1, 3
	};

	//HRESULT hr = vertices.Initialize(device, vertexData.data(), vertexData.size());

	//hr = indices.Initialize(device, indexData.data(), indexData.size());

	/*spriteBatch = std::make_unique<SpriteBatch>(context);
	ComPtr<ID3D11Resource> resource;
	CreateWICTextureFromFile(device, spritePath,resource.GetAddressOf(), shaderResource.ReleaseAndGetAddressOf());

	ComPtr<ID3D11Texture2D> texture;
	resource.As(&texture);

	CD3D11_TEXTURE2D_DESC texDesc;
	texture->GetDesc(&texDesc);*/
}

void Sprite::Draw()
{
	/*spriteBatch->Begin();

	spriteBatch->Draw(shaderResource.Get(), pos);

	spriteBatch->End();*/
}
