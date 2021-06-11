#pragma once
struct Vector2
{
	int x, y;

	Vector2();


	Vector2(int x, int y);

	Vector2 operator - () const;

	Vector2 operator + (const Vector2& other);

	Vector2 operator - (const Vector2& other);

	float Length();

};

