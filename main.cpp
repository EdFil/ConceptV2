#include <iostream>

#include <SDL.h>

SDL_Window* g_window;
SDL_Renderer* g_renderer;
bool _isRunning = true;

int main(int, char**) {
	SDL_LogSetAllPriority(SDL_LOG_PRIORITY_VERBOSE);

	// Init SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_Init Error: %s", SDL_GetError());
		return -1;
	}

	g_window = SDL_CreateWindow("ConceptV2", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
	if (g_window == nullptr) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_CreateWindow Error: %s", SDL_GetError());
		SDL_Quit();
		return -2;
	}

	g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (g_renderer == nullptr) {
		SDL_DestroyWindow(g_window);
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_CreateRenderer Error: %s", SDL_GetError());
		SDL_Quit();
		return -3;
	}

	while (_isRunning) {
		// Fetch SDL_Events
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				_isRunning = false;
			}
		}

		// Render Scene
		SDL_SetRenderDrawColor(g_renderer, (Uint8)(rand() % 256), (Uint8)(rand() % 256), (Uint8)(rand() % 256), 255);
		SDL_RenderClear(g_renderer);
		SDL_RenderPresent(g_renderer);
	}

	SDL_DestroyRenderer(g_renderer);
	SDL_DestroyWindow(g_window);
	SDL_Quit();

	return 0;
}