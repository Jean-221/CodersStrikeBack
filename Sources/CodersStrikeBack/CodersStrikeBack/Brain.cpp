#include "Brain.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void Brain::AcquireBoardState()
{
	// store pod position before instantiation
	Vector2 podPos;

	// capture input from codingame for the player pod and the next checkpoint
	cin >> podPos.x >> podPos.y >> m_cNextCheckpoint.position.x >> m_cNextCheckpoint.position.y
		>> m_cNextCheckpoint.Dist >> m_cNextCheckpoint.Angle; cin.ignore();

	// update player data
	m_cPlayer.UpdatePositionAndForward(podPos, m_cNextCheckpoint);

	Checkpoint c(m_cNextCheckpoint.position);

	// create checkpoints and store them (will become obsolete in gold)
	if (!m_bFirstLapDone && find(m_vCheckpoints.begin(), m_vCheckpoints.end(), c) == m_vCheckpoints.end())
		m_vCheckpoints.push_back(c);
	else if (c == *m_vCheckpoints.begin() && m_vCheckpoints.size() >= 2)  // if the next checkpoint is the first, and we have already passed 2nd checkpoint
		m_bFirstLapDone = true;											  // we have completed first lap

	// capture input from codingame for the ennemy pod
	cin >> podPos.x >> podPos.y; cin.ignore();

	// update ennemy data
	m_cEnnemy.UpdatePositionAndForward(podPos, m_cNextCheckpoint);
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

	// Fill thrust string with skill usage or thrust value
	if (m_cSkill.UseBoost(m_cNextCheckpoint))
		thrust = "BOOST";
	else
		thrust = to_string(m_cMovementData.thrust);

	cout << m_cMovementData.targetPos.x << " " << m_cMovementData.targetPos.y << " " << thrust << endl;
}
