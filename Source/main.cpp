#include <iostream>

#include "Engine/Engine.hpp"

// <DEBUG>
#include "Engine/IO/FileManager.hpp"
// </DEBUG>

int main(int, char**) {
	// <DEBUG>
	FileManager fileManager;
	std::string something = fileManager.fullpathForFileName("Test.txt");
	
	std::string test = fileManager.dataForFilePath("Test.txt");
	std::string test2 = fileManager.dataForFilePath("Test.txt");
	// </DEBUG>

	Engine* engine = new Engine();
	if (engine->initialize()) {
		engine->run();
	}

	engine->cleanup();
	return 0;
}