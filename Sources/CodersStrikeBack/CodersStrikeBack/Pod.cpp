#include "Pod.h"


void Pod::UpdatePosition(Vector2 _cNewPosition)
{
	m_cPreviousPosition = m_cPosition;
	m_cPosition = _cNewPosition;

	// Will be incoherent at the first turn
	m_cPreviousVelocity = m_cVelocity;
	m_cVelocity = m_cPosition - m_cPreviousPosition;
	
	m_cDeltaVelocity = m_cVelocity - m_cPreviousVelocity;
}

int Pod::GetRadius() const
{
	return 400;
}

Vector2 Pod::GetVelocity() const
{
	return m_cVelocity;
}

Vector2 Pod::GetDeltaVelocity() const
{
	return m_cDeltaVelocity;
}
