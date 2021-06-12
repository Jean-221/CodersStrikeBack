#pragma once
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <assert.h>     /* assert */
#include <iostream>

#include "MovementBrain.h"
#include "Tests.h"

using namespace std;

float RandFloat()
{
	return static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 10)) - RAND_MAX/20;
}


void VectorAddTest()
{
	Vector2 v1(RandFloat(), RandFloat());
	Vector2 v2(RandFloat(), RandFloat());

	Vector2 v3 = v1 + v2;

	assert(v3.x == v1.x + v2.x);
	assert(v3.y == v1.y + v2.y);
}

void VectorUnaryMinus()
{
	Vector2 v1(RandFloat(), RandFloat());
	assert(-(v1.x) == (-v1).x);
	assert(-(v1.y) == (-v1).y);
}

void VectorMinus()
{
	Vector2 v1(RandFloat(), RandFloat());
	Vector2 v2(RandFloat(), RandFloat());

	Vector2 v3 = v1 - v2;

	assert(v3.x == v1.x - v2.x);
	assert(v3.y == v1.y - v2.y);
}

void VectorEqualityTest()
{
	Vector2 v1(RandFloat(), RandFloat());
	Vector2 v2(RandFloat(), RandFloat());
	Vector2 v3 = v1;

	assert(v3 == v1);
	assert(!(v3 == v2));
}

void VectorDotTest()
{
	Vector2 v1(0, 1);
	Vector2 v2(1, 0);
	Vector2 v3(0, -1);

	assert(v1.dot(v2) == 0);
	assert(v1.dot(v3) == -1);
	assert(v1.dot(v1) == 1);
	// Should test other
}

void VectorMultTest()
{
	float x = RandFloat(), y = RandFloat(), c = RandFloat();
	Vector2 v1(x, y);
	Vector2 v2 = v1 * c;

	assert(v2.x == (v1.x * c) && (v2.y == (v1.y * c)));
}


void AllTest()
{
	srand(static_cast<unsigned int>(time(NULL)));

	VectorAddTest();
	VectorUnaryMinus();
	VectorMinus();
	VectorEqualityTest();
	VectorDotTest();
	VectorMultTest();
}