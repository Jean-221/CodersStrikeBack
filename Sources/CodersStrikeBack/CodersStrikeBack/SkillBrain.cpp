#include "SkillBrain.h"

bool SkillBrain::UseBoost(const CheckpointData &_cChecpointData)
{
    if (m_bBoostAvailable && _cChecpointData.Dist > m_iBoostDistActivation
        && _cChecpointData.Angle < m_iMaximumAngleForBoost)
    {
        m_bBoostAvailable = false;
        return true;
    }

    return false;
}
