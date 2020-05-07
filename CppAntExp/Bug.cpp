#include "Game.h"

Bug::Bug(const int x, const int y, const int maxLifeCycle, const int currentLifeCycle)
	: x(x), y(y), maxLifeCycle(maxLifeCycle), currentLifeCycle(currentLifeCycle) {
}

void Bug::move(int x, int y) {
	int oldX = this->x;
	int oldY = this->y;

	this->x = x;
	this->y = y;

	MapConfig* map = MapConfig::getInstance();
	map->setBug(nullptr, oldX, oldY);
	map->setBug(this, x, y);

	onMove(x, y, oldX, oldY);
}

void Bug::addLifeCycle() {
	currentLifeCycle = (currentLifeCycle + 1) % maxLifeCycle;
	onLifeCycleChanged();
}