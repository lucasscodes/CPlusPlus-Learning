#include <iostream>
#include <string>
using namespace std;


void rekursionPrint(char * input, int len, int now = 0); //Defaultparam will be passed down from this PrototypeFunc!
string rekursionString(char * pointer, int len, int now = 0);

int main () {
    char text[] = "Hallo!";
    void* pointer = &text;

    rekursionPrint((char *)pointer, 6);
    cout << endl << rekursionString((char *)pointer, 6) << endl;
    
    return 0;
}

void rekursionPrint(char* text, int len, int now) { 
    if (len != 1) {
        cout << text[now];
        rekursionPrint(text, len-1, now+1);
    }
    else {
        cout << text[now];
    }
}

string rekursionString(char* text, int len, int now) {
    if (now == (len-1)) {
        string res = {text[now]};
        return res;
    }
    else {
        string res = {text[now]};
        return res + rekursionString(text, len, (now+1));
    }
}