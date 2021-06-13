#include "Pod.h"


void Pod::UpdatePositionAndForward(Vector2 _cNewPosition, Vector2 _cNewVelocity, int _iAngleFromEast, int _iNextCheckPointId)
{
	m_cPreviousPosition = m_cPosition;
	m_cPosition = _cNewPosition;

	// Compute forward from angle from east
	m_cForward = Vector2(1, 0).rotatedVector(_iAngleFromEast);

	m_iNextCheckpointIndex = _iNextCheckPointId;

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

Vector2 Pod::GetForward() const
{
	return m_cForward;
}

int Pod::GetNextCheckpointID() const
{
	return m_iNextCheckpointIndex;
}
