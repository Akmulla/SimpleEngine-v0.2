#include "Sprite.h"

Sprite::Sprite(Graphics& gfx, const wchar_t* spritePath, float width, float height)
{
	HRESULT hr = S_OK;

	using namespace Microsoft::WRL;
	using namespace DirectX;

	device = gfx.GetDevice();
	context = gfx.GetContext();
	
	hr =  CreateGeometry();

	if (SUCCEEDED(hr))
		OutputDebugString("\nSprite geometry created\n\n");
	

}

HRESULT Sprite::CreateGeometry()
{
	HRESULT hr = S_OK;

	//Create vertices and vertex data
	Vertex2D vertexData[] =
	{
		Vertex2D(-0.5f, -0.5f, 0.0f, 0.0f, 0.0f), //TopLeft
		Vertex2D(0.5f, -0.5f, 0.0f, 1.0f, 0.0f), //TopRight
		Vertex2D(-0.5, 0.5, 0.0f, 0.0f, 1.0f), //Bottom Left
		Vertex2D(0.5, 0.5, 0.0f, 1.0f, 1.0f), //Bottom Right
	};

	CD3D11_BUFFER_DESC vDesc(
		sizeof(vertexData),
		D3D11_BIND_VERTEX_BUFFER
	);

	D3D11_SUBRESOURCE_DATA vData;
	ZeroMemory(&vData, sizeof(D3D11_SUBRESOURCE_DATA));
	vData.pSysMem = vertexData;
	vData.SysMemPitch = 0;
	vData.SysMemSlicePitch = 0;

	hr = device->CreateBuffer(
		&vDesc,
		&vData,
		&m_pVertexBuffer
	);


	//Create indices and index data
	UINT indexData[] =
	{
		0, 1, 2,
		2, 1, 3
	};

	CD3D11_BUFFER_DESC iDesc(
		sizeof(indexData),
		D3D11_BIND_INDEX_BUFFER
	);

	D3D11_SUBRESOURCE_DATA iData;
	ZeroMemory(&iData, sizeof(D3D11_SUBRESOURCE_DATA));
	iData.pSysMem = indexData;
	iData.SysMemPitch = 0;
	iData.SysMemSlicePitch = 0;

	hr = device->CreateBuffer(
		&iDesc,
		&iData,
		&m_pIndexBuffer
	);

	return hr;
}

void Sprite::Draw()
{
	/*spriteBatch->Begin();

	spriteBatch->Draw(shaderResource.Get(), pos);

	spriteBatch->End();*/
}
