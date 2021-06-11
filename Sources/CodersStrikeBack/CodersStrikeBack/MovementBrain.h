#pragma once
#include "DataStructure.h"


class MovementBrain
{
private:
    static int s_iMaxThrust;
    static int s_iTurningThrust;
               
    static int s_iDecelerationDist;
    static int s_iAlignementThreshold;
public:

    MovementInstructionData ComputeMovement(const CheckpointData&);

};

