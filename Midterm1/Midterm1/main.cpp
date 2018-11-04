#ifndef _CRT_SECURE_NO_WARNINGS, Game_hpp
#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <iostream>
#include <assert.h>
#include <time.h>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <string.h>
#include <array>

#include "SDL2-2.0.8\include\SDL_mixer.h"
#include "SDL2-2.0.8\include\SDL.h"
#include "SDL2-2.0.8\include\SDL_image.h"
#include "Table_File_core.h"
#include "Table_File_data.h"


#pragma comment(lib,"SDL2-2.0.8\\lib\\x86\\SDL2.lib")
#pragma comment(lib,"SDL2-2.0.8\\lib\\x86\\SDL2main.lib")
#pragma comment(lib,"SDL2-2.0.8\\lib\\x86\\SDL2_image.lib")
#pragma comment(linker,"/subsystem:console")

//#include "Game.h"
#include "Sprites.h"
#include "Tiles.h"
#include "Music.h"
#include "Movement.h"
#include "Emitter.h"

using namespace std;


///////////////////////////////PARTICLE STUFF/////////////////////



//void ParticleSpawn(Sprite::sprite_extra &extra, Sprite::sprite_pos &pos, Sprite::sprite_pos);

unsigned int last_frame_change_time = 0;

int music_channel = 1;
bool day = true;



