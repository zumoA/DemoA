#pragma once
#include <SFML/Graphics.hpp>

class Bobo
{
public:
	Bobo ( sf::Vector2f* player,sf::Vector2f vmapxy );//������꣬��������
	~Bobo ();
	void Update ();

private:
	sf::Vector2f player;
	sf::Vector2f pix;
	sf::Vector2f mapxy;
};


