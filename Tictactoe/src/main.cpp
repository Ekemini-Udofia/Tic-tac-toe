#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_audio.h>


int main()
{
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_CreateWindowAndRenderer("Tictactoe", 320, 240, SDL_WINDOW_RESIZABLE, &window, &renderer);
	//SDL_RenderSetScale(renderer, 4, 4);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderPoint(renderer, 640.0 / 2, 480.0 / 2);
	SDL_RenderPresent(renderer);
	SDL_Delay(20000);

	return 0;
}