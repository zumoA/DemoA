#include "Animen.h"


Animen::Animen ( sf::Texture* texture , sf::Vector2u imagmaxs , float switchtime )
{
	this->imagmaxs = imagmaxs;
	this->switchtime = switchtime;
	totatime = 0.0f;
	currentimage.x = 0;
	uvRect.width = texture->getSize ().x / float ( imagmaxs.x );
	uvRect.height = texture->getSize ().y / float ( imagmaxs.y );
}


Animen::~Animen ()
{
} 

void Animen::Update ( int row , float fpstime ,bool imageRight )
{
	currentimage.y = row;
	totatime += fpstime;
	if ( totatime >= switchtime ) {
		totatime -= switchtime;
		currentimage.x++;
		if ( currentimage.x >= imagmaxs.x ) {
			currentimage.x = 0;
		}
	}
	uvRect.top = currentimage.y *= uvRect.height;
	if ( !imageRight ) {
		uvRect.left = currentimage.x*uvRect.width;
		uvRect.width = abs ( uvRect.width );
	}
	else {
		uvRect.left = ( currentimage.x + 1 )*abs ( uvRect.width );
		uvRect.width = -abs ( uvRect.width );
	}
}
