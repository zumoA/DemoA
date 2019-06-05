#include "Player.h"



Player::Player ( sf::Texture* texture , sf::Vector2u imagmaxs , float switchtime, float speed ) :
	animen(texture,imagmaxs,switchtime)
{
	this->speed = speed;
	row = 0;
	imageRight = true;
	body.setSize ( sf::Vector2f ( 64.0f , 64.0f ) );
	body.setOrigin ( body.getSize () / 2.0f );
	body.setPosition ( 0.0f , 100.0f );
	body.setTexture ( texture );
}


Player::~Player ()
{
}

void Player::Update ( float fpstime )
{
	sf::Vector2f movement ( 0.0f , 0.0f );
	if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::Left ) )
		movement.x -= speed * fpstime;
	if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::Right ) )
		movement.x += speed * fpstime;

	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Up))
		movement.y -= speed * fpstime;
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Down))
		movement.y += speed * fpstime;

	if ( movement.x == 0.0f ) {
		row = 0;
	}
	else
	{
		row = 1;
		if ( movement.x > 0.0f )
			imageRight = true;
		else
			imageRight = false;
	}
	animen.Update ( row , fpstime , imageRight );
	body.setTextureRect ( animen.uvRect );
	body.move ( movement );
}

void Player::Draw ( sf::RenderWindow& window )
{
	window.draw ( body );
}



