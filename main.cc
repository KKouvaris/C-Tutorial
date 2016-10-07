#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Particle.hh"
#include "Screen.hh"
#include "Array.hh"

const int minColumn = 0;
const int maxColumn = 80;

int main() {
	
	std::string filename("config.txt");
	std::ifstream config(filename.c_str());
	if (!config){
		std::cerr << "Could not open file." << std::endl;
		return EXIT_FAILURE;
	}
	
	Array particles;
	while (config){
		Particle p;
		config >> p;
		if (!config) break;
		particles.push_back(p);
	}

	Screen screen(maxColumn-minColumn+1);
	int timeStep = 0;
	const int stopTime = 60;	
	
	while (timeStep < stopTime) {
		screen.clear();
		for (unsigned i=0; i<particles.size(); i++){
			particles[i].draw(screen);
			particles[i].move();
		}
		screen.print();
		timeStep++;
	}
	//delete particles;
}