int main(int argc, char **argv)
{

	Mix_Init;
	SDL_ShowCursor(SDL_DISABLE);
	SDL_Init(SDL_INIT_AUDIO);


	Game::renderer = SDL_CreateRenderer(Game::window, -1, SDL_RENDERER_ACCELERATED);//renderer for game

//	unsigned char prev_key_state[256];
//	unsigned char *keys = (unsigned char*)SDL_GetKeyboardState(NULL);

	srand(time(0));
	Tile::PullMap();

	//////SPRITES/////
	int num_guy = 7;

	Sprite::sprite_pos *guy_pos = new Sprite::sprite_pos[num_guy];
	Sprite::sprite_size *guy_size = new Sprite::sprite_size[num_guy];
	Sprite::sprite_vel *guy_vel = new Sprite::sprite_vel[num_guy];
	Sprite::sprite_info *guy_info = new Sprite::sprite_info[num_guy];
	Sprite::sprite_type *guy_type = new Sprite::sprite_type[num_guy];
	//////SPRITE END/// RELY ON DEFAULTS




	////////BACKGROUND OBJECTS/////////////////////////////////
	int num_sprites = 10;

	Sprite::sprite_pos *bg_pos = new Sprite::sprite_pos[num_sprites];
	Sprite::sprite_size *bg_size = new Sprite::sprite_size[num_sprites];
	Sprite::sprite_vel *bg_vel = new Sprite::sprite_vel[num_sprites];
	Sprite::sprite_info *bg_info = new Sprite::sprite_info[num_sprites];
	Sprite::sprite_type *bg_type = new Sprite::sprite_type[num_sprites];
	//////// INIT OBJECTS

	bg_pos[0] = { Game::screen_width / 2, 0 };
	bg_size[0] = { 128,128 };
	bg_info[0] = { "Art\\Background\\sun.png", 0 };
	bg_type[0] = { "Art\\Background\\sun.png", 0, 0, 512,512,1,100,0, Game::TexLoad(bg_info[0].path) };

	bg_pos[1] = { 0, 0 };
	bg_size[1] = { 960,750 };
	bg_info[1] = { "Art\\Background\\8320.jpg", 0 };
	bg_type[1] = { "Art\\Background\\8320.jpg", 0, 0, 2056,2056,1,100,0,  Game::TexLoad(bg_info[1].path) };//night || stars

	bg_pos[2] = { (Game::screen_width / 2 - 100), 0 };
	bg_size[2] = { 128,128 };
	bg_info[2] = { "Art\\Background\\moon.jpg", 0 };
	bg_type[2] = { "Art\\Background\\moon.jpg", 0, 0, 5020,5020,1,100 ,0,  Game::TexLoad(bg_info[2].path) };

	bg_pos[3] = { 0, 0 };
	bg_size[3] = { 960,750 };
	bg_info[3] = { "Art\\Background\\tree_sky.jpg", 0 };
	bg_type[3] = { "Art\\Background\\tree_sky.jpg", 0, 0, 5020,5020,1,100,0,  Game::TexLoad(bg_info[3].path) };





	/////////BACKGROUND END//////////////////////

	////////////////EMITTER BEGIN//////////////////

	int partNum = 30;
	int emitNum = 3;

	Sprite::sprite_pos *PEmit_pos = new Sprite::sprite_pos[emitNum];
	Sprite::sprite_size *PEmit_size = new Sprite::sprite_size[emitNum];
	Sprite::sprite_vel *PEmit_vel = new Sprite::sprite_vel[emitNum];
	Sprite::sprite_info *PEmit_info = new Sprite::sprite_info[emitNum];
	Sprite::sprite_type *PEmit_type = new Sprite::sprite_type[emitNum];

	Sprite::sprite_pos *part_pos = new Sprite::sprite_pos[partNum];
	Sprite::sprite_size *part_size = new Sprite::sprite_size[partNum];
	Sprite::sprite_vel *part_vel = new Sprite::sprite_vel[partNum];
	Sprite::sprite_info *part_info = new Sprite::sprite_info[partNum];
	Sprite::sprite_type *part_type = new Sprite::sprite_type[partNum];
	Sprite::sprite_extra *part_extra = new Sprite::sprite_extra[partNum];

	////////////EMITTER INIT/////////////

	PEmit_pos[0] = { 200 , 200 };
	PEmit_vel[0] = { 0 ,0 };
	PEmit_size[0] = { 50,50 };
	PEmit_info[0] = { "Art\\magic_ball.png" , 0 };
	PEmit_type[0] = { "Art\\magic_ball.png", 30, 30, 50,50,1,100,0, Game::TexLoad(PEmit_info[0].path) };


	for (int i = 0; i < partNum; i++)
	{
		part_pos[i] = { PEmit_pos[0].x,PEmit_pos[0].y }; // PEmit_pos[0].x,PEmit_pos[0].y 
		part_vel[i] = { 0,  -5 };
		part_extra[i] = { 30, true };
		part_size[i] = { part_extra[i].TTL , part_extra[i].TTL };
		part_info[i] = { "Art\\magic.png", 5 };
		part_type[i] = { "Art\\magic.png", 30, 430, 40,60,5,100,0,  Game::TexLoad(part_info[i].path) };//40 60   430
		
	}
	cout << "noise" << endl;
	////////////////EMITTER END///////////////

	///////////MUSIC AND SOUND///////////////

	static const char *chill = "Art\\Sound\\ChillingMusic.wav";
	static const char *moody = "Art\\Sound\\MoodyLoop.wav";
	static const char *discord = "Art\\Sound\\DiscordToday.wav";
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 2048);
	Mix_Music *music = NULL;
	Mix_Music *music2 = NULL;
	Mix_Music *music3 = NULL;
	music = Mix_LoadMUS(chill);
	music2 = Mix_LoadMUS(moody);
	music3 = Mix_LoadMUS(discord);
	Mix_Chunk *fx = Mix_LoadWAV("Art\\Sound\\coin.wav");
	Mix_VolumeMusic(20);//couldnt get this to work, should dictate sound level.
	Mix_FadeInMusic(music, -1, 1500);

	//////////END INIT MUSIC AND SOUND/////////




	for (int i = 0; i < num_guy; i++)
	{
		guy_info[i] = { "Art\\run.png", 0 };
		//NPC[i] = { "Art\\run.png", 10 , 30 , 110 , 30 , 7 , 15,0, TexLoader::TexLoad(PEmit_info[0].path) };
		guy_size[i] = { 64, 84 };

	}

	 
	guy_type[0] =
	{
		"Art\\run.png",0,0,108,140,8,100,0,Game::TexLoad(guy_info[0].path)
	};

	guy_type[1] =
	{
		"Art\\Sprites\\whale.png",0,0,108,140,8,100,0,Game::TexLoad(guy_info[0].path)
	};

	guy_type[2] =
	{
		"Art\\Sprites\\magic_ball.png",30, 30, 50,50,1,100,0, Game::TexLoad(PEmit_info[0].path)
	};

	guy_type[3] =
	{
		"Art\\Sprites\\magic.png", 30, 430, 40,60,5,50,0,  Game::TexLoad(PEmit_info[0].path)
	};

	


	unsigned char *key_state = (unsigned char*)SDL_GetKeyboardState(NULL);
	static unsigned char last_key_state[256];



	int counter = 0;
	bool done = false;
	while (!done)
	{
		Game::FPSstart();

		memcpy(Game::prev_key_state, Game::keys, 256);
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			key_state = Game::prev_key_state;


			memcpy(last_key_state, key_state, 256);
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT || key_state[SDL_SCANCODE_X])
				{
					done = true;
					void end();
				}
			}
			key_state = (unsigned char*)SDL_GetKeyboardState(NULL);


			if (key_state[4] || key_state[SDL_SCANCODE_LEFT])
			{
				guy_pos[0].x = guy_pos[0].x - 10;
				std::cout << "left\n";
				//Mix_PlayChannel(-1, fx, 0);


			}
			else if (key_state[SDL_SCANCODE_D] || key_state[SDL_SCANCODE_RIGHT])
			{
				guy_pos[0].x = guy_pos[0].x + 10;
				std::cout << "right\n";
				//Mix_PlayChannel(-1, fx, 0);
			}
			else if (key_state[SDL_SCANCODE_W] || key_state[SDL_SCANCODE_UP])
			{
				guy_pos[0].y = guy_pos[0].y + 10;
				std::cout << "up\n";
				//Mix_PlayChannel(-1, fx, 0);
			}
			else if (key_state[SDL_SCANCODE_S] || key_state[SDL_SCANCODE_DOWN])
			{

			}
			else if (key_state[SDL_SCANCODE_1])
			{
				if (music_channel != 1)
				{
					Mix_FadeOutMusic(1500);
					Mix_FadeInMusic(music, -1, 2500);
					music_channel = 1;
					day = true;
				}
				else
				{
					Mix_FadeOutMusic(1500);
					music_channel = 0;
				}

			}
			else if (key_state[SDL_SCANCODE_2])
			{
				if ((music_channel != 2) && (music_channel != 0))
				{
					Mix_FadeOutMusic(1500);
					Mix_FadeInMusic(music2, -1, 2500);
					music_channel = 2;
					day = !day;
				}
				else if (music_channel == 0)
				{
					Mix_FadeOutMusic(1500);
					Mix_FadeInMusic(music2, -1, 2500);
					music_channel = 0;
				}
				else
				{
					Mix_FadeOutMusic(1500);
					music_channel = 0;
				}
			}
			else if (key_state[SDL_SCANCODE_3])
			{
				if (music_channel != 3)
				{
					Mix_FadeOutMusic(1500);
					Mix_FadeInMusic(music3, -1, 2500);
					music_channel = 3;
					day = false;
				}
				else
				{
					Mix_FadeOutMusic(1500);
					music_channel = 0;
				}
			}
			else
			{

			}

		}
		unsigned int current_time = SDL_GetTicks();



		














		/////////////Day/Night///////////////////
		if (day)
		{
			Sprite::easySprite(bg_type[3], bg_info[3], bg_pos[3], bg_size[3]);
			Sprite::easySprite(bg_type[0], bg_info[0], bg_pos[0], bg_size[0]);
		}
		if (!day)
		{
			Sprite::easySprite(bg_type[1], bg_info[1], bg_pos[1], bg_size[1]);
			Sprite::easySprite(bg_type[2], bg_info[2], bg_pos[2], bg_size[2]);
		}
		/////////////Day/Night END/////////




		Tile::TilePlacement(Tile::map); // Place Tiles


										////////for loops for sprites/////////////
		for (int i = 0; i < num_guy; i++)
		{

			if ((i > 0) && (music_channel == 1))
			{
				//guy_vel[i] = NPCvel(guy_vel[i]);
				Movement::NPCmove(guy_pos[i], guy_vel[i]);
				guy_info[i].frame++;
				if (guy_info[i].frame == guy_type[0].n_frames)
					guy_info[i].frame = 0;

			}
			if ((i > 0) && (music_channel == 3))
			{
				Movement::NPCdance(guy_pos[i], guy_vel[i]);
			}
			if ((i > 0) && (music_channel == 2))
			{
				Movement::NPCerratic(guy_vel[i]);
			}
			//cout << guy_pos[i].y << " :POS with " << guy_vel[i].vy << " :VEL   " << i << endl;

			Movement::NatVel(guy_vel[i]);
			Movement::NatMovement(guy_vel[i], guy_pos[i], guy_size[i]);

			
			Sprite::easySprite(guy_type[0], guy_info[i], guy_pos[i], guy_size[i]);
			//cout << guy_pos[i].y << " :POS with " << guy_vel[i].vy << " :VEL" << i << endl;

		}

		////////////Emitter////////////////
		///https://natureofcode.com/book/chapter-4-particle-systems
		////

		for (int i = 0; i < partNum; i++)
		{

			ParticleSpawn(part_extra[i], part_pos[i], PEmit_pos[0]);

			Sprite::easySprite(part_type[i], part_info[i], part_pos[i], part_size[i]);

			if (part_info->frame < part_type->n_frames)
				part_info->frame++;
			else
				part_info->frame = 0;


			Movement::NatVel(part_vel[i]);
			Movement::NPCerratic(part_vel[i]);
			part_info[i].frame++;
			if (part_info[i].frame == part_type[i].n_frames)
				part_info[i].frame = 0;


			Movement::NatMovement(part_vel[i], part_pos[i], part_size[i]);

		}



		Sprite::easySprite(PEmit_type[0], PEmit_info[0], PEmit_pos[0], PEmit_size[0]);



		///////////Emitter End////////////




		Game::FPSend(10);
		SDL_RenderPresent(Game::renderer);
		SDL_RenderClear(Game::renderer);
		
	}
	return 0;
}
///////////////////////////////////

