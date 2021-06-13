#pragma once
struct Vector2
{
	float x, y;

	Vector2();


	Vector2(float x, float y);

	Vector2& operator = (Vector2 other);

	Vector2 operator - () const;

	Vector2 operator + (const Vector2& other) const;

	Vector2 operator - (const Vector2& other) const;

	bool operator == (const Vector2& other) const;

	Vector2 operator *(float) const;

	Vector2 operator /(float) const;

	Vector2 Normalized() const;

	float dot(Vector2 other) const;

	/// <summary>
	/// return int approximation to simplify calculation since every game variable are int
	/// </summary>
	/// <returns></returns>
	float Length() const;

};

