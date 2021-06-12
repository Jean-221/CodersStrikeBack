#include "PhysicComputation.h"

bool PhysicComputation::AreEntityColliding(const SceneEntity& first, const SceneEntity& second)
{
    return (second.GetPosition() - first.GetPosition()).Length() < (first.GetRadius() + second.GetRadius());
}
