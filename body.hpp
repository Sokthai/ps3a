

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
	body();
	body(sf::Vector2f, sf::Vector2f, float, string);
	body(float, float, float, float, float, string);

	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f);
	void setPosition(float, float);


	sf::Vector2f getVelocity();
	void setVelocity(int t);


	float getMass();
	void setMass(float);

	string getImage();
	void setImage(string);

	sf::Vector2f scale(sf::Vector2f p);
	friend istream  &operator>>(istream&, body&);

	void virtual draw(sf::RenderTarget&, sf::RenderStates) const;

private:


	sf::Vector2f _p, _v;// _f,  _a;
	float _mass;
	string _image;
	sf::Sprite _sprite;
	sf::Texture _texture;


	sf::Vector2f getForce();
	sf::Vector2f getAcceleration();
 
};

#endif /* PS3A_BODY_HPP_ */
