#pragma once
#include <vector>
#include "DataStructure.h"
#include "MovementBrain.h"
#include "SkillBrain.h"
#include "Pod.h"
#include "Checkpoint.h"

using namespace std;


/// <summary>
/// Handle component that'll decide movement and use of skill of pods and translate instruction for codingame
/// </summary>
class Brain
{
protected:
    static const int s_iNumberOfPlayerPods;
    static const int s_iNumberOfEnnemyPods;

    CheckpointData m_cNextCheckpoint; // position of the next check point
    MovementInstructionData m_cMovementData;

    MovementBrain m_cMovementBrain;
    SkillBrain m_cSkill;

    vector<Pod> m_vPlayer;
    vector<Pod> m_vEnnemy;

    vector<Checkpoint> m_vCheckpoints;
    bool m_bFirstLapDone = false;

    // Circuit data
    int m_iNbLaps = 0;
    int m_iCheckpointCount = 0;


    /// <summary>
    /// Compute command for the pod
    /// </summary>
    /// <param name="">index of the player pod to compute</param>
    /// <returns>Movement data for the pod</returns>
    MovementInstructionData ComputePodCommand(int);

public:
    Brain();

    /// <summary>
    /// Acquire Lap information( checkpoint, number of laps, etc)
    /// </summary>
    void AcquireLapInformation();

    /// <summary>
    /// Acquire input from codingame
    /// </summary>
    void AcquireBoardState();

    /// <summary>
    /// call the compute of command and print them
    /// </summary>
    void ComputeAndPrintInstruction();
};

