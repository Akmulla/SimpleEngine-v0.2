#pragma once
#include "GameObject.h"
#include "Graphics.h"
#include <memory>
#include <WICTextureLoader.h>
#include <string>
#include <SpriteBatch.h>
#include <vector>
#include "Vertex2D.h"
#pragma comment(lib,"DirectXTK.lib")

class Sprite 
{
public:
	Sprite(Graphics&, const wchar_t* spritePath, float width, float height);
	void Draw();
private:
	DirectX::XMMATRIX worldMatrix = DirectX::XMMatrixIdentity();

	Microsoft::WRL::ComPtr<ID3D11Buffer>            m_pVertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11Buffer>            m_pIndexBuffer;
	Microsoft::WRL::ComPtr<ID3D11InputLayout>       m_pInputLayout;
	Microsoft::WRL::ComPtr<ID3D11PixelShader>       m_pPixelShader;
	Microsoft::WRL::ComPtr<ID3D11Buffer>            m_pConstantBuffer;

	ID3D11Device* device;
	ID3D11DeviceContext* context;

	HRESULT CreateGeometry();
};