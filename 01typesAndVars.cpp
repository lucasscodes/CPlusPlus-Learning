#include <iostream>
using namespace std;

int main () {
    typedef int counter;
    counter tick_c = 100;  // tick_c is a valid integer variable

    enum colour {red, green, blue} a_colour, another_colour;
    a_colour = green;  // a_colour will be assigned value of '1'
    cout << "a_colour: " <<  a_colour << '\n';
    cout << "another_colour: " << another_colour << '\n';

    int foo; //The variable foo can be used, but since we did not initialize it, we don't know what's in it. 
    cout << "foo: " << foo << '\n';
    int bar = 1;

    int a = 0, b = 1, c = 2, d = 3, e = 4;
    a = b - c + d * e;
    cout << "a: "<< a << '\n'; // will print 1-2+3*4 = 11
    
    bool b2 = false;
    cout << "b2: " << b2 << "\n";

    a = 3;
    float b3 = 4.5;
    double c2 = 5.25; //doubles the float precision
    double sum;

    cout << "The sum of a, b, and c is " << a+b3+c2 << std::endl;
    return 0;
}

