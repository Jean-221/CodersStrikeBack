#include "MovementBrain.h"
#include <iostream>

using namespace std;

void MovementBrain::AcquireBoardState()
{
    cin >> m_cPodPosition.x >> m_cPodPosition.y >> m_cNextCheckpoint.x >> m_cNextCheckpoint.y >> m_iNextCheckpointDist >> m_iNextCheckpointAngle; cin.ignore();

    cin >> opponent.x >> opponent.y; cin.ignore();
}

InstructionData MovementBrain::GetPodCommand()
{
    InstructionData data;

    data.targetPos = m_cNextCheckpoint;
    data.thrust;

    return InstructionData();
}
