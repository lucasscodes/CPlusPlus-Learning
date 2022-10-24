#include <iostream>
using namespace std;

int squareNumbers(int x){ // Declares function "squareNumbers" that takes in parameter of x.
    int y=x*x; //creates int variable equating to x squared
    return y; //returns the value of y when the function is called
}

void helloThere(string name){//void means this function doesn't return anything
    cout << "Hello, " << name << endl;
}

//a function that prints out the sum of the given variables, a, b, and c. Below is the given code.
void sum(int a, int b, int c) {
    cout << a+b+c << endl;
}

int main () {
    int a = 1;
    int b = 4;
    int c = 3;
    int input = 9;
    cout << squareNumbers(input) << endl;
    helloThere("test");
    sum(1,2,3);
    return 0;
}