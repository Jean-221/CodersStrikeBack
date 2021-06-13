#include "Pod.h"


void Pod::UpdatePositionAndForward(Vector2 _cNewPosition, CheckpointData _cNextCheckpoint)
{
	m_cPreviousPosition = m_cPosition;
	m_cPosition = _cNewPosition;

	// get vector from pod to checkpoint and normalize it
	m_cForward = (_cNextCheckpoint.position - m_cPosition).Normalized();
	// Rotate vector to the orientation of the pod relative to the checkpoint
	m_cForward = m_cForward.rotatedVector(_cNextCheckpoint.Angle);

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
