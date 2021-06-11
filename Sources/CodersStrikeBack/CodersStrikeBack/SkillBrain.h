#pragma once
#include "DataStructure.h"

class SkillBrain
{
private:
	bool m_bBoostAvailable = true;
	int m_iBoostDistActivation = 5000;
	int m_iMaximumAngleForBoost = 30;

public:
	bool UseBoost(const CheckpointData&);
};

