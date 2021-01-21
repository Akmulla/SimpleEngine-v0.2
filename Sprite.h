#pragma once
#include "GameObject.h"
#include <memory>
#include <WICTextureLoader.h>
#include <string>
#include <SpriteBatch.h>

class Sprite 
{
public:
	Sprite(Graphics*, std::string spritePath, float width, float height);
private:
	DirectX::XMMATRIX worldMatrix = DirectX::XMMatrixIdentity();
	std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;
	ID3D11Device* device;
	ID3D11DeviceContext* context;
};