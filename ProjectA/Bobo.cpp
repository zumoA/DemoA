#include "Bobo.h"

Bobo::Bobo ( sf::Vector2f* player ,sf::Vector2f vmapxy )
{
	this->player.x = player->x;
	this->player.y = player->y;
	mapxy = vmapxy;
	pix.x = 64;
	pix.y = 32;
}

Bobo::~Bobo ( )
{
	
}

void Bobo::Update () {
	float rplayer=player.y;
	if ( player.y+pix.x>mapxy.y ||
		player.y<mapxy.y)
	{
		player.y = rplayer;
	}
}
