#include "PhysicComputation.h"

int PhysicComputation::AreEntityInCollidingPath(const SceneEntity& _cFirst, const SceneEntity& _cSecond, int _iNbTurn)
{
    while (_iNbTurn >= 0)
    {
        float distBetweenEntity = ((_cSecond.GetPosition() + _cSecond.GetVelocity() * _iNbTurn) - (_cFirst.GetPosition() + _cFirst.GetVelocity() * _iNbTurn)).Length();
        float collisionDistance = _cFirst.GetRadius() + _cSecond.GetRadius();

        if (distBetweenEntity < collisionDistance)
            return _iNbTurn;

        _iNbTurn--;
    }

    return 0;
}
