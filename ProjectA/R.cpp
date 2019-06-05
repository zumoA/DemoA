#include <SFML/Graphics.hpp>
#include "Animen.h"
#include "Player.h"
#include "Gmap.h"
#include"Bobo.h"


static const float VIEW_W = 640.0f;//摄像机分辨率
static const float VIEW_H = 360.0f;

void Resizeview ( const sf::RenderWindow& window , sf::View& view ) {//窗口比例改变绘制
	float scale = float ( window.getSize ().x ) / float ( window.getSize ().y );
	view.setSize ( VIEW_H*scale , VIEW_H );
}
int main ()
{
	sf::RenderWindow window ( sf::VideoMode ( 1920 , 1080 ) , "Go!" );//创建窗口

	sf::View view ( sf::Vector2f ( 0.0f , 0.0f ) , sf::Vector2f ( VIEW_W  , VIEW_H) );//摄像机大小

	sf::Texture playertexture;
	sf::Texture maptexture;
	maptexture.loadFromFile ( "Res/TILE1_A.png" );//载入地图纹理
	playertexture.loadFromFile ( "Res/keke_a.png" );//载入纹理

	
	

	Player player ( &playertexture , sf::Vector2u ( 4 , 8 ) , 0.1f , 300.0f );//传入纹理，纹理帧，帧率，基础移动速度

	float fpstime = 0.0f;//计算帧时间
	sf::Clock clock;
	
	//Bobo bobo (fpstime);
	//bobo.Update ();

	while ( window.isOpen () )//主循环
	{
		fpstime = clock.restart ().asSeconds();

		sf::Event event;
		while ( window.pollEvent ( event ) )//事件
		{
			if ( event.type == sf::Event::Closed )//退出
				window.close ();
			if ( event.type == sf::Event::Resized )//改变比例
				Resizeview ( window , view );
		}

		player.Update ( fpstime );//传入帧时间
		view.setCenter ( player.getposition () );//摄像机中心

		window.clear (sf::Color::White);//屏幕清除
		window.setView ( view );//摄像机窗口


		for ( int x = 0; x < 5; x++ ) {	//传入纹理，纹理坐标，图像帧数量，绘制坐标
			Gmap gmap ( &maptexture , sf::Vector2u ( 5.0f , 25.0f ) , sf::Vector2u ( 30 , 56 ) , sf::Vector2f ( 0.0f + ( 32 * x ) , 132.0f ) );
			gmap.Draw ( window );

			Bobo bobo ( &player.getposition () , sf::Vector2f ( 0.0f  , 132.0f ) );
			bobo.Update ();
		}
		

		
		player.Draw ( window);//传入窗口
		window.display ();//更新

		{
			printf ( "%4.2f，%4.2f \n" , player.getposition().x,player.getposition().y );
		}
		


	}

	return EXIT_SUCCESS;
}