//////////////////////////////////
//void Tile::PullMap()
//{
//	ifstream infile("Art\\Again.txt");
//	string line = "";
//	string data;
//
//	int colCount = 1;
//	int rowCount = 1;
//
//	getline(infile, data);
//	for (int i = 0; data[i]; i++)
//	{
//		if (data[i] == ',')
//		{
//			colCount++;
//		}
//	}
//
//	while (getline(infile, data))
//	{
//		rowCount++;
//	}
//
//	infile.clear();//clears EoF flag
//	infile.seekg(0, ios::beg);//goes to beginning file
//
//	Tile::map.resize(rowCount, std::vector<int>(colCount, 0));
//	{
//		string s;


//		for (int j = 0; j < rowCount; j++)
//		{
//			for (int k = 0; k < colCount; k++)
//			{
//				getline(infile, s, ',');
//				Tile::map[j][k] = stoi(s);
//			}
//		}
//		cout << "********** " << rowCount << " **********" << endl;
//		cout << "********** " << colCount << " **********" << endl;
//
//		Tile::rows = rowCount;
//		Tile::cols = colCount;
//	}
//}
///////////////////////////////////
//
//void Tile::TilePlacement(vector<vector<int>> &vect)
//{
//	//int imgFlags = IMG_INIT_PNG;
//
//	SDL_Texture * texture = Game::TexLoad("tile.png");//thing for loading textures
//	SDL_SetRenderDrawColor(Game::renderer, 255, 10, 15, 55);
//
//	int x = 0;
//	int y = 0;
//
//	SDL_Rect src;
//	src.w = 32;
//	src.h = 32;
//
//	SDL_Rect dest;
//	dest.w = 32;
//	dest.h = 32;
//
//
//	for (int k = 0; k < Tile::rows; k++)
//	{
//
//		for (int j = 0; j < Tile::cols; j++)
//		{
//
//			switch (vect[k][j])
//			{
//			case 164: //Sky
//			{
//				x = 117;
//				y = 176;
//
//				//SRC rect
//				src.x = x;
//				src.y = y;
//
//				//DEST rect
//				dest.x = j * 32;
//				dest.y = k * 32;
//				break;
//			}
//
//			case 88:  //Dirt
//			{
//				x = 784;
//				y = 67;
//
//				//SRC rect
//				src.x = x;
//				src.y = y;
//
//				//DEST rect
//				dest.x = j * 32;
//				dest.y = k * 32;
//
//				SDL_RenderCopy(Game::renderer, texture, &src, &dest);
//				break;
//			}
//
//			default: //Oops
//			{
//				x = 99;
//				y = 99;
//				break;
//			}
//			}
//
//			////SRC rect
//			//src.x = x;
//			//src.y = y;
//
//			////DEST rect
//			//dest.x = j * 32;
//			//dest.y = k * 32;
//
//			//SDL_RenderCopy(Game::renderer, texture, &src, &dest);
//
//		}
//	}
//	SDL_DestroyTexture(texture);
//}
/////////////////////////////////

