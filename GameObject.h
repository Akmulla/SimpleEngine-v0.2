#pragma once
#include <DirectXMath.h>
#include "IRenderable.h"

class GameObject
{
public:
	virtual void Update(float dt) = 0;

	void SetPosition(const DirectX::XMFLOAT3& pos);
	void SetRotation(const DirectX::XMFLOAT3& rot);
	void SetScale(const DirectX::XMFLOAT3& scale);

	const DirectX::XMFLOAT3& GetPosition() const;
	const DirectX::XMFLOAT3& GetRotation() const;
	const DirectX::XMFLOAT3& GetScale() const;
private:
	DirectX::XMFLOAT3 m_pos;
	DirectX::XMFLOAT3 m_rot;
	DirectX::XMFLOAT3 m_scale;
};