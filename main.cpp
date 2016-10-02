/*
 * main.cpp
 *
 *  Created on: Oct 2, 2016
 *      Author: allen
 */

#include "body.hpp"

int main(int argc, char* argv[]){
	float x = 0, y = 0;
	sf::Vector2f p;
	sf::Vector2f v;
	p.x = 50;
	p.y = 50;

	v.x = 0;
	v.y = 0;

	body sun(p, v, 100, "sun.gif");
	body earth(p, v, 100, "earth.gif");


	 sf::RenderWindow window(sf::VideoMode(500, 500), "Cosmos");

	 while(window.isOpen() ){
	 		 sf::Event event;
	 		 while(window.pollEvent(event)){
	 			 if (event.type == sf::Event::Closed){
	 			 	 window.close();
	 			 }
	 		 }


	 		 window.clear();
	 		 window.draw(earth);
	 		 window.display();

	 		 p.x = x;
	 		 p.y = y;
	 		 x += 0.1f;
	 		 y += 0.1f;
	 		 sun.setPosition(p);

	 	 }


	return 0;
}
