#include <stdio.h>
#include <iostream>
using namespace std;

void addoneUseless(int n) {// n is local variable which only exists within the function scope
    n++; // therefore incrementing it has no effect
}
void addone(int *number) {
    // n is a pointer here which point to a memory-adress outside the function scope
    (*number)++; // this will effectively increment the value of n
}
void help() {
    int n;
    printf("Before: %d\n", n);
    addoneUseless(n);
    printf("After: %d\n", n);

    int n2;
    printf("Before: %d\n", n2);
    addone(&n2);
    printf("after: %d\n", n2);
    /*Notice that when calling the addone function, 
    we must pass a reference (note the "&"-sign) to the variable n, 
    and not the variable itself - this is done so that the function knows the address of the variable, 
    and won't just receive a copy of the variable itself.*/
}

struct person {
    char * name;//use "char *" instead of string for printf!
    int age;
};
/* function declaration, write your code here */
void birthday(person *per) {
    (*per).age++; //get the pointed person and incr. its age
}

int main() {
    help();

    person john;
    john.name = (char *)"John", john.age = 27;
    printf("%s is %d years old.\n", john.name, john.age); //%s seems to need char * instead of string!
    birthday(&john); //Write a function called birthday, which adds one to the age of a person.
    printf("Happy birthday! %s is now %d years old.\n", john.name, john.age);

    return 0;
}