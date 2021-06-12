#pragma once
#include <vector>
#include "DataStructure.h"
#include "MovementBrain.h"
#include "SkillBrain.h"
#include "Pod.h"
#include "Checkpoint.h"

class Brain
{
protected:

    CheckpointData m_cNextCheckpoint; // position of the next check point
    MovementInstructionData m_cMovementData;

    SkillBrain m_cSkill;

    Pod m_cPlayer;
    Pod m_cEnnemy;

    std::vector<Checkpoint> m_vCheckpoints;
    bool m_bFirstLapDone = false;


public:
    void AcquireBoardState();

    void ComputePodCommand();

    void ComputeAndPrintInstruction();
};

