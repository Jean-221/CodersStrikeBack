#include "MovementBrain.h"
#include <iostream>

using namespace std;

MovementInstructionData MovementBrain::ComputeMovement(const CheckpointData &_cChecpointData, const Pod& _cPlayer) const
{
    // Compute number of turn needed to atteign checkpoint at our speed (approximated to superior int)
    // TODO : Move to PhysicComputation
    float nbTurn = ceil(_cChecpointData.Dist / _cPlayer.GetVelocity().Length());

    // Compute our position in this number of turn, base on our velocity
    Vector2 anticipatedPos = _cPlayer.GetPosition() + _cPlayer.GetVelocity()* nbTurn;

    // Pos we will aim to compensate, devided by nbr of turn before reaching target (the closer we are the more we want to compensate)
    Vector2 aimedPos = _cChecpointData.position + (_cChecpointData.position - anticipatedPos) / nbTurn;

    // data structure to return to brain which will give instruction
    MovementInstructionData data;

    // floor to prevent floating point value
    data.targetPos = aimedPos.Floor();

    // thrust depend on our alignement with target (dot will decrease if we steer away) if dot is negative we take the default tunrningthrust
    // because we need to turn around
    data.thrust = static_cast<int>(floor(max(_cPlayer.GetForward().dot((aimedPos - _cPlayer.GetPosition()).Normalized()) * s_iMaxThrust, s_iTurningThrust)));


    return data;
}

float MovementBrain::s_iMaxThrust = 100;
float MovementBrain::s_iTurningThrust = 10;
