#ifndef Array_hh
#define Array_hh

#include "Particle.hh"

template<typename T>
class Array{
	
public:
	Array();
	Array(const Array&);
	~Array();
	Array& operator=(Array);
	T& operator[](unsigned const);
	void push_back(T&);
	friend void swap(Array&, Array&);
	unsigned size(){return N;}
	
private:
	//properties
	unsigned N;
	Particle* buffer;
};

//constructors

//default constructor
template<typename T>
Array<T>::Array():N(0),buffer(NULL){}

//copy constructor
template<typename T>
Array<T>::Array(const Array<T>& other)
:N(other.N), buffer(new T[N]){
	std::copy(other.buffer, other.buffer + other.N, this->buffer);
}

//assignment constructor
template<typename T>
Array<T>& Array<T>::operator=(Array<T> other){
	swap(*this,other);
	return *this;
}	

template<typename T>
void swap(Array<T>& lhs, Array<T>& rhs){
	using std::swap;
	swap(lhs.buffer,rhs.buffer);
	swap(lhs.N, rhs.N);
}

template<typename T>
T& Array<T>::operator[](unsigned const pos){
	return this->buffer[pos];
}

//destructor
template<class T>
Array<T>::~Array(){
	delete [] this->buffer;
}

//push back function
template<typename T>
void Array<T>::push_back(T& p){
	//allocate memory for new array
	T* new_array = new T[N+1];
	//copy old
	std::copy(buffer,buffer+N,new_array);
	//assign new
	new_array[N] = p;
	delete [] buffer;
	buffer = new_array;
	N++;
}

#endif
