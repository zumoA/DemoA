#pragma once
#include <SFML/Graphics.hpp>

class Gmap
{
public:
	Gmap ( sf::Texture* texture , sf::Vector2u indeximage, sf::Vector2u imagmaxs,sf::Vector2f mapxy);//���������������꣬��ͼ����
	~Gmap ();

	void Update ();
	void Draw (sf::RenderWindow& window);



private:
	sf::Vector2u imagmaxs;//����֡��������
	sf::IntRect uvRect;//��������
	sf::Vector2f mapxy;//�����ͼ����

	sf::RectangleShape dmap;//���ڻ��Ƶ�����


	sf::Vector2u indeximage;//��������

};

