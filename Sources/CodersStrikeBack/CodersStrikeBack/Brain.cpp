#include "Brain.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void Brain::AcquireBoardState()
{
	Vector2 podPos;

	cin >> podPos.x >> podPos.y >> m_cNextCheckpoint.position.x >> m_cNextCheckpoint.position.y
		>> m_cNextCheckpoint.Dist >> m_cNextCheckpoint.Angle; cin.ignore();

	m_cPlayer.UpdatePosition(podPos);

	Checkpoint c(m_cNextCheckpoint.position);

	if (!m_bFirstLapDone && find(m_vCheckpoints.begin(), m_vCheckpoints.end(), c) == m_vCheckpoints.end())
		m_vCheckpoints.push_back(c);
	else if (c == *m_vCheckpoints.begin() && m_vCheckpoints.size() >= 2)  // if the next checkpoint is the first, and we have already passed 2nd checkpoint
		m_bFirstLapDone = true;											  // we have completed first lap

	cin >> podPos.x >> podPos.y; cin.ignore();

	m_cEnnemy.UpdatePosition(podPos);
}

void Brain::ComputePodCommand()
{
	MovementBrain movementBrain;
	m_cMovementData = movementBrain.ComputeMovement(m_cNextCheckpoint, m_cPlayer);
}

void Brain::ComputeAndPrintInstruction()
{
	string thrust;

	ComputePodCommand();


	if (m_cSkill.UseBoost(m_cNextCheckpoint))
		thrust = "BOOST";
	else
		thrust = to_string(m_cMovementData.thrust);

	cout << m_cMovementData.targetPos.x << " " << m_cMovementData.targetPos.y << " " << thrust << endl;
}
