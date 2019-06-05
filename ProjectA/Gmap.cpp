#include "Gmap.h"



Gmap::Gmap ( sf::Texture* texture , sf::Vector2u indeximage , sf::Vector2u imagmaxs, sf::Vector2f mapxy )
{
	this->imagmaxs = imagmaxs;
	this->mapxy = mapxy;
	this->indeximage = indeximage;
	dmap.setPosition ( mapxy );
	dmap.setTexture ( texture );
	dmap.setSize ( sf::Vector2f ( 32.0f , 32.0f ) );
	uvRect.width = texture->getSize ().x / float ( imagmaxs.x );
	uvRect.height = texture->getSize ().y / float ( imagmaxs.y );
}


Gmap::~Gmap ()
{
}

void Gmap::Update ()
{
		uvRect.left = indeximage.x*uvRect.width;
		uvRect.top = indeximage.y*uvRect.height;
		dmap.setTextureRect ( uvRect );
}

void Gmap::Draw ( sf::RenderWindow & window )
{
	Update ();
	window.draw ( dmap );
}