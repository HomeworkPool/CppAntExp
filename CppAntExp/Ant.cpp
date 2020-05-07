#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>

#include "Game.h"

using std::vector;
using std::cout;
using std::endl;

Ant::Ant(const int x, const int y, const int maxLifeCycle, const int currentLifeCycle)
	: Bug(x, y, maxLifeCycle, currentLifeCycle) {
}

void Ant::breed() {
}

char Ant::getDescriptionChar() const {
	return 'o';
}

void Ant::onLifeCycleChanged() {
}

void Ant::onMove(int newX, int newY, int oldX, int oldY) {
	
}

void Ant::doEventLoop(char type) {
	if (type == 'o') {
		randomMove();
	}
}

void Ant::randomMove() {
	int direction = rand() % 4;
	MapConfig* const instance = MapConfig::getInstance();

	switch (direction) {
		case DIRECTION_UP:
			if (y > 0 && instance->getBug(x, y - 1) == nullptr)
				move(x, y - 1);
			break;

		case DIRECTION_DOWN:
			if (y < instance->getLine() - 1 && instance->getBug(x, y + 1) == nullptr)
				move(x, y + 1);
			break;

		case DIRECTION_LEFT:
			if (x > 0 && instance->getBug(x - 1, y) == nullptr)
				move(x - 1, y);
			break;

		case DIRECTION_RIGHT:
			if (x < instance->getCol() - 1 && instance->getBug(x + 1, y) == nullptr)
				move(x + 1, y);
			break;

		default:
			throw std::invalid_argument("Unexpected direction");
			break;
	}
}

void Ant::addAnt() {
	MapConfig::getInstance()->addBug(new Ant());
}
