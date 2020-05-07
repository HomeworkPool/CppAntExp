#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>

#include "Game.h"

using std::vector;
using std::cout;
using std::endl;

Ant::Ant(const int x, const int y, const int currentLifeCycle)
	: Bug(x, y, 4, currentLifeCycle) {
}

void Ant::breed() {
	MapConfig* const instance = MapConfig::getInstance();
	
	if (y > 0 && instance->getBug(x, y - 1) == nullptr)
		breedImpl(x, y - 1);
	if (y < instance->getLine() - 1 && instance->getBug(x, y + 1) == nullptr)
		breedImpl(x, y + 1);
	if (x > 0 && instance->getBug(x - 1, y) == nullptr)
		breedImpl(x - 1, y);
	if (x < instance->getCol() - 1 && instance->getBug(x + 1, y) == nullptr)
		breedImpl(x + 1, y);
}

void Ant::breedImpl(int x, int y) {
	addAnt(x, y);
	isLastBreedSuccess = true;
	addLifeCycle();
}


char Ant::getDescriptionChar() const {
	return 'O';
}

void Ant::onLifeCycleChanged() {
	if (currentLifeCycle == 0) {
		breed();
	}
}

void Ant::onMove(int newX, int newY, int oldX, int oldY) {
	
}

void Ant::doEventLoop(char type) {
	if (type == 'O') {
		randomMove();

		if (!isLastBreedSuccess && currentLifeCycle == 0)
			breed();
		else
			addLifeCycle();
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

void Ant::addAnt(int x, int y) {
	MapConfig::getInstance()->addBug(new Ant(x, y, 0));
}
