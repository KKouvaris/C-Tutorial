#ifndef Dyn_Particle_hh
#define Dyn_Particle_hh

#include 'Particle.hh'

class Array{
	
public:
	Array();
	Array(const int&);
	~Array();
	Array& operator=(Array);
	
private:
	//properties
	unsigned N;
	Particle* actual_array;
};
#endif
