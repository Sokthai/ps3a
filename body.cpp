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

	//setImage(image);
	//setPosition(x, y);

}

void body::setPosition(float x, float y){
  _p.x = x;
  _p.y = y;
  
  _sprite.setPosition( scale() + _p.x, scale() +  _p.y);
}

void body::setPosition(sf::Vector2f p){
  _p = p;
  p.x += scale();
  p.y += scale();
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







float body::scale(){
  return 2.5 * pow(10, 2);
}




void body::draw(sf::RenderTarget& target, sf::RenderStates states) const {
   target.draw(_sprite, states);
 }




istream &operator>>( istream  &input, body &b)  { 
    //input >> D.feet >> D.inches;

         return input;            
}


/*
 std::ostream& operator<< (std::ostream &out, body &lfsr){
    out << lfsr._seed;
	 return out;
}
 */
