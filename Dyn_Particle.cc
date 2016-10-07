//constructors

//default constructor
Array::Array():N(0),actual_array(NULL){};
Array(const int& N){
	Particle* this->actual_array = new Particle(N);
}

//copy constructor
Array::Array(const Array& other)
:N(other.N), actual_array(new Particle[N]){
	std::copy(other.actual_array, other.actual_array + other.N, this->actual_array);
}

//assignment constructor
Array& Array::operator=(Array other){
	using std::swap;
	swap(*this,other);
	return *this;
}	

//destructor
Array::~Array(){
	delete [] this->actual_array;
}

//push back function
void Array::push_back(Particle& p){
	//increase the number of elements
	this->N++;
	//allocate memory for new array
	Particle* new_array = new Particle[this->N];
	std::swap(*this->actual_array,new_array);
	(this->actual_array[this->N]).symbol = p.symbol;
	(this->actual_array[this->N]).position = p.position;
	(this->actual_array[this->N]).speed = p.speed;
}