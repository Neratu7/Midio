



namespace Tile
	{
		struct tile_pos
		{
			int x;
			int y;
		};
		struct tile_size
		{
			int w;
			int h;
		};
		struct tile_info
		{
			unsigned char* path;
			int medium;
		};
	

		std::vector < std::vector <int> > map;
		int rows;
		int cols;

		void PullMap();
		void TilePlacement(std::vector<std::vector<int>> &vect);
		int tileCollide(Sprite::sprite_pos *pos, Sprite::sprite_size *size, Sprite::sprite_vel *vel, Tile::tile_pos *tpos, Tile::tile_size *tsize);
	


	}




void Tile::PullMap()
{
	std::ifstream infile("Art\\Again.txt");
	std::string line = "";
	std::string data;

	int colCount = 1;
	int rowCount = 1;

	std::getline(infile, data);
	for (int i = 0; data[i]; i++)
	{
		if (data[i] == ',')
		{
			colCount++;
		}
	}

	while (getline(infile, data))
	{
		rowCount++;
	}

	infile.clear();//clears EoF flag
	infile.seekg(0, std::ios::beg);//goes to beginning file

	Tile::map.resize(rowCount, std::vector<int>(colCount, 0));
	{
		std::string s;
		for (int j = 0; j < rowCount; j++)
		{
			for (int k = 0; k < colCount; k++)
			{
				getline(infile, s, ',');
				Tile::map[j][k] = stoi(s);
			}
		}
		std::cout << "********** " << rowCount << " **********" << std::endl;
		std::cout << "********** " << colCount << " **********" << std::endl;

		Tile::rows = rowCount;
		Tile::cols = colCount;
	}
}

void Tile::TilePlacement(std::vector<std::vector<int>> &vect)
{
	//int imgFlags = IMG_INIT_PNG;

	SDL_Texture * texture = Game::TexLoad("tile.png");//thing for loading textures
	SDL_SetRenderDrawColor(Game::renderer, 255, 10, 15, 55);

	int x = 0;
	int y = 0;

	SDL_Rect src;
	src.w = 32;
	src.h = 32;

	SDL_Rect dest;
	dest.w = 32;
	dest.h = 32;


	for (int k = 0; k < Tile::rows; k++)
	{

		for (int j = 0; j < Tile::cols; j++)
		{

			switch (vect[k][j])
			{
			case 164: //Sky
			{
				x = 117;
				y = 176;

				//SRC rect
				src.x = x;
				src.y = y;

				//DEST rect
				dest.x = j * 32;
				dest.y = k * 32;
				break;
			}

			case 88:  //Dirt
			{
				x = 784;
				y = 67;

				//SRC rect
				src.x = x;
				src.y = y;

				//DEST rect
				dest.x = j * 32;
				dest.y = k * 32;

				SDL_RenderCopy(Game::renderer, texture, &src, &dest);
				break;
			}

			default: //Oops
			{
				x = 99;
				y = 99;
				break;
			}
			}

			////SRC rect
			//src.x = x;
			//src.y = y;

			////DEST rect
			//dest.x = j * 32;
			//dest.y = k * 32;

			//SDL_RenderCopy(Game::renderer, texture, &src, &dest);

		}
	}
	SDL_DestroyTexture(texture);
}



int Tile::tileCollide(Sprite::sprite_pos *pos, Sprite::sprite_size *size, Sprite::sprite_vel *vel, Tile::tile_pos *tpos, Tile::tile_size *tsize)
{

	enum { NO_COLLISION = 0, TOP_OF_B, RIGHT_OF_B, BOTTOM_OF_B, LEFT_OF_B };

	float w = 0.5 * (size->w + tsize->w);
	float h = 0.5 * (size->h + tsize->h);
	float dx = pos->x - tpos->x + 0.5*(size->w - tsize->w);
	float dy = pos->y - tpos->y + 0.5*(size->h - tsize->h);

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

//////////

