#ifndef Screen_hh
#define Screen_hh

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

#endif
