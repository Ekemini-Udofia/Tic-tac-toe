#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>

constexpr int screen_width = 1000;
constexpr int screen_height = 700;

SDL_Window* window{ nullptr };
SDL_Surface* winSurface{ nullptr };
SDL_Renderer* renderer{ nullptr };
SDL_Surface* Test_surface{ nullptr };



const char* title = "Tictactoe";

Uint8 r = 255;
Uint8 g = 90;
Uint8 b = 120;
Uint8 a = 255;

Uint32 color = (r << 24) | (g << 16) | (b << 8) | a;




bool init()
{
	bool success{ true };
	if (!SDL_Init(SDL_INIT_VIDEO) )
	{
		SDL_Log("Failed to initialize SDL. SDL Error %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		if (( window = SDL_CreateWindow(title, screen_width, screen_height, 0 )) == nullptr) 
		{
			SDL_Log("Failed to create a window! Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			winSurface = SDL_GetWindowSurface(window);


		}
	}
	return success;

}

bool load_media()
{
	bool success{ true };
	std::string imagepath{ "App_Resources/app.bmp" };
	if ((Test_surface = SDL_LoadBMP(imagepath.c_str())) == nullptr)
	{
		SDL_Log("Failed to load image. SDL Error: %s\n", imagepath.c_str(), SDL_GetError());
		success = false;
	}
	return success;
}

void Destroy_Window()
{
	
	SDL_DestroySurface(winSurface);
	winSurface = nullptr;
	SDL_DestroySurface(Test_surface);
	Test_surface = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_Quit();

}

int main(int argc, char* argv[])
{
	int exitcode{ 0 };

	if (!init())
	{
		SDL_Log("Failed to initialize SDL. SDL Error %s\n", SDL_GetError());
		exitcode = 1;
	}
	else
	{
		if (!load_media())
		{
			SDL_Log("Failed to load media. SDL Error %s\n");
			exitcode = 2;
		}
		else
		{
			bool quit{ false };
			SDL_Event e;
			SDL_zero(e);
			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_EVENT_QUIT)
					{
						quit = true;
					}
				}
				SDL_FillSurfaceRect(winSurface, nullptr, color);
				SDL_BlitSurface(Test_surface, nullptr, winSurface, nullptr);
				SDL_UpdateWindowSurface(window);
			}

		}
	}

	Destroy_Window();
	return exitcode;
}

