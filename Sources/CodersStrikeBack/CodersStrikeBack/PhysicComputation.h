#pragma once
#include "SceneEntity.h"

/// <summary>
/// Compute and anticipate collisions
/// </summary>
class PhysicComputation
{
public:
	bool AreEntityColliding(const SceneEntity &first, const SceneEntity &second);
};

