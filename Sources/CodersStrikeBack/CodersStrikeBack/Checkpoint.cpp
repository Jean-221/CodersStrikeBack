#include "Checkpoint.h"

Checkpoint::Checkpoint(Vector2 _cPosition)
{
    m_cPosition = _cPosition;
}

int Checkpoint::GetRadius() const
{
    return 600;
}

Vector2 Checkpoint::GetVelocity() const
{
    return { 0, 0 };
}
