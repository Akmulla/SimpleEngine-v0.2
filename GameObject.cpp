#include "GameObject.h"


GameObject::GameObject()
{
    m_pos = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
    m_rot = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
    m_scale = DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f);
}

void GameObject::SetPosition(const DirectX::XMFLOAT3& pos)
{
    m_pos = pos;
}

void GameObject::SetRotation(const DirectX::XMFLOAT3& rot)
{
    m_rot = rot;
}

void GameObject::SetScale(const DirectX::XMFLOAT3& scale)
{
    m_scale = scale;
}

void GameObject::Move(const DirectX::XMFLOAT3& movement)
{
    m_pos.x += movement.x;
    m_pos.y += movement.y;
    m_pos.z += movement.z;
}

const DirectX::XMFLOAT3& GameObject::GetPosition() const
{
    return m_pos;
}

const DirectX::XMFLOAT3& GameObject::GetRotation() const
{
    return m_rot;
}

const DirectX::XMFLOAT3& GameObject::GetScale() const
{
    return m_scale;
}

