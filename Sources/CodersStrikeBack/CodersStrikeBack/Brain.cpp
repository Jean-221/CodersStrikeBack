#include "Brain.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


Brain::Brain()
{
	m_vPlayer.resize(s_iNumberOfPlayerPods);
	m_vEnnemy.resize(s_iNumberOfEnnemyPods);
}

void Brain::AcquireLapInformation()
{
	cin >> m_iNbLaps; cin.ignore();
	cin >> m_iCheckpointCount; cin.ignore();

	for (int i = 0; i < m_iCheckpointCount; i++)
	{
		Vector2 checkpointPos;
		cin >> checkpointPos.x >> checkpointPos.y; cin.ignore();

		// Should not be called after first turn, need some cleaning
		if (m_vCheckpoints.size() < m_iCheckpointCount)
			m_vCheckpoints.push_back(Checkpoint(checkpointPos));
	}
}

void Brain::AcquireBoardState()
{
	// store pod position before instantiation
	Vector2 podPos, podVelocity;
	int podAngle, nextCheckpointId;


	for (int i = 0; i < s_iNumberOfPlayerPods; i++)
	{
		// capture input from codingame for the player pod and the next checkpoint
		cin >> podPos.x >> podPos.y >> podVelocity.x >> podVelocity.y
			>> podAngle >> nextCheckpointId; cin.ignore();

		// update player data
		m_vPlayer[i].UpdatePositionAndForward(podPos, podVelocity, podAngle, nextCheckpointId);
	}



	for (int i = 0; i < s_iNumberOfEnnemyPods; i++)
	{
		// capture input from codingame for the ennemy pod
		cin >> podPos.x >> podPos.y >> podVelocity.x >> podVelocity.y
			>> podAngle >> nextCheckpointId; cin.ignore();

		// update ennemy data
		m_vEnnemy[i].UpdatePositionAndForward(podPos, podVelocity, podAngle, nextCheckpointId);
	}
}

MovementInstructionData Brain::ComputePodCommand(int _iIndex)
{
	return m_cMovementBrain.ComputeMovement(m_vCheckpoints, m_vPlayer[_iIndex]);
}


void Brain::ComputeAndPrintInstruction()
{
	string thrust;
	MovementInstructionData MoveInst;

	for (int i = 0; i < s_iNumberOfPlayerPods; i++)
	{
		MoveInst = ComputePodCommand(i);

		// Fill thrust string with skill usage or thrust value
		if (m_cSkill.UseBoost(m_vPlayer[i], m_vCheckpoints))
			thrust = "BOOST";
		else if (m_cSkill.UseShield(m_vPlayer[i], m_vEnnemy))
			thrust = "Shield";
		else
			thrust = to_string(MoveInst.thrust);

		cout << MoveInst.targetPos.x << " " << MoveInst.targetPos.y << " " << thrust << endl;
	}
}

const int Brain::s_iNumberOfPlayerPods = 2;
const int Brain::s_iNumberOfEnnemyPods = 2;
