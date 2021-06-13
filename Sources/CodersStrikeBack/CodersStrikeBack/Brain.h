#pragma once
#include <vector>
#include "DataStructure.h"
#include "MovementBrain.h"
#include "SkillBrain.h"
#include "Pod.h"
#include "Checkpoint.h"


/// <summary>
/// Handle component that'll decide movement and use of skill of pods and translate instruction for codingame
/// </summary>
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


    /// <summary>
    /// Compute command for the pod
    /// </summary>
    void ComputePodCommand();

public:
    /// <summary>
    /// Acquire input from codingame
    /// </summary>
    void AcquireBoardState();

    /// <summary>
    /// call the compute of command and print them
    /// </summary>
    void ComputeAndPrintInstruction();
};

