
#include <SDL3/SDL.h>
//#include <SDL3/SDL_main.h>
#include <string>
#include <SDL3_image/SDL_image.h>


//sets the screen dimensions 
constexpr int screen_width = 670;
constexpr int screen_height = 480;

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
		if (!SDL_CreateWindowAndRenderer(title, screen_width, screen_height, 0, &window, &renderer))
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
void game_gui()
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
					//else if (e.type == SDL_EVENT_KEY_DOWN)
					//{
					//	//Set texture
					//	if (e.key.key == SDLK_1)
					//	{
					//		currentTexture = &blank_button;
					//	}
					//	else if (e.key.key == SDLK_2)
					//	{
					//		currentTexture = &x_button;
					//	}
					//	else if (e.key.key == SDLK_3)
					//	{
					//		currentTexture = &o_button;
					//	}
					//	else if (e.key.key == SDLK_4)
					//	{
					//		currentTexture = &exit_button;
					//	}
					//}

				}

				SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, 0xFF);
				SDL_RenderClear(renderer);


				// first column

				new_game_button.renderscreen(20.0, 15.0);
				online_button.renderscreen(20.0, 100.0);
				exit_button.renderscreen(20.0, 185.0);
				turn_label.renderscreen(20.0, 270.0);

				//second column

				blank_button.renderscreen(212.5, 15.0);
				blank_button.renderscreen(212.5, 170.0);
				blank_button.renderscreen(212.5, 325.0);

				//third column

				blank_button.renderscreen(362.5, 15.0);
				blank_button.renderscreen(362.5, 170.0);
				blank_button.renderscreen(362.5, 325.0);

				//fourth column

				blank_button.renderscreen(512.5, 15.0);
				blank_button.renderscreen(512.5, 170.0);
				blank_button.renderscreen(512.5, 325.0);

				//Render image on screen
				//currentTexture->renderscreen((screen_width - currentTexture->getWidth()) / 3.f, (screen_height - currentTexture->getHeight()) / 4.f);
				//x_texture->renderscreen((screen_width - x_texture->getWidth()) / 3.f, (screen_height - x_texture->getHeight()) / 4.f);
				//o_texture->renderscreen((screen_width - o_texture->getWidth()) / 3.f, (screen_height - o_texture->getHeight()) / 4.f);
				//exit_texture->renderscreen((screen_width - exit_texture->getWidth()) / 2.f, (screen_height - exit_texture->getHeight()) / 1.f);


				/*
				float grid_width = 300.f;
				float grid_height = 300.f;

				float cell_width = grid_width / 2.f;
				float cell_height = grid_height / 2.f;

				float grid_x = (screen_width - grid_width) / 2.f;
				float grid_y = (screen_height - grid_height) / 2.f;

				// Top-left
				currentTexture->renderscreen(
					grid_x + 0 * cell_width + (cell_width - currentTexture->getWidth()) / 2.f,
					grid_y + 0 * cell_height + (cell_height - currentTexture->getHeight()) / 2.f
				);

				// Top-right
				x_texture->renderscreen(
					grid_x + 1 * cell_width + (cell_width - x_texture->getWidth()) / 2.f,
					grid_y + 0 * cell_height + (cell_height - x_texture->getHeight()) / 2.f
				);

				// Bottom-left
				o_texture->renderscreen(
					grid_x + 0 * cell_width + (cell_width - o_texture->getWidth()) / 2.f,
					grid_y + 1 * cell_height + (cell_height - o_texture->getHeight()) / 2.f
				);

				// Bottom-right
				exit_texture->renderscreen
				(
					grid_x + 1 * cell_width + (cell_width - exit_texture->getWidth()) / 2.f,
					grid_y + 1 * cell_height + (cell_height - exit_texture->getHeight()) / 2.f
				);*/


				//Update screen
				SDL_RenderPresent(renderer);


				SDL_RenderPresent(renderer);

				SDL_FillSurfaceRect(winSurface, nullptr, color);
				SDL_BlitSurface(Test_surface, nullptr, winSurface, nullptr);
				SDL_UpdateWindowSurface(window);

			}

		}
	}

	Destroy_Window();
	//return exitcode;
}


