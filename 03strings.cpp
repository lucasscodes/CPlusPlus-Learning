#include <stdio.h> //comes later
#include <iostream>
using namespace std;

struct person{ //comes later
    char * name; //printf only works if this isnt a string?
    int age;
};

int main () {
    string sometext="This is a new te"; //Declaring a string
    string sometext2="xt!"; //String concat

    cout << "Initial value of sometext is: " << sometext+sometext2 << endl;  //Writing the initial text to the console.
    //Note: that endl isn't needed to show the value on the console, but adds a new line at the end

    getline(cin, sometext);  //Reading textinput from the keyboard

    cout << "You entered: " << sometext << endl;  //Writing the given text back to the console.


    //dont care about the following, just check the terminal values
    person p1;
    p1.name = (char *)"John", p1.age = 27;
    string test = p1.name;
    cout << test << endl;
    printf("%s\n", p1.name); // should print "John"

    return 0;
}