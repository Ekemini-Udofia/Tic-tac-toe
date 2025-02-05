
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <string>
#include <SDL3_image/SDL_image.h>
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
			/*int flags = IMG_INIT_JPG | IMG_INIT_PNG;
			int innitialize_img = IMG_Init(flags);
			if (!(innitialize_img & flags))
			{
				SDL_Log("SDL_image could not initialize! SDL_image error: %s\n", SDL_GetError());
				success = false;
			}*/
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
	else
	{
		if (!tic_Button.loadFromFile("App_Resources/SDL3_New_Game_Button.png"))
		{
			SDL_Log("Unable to load png image!\n");
		}


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
		if (!load_media())
		{
			SDL_Log("Failed to load media. SDL Error %s\n");
			exitcode = 2;
		}
		else
		{
			if (!load_media())
			{
				SDL_Log("Unable to load media!\n");
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
					SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
					SDL_RenderClear(renderer);

					tic_Button.renderscreen(0.f, 0.f);

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

