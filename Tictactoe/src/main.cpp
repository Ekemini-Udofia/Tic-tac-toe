#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_audio.h>
#include <SDL3/SDL_video.h>

#include <SDL3/SDL_init.h>

int main()
{
	const char* title = "Tictactoe";
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	SDL_Window* window = SDL_CreateWindow(title, 1280, 720, SDL_WINDOW_ALWAYS_ON_TOP);
	if (!window) {
		std::cout << "Failed to create a window! Error: " << SDL_GetError << '\n';
	}
	SDL_Surface* winSurface = SDL_GetWindowSurface(window);

	// do drawing
	Uint32 color = SDL_MapRGB(*SDL_PixelFormatDetails::format, NULL, 255, 90, 120);
	SDL_FillSurfaceRect(winSurface, NULL, color);

	SDL_UpdateWindowSurface(window);
	SDL_Delay(10000);
	SDL_DestroyWindow(window);
	window = NULL;
	winSurface = NULL;
	SDL_Quit();
}