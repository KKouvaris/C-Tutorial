	#include "Particle.hh"
	#include "Screen.hh"

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
	
