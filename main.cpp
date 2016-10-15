#include "body.hpp"
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main(int argc, char* argv[]){



	sf::Vector2f p;
	sf::Vector2f v;
	p.x = 0;
	p.y = 0;
	v.x = 0;
	v.y = 0;

	int universe = (2.5 * pow(10, 2)) * 2; // scale by 10^9 for the position

	//scale the mass by 10^9
//	body sun(p, v, 1.98 * pow(10, 21), "sun.gif");
//	body earth(1.5 * pow(10, 2), 0, 0, 2.98 * pow(10, 4), 5.97 * pow(10, 15), "earth.gif");
//	body mars(2.27 * pow(10, 2), 0, 0, 2.41 * pow(10, 4), 6.4 * pow(10, 14), "mars.gif");
//	body mercury(5.8 * pow(10, 1), 0, 0, 4.79 * pow(10, 4), 3.3 * pow(10, 14), "mercury.gif");
//	body venus(1.1 * pow(10, 2), 0, 0, 3.5 * pow(10, 4), 4.87 * pow(10, 15), "venus.gif");


	vector<body> celestial;
	body planets;//= new planets();
	string input;

	for (int i = 0; i < 5; i++){
		getline (cin , input);
		istringstream iss (input);
		celestial.push_back(planets);
		iss >> celestial.at(i);
	}

//	cout << celestial[0].getImage() << endl;
//	cout << celestial[1].getImage() << endl;
//	cout << celestial[2].getImage() << endl;
	cout << celestial[3].getImage() << endl;
	cout << celestial[4].getImage() << endl;

	cout << celestial.size() << endl;

	 sf::RenderWindow window(sf::VideoMode(universe, universe), "Celestial");




	 while(window.isOpen() ){
	 		 sf::Event event;
	 		 while(window.pollEvent(event)){
	 			 if (event.type == sf::Event::Closed){
	 			 	 window.close();
	 			 }
	 		 }
	 		 window.clear();



//	 		window.draw(sun);
//	 		window.draw(mars);
//	 		window.draw(earth);
//	 		window.draw(venus);
//	 		window.draw(mercury);
	 		 for ( int i = 0; i < celestial.size(); i++){
	 			 window.draw(celestial[i]);
	 			 //celestial[i].setPosition();
	 		 }
	 		 window.display();
	 	 }


	return 0;
}
