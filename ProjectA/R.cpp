#include <SFML/Graphics.hpp>
#include "Animen.h"
#include "Player.h"
#include "Gmap.h"
#include"Bobo.h"


static const float VIEW_W = 640.0f;//������ֱ���
static const float VIEW_H = 360.0f;

void Resizeview ( const sf::RenderWindow& window , sf::View& view ) {//���ڱ����ı����
	float scale = float ( window.getSize ().x ) / float ( window.getSize ().y );
	view.setSize ( VIEW_H*scale , VIEW_H );
}
int main ()
{
	sf::RenderWindow window ( sf::VideoMode ( 1920 , 1080 ) , "Go!" );//��������

	sf::View view ( sf::Vector2f ( 0.0f , 0.0f ) , sf::Vector2f ( VIEW_W  , VIEW_H) );//�������С

	sf::Texture playertexture;
	sf::Texture maptexture;
	maptexture.loadFromFile ( "Res/TILE1_A.png" );//�����ͼ����
	playertexture.loadFromFile ( "Res/keke_a.png" );//��������

	
	

	Player player ( &playertexture , sf::Vector2u ( 4 , 8 ) , 0.1f , 300.0f );//������������֡��֡�ʣ������ƶ��ٶ�

	float fpstime = 0.0f;//����֡ʱ��
	sf::Clock clock;
	
	//Bobo bobo (fpstime);
	//bobo.Update ();

	while ( window.isOpen () )//��ѭ��
	{
		fpstime = clock.restart ().asSeconds();

		sf::Event event;
		while ( window.pollEvent ( event ) )//�¼�
		{
			if ( event.type == sf::Event::Closed )//�˳�
				window.close ();
			if ( event.type == sf::Event::Resized )//�ı����
				Resizeview ( window , view );
		}

		player.Update ( fpstime );//����֡ʱ��
		view.setCenter ( player.getposition () );//���������

		window.clear (sf::Color::White);//��Ļ���
		window.setView ( view );//���������


		for ( int x = 0; x < 5; x++ ) {	//���������������꣬ͼ��֡��������������
			Gmap gmap ( &maptexture , sf::Vector2u ( 5.0f , 25.0f ) , sf::Vector2u ( 30 , 56 ) , sf::Vector2f ( 0.0f + ( 32 * x ) , 132.0f ) );
			gmap.Draw ( window );

			Bobo bobo ( &player.getposition () , sf::Vector2f ( 0.0f  , 132.0f ) );
			bobo.Update ();
		}
		

		
		player.Draw ( window);//���봰��
		window.display ();//����

		{
			printf ( "%4.2f��%4.2f \n" , player.getposition().x,player.getposition().y );
		}
		


	}

	return EXIT_SUCCESS;
}

