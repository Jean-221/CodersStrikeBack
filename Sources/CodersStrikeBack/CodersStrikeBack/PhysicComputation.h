#pragma once
#include "SceneEntity.h"

/// <summary>
/// Compute and anticipate collisions
/// </summary>
class PhysicComputation
{
public:
	/// <summary>
	/// Compute if the two entyti will colide (if they keep trajectory & speed)
	/// </summary>
	/// <param name="">first entity</param>
	/// <param name="">second entity</param>
	/// <param name="">number of turn to check, must be positive, or null to check current overlapping</param>
	/// <returns>number of turn before collision</returns>
	int AreEntityInCollidingPath(const SceneEntity&, const SceneEntity&, unsigned int);
};

