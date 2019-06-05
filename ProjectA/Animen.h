#pragma once
#include <SFML/Graphics.hpp>

class Animen
{
public:
	Animen (sf::Texture* texture,sf::Vector2u imagmaxs,float switchtime);//Animen构造，纹理指针，图像大小除以帧
	~Animen ();
	void Update ( int row , float fpstime ,bool imageRight);//更新动画，帧时间

	sf::IntRect uvRect;//帧向量
private:



	sf::Vector2u imagmaxs;//纹理数量
	sf::Vector2u currentimage;//当前纹理

	float totatime;//持续时间
	float switchtime;//切换时间
};