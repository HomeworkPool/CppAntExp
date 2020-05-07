#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>

#include "Game.h"

using std::vector;
using std::cout;
using std::endl;

Game* Game::instance = nullptr;

Game::Game() {
	MapConfig::createInstance(20, 20);
	map = MapConfig::getInstance();
}

Game::~Game() {
	delete instance;
	delete map;
	instance = nullptr;
}

Game* Game::getInstance() {
	return instance == nullptr ? (instance = new Game()) : instance;
}

void Game::draw() const {
	for (int y = 0; y < map->line; ++y) {
		for (int x = 0; x < map->col; ++x) {
			Bug* bug = map->getBug(x, y);

			if (bug != nullptr) {
				cout << bug->getDescriptionChar();
			}
			else {
				cout << " ";
			}
		}

		cout << endl;
	}
}

void Game::doEventLoop() {
	system("cls");
	draw();
}