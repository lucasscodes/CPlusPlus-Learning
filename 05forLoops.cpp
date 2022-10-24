#include <iostream>
using namespace std;

int main () {
    int count = 10;
    // prints Hello C++ for 10 times
    for(int i = 0; i < count; i++) {
        cout << "Hello C++";
        if (i<(count-1)) {
            cout << ", ";
        }
        else {
            cout << endl;
        }
    }

    // prints numbers 0 - 9
    int i = 0;
    for( ; i < count ; )
    {
        cout << i;
        if (i < (count-1)) {
            cout << ", ";
        }
        else {
            cout << endl;
        }
        i++;
    }

    /* fetch each array-element and print it out
    int arr[] = {1,2,3,4,5,6};

    for(int n : arr)
    {
        cout << n << endl;
    }
    Warning: the example above will reference the original memory of arr[] and has write-access!

    As you often don't need to write to that adress-space, you should consider to access it read-only for safety reasons.
    To avoid write-access, you might consider using a const-reference like shown below,
    which will create a constant -and therefore unchangeable- reference named "n" to each existing value of "arr",
    effectively referncing the values read-only.

    You'll learn more about reference's and pointer's in the next chapters. */

    // fetch each array-element and print it out (readonly)
    int arr[] = {1,2,3,4,5,6};
    int len = 6;

    for(const int& n : arr)
    {
        if (n < len) {
            cout << n << ", ";
        }
        else {
            cout << n << endl;
        }
    }

    //Try to print all the even numbers below 20 using a for loop in ascending order.
    for (int i = 20; i >= 0; i--) {
        if (i % 2 == 0) { //check for even numbers mathematically
            cout << i;
            //append them in the console if there will be more
            if (i > 0) {
                cout << ", ";
            }
            else { //last one closes the cout
                cout << endl;
            }
        }
    }
    return 0;
}