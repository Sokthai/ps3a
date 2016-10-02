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

using namespace std;


class body : public sf::Drawable, sf::Transformable{
public:
	body(sf::Vector2f, sf::Vector2f, float, string);
//	friend std::ostream& operator>> (std::ostream &out);

	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f p);

//	sf::Vector2f getVelocity(){ return _v; }
//	void setVelocity(sf::Vector2f v){ _v = v; }

//	string getImage(){ return _image; }
//	void setImage(string image){ _image = image; }
//
//	float getMass(){ return _mass; }
//	void setMass(float mass){ _mass = mass;}

	void virtual draw(sf::RenderTarget&, sf::RenderStates) const;

private:

	sf::Vector2f _p, _v, _f, _a;
	string _image;
	float _mass;
	 sf::Sprite _sprite;
	 sf::Texture _texture;

};

#endif /* PS3A_BODY_HPP_ */
