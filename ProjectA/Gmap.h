#pragma once
#include <SFML/Graphics.hpp>

class Gmap
{
public:
	Gmap ( sf::Texture* texture , sf::Vector2u indeximage, sf::Vector2u imagmaxs,sf::Vector2f mapxy);//接受纹理，纹理坐标，地图坐标
	~Gmap ();

	void Update ();
	void Draw (sf::RenderWindow& window);



private:
	sf::Vector2u imagmaxs;//纹理帧长宽数量
	sf::IntRect uvRect;//纹理向量
	sf::Vector2f mapxy;//纹理地图坐标

	sf::RectangleShape dmap;//正在绘制的纹理


	sf::Vector2u indeximage;//纹理坐标

};

