/*
 * body.h
 *
 *  Created on: Oct 1, 2016
 *      Author: allen
 */

#ifndef PS3A_BODY_HPP_
#define PS3A_BODY_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;


class body : public sf::Drawable, sf::Transformable{
public:
	body(sf::Vector2f, sf::Vector2f, float, string);
	body(float, float, float, float, float, string);
//	friend std::ostream& operator>> (std::ostream &out);

  sf::Vector2f getPosition();
  void setPosition(sf::Vector2f);
  void setPosition(float, float);

  sf::Vector2f getVelocity();
  void setVelocity(sf::Vector2f);

	string getImage();
  void setImage(string);

  float getMass();
  void setMass(float);
  float scale();

	void virtual draw(sf::RenderTarget&, sf::RenderStates) const;

private:
  sf::Vector2f force();
  sf::Vector2f  acceleration();
  sf::Vector2f velocity(int);
  void position(int);
  sf::Vector2f _p, _v, _f,  _a;
	string _image;
  float _mass, _r;
	 sf::Sprite _sprite;
	 sf::Texture _texture;
  const float  _G = 6.67 * pow(10, -11);
  
  const float _sunMass = pow(2, 30);
 
};

#endif /* PS3A_BODY_HPP_ */
