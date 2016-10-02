/*
 * main.cpp
 *
 *  Created on: Oct 2, 2016
 *      Author: allen
 */

#include "body.hpp"

int main(int argc, char* argv[]){

	sf::Vector2f p;
	sf::Vector2f v;
	p.x = 0;
	p.y = 0;

	v.x = 0;
	v.y = 0;

	body sun(p, v, 100, "sun.gif");

	 sf::CircleShape shape(100.f);
	  shape.setFillColor(sf::Color::Green);


	  sf::RenderWindow window(sf::VideoMode(200, 200), "Cosmos");

	 while(window.isOpen() ){
	 		 sf::Event event;
	 		 while(window.pollEvent(event)){
	 			 if (event.type == sf::Event::Closed){
	 			 	 window.close();
	 			 }
	 		 }

	 		 window.clear();
	 		 window.draw(sun);
	 		 window.display();

	 	 }


	return 0;
}
