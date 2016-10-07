#include "Array.hh"
#include <algorithm>

//constructors

//default constructor
Array::Array():N(0),buffer(NULL){}
Array::Array(const int& N):buffer(new Particle[N]){}

//copy constructor
Array::Array(const Array& other)
:N(other.N), buffer(new Particle[N]){
	std::copy(other.buffer, other.buffer + other.N, this->buffer);
}

//assignment constructor
Array& Array::operator=(Array other){
	swap(*this,other);
	return *this;
}	

void swap(Array& lhs, Array& rhs){
	using std::swap;
	swap(lhs.buffer,rhs.buffer);
	swap(lhs.N, rhs.N);
}

Particle& Array::operator[](unsigned const pos){
	return this->buffer[pos];
}

//destructor
Array::~Array(){
	delete [] this->buffer;
}

//push back function
void Array::push_back(Particle& p){
	//allocate memory for new array
	Particle* new_array = new Particle[N+1];
	//copy old
	std::copy(buffer,buffer+N,new_array);
	//assign new
	new_array[N] = p;
	delete [] buffer;
	buffer = new_array;
	N++;
}