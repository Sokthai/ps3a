/*
 * main.cpp
 *
 *  Created on: Oct 2, 2016
 *      Author: allen
 */

#include "body.hpp"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	float x = 0, y = 0;
	sf::Vector2f p;
	sf::Vector2f v;
	p.x = 0;
	p.y = 0;

	v.x = 0;
	v.y = 0;

	int winSize = (2.5 * pow(10, 2)) * 2; // scale by 10^9
	
	body sun(p, v, 100, "sun.gif");
	body earth(1.5 * pow(10, 2), 0, 25, 12, 100, "earth.gif");
	body mars(2.27 * pow(10, 2), 0,63, 20, 100, "mars.gif");
	body mercury(5.8 * pow(10, 1), 0, 65, 50, 100, "mercury.gif");
	body venus(1.1 * pow(10, 2), 0, 50, 52, 100, "venus.gif");

	
	 sf::RenderWindow window(sf::VideoMode(winSize, winSize), "Cosmos");

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
