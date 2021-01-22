#include "GameObject.h"


//void GameObject::Update(float dt)
//{
//}

void GameObject::SetPosition(const DirectX::XMFLOAT3& pos)
{
    this->pos = pos;
}

void GameObject::SetRotation(const DirectX::XMFLOAT3& rot)
{
    this->rot = rot;
}

void GameObject::SetScale(const DirectX::XMFLOAT3& scale)
{
    this->scale = scale;
}

const DirectX::XMFLOAT3& GameObject::GetPosition() const
{
    return pos;
}

const DirectX::XMFLOAT3& GameObject::GetRotation() const
{
    return rot;
}

const DirectX::XMFLOAT3& GameObject::GetScale() const
{
    return scale;
}

