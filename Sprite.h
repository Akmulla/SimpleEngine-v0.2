#pragma once
#include "GameObject.h"
#include <memory>
#include <WICTextureLoader.h>
#include <string>
#include <SpriteBatch.h>

class Sprite 
{
public:
	Sprite(Graphics*, const wchar_t* spritePath, float width, float height);
private:
	DirectX::XMMATRIX worldMatrix = DirectX::XMMatrixIdentity();
	std::unique_ptr<DirectX::SpriteBatch> spriteBatch;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> texture;
	ID3D11Device* device;
	ID3D11DeviceContext* context;
};