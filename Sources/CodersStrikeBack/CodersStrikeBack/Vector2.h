#pragma once

/// <summary>
/// Vector2 of float
/// </summary>
struct Vector2
{
	float x, y;

	Vector2();


	Vector2(float x, float y);

	Vector2& operator = (Vector2);

	Vector2 operator - () const;

	Vector2 operator + (const Vector2&) const;

	Vector2 operator - (const Vector2&) const;

	bool operator == (const Vector2&) const;

	Vector2 operator *(float) const;

	Vector2 operator /(float) const;

	Vector2 Normalized() const;

	float dot(Vector2) const;

	/// <summary>
	/// return a vector rotated by the angle given
	/// </summary>
	/// <param name="_angleDeg">angle for rotation</param>
	/// <returns>new rotated vector</returns>
	Vector2 rotatedVector(float _angleDeg) const;

	/// <summary>
	/// floor the 2 coordinate to have integer for the display in codingame
	/// </summary>
	/// <returns>new vector with both coordinate floored</returns>
	Vector2 Floor() const;
	

	/// <summary>
	/// return int approximation to simplify calculation since every game variable are int
	/// </summary>
	/// <returns></returns>
	float Length() const;

};

