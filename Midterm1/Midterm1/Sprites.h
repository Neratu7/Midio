
#include "Game.h"
#include <string>
#include "SDL2-2.0.8\include\SDL.h"

//using namespace Game;


namespace Sprite
{
	struct sprite_pos
	{
		int x = Game::screen_width / 2;
		int y = Game::screen_height / 2;
	};
	struct sprite_size
	{
		int w = 32;
		int h = 50;
	};
	struct sprite_info
	{
		const char* path;
		int frame = 0;
	};
	struct sprite_vel
	{
		float vx = 0;
		float vy = 0;
	};
	struct sprite_extra
	{
		int TTL = 10;
		bool state = true;
	};

	//struct sprite_type
	//{
	//	string path = "Art\\run.png";
	//	int ffx = 0;
	//	int ffy = 0;
	//	int fw = 108;
	//	int fh = 140;
	//	int n_frames = 8;
	//	int frame_duration = 100;
	//	int current_frame = 0;
	//	SDL_Texture *texture = NULL;
	//};

	struct sprite_type
	{
		std::string path = "Art\\run.png";
		int ffx = 0;
		int ffy = 0;
		int fw = 108;
		int fh = 140;
		int n_frames = 8;
		int frame_duration = 100;
		int current_frame = 0;
		SDL_Texture *texture = NULL;
		int number = 0;
	};

	

	void easySprite(Sprite::sprite_type, Sprite::sprite_info, Sprite::sprite_pos, Sprite::sprite_size);
	

}

//void easySprite(Sprite::sprite_type, Sprite::sprite_info, Sprite::sprite_pos, Sprite::sprite_size);

void Sprite::easySprite(Sprite::sprite_type type, Sprite::sprite_info info, Sprite::sprite_pos pos, Sprite::sprite_size size)
//void easySprite(Sprite::sprite_type type, Sprite::sprite_info info, Sprite::sprite_pos pos, Sprite::sprite_size size)
{

	//SDL_Texture *runTexture = TexLoader::TexLoad(info.path);


	if (type.number == 0)
	{

		Game::Ssrc.x = type.ffx + (info.frame * type.fw);
		Game::Ssrc.y = type.ffy;
		Game::Ssrc.w = type.fw;
		Game::Ssrc.h = type.fh;

	}
	if (info.path == "Art\\Sprites\\whale.png")
	{

		Game::Ssrc.x = type.ffx + (info.frame * type.fw);
		Game::Ssrc.y = type.ffy;
		Game::Ssrc.w = type.fw;
		Game::Ssrc.h = type.fh;

	}
	if (info.path == "Art\\magic.png")
	{

		Game::Ssrc.x = type.ffx + (info.frame * type.fw);
		Game::Ssrc.y = type.ffy;
		Game::Ssrc.w = type.fw;
		Game::Ssrc.h = type.fh;

	}
	else
	{

		Game::Ssrc.x = type.ffx + (info.frame * type.fw);
		Game::Ssrc.y = type.ffy;
		Game::Ssrc.w = type.fw;
		Game::Ssrc.h = type.fh;

	}

	Game::Sdest.x = pos.x;
	Game::Sdest.y = pos.y;
	Game::Sdest.w = size.w;
	Game::Sdest.h = size.h;



	//cout << info.frame * type.fw << " " << type.fw << endl;

	SDL_SetRenderDrawColor(Game::renderer, 33, 33, 33, 33);
	SDL_RenderCopyEx(Game::renderer, type.texture, &Game::Ssrc, &Game::Sdest, 0, NULL, SDL_FLIP_NONE);
	//SDL_DestroyTexture(type.texture);

}

void Animate()
{

}

//type.path = "Art\\run.png";
//type.ffx = 0;
//type.ffy = 0;
//type.fw = 108;
//type.fh = 140;
//type.n_frames = 8;
//type.frame_duration = 100;
//type.current_frame = 0;
//type.texture = NULL;
//type.number = 0;



