#include "PhysicalGameObject.h"

Rigidbody* PhysicalGameObject::GetRigidbody()
{
	return m_rb;
}

PhysicalGameObject::PhysicalGameObject()
{
	AABB box;
	box.leftBot = { -m_scale.x,-m_scale.y };
	box.rightTop = { m_scale.x,m_scale.y };
	m_rb = new Rigidbody(box);
}

PhysicalGameObject::~PhysicalGameObject()
{
	delete m_rb;
}

void PhysicalGameObject::OnCollision(CollisionData data)
{
	/////
}

void PhysicalGameObject::UpdateAABB()
{
	AABB& aabb = m_rb->m_AABB;
	//float width = aabb.GetWidth();
	//float height = aabb.GetHeight();

	aabb.leftBot = { m_pos.x - m_scale.x / 2.0f, m_pos.y - m_scale.y / 2.0f };
	aabb.rightTop = { m_pos.x + m_scale.x / 2.0f, m_pos.y + m_scale.y / 2.0f };
}
