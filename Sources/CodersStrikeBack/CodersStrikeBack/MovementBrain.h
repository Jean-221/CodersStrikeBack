#pragma once
#include "DataStructure.h"
#include "Pod.h"


/// <summary>
/// Compute steering and thrust of the pod
/// </summary>
class MovementBrain
{
protected:
    static float s_iMaxThrust;
    static float s_iTurningThrust;
public:
    /// <summary>
    /// Compute instruction for the pod steering
    /// </summary>
    /// <param name=""></param>
    /// <param name="_cPlayer"></param>
    /// <returns></returns>
    MovementInstructionData ComputeMovement(const CheckpointData&, const Pod &_cPlayer) const;

};

