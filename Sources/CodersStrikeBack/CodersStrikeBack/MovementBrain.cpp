#include "MovementBrain.h"
#include <iostream>

using namespace std;

MovementInstructionData MovementBrain::ComputeMovement(const vector<Checkpoint> &_vChecpointData, const Pod& _cPlayer) const
{
    int checkpointId = _cPlayer.GetNextCheckpointID();
    // Compute number of turn needed to atteign checkpoint at our speed (approximated to superior int)
    // TODO : Move to PhysicComputation
    float nbTurn = ceil((_vChecpointData[checkpointId].GetPosition() - _cPlayer.GetPosition()).Length() / _cPlayer.GetVelocity().Length());

    // Compute our position in this number of turn, based on our velocity
    Vector2 anticipatedPos = _cPlayer.GetPosition() + _cPlayer.GetVelocity()* nbTurn * 0.85f;

    // Pos we will aim to compensate, devided by nbr of turn before reaching target (the closer we are the more we want to compensate)
    Vector2 aimedPos = _vChecpointData[checkpointId].GetPosition() + (_vChecpointData[checkpointId].GetPosition() - anticipatedPos) / nbTurn;

    // data structure to return to brain which will give instruction
    MovementInstructionData data;

    // floor to prevent floating point value
    data.targetPos = aimedPos.Floor();

    // thrust depend on our alignement with target (dot will decrease if we steer away) if dot is negative we take the default tunrningthrust
    // because we need to turn around
    data.thrust = static_cast<int>(floor(max(_cPlayer.GetForward().dot((aimedPos - _cPlayer.GetPosition()).Normalized()) * s_iMaxThrust, s_iTurningThrust)));

    // Last minute test, stop thrust and start turning when we're almost certain to pass the checkpoint
    if (nbTurn < 4 && (_cPlayer.GetVelocity().Length() > 400)
        && (_vChecpointData[checkpointId].GetPosition() - anticipatedPos).Length() < 600)
    {
        data.targetPos = _vChecpointData[(_cPlayer.GetNextCheckpointID() + 1) % _vChecpointData.size()].GetPosition();
        data.thrust = 0;
    }

    return data;
}

float MovementBrain::s_iMaxThrust = 100;
float MovementBrain::s_iTurningThrust = 10;
