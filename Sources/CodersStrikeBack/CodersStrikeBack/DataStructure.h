#pragma once
#include "Vector2.h"


struct MovementInstructionData
{
    Vector2 targetPos;
    int thrust = 0;
};


struct CheckpointData
{
    Vector2 position; // position of the next check point

    int Dist; // distance to the next checkpoint
    int Angle; // angle between your pod orientation and the direction of the next checkpoint
};