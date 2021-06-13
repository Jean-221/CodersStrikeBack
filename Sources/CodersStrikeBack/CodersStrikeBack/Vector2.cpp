#include "Vector2.h"
#define _USE_MATH_DEFINES
#include <cmath>

Vector2::Vector2()
{
	y = 0;
	x = 0;

}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2 Vector2::operator-() const
{
	return Vector2(-x, -y);
}

Vector2 Vector2::operator+(const Vector2& _cOther) const
{
	return Vector2(x + _cOther.x, y + _cOther.y);
}

Vector2 Vector2::operator-(const Vector2& _cOther) const
{
	return *this + (-_cOther);
}

bool Vector2::operator==(const Vector2& _cOther) const
{
	return x == _cOther.x && y == _cOther.y;;
}

Vector2 Vector2::operator*(float _fMult) const
{
	return Vector2(x * _fMult, y * _fMult);
}

Vector2 Vector2::operator/(float _fDiv) const
{
	return *this * (1/ _fDiv);
}

Vector2 Vector2::Normalized() const
{
	return Vector2(x, y)/Length();
}

float Vector2::dot(Vector2 _cOther) const
{
	return x * _cOther.x + y * _cOther.y;
}

Vector2 Vector2::rotatedVector(float _fAngleDeg) const
{
	float angleRad = _fAngleDeg * M_PI / 180.f;
	float newX = x * cos(angleRad) - y * sin(angleRad);
	float newY = x * sin(angleRad) + y * cos(angleRad);
	return Vector2(newX, newY);
}

Vector2 Vector2::Floor() const
{
	return Vector2(floor(x), floor(y));
}

Vector2& Vector2::operator=(Vector2 _cOther)
{
	x = _cOther.x;
	y = _cOther.y;

	return *this;
}

float Vector2::Length() const
{
	return sqrt(pow(x, 2) + pow(y, 2));
}
