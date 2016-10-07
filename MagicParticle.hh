class MagicParticle: public Particle{
public:
	MagicParticle(): Particle() {}
	MagicParticle(char s, double p, double sp):Particle(s,p,sp){}
	virtual void move();
};

void MagicParticle::move(){
	position += speed;
	if (position >= maxColumn) {
		position = minColumn;
	} else if (position < minColumn) {
		position = minColumn;
	}
}
