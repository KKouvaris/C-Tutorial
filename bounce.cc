// N.B. This program contains a bug, on purpose.

#include <iostream>
#include <algorithm>

using std::cout; using std::endl;

const int minColumn = 0;
const int maxColumn = 80;

class Screen{

public:
	Screen(const unsigned size){
		this->size = size;
		this->buffer = new char[size];
	}

	Screen(const Screen& other):size(other.size){
		//this->buffer = new char[other.size];
		std::copy(other.buffer, other.buffer + other.size, this->buffer);
	}
	
	~Screen(){
		delete [] this->buffer;
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
	//methods
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

	void initialise(const char symbol, const double position, const double speed){
		this->symbol = symbol;
		this->position = position;
		this->speed = speed;
	}

	void draw(Screen& screen) const {
		screen.put(position,symbol); 
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
	
	const int particleNumber = 4;
	Particle particles[particleNumber];	

	particles[0].initialise('*',1,1);
	particles[1].initialise('+',2,2);
	particles[2].initialise('x',3,3);
	particles[3].initialise('o',4,4);
	
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