#pragma once
#include <DirectXMath.h>
#include "IRenderable.h"

class GameObject
{
public:
	virtual void Update(float dt) = 0;

	void SetPosition(const DirectX::XMFLOAT2& pos);
	void SetRotation(const DirectX::XMFLOAT2& rot);
	void SetScale(const DirectX::XMFLOAT2& scale);

	const DirectX::XMFLOAT2& GetPosition() const;
	const DirectX::XMFLOAT2& GetRotation() const;
	const DirectX::XMFLOAT2& GetScale() const;
protected:
	DirectX::XMFLOAT2 pos;
	DirectX::XMFLOAT2 rot;
	DirectX::XMFLOAT2 scale;
};