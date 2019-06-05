#pragma once
#include <SFML/Graphics.hpp>
#include "Animen.h"

class Player
{
public:
	Player ( sf::Texture* texture , sf::Vector2u imagmaxs , float switchtime , float speed );//Player，Animen构造
	~Player ();

	void Update (float fpstime);
	void Draw ( sf::RenderWindow& window );//传入窗口绘制body




	sf::Vector2f getposition () { return body.getPosition (); }//获取图像位置更新
private:
	sf::RectangleShape body;//矩形形状
	Animen animen;
	unsigned int row;
	float speed;//速度
	bool imageRight;//转向
};

