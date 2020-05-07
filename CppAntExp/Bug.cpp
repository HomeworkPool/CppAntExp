#include "Game.h"

Bug::Bug(const int x, const int y, const int maxLifeCycle, const int currentLifeCycle = 0, const int randomSeed = 77)
	: x(x), y(y), maxLifeCycle(maxLifeCycle), currentLifeCycle(currentLifeCycle) {
}

void Bug::move(int x, int y) {
	int oldX = this->x;
	int oldY = this->y;

	this->x = x;
	this->y = y;

	onMove(x, y, oldX, oldY);
}

void Bug::addLifeCycle() {
	currentLifeCycle = (currentLifeCycle + 1) % maxLifeCycle;
	onLifeCycleChanged();
}