//////////////////////////////////

/////////////////////////////////

//////////////////////////////////


/*



int tileCollide(Sprite::sprite_pos *pos, Sprite::sprite_size *size, Tile::tile_pos *tpos, Tile::tile_size *tsize)
{
	if (pos->x + size->w < tpos->x) return 0;
	if (tpos->x + tsize->w < pos->x) return 0;
	if (pos->y + size->h < tpos->y) return 0;
	if (tpos->y + tsize->h < pos->y) return 0;
	return 1;
}



//minkowski sum
//int tileCollide(Sprite::sprite_pos *pos, Sprite::sprite_size *size, Sprite::sprite_vel *vel, Tile::tile_pos *tpos, Tile::tile_size *tsize)
//{
//	enum { NO_COLLISION = 0, TOP_OF_B, RIGHT_OF_B, BOTTOM_OF_B, LEFT_OF_B };
//
//	float w = 0.5 * (size->w + tsize->w);
//	float h = 0.5 * (size->h + tsize->h);
//	float dx = pos->x - tpos->x + 0.5*(size->w - tsize->w);
//	float dy = pos->y - tpos->y + 0.5*(size->h - tsize->h);
//
//	if (dx*dx <= w * w && dy*dy <= h * h)
//	{
//		float wy = w * dy;
//		float hx = h * dx;
//
//		if (wy > hx)
//		{
//			return (wy + hx > 0) ? BOTTOM_OF_B : LEFT_OF_B;
//		}
//		else
//		{
//			return (wy + hx > 0) ? RIGHT_OF_B : TOP_OF_B;
//		}
//	}
//	return NO_COLLISION;
//}







/*

//if collision is a rare event and direction is important, use this
int collision2(const Box_Pos *pa, const Box_Size *sa, const Box_Pos *pb, const Box_Size *sb)
{
enum { NO_COLLISION = 0, TOP_OF_B, RIGHT_OF_B, BOTTOM_OF_B, LEFT_OF_B};

float w = 0.5 * (sa->w + sb->w);
float h = 0.5 * (sa->h + sb->h);
float dx = pa->x - pb->x + 0.5*(sa->w - sb->w);
float dy = pa->y - pb->y + 0.5*(sa->h - sb->h);

if (dx*dx <= w * w && dy*dy <= h * h)
{
float wy = w * dy;
float hx = h * dx;

if (wy > hx)
{
return (wy + hx > 0) ? BOTTOM_OF_B : LEFT_OF_B;
}
else
{
return (wy + hx > 0) ? RIGHT_OF_B : TOP_OF_B;
}
}
return NO_COLLISION;
}

*/






#endif _CRT_SECURE_NO_WARNINGS , Game_hpp;

