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


//	 1.4960e+11  0.0000e+00  0.0000e+00  2.9800e+04  5.9740e+24    earth.gif
//	 2.2790e+11  0.0000e+00  0.0000e+00  2.4100e+04  6.4190e+23     mars.gif
//	 5.7900e+10  0.0000e+00  0.0000e+00  4.7900e+04  3.3020e+23  mercury.gif
//	 0.0000e+00  0.0000e+00  0.0000e+00  0.0000e+00  1.9890e+30      sun.gif
//	 1.0820e+11  0.0000e+00  0.0000e+00  3.5000e+04  4.8690e+24    venus.gif

	vector<body> celestial;
	body planets;
	string input;

	for (int i = 0; i < 5; i++){
		getline (cin , input);
		istringstream iss (input);
		celestial.push_back(planets);
		iss >> celestial.at(i);
	}

	cout << celestial[0].getImage() << endl;
	cout << celestial[1].getImage() << endl;
	cout << celestial[2].getImage() << endl;
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
	 		 for ( int i = 0; i < celestial.size(); i++){
	 			 window.draw(celestial[i]);
	 		 }
	 		 window.display();
	 	 }


	return 0;
}
