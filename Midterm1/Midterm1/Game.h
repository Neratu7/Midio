#ifndef Game_hpp
#pragma once


#include "SDL2-2.0.8\include\SDL.h"
#include "SDL2-2.0.8\include\SDL_image.h"


namespace Game
{


	SDL_Rect Ssrc = { NULL,NULL };;
	SDL_Rect Sdest = { NULL,NULL };
	SDL_Renderer *renderer;
	int screen_width = 960;
	int screen_height = 768;
	unsigned char *key_state = NULL;;
	unsigned char prev_key_state[256];
	unsigned char *keys = (unsigned char*)SDL_GetKeyboardState(NULL);
	// unsigned char* SDL_GetKeyboardState(NULL);
	double t1, t2, t3, Tdelay;


	SDL_Window *window = SDL_CreateWindow(
		"Fortnite",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		screen_width, screen_height, SDL_WINDOW_SHOWN);



	void initialize();
	void end();
	void getkeystate();
	void FPSstart();
	void FPSend(int);
	SDL_Texture* TexLoad(const char*);


		//	SDL_Init(SDL_INIT_VIDEO);
		//	IMG_Init(IMG_INIT_JPG);
		//	srand(time(0));
		//
		//
		//	Ssrc = { NULL,NULL };
		//	Sdest = { NULL,NULL };
		//	*renderer;
		//	screen_width = 960;
		//	screen_height = 768;
		//	*key_state = NULL;
		//	prev_key_state[256];
		//	*keys = (unsigned char)SDL_GetKeyboardState(NULL);
		//	t1 = NULL, t2 = NULL, t3 = NULL, Tdelay = NULL;
		//
		//
		//	window = SDL_CreateWindow(
		//		"Fortnite",
		//		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		//		screen_width, screen_height, SDL_WINDOW_SHOWN);



}

void Game::initialize()
{
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_JPG);
	srand(time(0));
}



SDL_Texture* Game::TexLoad(const char* path) //loads texture from path given, then returns texture
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path);
	newTexture = SDL_CreateTextureFromSurface(Game::renderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);

	return newTexture;
}

void Game::end()
{
	SDL_DestroyRenderer(Game::renderer);
	SDL_DestroyWindow(Game::window);
	Game::renderer = NULL;
	Game::window = NULL;

	IMG_Quit();
	SDL_Quit();
}

void Game::getkeystate()
{
	Game::key_state = (unsigned char*)SDL_GetKeyboardState(NULL);
}

void Game::FPSend(int i)
{
	Tdelay = 1000 / i;
	t2 = SDL_GetTicks();
	t3 = t2 - t1;


	if (Tdelay > t3)
	{
		SDL_Delay(Tdelay - t3);
	}
}

void Game::FPSstart()
{
	t1 = SDL_GetTicks();
}

#endif Game_hpp;

//#ifndef Game_hpp
//#pragma once
//
//#include "Game.h"
//#include "SDL2-2.0.8\include\SDL.h"
//#include "SDL2-2.0.8\include\SDL_image.h"
//#include <chrono>
//
//
//using namespace std;
////using namespace Game;
//
//
//
//
//
//void Game::initialize()
//{
//	SDL_Init(SDL_INIT_VIDEO);
//	IMG_Init(IMG_INIT_JPG);
//	srand(time(0));
//
//
//	Ssrc = { NULL,NULL };
//	Sdest = { NULL,NULL };
//	*renderer;
//	screen_width = 960;
//	screen_height = 768;
//	*key_state = NULL;
//	prev_key_state[256];
//	*keys = (unsigned char)SDL_GetKeyboardState(NULL);
//	t1 = NULL, t2 = NULL, t3 = NULL, Tdelay = NULL;
//
//
//	window = SDL_CreateWindow(
//		"Fortnite",
//		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
//		screen_width, screen_height, SDL_WINDOW_SHOWN);
//}
//
//
//
//SDL_Texture* TexLoad(const char* path) //loads texture from path given, then returns texture
//{
//	SDL_Texture* newTexture = NULL;
//	SDL_Surface* loadedSurface = IMG_Load(path);
//	newTexture = SDL_CreateTextureFromSurface(Game::renderer, loadedSurface);
//	SDL_FreeSurface(loadedSurface);
//
//	return newTexture;
//}
//
//void Game::end()
//{
//	SDL_DestroyRenderer(Game::renderer);
//	SDL_DestroyWindow(Game::window);
//	Game::renderer = NULL;
//	Game::window = NULL;
//
//	IMG_Quit();
//	SDL_Quit();
//}
//
//void Game::getkeystate()
//{
//	Game::key_state = (unsigned char*)SDL_GetKeyboardState(NULL);
//}
//
//void Game::FPSend(int i)
//{
//	Tdelay = 1000 / i;
//	t2 = SDL_GetTicks();
//	t3 = t2 - t1;
//
//
//	if (Tdelay > t3)
//	{
//		SDL_Delay(Tdelay - t3);
//	}
//}
//
//void Game::FPSstart()
//{
//	t1 = SDL_GetTicks();
//}
//
//#endif Game_hpp;