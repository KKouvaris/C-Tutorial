#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Particle.hh"
#include "Screen.hh"

const int minColumn = 0;
const int maxColumn = 80;

int main() {
	int timeStep = 0;
	const int stopTime = 60;

	Screen screen(maxColumn-minColumn+1);	
	
	std::string filename("config.txt");
	std::ifstream config(filename.c_str());
	if (!config){
		std::cerr << "Could not open file." << std::endl;
		return EXIT_FAILURE;
	}
	
	unsigned particleNumber;	
	//read the number of particles
	config >> particleNumber;
	
	Particle* particles = new Particle[particleNumber];
	//read particles' values
	for (unsigned i=0; i<particleNumber; i++){
		char sym; double pos, sp;
		config >> sym >> pos >> sp;
		particles[i] =  Particle(sym,pos,sp);
	}

	while (timeStep < stopTime) {
		screen.clear();
		for (unsigned i=0; i<particleNumber; i++){
			particles[i].draw(screen);
			particles[i].move();
		}
		screen.print();
		timeStep++;
	}
	delete [] particles;
}