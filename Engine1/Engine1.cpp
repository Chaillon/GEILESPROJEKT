// Engine1.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
#include <memory>
#include <forward_list>
#include <vector>
#include <string>
#include <iostream>
using namespace std;


class GameWindow : public Gosu::Window {
public:
	
	Gosu::Image bild;
	Gosu::Image Figur;
	GameWindow() : Window(1920, 1080) ,bild("tears.jpg"),Figur("Figur2.jpg")
	{
		set_caption("Gosu Tutorial Game mit Git");
	}

	double x = 0;
	double y = 0;
	double rot;
	double high = 0;
	double side = 0;
	void update() override {
		x = input().mouse_x();
		y = input().mouse_y();
		if (input().down(Gosu::MS_LEFT)) {
			rot += 10;
		}
		else if (input().down(Gosu::MS_RIGHT)) {
			rot -= 10;
		}
		if (input().down(Gosu::KB_DOWN)) {
			high += 3;
		}
		else if (input().down(Gosu::KB_UP)) {
			high -= 3;
		}
		else if (input().down(Gosu::KB_RIGHT)) {
			side += 3;
		}
		else if (input().down(Gosu::KB_LEFT)) {
			side -= 3;
		}
	}

	void draw() override {
		

		graphics().draw_line(
			(x - 25), y, Gosu::Color::WHITE,
			(x + 25), y, Gosu::Color::WHITE,
			0.1
		);

		graphics().draw_line(
			x, (y - 25), Gosu::Color::WHITE,
			x, (y + 25), Gosu::Color::WHITE,
			0.1
		);


		bild.draw_rot(0, 0, 0.0,
			0.0,
			0.0, 0.0
		);

		Figur.draw_rot(side, high,
			0.0,
			0.0, 0.0,
			0.2
		);

		/*graphics().draw_line(
		x,y,Gosu::Color::BLUE,
		200,200,Gosu::Color::GREEN,
		0.0
		);*/
		/*Gosu::Graphics::draw_triangle(
			x, y, Gosu::Color::RED,
			200, 100, Gosu::Color::BLUE,
			200, 400, Gosu::Color::GREEN,
			0.0
		);*/
		
	}
};

int main()
{
	GameWindow window;
	window.show();
	
}

