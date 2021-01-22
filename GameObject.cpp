#include "GameObject.h"


//void GameObject::Update(float dt)
//{
//}

void GameObject::SetPosition(const DirectX::XMFLOAT2& pos)
{
    this->pos = pos;
}

void GameObject::SetRotation(const DirectX::XMFLOAT2& rot)
{
    this->rot = rot;
}

void GameObject::SetScale(const DirectX::XMFLOAT2& scale)
{
    this->scale = scale;
}

const DirectX::XMFLOAT2& GameObject::GetPosition() const
{
    return pos;
}

const DirectX::XMFLOAT2& GameObject::GetRotation() const
{
    return rot;
}

const DirectX::XMFLOAT2& GameObject::GetScale() const
{
    return scale;
}

