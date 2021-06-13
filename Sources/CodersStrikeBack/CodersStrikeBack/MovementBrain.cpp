#include "MovementBrain.h"
#include <iostream>

using namespace std;

MovementInstructionData MovementBrain::ComputeMovement(const CheckpointData &_cChecpointData, const Pod& _cPlayer) const
{
    // Compute number of turn needed to atteign checkpoint at our speed (approximated to superior int)
    float nbTurn = ceil(_cChecpointData.Dist / _cPlayer.GetVelocity().Length());

    // Compute our position in this number of turn, base on our velocity
    Vector2 anticipatedPos = _cPlayer.GetPosition() + _cPlayer.GetVelocity()* nbTurn;

    // Pos we will aim to compensate
    Vector2 aimedPos = _cPlayer.GetPosition() + (_cChecpointData.position - anticipatedPos);

    MovementInstructionData data;

    data.targetPos = _cChecpointData.position;
    //data.thrust = _cPlayer.GetVelocity().dot(anticipatedPos - _cPlayer.GetPosition()) < 0 ? s_iTurningThrust : s_iMaxThrust;
    //data.thrust = ((_cChecpointData.Dist < s_iDecelerationDist) || (_cChecpointData.Angle > s_iAlignementThreshold)) ? s_iTurningThrust : s_iMaxThrust;
    data.thrust = s_iMaxThrust;

    // pod take aproximatively 7 turn from full speed to turn around
    if (nbTurn < 7)
    {
        data.thrust = static_cast<int>(max(floor(_cPlayer.GetVelocity().Normalized().dot((data.targetPos - _cPlayer.GetPosition()).Normalized()) * s_iMaxThrust), 40.f));
    }

    return data;
}

int MovementBrain::s_iMaxThrust = 100;
int MovementBrain::s_iTurningThrust = 10;

int MovementBrain::s_iDecelerationDist = 700;
int MovementBrain::s_iAlignementThreshold = 90;
