#pragma once
#include "DataStructure.h"

class SkillBrain
{
private:
	bool m_bBoostAvailable = true;
	int m_iBoostDistActivation = 5000;

public:
	bool UseBoost(const CheckpointData&);
};

