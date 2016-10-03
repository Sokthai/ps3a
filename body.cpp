/*
 * body.cpp
 *
 *  Created on: Oct 1, 2016
 *      Author: allen
 */

#include "body.hpp"


body::body(sf::Vector2f p, sf::Vector2f v, float mass, string image):
  _p(p), _v(v), _mass(mass), _image(image){

 
  setImage(image);
	setPosition(p);
}


body::body(float x, float y, float vx,
		float vy, float mass, string image){
	_p.x = x; _p.y = y;
	_v.x = vx; _v.y = vy;
	_mass = mass; _image = image;

	setImage(image);
	setPosition(x, y);

}

void body::setPosition(float x, float y){
  x += scale();
  y += scale();
	_sprite.setPosition(x,  y);
}

void body::setPosition(sf::Vector2f p){
  p.x = scale();
  p.y = scale();
  _sprite.setPosition(p);
}

sf::Vector2f body::getPosition(){//return current position
	return _p;
}


string body::getImage(){
  return _image;
}

void body::setImage(string image){
  _image = image;
  	_texture.loadFromFile(image);
	_sprite.setTexture(_texture);
;
}

void body::setMass(float mass){
  _mass = mass;
}

float body::getMass(){
  return _mass;
}

void body::setVelocity(sf::Vector2f v){
  _v = v;
}

sf::Vector2f body::getVelocity(){
  return _v;
}


float body::scale(){
  
  return 2.5 * pow(10, 2);
}


sf::Vector2f body::force(){
  // r = sqrt(change of x^2 + change of y^2)
  // F = G * m1 * m2 / r^2
  // F.x = F * cos(theta)
  // F.y = F * sin(theta)
  // theta = sin^-1 (opposite / hypotenuse)
  
  _r = sqrt(pow((_p.x - scale()), 2) + pow((_p.y - scale()), 2));
  float theta = asin((_p.y - scale()) / _r);
  _f.x = ((_G * _SUNMASS * _mass) / pow(_r, 2)) * cos(theta);
  _f.y = ((_G * _SUNMASS * _mass) / pow(_r, 2)) * sin(theta);
  return _f;
}

sf::Vector2f body::acceleration(){
  // a = F/m
  _a.x = force().x / _mass;
  _a.y = force().x / _mass;
  return _a;
}


sf::Vector2f body::velocity(int T){
  //v = v0 +  change of t * a
  //starting at time t = 0.0, and continuing as long as t < T
  _v.x += T * acceleration().x;
  _v.y += T * acceleration().y;
  return _v;
}

void body::position(int T){
  _p.x += _p.x + T * velocity(T).x;
  _p.y += _p.y + T * velocity(T).y;
  setPosition(_p);
}


void body::draw(sf::RenderTarget& target, sf::RenderStates states) const {
   target.draw(_sprite, states);
 }
