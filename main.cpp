#include "body.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]){

  vector<body*> b;// (new body(1, 2, 3, 4, 5, "sun.gif"));

  
   b.push_back( new body(1, 2, 3, 4, 5, "picture"));
  vector<body*> c (b);

  /*
  cout << b[0]->getPosition().y << endl;
  cout << c[0]->getPosition().x << endl;
  c[0]->setPosition(sf::Vector2f(18, 19));
  cout <<"this is c " <<  c[0]->getPosition().y << endl;
  cout <<"this is b " <<  b[0]->getPosition().y << endl;
 
  
 /*
  vector<body>::iterator v = b.begin();
  while (v != b.end()) {
      body &bo = *v;
    cout << "value of vector is " << bo.getPosition().x << endl;
    v++;

  }

  
  vector<body> db (5, body(10, 20, 30, 40, 50, "image"));  
  vector<body>::iterator i;
  for (i = db.begin(); i != db.end(); ++i){
    body &bo = *i;
    cout << bo.getPosition().x << endl;
  }
  */

  
 
	sf::Vector2f p;
	sf::Vector2f v;
	p.x = 0;
	p.y = 0;
	v.x = 0;
	v.y = 0;

	int universe = (2.5 * pow(10, 2)) * 2; // scale by 10^9 for the position
	
	//scale the mass by 10^9
	body sun(p, v, 1.98 * pow(10, 21), "sun.gif");
	body earth(1.5 * pow(10, 2), 0, 0, 2.98 * pow(10, 4), 5.97 * pow(10, 15), "earth.gif");
	body mars(2.27 * pow(10, 2), 0, 0, 2.41 * pow(10, 4), 6.4 * pow(10, 14), "mars.gif");
	body mercury(5.8 * pow(10, 1), 0, 0, 4.79 * pow(10, 4), 3.3 * pow(10, 14), "mercury.gif");
	body venus(1.1 * pow(10, 2), 0, 0, 3.5 * pow(10, 4), 4.87 * pow(10, 15), "venus.gif");


//	vector <body*> theBody
//	  theBody.push_back(new body(sun));
//	cout << theBody.max_size();



	

	 sf::RenderWindow window(sf::VideoMode(universe, universe), "Celestial");

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
	 	 }

	
	return 0;
}
