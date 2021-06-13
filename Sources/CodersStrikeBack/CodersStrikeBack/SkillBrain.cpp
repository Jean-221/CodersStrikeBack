#include "SkillBrain.h"
#include <cmath>

bool SkillBrain::UseBoost(const CheckpointData &_cChecpointData)
{
    if (m_bBoostAvailable && _cChecpointData.Dist > m_iBoostDistActivation
        && abs(_cChecpointData.Angle) < m_iMaximumAngleForBoost)
    {
        m_bBoostAvailable = false;
        return true;
    }

    return false;
}
