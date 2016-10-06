#ifndef Particle_hh
#define Particle_hh

#include "Screen.hh"

class Particle{
	
public:	

	Particle();
	Particle(const char, const double, const double);
	~Particle();
	Particle(const Particle&);
	Particle& operator=(const Particle&);
	void draw(Screen&) const;
	void move();

private:
	//properties
	char symbol;
	double position;
	double speed;

};
#endif
