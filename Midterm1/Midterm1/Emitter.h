




namespace Emitter
{
	void ParticleSpawn(Sprite::sprite_extra &extra, Sprite::sprite_pos &pos, Sprite::sprite_pos emit_pos);
}


/*
namespace Emitter
{
struct part_pos
{
int x;
int y;
};

struct part_vel
{
int vx;
int vy;
};

struct part_size
{
int w;
int h;
};

struct part_info
{
const char* path;//SDL_Rect shape;
int TTL;
};

struct part_type
{
string path = "Art\\magic.png";
int ffx = 0;
int ffy = 0;
int fw = 108;
int fh = 140;
int n_frames = 8;
int frame_duration = 100;
};

struct emit_pos
{
int x;
int y;
};

struct emit_vel
{
int vx;
int vy;
};

struct emit_info
{
const char* path;
int amount[10];
int timing;
};

struct emit_size
{
int w;
int h;
};

struct emit_type
{
string path = "Art\\magic_ball.png";
int ffx = 0;
int ffy = 0;
int fw = 108;
int fh = 140;
int n_frames = 8;
int frame_duration = 100;
};
}
*/

///////////////////////////////PARTICLE STUFF/////////////////////
//namespace Particle_Emitter
//{
//
//	struct Particle_Emitter
//	{
//		Vec2D *pos;
//		Vec2D *force;
//		Vec2D *vel;
//		float *life;
//		int *state;
//		int n_particles;
//
//		float emitter_mass;
//		float particle_mass;
//		Vec2D emitter_pos;
//		Vec2D emitter_force;
//		Vec2D emitter_vel;
//
//		RGB particle_color;
//		float particle_size;
//	};
//
//	struct Vec2D
//	{
//		float x = NULL;
//		float y = NULL;
//	};
//
//	struct RGB
//	{
//		unsigned char r = NULL, g = NULL, b = NULL;
//	};
//
//	void init(Particle_Emitter *p, int n_particles)
//	{
//		p->n_particles = n_particles;
//
//		//allocations
//		p->pos = new Vec2D[p->n_particles];
//		p->force = new Vec2D[p->n_particles];
//		p->vel = new Vec2D[p->n_particles];
//		p->life = new float[p->n_particles];
//		p->state = new int[p->n_particles];
//
//		memset(p->pos, 0, sizeof(Vec2D)*p->n_particles);
//		memset(p->force, 0, sizeof(Vec2D)*p->n_particles);
//		memset(p->vel, 0, sizeof(Vec2D)*p->n_particles);
//		memset(p->life, 0, sizeof(float)*p->n_particles);
//		memset(p->state, 0, sizeof(int)*p->n_particles);
//
//		p->emitter_force = {};
//		p->emitter_vel = {};
//		p->emitter_pos = { 50,50 };//TODO
//		p->particle_color = { 165,75,0 };
//		p->particle_size = 4.0;
//		p->emitter_mass = 1.0;
//		p->particle_mass = 0.1;
//
//	}
//
//	void spawn_Many(Particle_Emitter *p, Vec2D influence_min, Vec2D influence_max, int how_many, float min_life, float max_life)
//	{
//		for (int i = 0; i < p->n_particles; i++)
//		{
//			if (p->state[i] == 0)
//			{
//				if (--how_many < 0) break;//TODO
//
//				p->state[i] = 1;
//
//				p->pos[i] = p->emitter_pos;
//				p->vel[i] = p->emitter_vel;
//				p->life[i] = min_life + (max_life - min_life)*rand() / RAND_MAX;
//				p->force[i] = {};
//
//				p->force[i].x += influence_min.x + (influence_max.x - influence_min.x)*rand() / RAND_MAX;
//				p->force[i].y += influence_min.y + (influence_max.y - influence_min.y)*rand() / RAND_MAX;
//			}
//		}
//	}
//	void clear_Forces_from_Particles(Particle_Emitter *p)
//	{
//		for (int i = 0; i < p->n_particles; i++)
//		{
//			if (p->state[i] != 0) p->force[i] = {};
//		}
//	}
//
//	void add_Force_to_Particles(Particle_Emitter *p, Vec2D f)
//	{
//		for (int i = 0; i < p->n_particles; i++)
//		{
//			if (p->state[i] != 0)
//			{
//				p->force[i].x += f.x;
//				p->force[i].y += f.y;
//			}
//		}
//	}
//
//	void update(Particle_Emitter *p, float time_elapsed)
//	{
//		//implicit euler, mass=1.0
//		Vec2D accel;
//		accel.x = p->emitter_force.x / p->emitter_mass;
//		accel.y = p->emitter_force.y / p->emitter_mass;
//
//		p->emitter_vel.x += accel.x*time_elapsed;
//		p->emitter_vel.y += accel.y*time_elapsed;
//		p->emitter_pos.x += p->emitter_vel.x*time_elapsed;
//		p->emitter_pos.y += p->emitter_vel.y*time_elapsed;
//
//		for (int i = 0; i < p->n_particles; i++)
//		{
//			if (p->state[i] == 0) continue;
//
//			p->life[i] -= time_elapsed;
//			if (p->life[i] <= 0.0)
//			{
//				p->state[i] = 0;
//				continue;
//			}
//
//			Vec2D accel;
//			accel.x = p->force[i].x / p->particle_mass;
//			accel.y = p->force[i].y / p->particle_mass;
//			p->vel[i].x += accel.x*time_elapsed;
//			p->vel[i].y += accel.y*time_elapsed;
//			p->pos[i].x += p->vel[i].x*time_elapsed;
//			p->pos[i].y += p->vel[i].y*time_elapsed;
//		}
//	}
//
//	void draw(Particle_Emitter *p, SDL_Renderer *renderer)
//	{
//		SDL_SetRenderDrawColor(renderer, p->particle_color.r, p->particle_color.g, p->particle_color.b, 255);
//		for (int i = 0; i < p->n_particles; i++)
//		{
//			if (p->state[i] == 0) continue;
//
//			SDL_Rect rect = { p->pos[i].x,p->pos[i].y,p->particle_size, p->particle_size };
//			SDL_RenderFillRect(renderer, &rect);
//		}
//	}
//
//
//
//}


