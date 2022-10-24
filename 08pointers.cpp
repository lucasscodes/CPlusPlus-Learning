// This will explain how pointers are used
#include <iostream> 
using namespace std; 

void help () {
    int a = 5;  //Declare and initialize a variable
    /* The following pointer declarations are all valid and they all are doing the same:
    Declaring a new pointer and initializing it with 0 (a non accessible memory address) for safety-reasons.
    int * b = 0;
    int* b = 0                 
    int *b = 0; // This is how its usually written.
    int *b; // <= this, however would cause "b" to point to some random address which might be unsafe. */
    int *b = 0; // Create a new pointer of type int and initialize it with 0

    cout << "\"b\" is initialized and now pointing to memory-address:  " << b << endl << endl;

    //Now make the pointer "point" to the address of a
    b = &a; //"b" now points to the address of "a"

    cout << "\"a\" is stored at memory-address:  " << &a << endl;
    cout << "\"b\" is stored at memory-address:  " << &b << endl;
    cout << "\"b\" is pointing to memory-address now:  " << b << endl << endl;

    cout << "The value of \"a\" is: " << a << endl;  // returns the value of a

    //the "*b" will get the value from the address b points to (the value of a)
    cout << "The value of the area \"b\" is pointing to is: " << *b << endl << endl << endl;

    //Now modify the value of the address "b" is pointing to...effectively changing the value of "a"     
    *b=10;

    cout << "\"a\" is still stored at memory-address:  " << &a << endl;
    cout << "\"b\" is still stored at memory-address:  " << &b << endl;
    cout << "\"b\" is still pointing to memory-address:  " << b << endl << endl;

    cout << "The value of \"a\" is now: " << a << endl;  // returns the value of a
    cout << "The value of the area \"b\" is pointing to is now: " << *b << endl << endl;

    void* p1;
    char* p2;
    // p2 = p1;         Valid in C but not C++!
    p2 = (char*) p1; // In C++ we have to typecast the pointer!
    /* C++ has also:
    1. Constant pointer, in which the address pointed to cannot be changed.
    2. Pointer to constant, in which the contents pointed to cannot be modified. */
}

int main() 
{
    int n = 1;
    
    //Indirectly access and modify the value of "n": 
    void* pointer1; //p1 being the void pointer
    int* pointer2; //and p2 the int pointer
    pointer1 = &n; //Create 2 pointers for the given integer "n"
    pointer2 = (int*) pointer1; //p2 must be assigned to p1
    (*pointer2)++; //indirectly increase the value of n's content by 1 and print the value

    cout << "n was 1 now its: " << n << endl; // <- This should print "2" without n being modified directly.
  
    return 0;
}