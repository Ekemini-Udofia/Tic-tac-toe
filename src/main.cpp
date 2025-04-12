
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>
#include <SDL3_image/SDL_image.h>


//sets the screen dimensions 
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

class Ltexture {

private:
	SDL_Texture* mTexture;

	int mWidth;

	int mHeight;
public:
	Ltexture();

	~Ltexture();

	bool loadFromFile(std::string path);

	void destroy();;

	void renderscreen(float x, float y);

	int getWidth();

	int getHeight();
};


Ltexture::Ltexture()
{
	mTexture = nullptr;
	mWidth = 0;
	mHeight = 0;
}

Ltexture::~Ltexture()
{
	destroy();
}

bool Ltexture::loadFromFile(std::string path)
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


void Ltexture::destroy()
{
	SDL_DestroyTexture(mTexture);
	mTexture = nullptr;
	mWidth = 0;
	mHeight = 0;
}

void Ltexture::renderscreen(float x, float y)
{
	SDL_FRect dstRect = { x, y, static_cast<float>(mWidth), static_cast<float>(mHeight) };

	SDL_RenderTexture(renderer, mTexture, nullptr, &dstRect);
}

int Ltexture::getWidth()
{
	return mWidth;
}

int Ltexture::getHeight()
{
	return mHeight;
}


Ltexture tic_Button;
Ltexture blank_button, x_button, o_button, exit_button;


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
	if (!blank_button.loadFromFile("res/SDL3_Buttons.png"))
	{
		SDL_Log("Unable to load up image!\n");
	}
	if (!x_button.loadFromFile("res/SDL3_O_Button.png"))
	{
		SDL_Log("Unable to load down image!\n");
	}
	if (!o_button.loadFromFile("res/SDL3_X_Button.png"))
	{
		SDL_Log("Unable to load left image!\n");
	}
	if (!exit_button.loadFromFile("res/SDL3_Exit_Button.png"))
	{
		SDL_Log("Unable to load right image!\n");
	}
	if (!tic_Button.loadFromFile("res/SDL3_New_Game_Button.png"))
	{
		SDL_Log("Unable to load blank image!\n");
	}

	return success;
}


void close()
{
	tic_Button.destroy();

	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;

	//IMG_Quit();
	SDL_Quit();
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
		if (!loadMedia())
		{
			SDL_Log("Failed to load media. SDL Error %s\n", SDL_GetError());
			exitcode = 2;
		}
		else
		{
			if (!loadMedia())
			{
				SDL_Log("Unable to load media!\n");
				exitcode = 2;
			}
			else
			{
				bool quit{ false };
				SDL_Event e;
				SDL_zero(e);
				Ltexture* currentTexture = &blank_button;
				Ltexture* x_texture = &x_button;
				Ltexture* o_texture = &o_button;
				Ltexture* exit_texture = &exit_button;

				SDL_Color bgColor = { 0xFF, 0xFF, 0xFF, 0xFF };
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

					//Render image on screen
					currentTexture->renderscreen((screen_width - currentTexture->getWidth()) / 2.f, (screen_height - currentTexture->getHeight()) / 2.f);
					//x_texture->renderscreen((screen_width - x_texture->getWidth()) / 2.f, (screen_height - x_texture->getHeight()) / 2.f);
					o_texture->renderscreen((screen_width - o_texture->getWidth()) / 2.f, (screen_height - o_texture->getHeight()) / 2.f);
					//exit_texture->renderscreen((screen_width - exit_texture->getWidth()) / 2.f, (screen_height - exit_texture->getHeight()) / 2.f);

					//Update screen
					SDL_RenderPresent(renderer);

					//tic_Button.renderscreen(0.0, 5.0);

					SDL_RenderPresent(renderer);

					SDL_FillSurfaceRect(winSurface, nullptr, color);
					SDL_BlitSurface(Test_surface, nullptr, winSurface, nullptr);
					SDL_UpdateWindowSurface(window);
				}
			}

		}
	}

	Destroy_Window();
	return exitcode;
}

