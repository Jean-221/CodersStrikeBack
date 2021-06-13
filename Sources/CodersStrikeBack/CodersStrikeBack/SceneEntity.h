#pragma once
#include "Vector2.h"

/// <summary>
/// Represent different board entity (checkpoint and pods)
/// </summary>
class SceneEntity abstract
{
protected:
	Vector2 m_cPosition;

public:
	virtual int GetRadius() const = 0;
	virtual Vector2 GetVelocity() const = 0;
	inline Vector2 GetPosition() const { return m_cPosition; }
};

