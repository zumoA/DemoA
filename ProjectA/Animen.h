#pragma once
#include <SFML/Graphics.hpp>

class Animen
{
public:
	Animen (sf::Texture* texture,sf::Vector2u imagmaxs,float switchtime);//Animen���죬����ָ�룬ͼ���С����֡
	~Animen ();
	void Update ( int row , float fpstime ,bool imageRight);//���¶�����֡ʱ��

	sf::IntRect uvRect;//֡����
private:



	sf::Vector2u imagmaxs;//��������
	sf::Vector2u currentimage;//��ǰ����

	float totatime;//����ʱ��
	float switchtime;//�л�ʱ��
};