#include <iostream>

using std::cout; using std::endl;

template< typename T>
void myswap(T& a, T&b){
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main(){
	int a = 1;
	int b = 2;
	cout << a << " " << b << endl;
	myswap(a,b);
	cout << a << " " << b << endl;
}