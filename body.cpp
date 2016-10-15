#include "body.hpp"


body::body(){}
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
  _p.x = x;
  _p.y = y;
 setPosition(_p);
}

void body::setPosition(sf::Vector2f p){
  _p = p;
  p = scale(p);
//  p.x += scale(p);
//  p.y += scale(p);
  _sprite.setPosition(p);
}

sf::Vector2f body::getPosition(){//return current position
	return _p;
}


string body::getImage(){
  return _image;
}

void body::setImage(string image){
  //_image = image;
	cout << "this is in setImage : " << image << endl;
  	_texture.loadFromFile(image);
	_sprite.setTexture(_texture);
}


sf::Vector2f body::getVelocity(){
	return _v;
}

float body::getMass(){
	return _mass;
}





sf::Vector2f body::scale(sf::Vector2f s){
	if (s.x > 0)
		s.x = s.x * 1e-9;
	if (s.y > 0)
		s.y = s.y * 1e-9;

	s.x += 250; //hard code
	s.y += 250; //hard code
  return s;
}




void body::draw(sf::RenderTarget& target, sf::RenderStates states) const {
   target.draw(_sprite, states);
 }



istream& operator>> (istream& input, body& b){
//	body sun(p, v, 1.98 * pow(10, 21), "sun.gif");
//	body earth(1.5 * pow(10, 2), 0, 0, 2.98 * pow(10, 4), 5.97 * pow(10, 15), "earth.gif");
//	body mars(2.27 * pow(10, 2), 0, 0, 2.41 * pow(10, 4), 6.4 * pow(10, 14), "mars.gif");
//	body mercury(5.8 * pow(10, 1), 0, 0, 4.79 * pow(10, 4), 3.3 * pow(10, 14), "mercury.gif");
//	body venus(1.1 * pow(10, 2), 0, 0, 3.5 * pow(10, 4), 4.87 * pow(10, 15), "venus.gif");

	input >> b._p.x;
	input >> b._p.y;
	input >> b._v.x;
	input >> b._v.y;
	input >> b._mass;
	input >> b._image;
//	cout << "this is in man : " << b._image << endl;
	b.setImage(b._image);
	b.setPosition(b._p);
	return input;
}



