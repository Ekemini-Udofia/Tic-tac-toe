#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>

constexpr int screen_width = 1000;
constexpr int screen_height = 700;





int main(int argc, char** args) {
	SDL_Window* window{ nullptr };
	SDL_Surface* winSurface{ nullptr };
	SDL_Renderer* renderer{ nullptr };



	const char* title = "Tictactoe";

	Uint8 r = 255;  
	Uint8 g = 90;   
	Uint8 b = 120;  
	Uint8 a = 255;  

	Uint32 color = (r << 24) | (g << 16) | (b << 8) | a;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
	{
		SDL_Log( "Failed to initialize SDL: %s\n", SDL_GetError() );
		system("PAUSE");
		return 1;
	}
	window = SDL_CreateWindow(title, screen_width, screen_height, SDL_WINDOW_RESIZABLE);
	if (!window) {
		SDL_Log( "Failed to create a window! Error: %s\n", SDL_GetError() );
		system("PAUSE");
		return 1;
	}
	winSurface = SDL_GetWindowSurface(window);
	if (!winSurface)
	{
		SDL_Log( "Failed to initialize the Windows Surface: %s\n", SDL_GetError() );
		system("PAUSE");
		return 1;
	}


	SDL_Event main;
	bool running = true;
	while (running)
	{
		SDL_PollEvent(nullptr);

		while (SDL_PollEvent(&main))
		{
			if (main.type == SDL_EVENT_QUIT)
			{
				running = false;
			}
		}

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		SDL_RenderPresent(renderer);

		SDL_FillSurfaceRect(winSurface, NULL, color);
		SDL_UpdateWindowSurface(window);
		system("PAUSE");
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	return 0;	
}