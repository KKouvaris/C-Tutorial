#include <algorithm>
#include "Particle.hh"
#include "Screen.hh"

int main() {

	int timeStep = 0;
	const int stopTime = 60;
	
	Screen screen(maxColumn-minColumn+1);
	
	const int particleNumber = 3;
	Particle particles[particleNumber]; // = { Particle('*',1,1), Particle('+',2,2), Particle('x',3,3)};	

	particles[0] = Particle('*',1,1);
	particles[1] = Particle('+',2,2);
	particles[2] = Particle('x',3,3);
	
	while (timeStep < stopTime) {
		screen.clear();
		for (int i=0; i<particleNumber; i++){
			particles[i].draw(screen);
			particles[i].move();
		}
		screen.print();
		timeStep++;
	}
}