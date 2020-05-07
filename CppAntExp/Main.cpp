#include "Game.h"

int main(int argc, char* argv[]) {
	Game* game = Game::getInstance();
	MapConfig* mapConfig = MapConfig::getInstance();

	for (int i = 0; i < 100; ++i) {
		Ant::addAnt();
	}

	for (int i = 0; i < 5; ++i) {
		
	}

	while (true) {
		game->doEventLoop();
		getchar();
	}
}
