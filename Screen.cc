#include <iostream>
#include <algorithm>
#include "Screen.hh"

using std::cout; using std::endl;

Screen::Screen(const unsigned size)
:size(size), buffer(new char[size]){}

Screen::Screen(const Screen& other)
:size(other.size), buffer(new char[size]){
	std::copy(other.buffer, other.buffer + other.size, this->buffer);
}

Screen::~Screen(){
	delete [] this->buffer;
}

Screen& Screen::operator=(Screen other){	
	swap(*this,other);
	return *this;
}	

char& Screen::operator[](unsigned const pos){
	return this->buffer[pos];
}

void Screen::clear(){
	for (unsigned i =0; i<this->size; i++){
		this->buffer[i] = ' ';
	}
}

void Screen::print() const {
	for (unsigned i = 0; i<this->size; i++){
		cout << this->buffer[i];
	}
	cout << endl;
}

void Screen::put(int position, char symbol){
	this->buffer[position]= symbol;
}

void swap(Screen& lhs, Screen& rhs){
	//swap
	using std::swap;
	swap(lhs.buffer,rhs.buffer);
	swap(lhs.size,rhs.size);	
}

