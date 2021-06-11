#pragma once
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <assert.h>     /* assert */
#include <iostream>

#include "MovementBrain.h"
#include "Tests.h"

using namespace std;

int RandInt()
{
	return rand() - RAND_MAX/2;
}


void VectorAddTest()
{
	Vector2 v1(RandInt(), RandInt());
	Vector2 v2(RandInt(), RandInt());

	Vector2 v3 = v1 + v2;

	assert(v3.x == v1.x + v2.x);
	assert(v3.y == v1.y + v2.y);
}

void VectorUnaryMinus()
{
	Vector2 v1(RandInt(), RandInt());
	assert(-(v1.x) == (-v1).x);
	assert(-(v1.y) == (-v1).y);
}

void VectorMinus()
{
	Vector2 v1(RandInt(), RandInt());
	Vector2 v2(RandInt(), RandInt());

	Vector2 v3 = v1 - v2;

	assert(v3.x == v1.x - v2.x);
	assert(v3.y == v1.y - v2.y);
}


void AllTest()
{
	srand(time(NULL));

	VectorAddTest();
	VectorUnaryMinus();
	VectorMinus();
}