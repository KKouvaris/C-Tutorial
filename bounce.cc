// N.B. This program contains a bug, on purpose.

#include <iostream>
#include <algorithm>

using std::cout; using std::endl;

const int minColumn = 0;
const int maxColumn = 80;

class Screen{

public:
	Screen(const unsigned size)
	:size(size), buffer(new char[size]){}

	Screen(const Screen& other)
	:size(other.size), buffer(new char[size]){
		std::copy(other.buffer, other.buffer + other.size, this->buffer);
	}
	
	~Screen(){
		delete [] this->buffer;
	}
	
	char& operator[](unsigned const pos){
		return this->buffer[pos];
	}
	
	void clear(){
		for (unsigned i =0; i<this->size; i++){
			this->buffer[i] = ' ';
		}
	}

	void print() const {
		for (unsigned i = 0; i<this->size; i++){
			cout << this->buffer[i];
		}
		cout << endl;
	}
		
	void put(int position, char symbol){
		this->buffer[position]= symbol;
	}


private:
	unsigned size;
	char * buffer;
	
};

class Particle{
	
public:	

	Particle()
	:symbol('o'),position(0),speed(0){}

	Particle(const char symbol, const double position, const double speed)
	:symbol(symbol),position(position),speed(speed){}
	
	~Particle(){}
	
	Particle(const Particle& other)
	:symbol(other.symbol),position(other.position),speed(other.speed){}
	
	Particle& operator=(const Particle& other){
		if (this != &other){
			this->symbol = other.symbol;
			this->position = other.position;
			this->speed = other.speed;
		}
		return *this;
	}
	
	void draw(Screen& screen) const {
		screen[position] = symbol; 
	}
	
	void move(){
		position += speed;
		if (position >= maxColumn) {
			position = maxColumn;
			speed = -speed;
		} else if (position < minColumn) {
			position = minColumn;
			speed = -speed;
		}
	}	
	

private:
	//properties
	char symbol;
	double position;
	double speed;

};

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