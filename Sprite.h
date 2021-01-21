#pragma once
#include "GameObject.h"
#include <memory>
#include <WICTextureLoader.h>
#include <string>

class Sprite 
{
public:
	Sprite(Graphics*, std::string spritePath, float width, float height);
private:
	DirectX::XMMATRIX worldMatrix = DirectX::XMMatrixIdentity();

	//std::unique_ptr<Texture> texture;
	ID3D11DeviceContext* deviceContext = nullptr;

	//IndexBuffer indices;
	//VertexBuffer<Vertex2D> vertices;
};