#include "PhysicalGameObject.h"

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
