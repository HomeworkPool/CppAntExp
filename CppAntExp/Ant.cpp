#include <random>
#include <stdexcept>
#include <vector>

using std::vector;

class Bug;
class MapConfig {
private:
	const int line;
	const int col;
	vector<Bug*> bugs;
	static MapConfig* instance;
	
	MapConfig(const int line, const int col) : line(line), col(col), bugs(vector<Bug*>(line* col)) {
	}
public:

	void setBug(Bug* bug, const int x, const int y) {
		bugs[this->line * y + x] = bug;
	}

	Bug* getBug(const int x, const int y) const {
		return bugs[this->line * y + x];
	}

	static void createInstance(const int line, const int col) {
		if (instance == nullptr)
			instance = new MapConfig(line, col);
		else
			throw std::invalid_argument("Already initialized");
	}

	static MapConfig* getInstance() {
		return instance;
	}
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

	Bug(const int x, const int y, const int maxLifeCycle, const int currentLifeCycle = 0, const int randomSeed = 77)
		: x(x), y(y), maxLifeCycle(maxLifeCycle), currentLifeCycle(currentLifeCycle) {
	}

	void move(int x, int y) {
		int oldX = this->x;
		int oldY = this->y;
		
		this->x = x;
		this->y = y;
		
		onMove(x, y, oldX, oldY);
	}

	void addLifeCycle() {
		currentLifeCycle = (currentLifeCycle + 1) % maxLifeCycle;
		onLifeCycleChanged();
	}
};

class Ant : public Bug {


public:
	void breed() override {
		
	}

	void onLifeCycleChanged() override {
		
	}

	void onMove(int newX, int newY, int oldX, int oldY) override {
		
	}

	void doEventLoop() override {
		
	}

	void randomMove() {
		int direction = rand() % 4;
		MapConfig* instance = MapConfig::getInstance();

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