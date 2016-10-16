#include "body.hpp"
#include <cmath>
#include <sstream>
//**********************************************************
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
//**********************************************************












//**********************************************************
void body::setPosition(float x, float y){
  _p.x = x;
  _p.y = y;
  //cout  << _image << " x: " << x << " p.x" << _p.x << " y: " << y << endl;
//  if (x > 0) x = x * 1e-9;
//  if (y > 0) y = y * 1e-9;

 setPosition(_p);
}

void body::setPosition(sf::Vector2f p){
  _p = p;
  p = scale(p);
  //sf::Vector2f f = getForce();
  //cout  << _image << " :x " << _p.x << endl;

  _sprite.setPosition(p);

}

sf::Vector2f body::getPosition(){//return current position
	return _p;
}
//**********************************************************









//**********************************************************
string body::getImage(){
  return _image;
}

void body::setImage(string image){
   _image = image;
	//cout << "this is in setImage : " << image  << endl;


  	_texture.loadFromFile(image);
	_sprite.setTexture(_texture);

}
//**********************************************************






//**********************************************************
float body::getMass(){
	return _mass;
}

void body::setMass(float mass){
	_mass = mass;
}

//**********************************************************





//**********************************************************
sf::Vector2f body::scale(sf::Vector2f s){
	if (s.x > 0)
		s.x = s.x * 1e-9;
	if (s.y > 0)
		s.y = s.y * 1e-9;



	s.x += 250; //hard code
	s.y += 250; //hard code

	//cout << "s.x is : " << s.x << " s.y is : " << s.y << endl;
  return s;
}
//**********************************************************


float body::scaleMass(float mass){
	float m = mass * 1e-20;
	return m;
}







//**********************************************************
sf::Vector2f body::getForce(){
	//r = sqrt(change of x^2 + chagne of y^2)
	//F = (G*m1*m2)/ r^2


	sf::Vector2f f;
	float G = 6.67 * 1e-11;
	float sunMass = scaleMass((1.989e+30));
//	cout << "p.x is " << (long)_p.x << endl;
//		cout << "p.y is " << (long)_p.y << endl;
	float r = sqrt(pow(_p.x, 2) + pow(_p.y, 2));
	//cout << "r is " << (long)r << endl;
//	cout << "this is p.y " << _p.y << endl;
//	cout << "this is p.x " << _p.x << endl;
//	cout << "this is r " << r << endl;

	int theta = asin(_p.y / r);
	cout << " _p.y in force " << _p.x  << endl;
	//cout << " theta " << theta << endl;
	f.x = ((G * scaleMass(_mass) * sunMass) / pow(r, 2));
	f.x *=  _p.x / r;
	f.y = ((G * scaleMass(_mass) * sunMass) / pow(r, 2));
	f.y *= _p.y / r;


//	cout << "this is y " << f.x <<endl;
	//cout << "f is " << scaleMass(G) * scaleMass(_mass) * scaleMass(sunMass) << endl;
	//cout << "force is " << ((G * scaleMass(_mass) * sunMass) / pow(r, 2)) * cos(theta) << endl;
	return f;
}
//**********************************************************









//**********************************************************
sf::Vector2f body::getAcceleration(){
	//a = F/m
	sf::Vector2f a;
	sf::Vector2f F = getForce();

	a.x = F.x / scaleMass(_mass);
	a.y = F.y / scaleMass(_mass);
//	cout << "this is f.x " << F.x << endl;
//	cout << "this is a.x " << a.x << endl;
//	cout << "this is a.y " << a.y << endl;
	return a;
}
//**********************************************************







//**********************************************************
sf::Vector2f body::getVelocity(){
	return _v;
}
void body::setVelocity(int t){
	sf::Vector2f a = getAcceleration();
	cout << "this is a.x " << a.x << endl;
	cout << "this is a.y " << a.y << endl;
	cout << "this is v.x " << _v.x << endl;
	cout << "this is v.y " << _v.y << endl;
	_v.x += t * a.x;
	_v.y += t * a.y;

	_p.x += t * _v.x;
	_p.y += t * _v.y;

//	cout << "this is _p.x " << _p.x << endl;
//	cout << "this is _p.y " << _p.y << endl;

	setPosition(_p);
}

//**********************************************************

void body::scale(body& b){
	if (b._p.x > 0) b._p.x *= 1e-9;
	if (b._p.y > 0) b._p.y *= 1e-9;

	//if (b._mass > 0) b._mass *= 1e-9;
	b._mass *= 1e-20;

	b._p.x += 250;
	b._p.y += 250;
}








//**********************************************************
void body::draw(sf::RenderTarget& target, sf::RenderStates states) const {
//	cout << "this is _spite : " << _sprite.getPosition().x << endl;


//	cout << _sprite.getTexture()->getSize().x  << endl;
	target.draw(_sprite, states);
 }
//**********************************************************










//**********************************************************
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
	b.scale(b);
	b.setImage(b._image);
	b.setPosition(b._p);

	return input;
}



