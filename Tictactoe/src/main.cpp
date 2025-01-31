#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_audio.h>
#include <SDL3/SDL_video.h>


int main()
{
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Init(SDL_INIT_EVENTS);

	SDL_CreateWindowAndRenderer("Tictactoe", 640, 480, SDL_WINDOW_MOUSE_CAPTURE, &window, &renderer);
	//SDL_Surface(SDL_LoadBMP());
	//SDL_SetWindowIcon();               (SDL_LoadBMP(“”), NULL);
	SDL_SetRenderScale(renderer, 4, 4);

	SDL_SetRenderDrawColor(renderer, 100, 100, 100, 0);
	SDL_RenderClear(renderer);

	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	//SDL_RenderPoint(renderer, 640.0 / 2, 480.0 / 2);
	SDL_RenderPresent(renderer);
	SDL_Delay(20000);

	return 0;
}