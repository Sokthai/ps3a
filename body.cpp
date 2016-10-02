/*
 * body.cpp
 *
 *  Created on: Oct 1, 2016
 *      Author: allen
 */

#include "body.hpp"


body::body(sf::Vector2f p, sf::Vector2f v, float mass, string image):
	_p(p), _v(v), _mass(mass), _image(image){
	_texture.loadFromFile(image);
	_sprite.setTexture(_texture);
	setPosition(p);
}


body::body(float x, float y, float vx,
		float vy, float mass, string image){
	_p.x = x; _p.y = y;
	_v.x = vx; _v.y = vy;
	_mass = mass; _image = image;

	_texture.loadFromFile(image);
	_sprite.setTexture(_texture);
	setPosition(x, y);

}

void body::setPosition(float x, float y){
	_sprite.setPosition(x,  y);
}


void body::setPosition(sf::Vector2f p){
	_sprite.setPosition(p);
}

sf::Vector2f body::getPosition(){//return current position
	return _p;
}

void body::draw(sf::RenderTarget& target, sf::RenderStates states) const {
   target.draw(_sprite, states);
 }
