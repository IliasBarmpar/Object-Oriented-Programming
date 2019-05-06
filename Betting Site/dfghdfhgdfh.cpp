#include <iostream>

using namespace std;

class A {
   public:
      virtual void print(){ cout << "print A" << endl; };
};

class B: public A {
    public:
        void print(){ cout << "print B" << endl; };
};

class C: public B {
     public:
        void print(){ 
        B::print();
		cout << "print C" << endl; };
};

int main()
{
   A *a = new C();

   a->print(); // will print 'print A'
  // b->print(); // will print 'print C'

   return 1;
}

