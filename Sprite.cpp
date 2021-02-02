#include "Sprite.h"

Sprite::Sprite(Graphics& gfx, const wchar_t* spritePath, float width, float height)
{
	HRESULT hr = S_OK;

	using namespace Microsoft::WRL;
	using namespace DirectX;

	m_device = gfx.GetDevice();
	m_context = gfx.GetContext();
	m_pTarget = gfx.GetRenderTarget();
	
	//hr =  CreateGeometry();

	if (SUCCEEDED(CreateGeometry()))
		OutputDebugString("\nSprite geometry created\n\n");
	
	if (SUCCEEDED(CreateShaders()))
		OutputDebugString("\nSprite shaders created\n\n");

	CreateTexture(spritePath);
}

HRESULT Sprite::CreateGeometry()
{
	HRESULT hr = S_OK;

	////////////////////Create vertices and vertex data
	Vertex2D vertexData[] =
	{
		Vertex2D(-0.5f, -0.5f, 0.0f, 0.0f, 1.0f), 
		Vertex2D(-0.5f, 0.5f, 0.0f, 0.0f, 0.0f),
		Vertex2D(0.5f, 0.5f, 0.0f, 1.0f,0.0f),
		Vertex2D(0.5f, -0.5f, 0.0f, 1.0f,1.0f), 
	};

	CD3D11_BUFFER_DESC vertexBufferDesc;
	ZeroMemory(&vertexBufferDesc, sizeof(vertexBufferDesc));

	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = sizeof(Vertex2D) * ARRAYSIZE(vertexData);
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA vertexBufferData;
	ZeroMemory(&vertexBufferData, sizeof(vertexBufferData));
	vertexBufferData.pSysMem = vertexData;
	vertexBufferData.SysMemPitch = 0;
	vertexBufferData.SysMemSlicePitch = 0;

	hr = m_device->CreateBuffer(
		&vertexBufferDesc,
		&vertexBufferData,
		&m_pVertexBuffer
	);

	///////////////////////Create indices and index data
	UINT indexData[] =
	{
		0, 1, 3,
		3, 1, 2
	};

	m_indexCount = ARRAYSIZE(indexData);

	CD3D11_BUFFER_DESC iDesc(
		sizeof(indexData),
		D3D11_BIND_INDEX_BUFFER
	);

	D3D11_SUBRESOURCE_DATA iData;
	ZeroMemory(&iData, sizeof(D3D11_SUBRESOURCE_DATA));
	iData.pSysMem = indexData;
	iData.SysMemPitch = 0;
	iData.SysMemSlicePitch = 0;

	hr = m_device->CreateBuffer(
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

	hr = m_device->CreateVertexShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &m_pVertexShader);

	D3D11_INPUT_ELEMENT_DESC layout2D[] =
	{
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0  },
		{"TEXCOORD", 0, DXGI_FORMAT::DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_CLASSIFICATION::D3D11_INPUT_PER_VERTEX_DATA, 0  }
	};

	hr = m_device->CreateInputLayout(layout2D,
		(UINT)std::size(layout2D),
		pBlob->GetBufferPointer(),
		pBlob->GetBufferSize(),
		&m_pInputLayout);


	hr = D3DReadFileToBlob(L"PixelShader.cso", &pBlob);
	if (FAILED(hr))
	{
		OutputDebugString("\nFailed to read pixel shader cso file\n\n");
		return hr;
	}

	hr = m_device->CreatePixelShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &m_pPixelShader);


	CD3D11_BUFFER_DESC constantBufferDesc(
		sizeof(CB_vertexshader),
		D3D11_BIND_CONSTANT_BUFFER
	);

	hr = m_device->CreateBuffer(
		&constantBufferDesc,
		nullptr,
		m_pConstantBuffer.GetAddressOf()
	);

	return hr;
}

HRESULT Sprite::CreateTexture(const wchar_t* spritePath)
{
	HRESULT hr = S_OK;

	D3D11_SAMPLER_DESC samplerDesc;
	// Create a texture sampler state description.
	samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.MipLODBias = 0.0f;
	samplerDesc.MaxAnisotropy = 1;
	samplerDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
	//samplerDesc.BorderColor[0] = 0;
	//samplerDesc.BorderColor[1] = 0;
	//samplerDesc.BorderColor[2] = 0;
	//samplerDesc.BorderColor[3] = 0;
	samplerDesc.MinLOD = 0;
	samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;

	hr = m_device->CreateSamplerState(&samplerDesc, &m_samplerState);

	hr = DirectX::CreateWICTextureFromFile(m_device, spritePath, m_texture.GetAddressOf(), m_textureView.ReleaseAndGetAddressOf());

	

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

	m_context->UpdateSubresource(
		m_pConstantBuffer.Get(),
		0,
		nullptr,
		&cb,
		0,
		0
	);

	//Set input layout
	m_context->IASetInputLayout(m_pInputLayout.Get());
	//Set render targets
	m_context->OMSetRenderTargets(1u, &m_pTarget, nullptr);
	//Set primitive topology
	m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	// Set up the IA stage by setting the input topology and layout.
	UINT stride = sizeof(Vertex2D);
	UINT offset = 0;

	m_context->IASetVertexBuffers(
		0,
		1,
		m_pVertexBuffer.GetAddressOf(),
		&stride,
		&offset
	);

	m_context->IASetIndexBuffer(
		m_pIndexBuffer.Get(),
		DXGI_FORMAT_R32_UINT,
		0
	);


	// Set up the vertex shader stage.
	m_context->VSSetShader(
		m_pVertexShader.Get(),
		nullptr,
		0
	);

	m_context->VSSetConstantBuffers(
		0,
		1,
		m_pConstantBuffer.GetAddressOf()
	);



	// Set up the pixel shader stage.
	m_context->PSSetShader(
		m_pPixelShader.Get(),
		nullptr,
		0
	);

	Microsoft::WRL::ComPtr<ID3D11BlendState> blendState;


	m_context->PSSetSamplers(0, 1, m_samplerState.GetAddressOf());
	m_context->PSSetShaderResources(0, 1, m_textureView.GetAddressOf());

	D3D11_RENDER_TARGET_BLEND_DESC rtbd = { 0 };
	rtbd.BlendEnable = true;
	rtbd.SrcBlend = D3D11_BLEND::D3D11_BLEND_SRC_ALPHA;
	rtbd.DestBlend = D3D11_BLEND::D3D11_BLEND_INV_SRC_ALPHA;
	rtbd.BlendOp = D3D11_BLEND_OP::D3D11_BLEND_OP_ADD;
	rtbd.SrcBlendAlpha = D3D11_BLEND::D3D11_BLEND_ONE;
	rtbd.DestBlendAlpha = D3D11_BLEND::D3D11_BLEND_ZERO;
	rtbd.BlendOpAlpha = D3D11_BLEND_OP::D3D11_BLEND_OP_ADD;
	rtbd.RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE::D3D11_COLOR_WRITE_ENABLE_ALL;

	D3D11_BLEND_DESC blendDesc = { 0 };
	blendDesc.RenderTarget[0] = rtbd;


	float blend[4] = { 0.0f, 0.0f, 0.0f,0.0f };
	m_device->CreateBlendState(&blendDesc, blendState.GetAddressOf());
	m_context->OMSetBlendState(blendState.Get(), blend, 0xFFFFFFFF);

	// Send command to graphic device
	m_context->DrawIndexed(
		m_indexCount,
		0,
		0
	);
}
