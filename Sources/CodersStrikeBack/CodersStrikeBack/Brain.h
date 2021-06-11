#pragma once
#include "DataStructure.h"
#include "MovementBrain.h"
#include "SkillBrain.h"

class Brain
{
private:
    Vector2 m_cPodPosition;
    Vector2 m_cOpponentPos;

    CheckpointData m_cNextCheckpoint; // position of the next check point
    MovementInstructionData m_cMovementData;

    SkillBrain m_cSkill;

public:
    void AcquireBoardState();

    void ComputePodCommand();

    void ComputeAndPrintInstruction();
};

