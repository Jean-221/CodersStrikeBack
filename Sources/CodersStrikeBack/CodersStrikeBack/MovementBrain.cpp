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
    data.thrust = ((m_iNextCheckpointDist < 150) || (m_iNextCheckpointAngle > 30)) ? 20 : 100;

    return data;
}