/// ////MORE PARTICLE/////////////////////
/*
Particle_Emitter::Particle_Emitter rocket;
Particle_Emitter::init(&rocket, 200);
rocket.emitter_pos.x = Game::screen_width / 2.0;
rocket.emitter_pos.y = Game::screen_height / 2.0;


Particle_Emitter::Particle_Emitter sparks_small;
Particle_Emitter::init(&sparks_small, 50);
sparks_small.particle_color = { 120,180,0 };
sparks_small.particle_size = 4;
sparks_small.particle_mass = 0.25;

Particle_Emitter::Vec2D f_gravity = { 0.0,0.00005 };

sparks_small.emitter_force = {};
Particle_Emitter::clear_Forces_from_Particles(&sparks_small);

rocket.emitter_force.x += f_gravity.x;
rocket.emitter_force.y += f_gravity.y;

Particle_Emitter::add_Force_to_Particles(&sparks_small, f_gravity);


Particle_Emitter::update(&sparks_small, 1.0);

SDL_SetRenderDrawColor(Game::renderer, 255, 0, 255, 255);
SDL_Rect rect = { rocket.emitter_pos.x,rocket.emitter_pos.y,5,5 };
SDL_RenderFillRect(Game::renderer, &rect);

Particle_Emitter::draw(&sparks_small, Game::renderer);
*/
/// /////////END MORE PARTICLE////////////////




void ParticleSpawn(Sprite::sprite_extra &extra, Sprite::sprite_pos &pos, Sprite::sprite_pos emit_pos)
{
	if (extra.TTL > 0)
	{
		extra.TTL = extra.TTL - rand() % 3;
	}
	if (extra.TTL <= 0)
	{
		extra.state = false;
	}

	if (extra.state == false)
	{
		pos.x = emit_pos.x;
		pos.y = emit_pos.y;
		extra.state = true;
		extra.TTL = 30;
	}
}