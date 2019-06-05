#pragma once
#include <SFML/Graphics.hpp>

class Bobo
{
public:
	Bobo ( sf::Vector2f* player,sf::Vector2f vmapxy );//玩家坐标，地形坐标
	~Bobo ();
	void Update ();

private:
	sf::Vector2f player;
	sf::Vector2f pix;
	sf::Vector2f mapxy;
};


