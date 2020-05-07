#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>

#include "Game.h"

using std::vector;
using std::cout;
using std::endl;

class Ant : public Bug {
private:

public:
	void breed() override {
		
	}

	char getDescriptionChar() const override {
		return 'o';
	}

	void onLifeCycleChanged() override {
		
	}

	void onMove(int newX, int newY, int oldX, int oldY) override {
		
	}

	void doEventLoop() override {
		
	}

	void randomMove() {
		int direction = rand() % 4;
		MapConfig* const instance = MapConfig::getInstance();

		switch (direction) {
		case DIRECTION_UP:

			break;

		case DIRECTION_DOWN:

			break;

		case DIRECTION_LEFT:
			break;

		case DIRECTION_RIGHT:
			break;
		}
	}
};