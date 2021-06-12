#pragma once
#include "SceneEntity.h"

class PhysicComputation
{
public:
	bool AreEntityColliding(const SceneEntity &first, const SceneEntity &second);
};

