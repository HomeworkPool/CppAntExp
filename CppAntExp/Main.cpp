#include <ctime>
#include <windows.h>

#include "Game.h"

int main(int argc, char* argv[]) {
	Game* game = Game::getInstance();
	MapConfig* mapConfig = MapConfig::getInstance();
	srand((unsigned int)(time(NULL)));

	for (int i = 0; i < 100; ++i) {
		Ant::addAnt();
	}

	for (int i = 0; i < 5; ++i) {
		Doodlebug::addDoodlebug();
	}

	game->draw();
	std::cout << std::endl << "This is the initial condition. Press Enter to start." << std::endl;
	getchar();

	while (true) {
		game->doEventLoop();
		std::cout << std::endl << "Press Enter to continue" << std::endl;
		getchar();
	}
}
