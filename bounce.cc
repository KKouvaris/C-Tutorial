// N.B. This program contains a bug, on purpose.

#include <iostream>

using std::cout; using std::endl;

const int minColumn = 0;
const int maxColumn = 80;
const int screenSize = maxColumn - minColumn + 1;

struct Particle{
	char symbol;
	double position;
	double speed;
};

void draw(Particle const * const, char * const);
void move(Particle* const);
void clear_screen(char * const);
void print_screen(char const * const);

int main() {

	int timeStep = 0;
	const int stopTime = 60;

	char* screen = new char[screenSize];
	
	const int particleNumber = 4;	
	Particle particles[particleNumber] = {	{'*',1,1},
											{'+',2,2},
											{'x',3,3},	
											{'o',4,4}};
											
	while (timeStep < stopTime) {
		clear_screen(screen);
		for (int i=0; i<particleNumber; i++){
			draw(&particles[i],screen);
			move(&particles[i]);
		}
		print_screen(screen);
		timeStep++;
	}
	delete [] screen;
}

void draw(Particle const * const p, char * const screen){
	screen[static_cast<int>(p->position)]= p->symbol; 
}

void move(Particle* const p){
  //move start
    p->position += p->speed;
    if (p->position >= maxColumn) {
      p->position = maxColumn;
      p->speed = -p->speed;
    } else if (p->position < minColumn) {
      p->position = minColumn;
      p->speed = -p->speed;
    }
	//move stop
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