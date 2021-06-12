#pragma once
#include "SceneEntity.h"

class Checkpoint : public SceneEntity
{
public:
	Checkpoint(Vector2);
	int GetRadius() const override;
	Vector2 GetVelocity() const override;

	bool operator ==(const Checkpoint &other) const
	{
		return GetPosition() == other.GetPosition();
	}
};

