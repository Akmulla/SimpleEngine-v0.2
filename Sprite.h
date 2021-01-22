#pragma once
#include "GameObject.h"
#include <memory>
#include <WICTextureLoader.h>
#include <string>
#include <SpriteBatch.h>
#pragma comment(lib,"DirectXTK.lib")

class Sprite 
{
public:
	Sprite(Graphics&, const wchar_t* spritePath, float width, float height);
	void Draw(DirectX::XMFLOAT2);
private:
	DirectX::XMMATRIX worldMatrix = DirectX::XMMatrixIdentity();
	std::unique_ptr<DirectX::SpriteBatch> spriteBatch;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> shaderResource;
	ID3D11Device* device;
	ID3D11DeviceContext* context;
};