#ifndef Array_hh
#define Array_hh

#include "Particle.hh"

class Array{
	
public:
	Array();
	Array(const int&);
	Array(const Array&);
	~Array();
	Array& operator=(Array);
	Particle& operator[](unsigned const);
	void push_back(Particle&);
	friend void swap(Array&, Array&);
	unsigned size(){return N;}
	
private:
	//properties
	unsigned N;
	Particle* buffer;
};
#endif
