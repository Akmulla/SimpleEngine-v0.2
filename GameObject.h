#pragma once
#include <DirectXMath.h>

class GameObject
{
public:
	GameObject();

	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;

	void SetPosition(const DirectX::XMFLOAT3& pos);
	void SetRotation(const DirectX::XMFLOAT3& rot);
	void SetScale(const DirectX::XMFLOAT3& scale);

	void Move(const DirectX::XMFLOAT3& movement);

	const DirectX::XMFLOAT3& GetPosition() const;
	const DirectX::XMFLOAT3& GetRotation() const;
	const DirectX::XMFLOAT3& GetScale() const;
protected:
	DirectX::XMFLOAT3 m_pos;
	DirectX::XMFLOAT3 m_rot;
	DirectX::XMFLOAT3 m_scale;
};