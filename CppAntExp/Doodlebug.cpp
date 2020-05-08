
#include "Game.h"

void Doodlebug::breedImpl(int x, int y) {
	addDoodlebug(x, y);
	isLastBreedSuccess = true;
	addLifeCycle();
}

void Doodlebug::killImpl(int x, int y) {
	MapConfig* const instance = MapConfig::getInstance();
	instance->removeBug(x, y);
	move(x, y);
	setHungerToMax();
}

Doodlebug::Doodlebug(const int x, const int y, const int currentLifeCycle)
	: Bug(x, y, 9, currentLifeCycle), hunger(MAX_HUNGER) {
	
}

Doodlebug::~Doodlebug() = default;

void Doodlebug::breed() {
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

char Doodlebug::getDescriptionChar() const {
	return 'X';
}

void Doodlebug::onLifeCycleChanged() {
	
}

void Doodlebug::onMove(int newX, int newY, int oldX, int oldY) {
	
}

void Doodlebug::doEventLoop(char type) {
	if (type == 'X') {
		hunger--;
		if (hunger <= 0) {
			MapConfig::getInstance()->removeBug(this->x, this->y);
			return;
		}

		tryKillAndRandomMove();

		if (!isLastBreedSuccess && currentLifeCycle == 0)
			breed();
		else
			addLifeCycle();
	}
}

void Doodlebug::setHungerToMax() {
	hunger = MAX_HUNGER;
}

void Doodlebug::tryKillAndRandomMove() {
	MapConfig* const instance = MapConfig::getInstance();

	if (y > 0 && instance->getBug(x, y - 1) != nullptr)
		killImpl(x, y - 1);
	else if (y < instance->getLine() - 1 && instance->getBug(x, y + 1) != nullptr)
		killImpl(x, y + 1);
	else if (x > 0 && instance->getBug(x - 1, y) == nullptr)
		killImpl(x - 1, y);
	else if (x < instance->getCol() - 1 && instance->getBug(x + 1, y) != nullptr)
		killImpl(x + 1, y);
	else
		randomMove();
}

void Doodlebug::addDoodlebug(int x, int y) {
	MapConfig::getInstance()->addBug(new Doodlebug(x, y, 0));
}
