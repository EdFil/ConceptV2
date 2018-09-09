#include <MemoryManager.hpp>
#include <LinearAllocator.hpp>

#include <SDL.h>

int main(int, char**) {
	SDL_LogSetAllPriority(SDL_LOG_PRIORITY_VERBOSE);

	MemoryManager memoryManager(1024 + sizeof(LinearAllocator));
	void* mem = memoryManager.allocate(1024);
	LinearAllocator linearAllocator(mem, 1024);
	linearAllocator.allocate(1000);
	
	return 0;
}

// #include <Engine.hpp>

// int main(int, char**) {
// 	Engine engine;
// 	if(engine.initialize()) {
// 		engine.run();
// 	}
// 	engine.cleanup();
// }c