#pragma once
#include "SceneEntity.h"
#include <vector>
#include "Checkpoint.h"
#include"DataStructure.h"

using namespace std;

/// <summary>
/// Represent pod and store his data
/// </summary>
class Pod : public SceneEntity
{
protected:
	/// <summary>
	/// Used to compute Velocity
	/// </summary>
	Vector2 m_cPreviousPosition;	
	
	/// <summary>
	/// Forward direction of the pod
	/// </summary>
	Vector2 m_cForward;				

	Vector2 m_cVelocity;
	/// <summary>
	/// Used to compute acceleration vector (m_cDeltaVelocity)
	/// </summary>
	Vector2 m_cPreviousVelocity;

	/// <summary>
	/// acceleration vector
	/// </summary>
	Vector2 m_cDeltaVelocity;

	int m_iNextCheckpointIndex = 0;

public:
	void UpdatePositionAndForward(Vector2, Vector2, int, int);
	int GetRadius() const override;
	/// <summary>
	/// Velocity computed with last position
	/// </summary>
	/// <returns></returns>
	Vector2 GetVelocity() const override;
	/// <summary>
	/// acceleration vector computed with last velocities
	/// </summary>
	/// <returns></returns>
	Vector2 GetDeltaVelocity() const;
	/// <summary>
	/// Forward direction of the pod
	/// </summary>
	/// <returns></returns>
	Vector2 GetForward() const;

	int GetNextCheckpointID() const;
};

