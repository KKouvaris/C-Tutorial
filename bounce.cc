// N.B. This program contains a bug, on purpose.

#include <iostream>

using std::cout; using std::endl;

const int minColumn = 0;
const int maxColumn = 80;
const int screenSize = maxColumn - minColumn + 1;

struct Particle{
	
	//properties
	char symbol;
	double position;
	double speed;
	
	//
	void move(){
		this->position += this->speed;
		if (this->position >= maxColumn) {
			this->position = maxColumn;
			this->speed = -this->speed;
		} else if (this->position < minColumn) {
			this->position = minColumn;
			this->speed = -this->speed;
		}
	}

	void initialise(const char sym, const double pos, const double sp){
		this->symbol = sym;
		this->position = pos;
		this->speed = sp;
	}

	void draw(char * const screen){
		screen[static_cast<int>(this->position)]= this->symbol; 
	}
	
};

void clear_screen(char * const);
void print_screen(char const * const);

int main() {

	int timeStep = 0;
	const int stopTime = 60;

	char* screen = new char[screenSize];
	
	const int particleNumber = 4;
	Particle particles[particleNumber];	

	particles[0].initialise('*',1,1);
	particles[1].initialise('+',2,2);
	particles[2].initialise('x',3,3);
	particles[3].initialise('o',4,4);
	
	while (timeStep < stopTime) {
		clear_screen(screen);
		for (int i=0; i<particleNumber; i++){
			particles[i].draw(screen);
			particles[i].move();
		}
		print_screen(screen);
		timeStep++;
	}
	delete [] screen;
}

void clear_screen(char * const screen){
	for (int i =0; i<screenSize; i++){
		i[screen] = ' ';
	}
}

void print_screen(char const * const screen){
	for (int i = 0; i<screenSize; i++){
		cout << *(screen + i);
	}
	cout << endl;
}