#include "PhysicalGameObject.h"

PhysicalGameObject::PhysicalGameObject(PhysicalParameters parameters)
{
	m_rb = new Rigidbody(parameters);
}

PhysicalGameObject::~PhysicalGameObject()
{
	delete m_rb;
}
