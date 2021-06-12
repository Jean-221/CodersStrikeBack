#pragma once
#include "DataStructure.h"
#include "Pod.h"


class MovementBrain
{
protected:
    static int s_iMaxThrust;
    static int s_iTurningThrust;
               
    static int s_iDecelerationDist;
    static int s_iAlignementThreshold;
public:

    MovementInstructionData ComputeMovement(const CheckpointData&, const Pod &_cPlayer) const;

};

