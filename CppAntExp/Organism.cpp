#include "Game.h"

Organism::Organism(const int x, const int y, const int maxLifeCycle, const int currentLifeCycle)
	: x(x), y(y), maxLifeCycle(maxLifeCycle), currentLifeCycle(currentLifeCycle) {
}

Organism::~Organism() = default;

int Organism::getX() const {
	return x;
}

int Organism::getY() const {
	return y;
}

void Organism::setX(const int x) {
	this->x = x;
}

void Organism::setY(const int y) {
	this->y = y;
}

void Organism::move(int x, int y) {
	int oldX = this->x;
	int oldY = this->y;

	this->x = x;
	this->y = y;

	MapConfig* map = MapConfig::getInstance();
	map->setBug(nullptr, oldX, oldY);
	map->setBug(this, x, y);

	onMove(x, y, oldX, oldY);
}

void Organism::randomMove() {
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

void Organism::addLifeCycle() {
	currentLifeCycle = (currentLifeCycle + 1) % maxLifeCycle;
	onLifeCycleChanged();
}
