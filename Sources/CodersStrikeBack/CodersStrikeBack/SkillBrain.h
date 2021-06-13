#pragma once
#include "DataStructure.h"
#include "Pod.h"

/// <summary>
/// Brain component to compute when to use skills
/// </summary>
class SkillBrain
{
protected:
	bool m_bBoostAvailable = true;
	int m_iBoostDistActivation = 6200;
	int m_iMaximumAngleForBoost = 5;

public:
	bool UseBoost(Pod&, const vector<Checkpoint>&);
	bool UseShield(Pod&, const vector<Pod>&);
};

