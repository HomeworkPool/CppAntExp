#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>

#include "Game.h"

using std::vector;
using std::cout;
using std::endl;

Ant::Ant(const int x, const int y, const int currentLifeCycle)
	: Organism(x, y, 4, currentLifeCycle) {
}

Ant::~Ant() = default;

void Ant::breed() {
	MapConfig* const instance = MapConfig::getInstance();
	
	if (y > 0 && instance->getBug(x, y - 1) == nullptr)
		breedImpl(x, y - 1);
	else if (y < instance->getLine() - 1 && instance->getBug(x, y + 1) == nullptr)
		breedImpl(x, y + 1);
	else if (x > 0 && instance->getBug(x - 1, y) == nullptr)
		breedImpl(x - 1, y);
	else if (x < instance->getCol() - 1 && instance->getBug(x + 1, y) == nullptr)
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

void Ant::addAnt(int x, int y) {
	MapConfig::getInstance()->addBug(new Ant(x, y, 0));
}