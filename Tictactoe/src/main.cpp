#include <iostream>
#include <SDL3/SDL.h>



int main(int argc, char** args){
	SDL_Window* window = NULL;
	SDL_Surface* winSurface = NULL;
	SDL_Renderer* renderer = nullptr;



	const char* title = "Tictactoe";

	Uint8 r = 255;  
	Uint8 g = 90;   
	Uint8 b = 120;  
	Uint8 a = 255;  

	Uint32 color = (r << 24) | (g << 16) | (b << 8) | a;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
	{
		std::cout << "Failed to initialize SDL" << SDL_GetError() << '\n';
		system("PAUSE");
		return 1;
	}
	window = SDL_CreateWindow(title, 1280, 720, SDL_WINDOW_RESIZABLE);
	if (!window) {
		std::cout << "Failed to create a window! Error: " << SDL_GetError << '\n';
		system("PAUSE");
		return 1;
	}
	winSurface = SDL_GetWindowSurface(window);
	if (!winSurface)
	{
		std::cout << "Failed to initialize the Windows Surface" << SDL_GetError() << '\n';
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
		SDL_FRect rectangle{ 10, 10, 20, 250 };

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &rectangle);

		SDL_RenderPresent(renderer);

		SDL_FillSurfaceRect(winSurface, NULL, color);
		SDL_UpdateWindowSurface(window);
		system("PAUSE");
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	return 0;	
}