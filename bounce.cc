// N.B. This program contains a bug, on purpose.

#include <iostream>

using std::cout; using std::endl;

const int minColumn = 0;
const int maxColumn = 80;

struct Screen{

	unsigned size;
	char * buffer;
		
	void initialise(const unsigned size){
		this->size = size;
		this->buffer = new char[size];
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
	
	void destroy(){
		delete [] this->buffer;
	}
	
};

struct Particle{
	
	//properties
	char symbol;
	double position;
	double speed;
	
	//
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

	void draw(char * const screen) const {
		screen[static_cast<int>(position)]= symbol; 
	}
	
};

int main() {

	int timeStep = 0;
	const int stopTime = 60;
	
	Screen screen;
	screen.initialise(maxColumn-minColumn+1);
	
	const int particleNumber = 4;
	Particle particles[particleNumber];	

	particles[0].initialise('*',1,1);
	particles[1].initialise('+',2,2);
	particles[2].initialise('x',3,3);
	particles[3].initialise('o',4,4);
	
	while (timeStep < stopTime) {
		screen.clear();
		for (int i=0; i<particleNumber; i++){
			particles[i].draw(screen.buffer);
			particles[i].move();
		}
		screen.print();
		timeStep++;
	}
	screen.destroy();
}