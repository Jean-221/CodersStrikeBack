#include "Brain.h"
#include <iostream>
#include <string>

using namespace std;

void Brain::AcquireBoardState()
{
	cin >> m_cPodPosition.x >> m_cPodPosition.y >> m_cNextCheckpoint.position.x >> m_cNextCheckpoint.position.y 
		>> m_cNextCheckpoint.Dist >> m_cNextCheckpoint.Angle; cin.ignore();

	cin >> m_cOpponentPos.x >> m_cOpponentPos.y; cin.ignore();
}

void Brain::ComputePodCommand()
{
	MovementBrain movementBrain;
	m_cMovementData = movementBrain.ComputeMovement(m_cNextCheckpoint);
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
