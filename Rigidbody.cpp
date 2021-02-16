#include "Rigidbody.h"

//Rigidbody::Rigidbody(float mass, AABB box) : m_mass(mass), m_velocity({0.0f,0.0f}), m_AABB(box)
//{
//
//}

Rigidbody::Rigidbody()
{
	m_mass = 1;
	//m_AABB = new AABB({ -1, -1 }, { 1, 1 });
	m_velocity = { 0,0 };
}

Rigidbody::Rigidbody(AABB box)
{
	m_mass = 1;
	//m_AABB = new AABB({ -1, -1 }, { 1, 1 });
	m_velocity = { 0,0 };
	m_AABB = box;
}

Rigidbody::~Rigidbody()
{
	//delete m_AABB;
}
