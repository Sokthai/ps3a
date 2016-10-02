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
	p.x = 250;
	p.y = 250;

	v.x = 0;
	v.y = 0;

	body sun(p, v, 100, "sun.gif");
	body earth(100, 100, 25, 12, 100, "earth.gif");
	body mars(60, 15,63, 20, 100, "mars.gif");
	body mercury(150, 250, 65, 50, 100, "mercury.gif");
	body venus(300, 350, 50, 52, 100, "venus.gif");


	 sf::RenderWindow window(sf::VideoMode(500, 500), "Cosmos");

	 while(window.isOpen() ){
	 		 sf::Event event;
	 		 while(window.pollEvent(event)){
	 			 if (event.type == sf::Event::Closed){
	 			 	 window.close();
	 			 }
	 		 }


	 		 window.clear();
	 		 window.draw(sun);
	 		 window.draw(earth);
	 		 window.draw(mars);
	 		 window.draw(mercury);
	 		 window.draw(venus);
	 		 window.display();

//	 		 p.x = x;
//	 		 p.y = y;
//	 		 x += 0.1f;
//	 		 y += 0.1f;
//	 		 sun.setPosition(p);

	 	 }


	return 0;
}
