#pragma once
#include <SFML/Graphics.hpp>
#include "Animen.h"

class Player
{
public:
	Player ( sf::Texture* texture , sf::Vector2u imagmaxs , float switchtime , float speed );//Player��Animen����
	~Player ();

	void Update (float fpstime);
	void Draw ( sf::RenderWindow& window );//���봰�ڻ���body




	sf::Vector2f getposition () { return body.getPosition (); }//��ȡͼ��λ�ø���
private:
	sf::RectangleShape body;//������״
	Animen animen;
	unsigned int row;
	float speed;//�ٶ�
	bool imageRight;//ת��
};

