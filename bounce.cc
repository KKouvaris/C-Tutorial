// N.B. This program contains a bug, on purpose.

#include <iostream>
#include <algorithm>

using std::cout; using std::endl;

const int minColumn = 0;
const int maxColumn = 80;

class Screen{

public:
	Screen(const unsigned);
	Screen(const Screen&);
	~Screen();
	Screen& operator=(Screen);
	char& operator[](unsigned const);
	void clear();
	void print() const;
	void put(int, char);
	
	friend void swap(Screen& lhs, Screen& rhs);

private:
	unsigned size;
	char * buffer;
	
};

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

	Particle::Particle()
	:symbol('o'),position(0),speed(0){}

	Particle::Particle(const char symbol, const double position, const double speed)
	:symbol(symbol),position(position),speed(speed){}
	
	Particle::~Particle(){}
	
	Particle::Particle(const Particle& other)
	:symbol(other.symbol),position(other.position),speed(other.speed){}
	
	Particle& Particle::operator=(const Particle& other){
		if (this != &other){
			this->symbol = other.symbol;
			this->position = other.position;
			this->speed = other.speed;
		}
		return *this;
	}
	
	void Particle::draw(Screen& screen) const {
		screen[position] = symbol; 
	}
	
	void Particle::move(){
		position += speed;
		if (position >= maxColumn) {
			position = maxColumn;
			speed = -speed;
		} else if (position < minColumn) {
			position = minColumn;
			speed = -speed;
		}
	}	
	

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