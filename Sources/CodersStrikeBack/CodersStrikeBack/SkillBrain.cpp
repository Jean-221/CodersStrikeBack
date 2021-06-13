#include "SkillBrain.h"
#include <cmath>
#include "PhysicComputation.h"

bool SkillBrain::UseBoost(Pod &_cPlayer, const vector<Checkpoint> &_vCheckpoints)
{
    Vector2 playerToCheckpoint = _vCheckpoints[_cPlayer.GetNextCheckpointID()].GetPosition() - _cPlayer.GetPosition();
    int dist = (playerToCheckpoint).Length();
    float dot = playerToCheckpoint.Normalized().dot(_cPlayer.GetForward());


    if (_cPlayer.HasBoost() && dist > m_iBoostDistActivation
        && abs(acos(dot)) < m_iMaximumAngleForBoost)
    {
        _cPlayer.UseBoost();
        return true;
    }

    return false;
}

bool SkillBrain::UseShield(Pod &_cPlayer, const vector<Pod> &_vEnnemies)
{
    PhysicComputation physic;

    for (int i = 0; i < _vEnnemies.size(); i++)
    {
        // TODO add more conditions to prevent pushing ennemy in the right direction
        if (physic.AreEntityInCollidingPath(_cPlayer, _vEnnemies[i], 1))
            return true;
    }

    return false;
}
