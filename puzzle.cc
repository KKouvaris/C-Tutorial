struct Inner {
   Inner(int){}
};

//1
//struct Outer {
//};

//2
//struct Outer {
//	Outer(){
//		
//	}
//};
//3 
//struct Outer {
//	Outer(){
//		Inner i(3);
//	}
//};
//4
struct Outer{
	Inner i;
	Outer(){i = 3;}
}

int main() {
  Outer o;
}