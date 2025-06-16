#include <cstdint>
#include <SDL3/SDL.h>
//#include <SDL3/SDL_main.h>
#include <string>
#include <SDL3_image/SDL_image.h>


//sets the screen dimensions 
constexpr uint16_t screen_width = 670;
constexpr uint16_t screen_height = 480;

SDL_Window* window{ nullptr };
SDL_Surface* winSurface{ nullptr };
SDL_Renderer* renderer{ nullptr };
SDL_Surface* Test_surface{ nullptr };





const char* title = "Tictactoe";

Uint8 r{ 255 };
Uint8 g{ 90 };
Uint8 b{ 120 };
Uint8 a{ 255 };

Uint32 color = (r << 24) | (g << 16) | (b << 8) | a;

class Ltexture {

private:
	SDL_Texture* mTexture;

	int mWidth;

	int mHeight;
public:
	Ltexture()
	{
		mTexture = nullptr;
		mWidth = 0;
		mHeight = 0;
	}

	~Ltexture()
	{
		destroy();
	}

	bool loadFromFile(std::string path)
	{
		destroy();

		SDL_Surface* loadedSurface = IMG_Load(path.c_str());
		if (loadedSurface == nullptr)
		{
			SDL_Log("Unable to load image %s! SDL_image error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			mTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
			if (mTexture == nullptr)
			{
				SDL_Log("Unable to create texture from loaded pixels! SDL error: %s\n", SDL_GetError());
			}
			else
			{
				mWidth = loadedSurface->w;
				mHeight = loadedSurface->h;
			}

			SDL_DestroySurface(loadedSurface);
		}

		return mTexture != nullptr;
	}

	void destroy()
	{
		SDL_DestroyTexture(mTexture);
		mTexture = nullptr;
		mWidth = 0;
		mHeight = 0;
	}

	void renderscreen(float x, float y)
	{
		SDL_FRect dstRect = { x, y, static_cast<float>(mWidth), static_cast<float>(mHeight) };

		SDL_RenderTexture(renderer, mTexture, nullptr, &dstRect);
	}

	int getWidth()
	{
		return mWidth;
	}

	int getHeight()
	{
		return mHeight;

	}
};

Ltexture new_game_button, online_button, exit_button, turn_label, x_button, o_button, blank_button;

bool init()
{
	bool success{ true };
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_Log("Failed to initialize SDL. SDL Error %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		if (!SDL_CreateWindowAndRenderer(title, static_cast<int>(screen_width), static_cast<int>(screen_height), SDL_WINDOW_TRANSPARENT, &window, &renderer))
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

bool loadMedia()
{
	//File loading flag
	bool success{ true };

	//Load directional images
	if (!new_game_button.loadFromFile("src\\gui\\assets\\SDL3_New_Game_Button.png"))
	{
		SDL_Log("Unable to load blank image!\n");
	}
	if (!online_button.loadFromFile("src\\gui\\assets\\SDL3_Online_Button.png"))
	{
		SDL_Log("Unable to load blank image!\n");
	}
	if (!exit_button.loadFromFile("src\\gui\\assets\\SDL3_Exit_Button.png"))
	{
		SDL_Log("Unable to load right image!\n");
	}
	if (!turn_label.loadFromFile("src\\gui\\assets\\SDL3_Turn_Label.png"))
	{
		SDL_Log("Unable to load right image!\n");
	}
	if (!blank_button.loadFromFile("src\\gui\\assets\\SDL3_Buttons.png"))
	{
		SDL_Log("Unable to load up image!\n");
	}
	if (!x_button.loadFromFile("src\\gui\\assets\\SDL3_O_Button.png"))
	{
		SDL_Log("Unable to load down image!\n");
	}
	if (!o_button.loadFromFile("src\\gui\\assets\\SDL3_X_Button.png"))
	{
		SDL_Log("Unable to load left image!\n");
	}



	return success;
}

/*
void close()
{
	//tic_Button.destroy();

	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;

	//IMG_Quit();
	SDL_Quit();
}
*/

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

//int main(int argc, char* argv[])
void init_gui()
{
	//int exitcode{ 0 };

	if (!init())
	{
		SDL_Log("Failed to initialize SDL. SDL Error %s\n", SDL_GetError());
		//exitcode = 1;
	}
	else
	{
		if (!loadMedia())
		{
			SDL_Log("Failed to load media. SDL Error %s\n", SDL_GetError());
			//exitcode = 2;
		}
		else
		{
			bool quit{ false };
			SDL_Event e;
			SDL_zero(e);

			//defining textures

			Ltexture* new_game_texture = &new_game_button;
			Ltexture* online_texture = &online_button;
			Ltexture* exit_texture = &exit_button;
			Ltexture* turn_texture = &turn_label;
			Ltexture* blank_texture = &blank_button;
			Ltexture* x_texture = &x_button;
			Ltexture* o_texture = &o_button;
			Ltexture* player_1;
			Ltexture* player_2;



			SDL_Color bgColor = { 0xD9, 0xD9, 0xD9, 0xFF };
			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_EVENT_QUIT)
					{
						quit = true;
					}
					// Graphics Main Loop


					//Update screen
					SDL_RenderPresent(renderer);


					SDL_RenderPresent(renderer);

					//SDL_FillSurfaceRect(winSurface, nullptr, color);
					SDL_BlitSurface(Test_surface, nullptr, winSurface, nullptr);
					SDL_UpdateWindowSurface(window);
				}

				//SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, 0xFF);
				//SDL_RenderClear(renderer);


				

			}

		}
	}

	Destroy_Window();
	//return exitcode;
}


