#include "GameObject.h"


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

