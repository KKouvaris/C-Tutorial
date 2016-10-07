#ifndef Particle_hh
#define Particle_hh

#include <iostream>

extern const int minColumn;
extern const int maxColumn;

class Screen;

class Particle{
	
public:	

	Particle();
	Particle(const char, const double, const double);
	~Particle();
	Particle(const Particle&);
	Particle& operator=(const Particle&);
	void draw(Screen&) const;
	void move();
	friend std::istream& operator>>(std::istream&, Particle&);

private:
	//properties
	char symbol;
	double position;
	double speed;

};
#endif
