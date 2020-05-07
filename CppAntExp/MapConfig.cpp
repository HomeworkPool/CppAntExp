#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>

#include "Game.h"

using std::vector;
using std::cout;
using std::endl;

MapConfig* MapConfig::instance = nullptr;

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

void MapConfig::createInstance(const int line, const int col) {
	if (instance == nullptr)
		instance = new MapConfig(line, col);
	else
		throw std::invalid_argument("Already initialized");
}

MapConfig* MapConfig::getInstance() {
	return instance;
}