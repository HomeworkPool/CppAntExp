#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>

#include "Game.h"

using std::vector;
using std::cout;
using std::endl;

MapConfig* MapConfig::instance = nullptr;
vector<char> MapConfig::EventLoopTypeList = vector<char>{ 'x', 'o' };

MapConfig::MapConfig(const int line, const int col) : line(line), col(col), bugs(vector<Bug*>(line* col, nullptr)) {
}

MapConfig::~MapConfig() {
	delete instance;
	instance = nullptr;
}

void MapConfig::setBug(Bug* bug, const int x, const int y) {
	bugs[this->line * y + x] = bug;
}

Bug* MapConfig::getBug(const int x, const int y) const {
	return bugs[this->line * y + x];
}

void MapConfig::addBug(Bug* bug) {
	bool spawned = false;

	while (!spawned) {
		int x = rand() % col;
		int y = rand() % line;

		if (getBug(x, y) == nullptr) {
			setBug(bug, x, y);
			spawned = true;
		}
	}
}

void MapConfig::createInstance(const int line, const int col) {
	if (instance == nullptr)
		instance = new MapConfig(line, col);
	else
		throw std::invalid_argument("Already initialized");
}

MapConfig* MapConfig::getInstance() {
	return instance;
}

int MapConfig::getLine() const {
	return line;
}

int MapConfig::getCol() const {
	return col;
}