void ArtInit(Sprite::sprite_type type)
{

	switch (type.number)
	{
		case 0: 
		{
			type.path = "Art\\run.png";
			type.ffx = 0;
			type.ffy = 0;
			type.fw = 108;
			type.fh = 140;
			type.n_frames = 8;
			type.frame_duration = 100;
			type.current_frame = 0;
			type.texture = NULL;
			type.number = 0;
		}

		case 1:
		{
			type.path = "Art\\magic.png";
			type.ffx = 653;
			type.ffy = 70;
			type.fw = 30;
			type.fh = 73;
			type.n_frames = 4;
			type.frame_duration = 100;
			type.current_frame = 0;
			type.texture = NULL;
			type.number = 1;
		}

		case 2:
		{
			type.path = "Art\\magic_ball.png";
			type.ffx = 0;
			type.ffy = 0;
			type.fw = 108;
			type.fh = 140;
			type.n_frames = 8;
			type.frame_duration = 100;
			type.current_frame = 0;
			type.texture = NULL;
			type.number = 2;
		}

		case 3:
		{
			type.path = "Art\\run.png";
			type.ffx = 0;
			type.ffy = 0;
			type.fw = 108;
			type.fh = 140;
			type.n_frames = 8;
			type.frame_duration = 100;
			type.current_frame = 0;
			type.texture = NULL;
			type.number = 3;
		}

		case 4:
		{
			type.path = "Art\\run.png";
			type.ffx = 0;
			type.ffy = 0;
			type.fw = 108;
			type.fh = 140;
			type.n_frames = 8;
			type.frame_duration = 100;
			type.current_frame = 0;
			type.texture = NULL;
			type.number = 4;
		}

		case 5:
		{
			type.path = "Art\\run.png";
			type.ffx = 0;
			type.ffy = 0;
			type.fw = 108;
			type.fh = 140;
			type.n_frames = 8;
			type.frame_duration = 100;
			type.current_frame = 0;
			type.texture = NULL;
			type.number = 5;
		}

	}
}



//void easySprite(Sprite::sprite_type type, Sprite::sprite_info info, Sprite::sprite_pos pos, Sprite::sprite_size size)
////void easySprite(Sprite::sprite_type type, Sprite::sprite_info info, Sprite::sprite_pos pos, Sprite::sprite_size size)
//{
//
//	//SDL_Texture *runTexture = TexLoader::TexLoad(info.path);
//
//
//	if (info.path == "Art\\run.png")
//	{
//
//		TexLoader::Ssrc.x = type.ffx + (info.frame * type.fw);
//		TexLoader::Ssrc.y = type.ffy;
//		TexLoader::Ssrc.w = type.fw;
//		TexLoader::Ssrc.h = type.fh;
//
//	}
//	if (info.path == "Art\\Sprites\\whale.png")
//	{
//
//		TexLoader::Ssrc.x = type.ffx + (info.frame * type.fw);
//		TexLoader::Ssrc.y = type.ffy;
//		TexLoader::Ssrc.w = type.fw;
//		TexLoader::Ssrc.h = type.fh;
//
//	}
//	if (info.path == "Art\\magic.png")
//	{
//
//		TexLoader::Ssrc.x = type.ffx + (info.frame * type.fw);
//		TexLoader::Ssrc.y = type.ffy;
//		TexLoader::Ssrc.w = type.fw;
//		TexLoader::Ssrc.h = type.fh;
//
//	}
//	else
//	{
//
//		TexLoader::Ssrc.x = type.ffx + (info.frame * type.fw);
//		TexLoader::Ssrc.y = type.ffy;
//		TexLoader::Ssrc.w = type.fw;
//		TexLoader::Ssrc.h = type.fh;
//
//	}
//
//	TexLoader::Sdest.x = pos.x;
//	TexLoader::Sdest.y = pos.y;
//	TexLoader::Sdest.w = size.w;
//	TexLoader::Sdest.h = size.h;
//
//
//
//	//cout << info.frame * type.fw << " " << type.fw << endl;
//
//	SDL_SetRenderDrawColor(Game::renderer, 33, 33, 33, 33);
//	SDL_RenderCopyEx(Game::renderer, type.texture, &TexLoader::Ssrc, &TexLoader::Sdest, 0, NULL, SDL_FLIP_NONE);
//	//SDL_DestroyTexture(type.texture);
//
//}