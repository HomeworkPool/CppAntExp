#pragma once

#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>

class Bug;
using std::vector;
using std::cout;
using std::endl;

class MapConfig {
private:
	const int line;
	const int col;
	vector<Bug*> bugs;
	static MapConfig* instance;
	MapConfig(const int line, const int col);
	~MapConfig();

public:
	MapConfig(const MapConfig& target) = delete;
	friend class Game;
	void setBug(Bug* bug, const int x, const int y);
	Bug* getBug(const int x, const int y) const;
	static void createInstance(const int line, const int col);
	static MapConfig* getInstance();
};


class Game {
private:
	static Game* instance;
	MapConfig* map;

	Game();
	~Game();
public:
	Game(const Game& target) = delete;

	static Game* getInstance();
	void draw() const;
	void doEventLoop();
};

class Bug {
private:
	int x;
	int y;
	int currentLifeCycle;
	const int maxLifeCycle;

public:
	static const int DIRECTION_UP = 0;
	static const int DIRECTION_DOWN = 1;
	static const int DIRECTION_LEFT = 2;
	static const int DIRECTION_RIGHT = 3;

	virtual void breed() = 0;
	virtual void onLifeCycleChanged() = 0;
	virtual void onMove(int newX, int newY, int oldX, int oldY) = 0;
	virtual void doEventLoop() = 0;
	virtual char getDescriptionChar() const = 0;

	Bug(const int x, const int y, const int maxLifeCycle, const int currentLifeCycle = 0, const int randomSeed = 77);
	void move(int x, int y);
	void addLifeCycle();
};