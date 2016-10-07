#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Particle.hh"
#include "MagicParticle.hh"
#include "Screen.hh"

const int minColumn = 0;
const int maxColumn = 80;

int main() {
	
	std::string filename("config.txt");
	std::ifstream config(filename.c_str());
	if (!config){
		std::cerr << "Could not open file." << std::endl;
		return EXIT_FAILURE;
	}
	
	
	std::vector<Particle*> particles;
	while (config){
		char kind;
		config >> kind;
		if (!config) break;
		Particle* ptcl;
		char c; double p,s;
		config >> c >> p >> s;
		if (kind == 1){
			ptcl = new MagicParticle(c,p,s);
		}else{
			ptcl = new Particle(c,p,s);
		}
		particles.push_back(ptcl);
	}
	
	Screen screen(maxColumn-minColumn+1);
	int timeStep = 0;
	const int stopTime = 60;	
	
	while (timeStep < stopTime) {
		screen.clear();
		for (unsigned i=0; i<particles.size(); i++){
			particles[i]->draw(screen);
			particles[i]->move();
		}
		screen.print();
		timeStep++;
	}
	for (unsigned i=0; i<particles.size(); i++)
		delete particles[i];
	//delete particles;
}