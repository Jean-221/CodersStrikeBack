#include "Vector2.h"

Vector2::Vector2()
{
	y = 0;
	x = 0;

}

Vector2::Vector2(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector2 Vector2::operator-() const
{
	return { -x, -y };
}

Vector2 Vector2::operator+(const Vector2& other)
{
	return { x + other.x, y + other.y };
}

Vector2 Vector2::operator-(const Vector2& other)
{
	return *this + (-other);
}

float Vector2::Length()
{
	return 0.0f;
}
