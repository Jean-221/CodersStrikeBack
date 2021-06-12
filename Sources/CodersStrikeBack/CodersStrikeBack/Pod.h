#pragma once
#include "SceneEntity.h"

class Pod : public SceneEntity
{
protected:
	Vector2 m_cPreviousPosition;	// Used to compute Velocity

	Vector2 m_cVelocity;
	Vector2 m_cPreviousVelocity;	// Used to compute acceleration vector (m_cDeltaVelocity)

	Vector2 m_cDeltaVelocity;		// acceleration vector

public:
	void UpdatePosition(Vector2);
	int GetRadius() const override;
	Vector2 GetVelocity() const override;
	Vector2 GetDeltaVelocity() const;
};

