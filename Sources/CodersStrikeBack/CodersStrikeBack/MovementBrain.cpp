#include "MovementBrain.h"
#include <iostream>

using namespace std;

MovementInstructionData MovementBrain::ComputeMovement(const CheckpointData &_cChecpointData)
{
    MovementInstructionData data;

    data.targetPos = _cChecpointData.position;
    data.thrust = ((_cChecpointData.Dist < s_iDecelerationDist) || (_cChecpointData.Angle > s_iAlignementThreshold)) ? s_iTurningThrust : s_iMaxThrust;

    return data;
}

int MovementBrain::s_iMaxThrust = 100;
int MovementBrain::s_iTurningThrust = 10;

int MovementBrain::s_iDecelerationDist = 90;
int MovementBrain::s_iAlignementThreshold = 90;
