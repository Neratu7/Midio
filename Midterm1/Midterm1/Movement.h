

namespace Movement
{
	void NPCvel(Sprite::sprite_vel &vel);
	void NPCmove(Sprite::sprite_pos &pos, Sprite::sprite_vel &vel);
	void NPCdance(Sprite::sprite_pos &pos, Sprite::sprite_vel &vel);
	void NPCerratic(Sprite::sprite_vel &vel);
	void NatMovement(Sprite::sprite_vel vel, Sprite::sprite_pos &pos, Sprite::sprite_size size);
	void runLeft(Sprite::sprite_vel &vel);
	void runRight(Sprite::sprite_vel &vel);
	void jump(Sprite::sprite_vel &vel);
	void NatVel(Sprite::sprite_vel &vel);
	void gravity(Sprite::sprite_vel &vel);

	Sprite::sprite_vel NPCvel(Sprite::sprite_vel);


	float accel = 1;
	float f_friction = 1;

}


void Movement::NPCvel(Sprite::sprite_vel &vel)
{
	int derk = (rand() % 5);

	if (derk < 3)
	{
		vel.vx = (vel.vx - 20);
		vel.vy = (vel.vy - 10);
	}

	else //if ((rand() % 5) >= 3)
	{
		vel.vx = (vel.vx + 10);
		vel.vy = (vel.vy + 10);
	}

	if (vel.vx > 20 || vel.vx < 20)
	{
		vel.vx = 5;
	}
	if (vel.vy > 20 || vel.vy < 20)
	{
		vel.vy = -1;
	}
}
void Movement::NPCmove(Sprite::sprite_pos &pos, Sprite::sprite_vel &vel)
{

	int dno = rand() % 3;

	switch (dno)
	{
	case 1: runLeft(vel); break;
	case 2: runRight(vel); break;
	case 3: jump(vel); break;
	}
}
void Movement::NPCdance(Sprite::sprite_pos &pos, Sprite::sprite_vel &vel)
{
	int dno = rand() % 5;


	switch (dno)
	{
	case 1: runLeft(vel); break;
	case 2: runRight(vel); break;
	default: jump(vel); break;

	}
	std::cout << "Leaving Dance with Vel " << vel.vy << std::endl;

}
void Movement::NPCerratic(Sprite::sprite_vel &vel)
{
	vel.vx = vel.vx + (((rand() % 101) - 51) / 10);
	vel.vy = vel.vy + (((rand() % 101) - 41) / 10);
}



void Movement::NatMovement(Sprite::sprite_vel vel, Sprite::sprite_pos &pos, Sprite::sprite_size size)
{
	pos.x = pos.x + vel.vx;
	pos.y = pos.y + vel.vy;

	/////////////// BOUNDING BOX BEGIN//////////////////
	if (((pos.y + size.h) > (Game::screen_height)) || (pos.y < 0))
	{
		pos.y = (Game::screen_height / 2) - size.h;
	}
	else if (((pos.x + size.w) > Game::screen_width) || (pos.x < 0))
	{
		pos.x = (Game::screen_width / 2) - size.w;
	}
	/////////////// BOUNDING BOX END///////////////////

	if (((pos.y + size.h) > 544))
	{
		(pos.y ) = 554 - size.h;
	}

	if (((pos.y + size.h) > 530) && (pos.x + size.w > 470) )
	{
		(pos.y) = 524 - size.h;
	}
	/////////////LAZY FLOOR///////////////









}

void Movement::runLeft(Sprite::sprite_vel &vel)
{
	vel.vx = vel.vx - 10;
}
/////////////////////////////////
void Movement::runRight(Sprite::sprite_vel &vel)
{
	vel.vx = vel.vx + 10;
}
////////////////////////////////
void Movement::jump(Sprite::sprite_vel &vel)
{
	if (vel.vy == 0)
	{
		vel.vy = vel.vy - 30;
	}
	std::cout << "JUMP with Vel " << vel.vy << std::endl;
}


void Movement::NatVel(Sprite::sprite_vel &vel)
{
	if (vel.vx != 0)
		if (vel.vx < 0)
		{
			vel.vx = vel.vx + Movement::f_friction;
		}
		else
		{
			vel.vx = vel.vx - Movement::f_friction;
		}
	vel.vy = vel.vy + Movement::accel;

	if (vel.vx > 20)
		vel.vx = 20;
	if (vel.vy > 20)
		vel.vy = 20;
	if (vel.vx < -20)
		vel.vx = -20;
	if (vel.vy < -100)
		vel.vy = -100;
}

void Movement::gravity(Sprite::sprite_vel &vel)
{
	if ((vel.vx + Movement::accel)>0)
	{
		vel.vy = (vel.vy + Movement::accel);
	}
}

