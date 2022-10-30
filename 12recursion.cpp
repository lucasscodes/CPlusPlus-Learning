#include <iostream>
using namespace std;

//TODO: You stopped here!

char text[] = {'H','a','l','l','o','!',};

void rekursion(char * input, int len, int now = 0);

int main () {
    rekursion(text, 6);
    return 0;
}

void rekursion(char input[], int len, int now) { //Defaultparam from the FuncPrototype seems to work here!
    if (len != 1) {
        cout << input[now];
        rekursion(input, len-1, now+1);
    }
    else {
        cout << input[now];
    }
}