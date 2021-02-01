#include "Sprite.h"

Sprite::Sprite(Graphics& gfx, const wchar_t* spritePath, float width, float height)
{
	HRESULT hr = S_OK;

	using namespace Microsoft::WRL;
	using namespace DirectX;

	device = gfx.GetDevice();
	context = gfx.GetContext();
	m_pTarget = gfx.GetRenderTarget();
	
	//hr =  CreateGeometry();

	if (SUCCEEDED(CreateGeometry()))
		OutputDebugString("\nSprite geometry created\n\n");
	
	if (SUCCEEDED(CreateShaders()))
		OutputDebugString("\nSprite shaders created\n\n");
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

HRESULT Sprite::CreateShaders()
{
	HRESULT hr = S_OK;

	Microsoft::WRL::ComPtr<ID3DBlob> pBlob;

	//Vertex shader

	hr = D3DReadFileToBlob(L"VertexShader.cso", &pBlob);
	if (FAILED(hr))
	{
		OutputDebugString("\nFailed to read vertex shader cso file\n\n");
		return hr;
	}

	hr = device->CreateVertexShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &m_pVertexShader);


	hr = D3DReadFileToBlob(L"PixelShader.cso", &pBlob);
	if (FAILED(hr))
	{
		OutputDebugString("\nFailed to read pixel shader cso file\n\n");
		return hr;
	}

	hr = device->CreatePixelShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &m_pPixelShader);

	D3D11_INPUT_ELEMENT_DESC layout2D[] =
	{
		{"POSITION", 0, DXGI_FORMAT::DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_CLASSIFICATION::D3D11_INPUT_PER_VERTEX_DATA, 0  },
		{"TEXCOORD", 0, DXGI_FORMAT::DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_CLASSIFICATION::D3D11_INPUT_PER_VERTEX_DATA, 0  },
	};

	device->CreateInputLayout(layout2D,
		(UINT)std::size(layout2D),
		pBlob->GetBufferPointer(),
		pBlob->GetBufferSize(),
		&m_pInputLayout);

	CD3D11_BUFFER_DESC cbDesc(
		sizeof(CB_vertexshader),
		D3D11_BIND_CONSTANT_BUFFER
	);

	hr = device->CreateBuffer(
		&cbDesc,
		nullptr,
		m_pConstantBuffer.GetAddressOf()
	);

	return hr;
}

void Sprite::Draw(DirectX::XMMATRIX worldMatrix, DirectX::XMMATRIX ortoMatrix)
{
	using namespace DirectX;
	XMMATRIX wvpMatrix = worldMatrix * ortoMatrix;
	
	const CB_vertexshader cb =
	{
		wvpMatrix
	};

	context->UpdateSubresource(
		m_pConstantBuffer.Get(),
		0,
		nullptr,
		&cb,
		0,
		0
	);

	//Set input layout
	context->IASetInputLayout(m_pInputLayout.Get());
	//Set render targets
	context->OMSetRenderTargets(1u, &m_pTarget, nullptr);

	/*spriteBatch->Begin();

	spriteBatch->Draw(shaderResource.Get(), pos);

	spriteBatch->End();*/
}
