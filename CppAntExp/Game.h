#pragma once

#include <iostream>
#include <random>
#include <set>
#include <stdexcept>
#include <vector>

class Organism;
using std::vector;
using std::cout;
using std::endl;

class MapConfig {
private:
	const int line;
	const int col;
	vector<Organism*> bugs;
	static MapConfig* instance;
	MapConfig(const int line, const int col);
	~MapConfig();

public:
	static vector<char> EventLoopTypeList;
	
	MapConfig(const MapConfig& target) = delete;
	friend class Game;
	void setBug(Organism* bug, const int x, const int y);
	void removeBug(const int x, const int y);
	Organism* getBug(const int x, const int y) const;
	void addBug(Organism* bug);
	static void createInstance(const int line, const int col);
	static MapConfig* getInstance();

	int getLine() const;
	int getCol() const;
};


class Game {
private:
	static Game* instance;
	MapConfig* map;
	std::set<Organism*> visitSet;

	Game();
	~Game();
public:
	Game(const Game& target) = delete;

	static Game* getInstance();
	void draw() const;
	void doEventLoop();
};

class Organism {
protected:
	int x;
	int y;
	int currentLifeCycle;
	const int maxLifeCycle;

public:
	static const int DIRECTION_UP = 0;
	static const int DIRECTION_DOWN = 1;
	static const int DIRECTION_LEFT = 2;
	static const int DIRECTION_RIGHT = 3;

	Organism(const int x, const int y, const int maxLifeCycle, const int currentLifeCycle = 0);
	virtual ~Organism();

	virtual void breed() = 0;
	virtual void onLifeCycleChanged() = 0;
	virtual void onMove(int newX, int newY, int oldX, int oldY) = 0;
	virtual void doEventLoop(char type) = 0;
	virtual char getDescriptionChar() const = 0;

	int getX() const;
	int getY() const;

	void setX(const int x);
	void setY(const int y);

	void move(int x, int y);
	void randomMove();
	void addLifeCycle();
};

class Ant : public Organism {
private:
	bool isLastBreedSuccess = true;
	void breedImpl(int x, int y);
	Ant(const int x = 0, const int y = 0, const int currentLifeCycle = 0);
	virtual ~Ant();
	
public:

	void breed() override;
	char getDescriptionChar() const override;
	void onLifeCycleChanged() override;
	void onMove(int newX, int newY, int oldX, int oldY) override;
	void doEventLoop(char type) override;

	static void addAnt(int x = -1, int y = -1);
};

class Doodlebug : public Organism {
private:
	bool isLastBreedSuccess = true;
	int hunger;
	void breedImpl(int x, int y);
	void killImpl(int x, int y);
	Doodlebug(const int x = 0, const int y = 0, const int currentLifeCycle = 0);
	virtual ~Doodlebug();
	
public:
	static const int MAX_HUNGER = 4;

	void breed() override;
	char getDescriptionChar() const override;
	void onLifeCycleChanged() override;
	void onMove(int newX, int newY, int oldX, int oldY) override;
	void doEventLoop(char type) override;
	void setHungerToMax();

	void tryKillAndRandomMove();

	static void addDoodlebug(int x = -1, int y = -1);
};
