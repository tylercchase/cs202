#include <iostream>
#include <SDL2/SDL.h>

#include <string>
#include <cmath>
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;


bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        SDL_SetWindowFullscreen(gWindow,SDL_WINDOW_FULLSCREEN);
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				// int imgFlags = IMG_INIT_PNG;
				// if( !( IMG_Init( imgFlags ) & imgFlags ) )
				// {
				// 	printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
				// 	success = false;
				// }
			}
		}
	}

	return success;
}

void close()
{
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}
int main(int argc, char* args[]) {

    if(!init()){
        std::cout << "Failed to init" << std::endl;
    }else{
        bool quit = false;
        SDL_Event KeyPress;
        
        while(!quit){
            while (SDL_PollEvent(&KeyPress) != 0)
            {
                if( KeyPress.type == SDL_QUIT )
					{
						quit = true;
					}
                switch (KeyPress.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    quit = true;
                    break;
                
                default:
                    break;
                }
            }
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
			SDL_RenderClear( gRenderer );

            SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
			SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );		
			SDL_RenderFillRect( gRenderer, &fillRect );

            SDL_RenderPresent( gRenderer );
        }
    }

    close();
    return 0;
}
