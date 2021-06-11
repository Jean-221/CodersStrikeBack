#pragma once
#include "Vector2.h"

struct InstructionData
{
    Vector2 targetPos;
    int thrust = 0;
};

class MovementBrain
{
private:
    Vector2 m_cPodPosition;
    Vector2 m_cNextCheckpoint; // position of the next check point

    int m_iNextCheckpointDist; // distance to the next checkpoint
    int m_iNextCheckpointAngle; // angle between your pod orientation and the direction of the next checkpoint

    Vector2 opponent;

public:
    void AcquireBoardState();

    InstructionData GetPodCommand();
};

