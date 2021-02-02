#pragma once
#include <memory>
#include <WICTextureLoader.h>
#include <string>
#include <SpriteBatch.h>
#include <vector>

#include "GameObject.h"
#include "Graphics.h"
#include "Vertex2D.h"
#include "ConstantBuffers.h"

#pragma comment(lib,"DirectXTK.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib,"D3DCompiler.lib")

class Sprite 
{
public:
	Sprite(Graphics&, const wchar_t* spritePath, float width, float height);
	void Draw(DirectX::XMMATRIX worldMatrix, DirectX::XMMATRIX ortoMatrix);
private:
	Microsoft::WRL::ComPtr<ID3D11Buffer>            m_pVertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11Buffer>            m_pIndexBuffer;
	
	Microsoft::WRL::ComPtr<ID3D11VertexShader>      m_pVertexShader;
	Microsoft::WRL::ComPtr<ID3D11PixelShader>       m_pPixelShader;

	Microsoft::WRL::ComPtr<ID3D11InputLayout>       m_pInputLayout;
	Microsoft::WRL::ComPtr<ID3D11Buffer>            m_pConstantBuffer;

	Microsoft::WRL::ComPtr<ID3D11Resource> m_texture;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_textureView;
	Microsoft::WRL::ComPtr<ID3D11SamplerState> m_samplerState;

	ID3D11Device* m_device;
	ID3D11DeviceContext* m_context;
	ID3D11RenderTargetView* m_pTarget;

	HRESULT CreateGeometry();
	HRESULT CreateShaders();
	HRESULT CreateTexture(const wchar_t* spritePath);

	unsigned int  m_indexCount;
};