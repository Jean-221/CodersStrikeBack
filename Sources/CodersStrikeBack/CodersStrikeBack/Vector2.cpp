#include "Vector2.h"
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

Vector2 Vector2::operator+(const Vector2& other) const
{
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const
{
	return *this + (-other);
}

bool Vector2::operator==(const Vector2& other) const
{
	return x == other.x && y == other.y;;
}

Vector2 Vector2::operator*(float mult) const
{
	return Vector2(x * mult, y * mult);
}

Vector2 Vector2::operator/(float div) const
{
	return Vector2(x/div, y/div);
}

Vector2 Vector2::Normalized() const
{
	return Vector2(x, y)/Length();
}

float Vector2::dot(Vector2 other) const
{
	return x * other.x + y * other.y;
}

Vector2& Vector2::operator=(Vector2 other)
{
	x = other.x;
	y = other.y;

	return *this;
}

float Vector2::Length() const
{
	return sqrt(pow(x, 2) + pow(y, 2));
}
