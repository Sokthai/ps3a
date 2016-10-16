#include "body.hpp"
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main(int argc, char* argv[]){



	sf::Vector2f p;
	sf::Vector2f v;
	p.x = 250;
	p.y = 250;
	v.x = 0;
	v.y = 0;

	int universe = (2.5 * pow(10, 2)) * 2; // scale by 10^9 for the position

	//scale the mass by 10^9
	body sun(p, v, 1.98e10, "sun.gif");
	body earth(250+ 1.5e+2, 250, 0, 2.98e+4, 5.97e+4, "earth.gif");
	body mars(2.27e+11, 0, 0, 2.41e+4, 6.4e+23, "mars.gif");
	body mercury(5.8e+10, 0, 0, 4.79e+4, 3.3e+23, "mercury.gif");
	body venus(1.1e+11, 0, 0, 3.5e+4, 4.87e+24, "venus.gif");


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
//	cout << celestial[3].getImage() << endl;
//	cout << celestial[4].getImage() << endl;
//
//	cout << celestial.size() << endl;

	 sf::RenderWindow window(sf::VideoMode(universe, universe), "Celestial");



	 sf::Clock clock;
	 sf::Time time = sf::seconds(50);
	 cout << time.asMilliseconds() << endl;
int i =0;

	 while(window.isOpen() ){
	 		 sf::Event event;
	 		 while(window.pollEvent(event)){
	 			 if (event.type == sf::Event::Closed){
	 			 	 window.close();
	 			 }
	 		 }
	 		 window.clear();


	 		// for ( int j = 0 ; j < 5; j++){
	 			 window.draw(earth);

//	 			 cout << j ;
	 		//}

	 		 earth.setVelocity(1000);
	 		 //cout << "x is : " << earth.getPosition().x << endl;
	 		//cout << "y is : " << earth.getPosition().y << endl;

//	 		earth.setPosition(earth.getPosition().x + i,
//	 				earth.getPosition().y + i );
//	 		i += 1000;
//	 		 cout << earth.getPosition().x << endl;



//	 		sf::Time t = clock.getElapsedTime();
//	 		cout << t.asSeconds() << endl;
//	 		clock.restart();

	 		window.draw(sun);
//	 		window.draw(mars);
//	 		window.draw(earth);

//	 		window.draw(venus);
//	 		window.draw(mercury);
//	 		 for ( int i = 0; i < celestial.size(); i++){
//	 			 window.draw(celestial[i]);
//	 			 //celestial[i].setPosition();
//	 		 }
	 		 window.display();
//	 		 earth.setVelocity();
	 	 }


	return 0;
}
