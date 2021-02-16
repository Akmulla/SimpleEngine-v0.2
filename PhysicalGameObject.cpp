#include "PhysicalGameObject.h"

PhysicalGameObject::PhysicalGameObject()
{
	m_rb = new Rigidbody();
}

PhysicalGameObject::~PhysicalGameObject()
{
	delete m_rb;
}
