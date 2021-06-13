#pragma once
#include "DataStructure.h"

/// <summary>
/// Brain component to compute when to use skills
/// </summary>
class SkillBrain
{
protected:
	bool m_bBoostAvailable = true;
	int m_iBoostDistActivation = 6200;
	int m_iMaximumAngleForBoost = 10;

public:
	bool UseBoost(const CheckpointData&);
};

