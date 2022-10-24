#include <iostream>
using namespace std;

void while1 () {
    int searched = 5;  //The value we're searching
    int given = -1; // The variable to which we'll write user's guesses

    //Greet the user:
    cout << "This is simple guessing game:" << endl;
    cout << "Please enter a number:" << endl;

    //This while-loop will terminate when the user entered the searched value
    while (searched != given) {
        cin >> given;  // Read a value from the keyboard
        /* Note, that the following line(s) within the loop-brackets
        will also execute if the user guessed correctly.
        Checking will be done at the start of the next iteration */
        cout << "Thank you for your guess..." << endl;  
    }
    cout << "You found the correct number. Good bye." << endl;
}

void while2 () {
    int count = 200;  // The start value
    int destination = 0;  // the destination

    // This while will normally terminate when count reaches the destination-value
    while (count > destination) {  
        count--;  // decrement count

        if (count == 190) { // If count will turn into 190...
            cout << "skipped..." << endl;
            continue; //... the while-loop will skip to the next iteration due to the "continue"-statement.
        }

        if (count < 180) { // If count falls below 180...
            cout << "aborted..." << endl;
            break; //... the while-loop will be aborted due to the "abort"-statement.
        }
        cout << count << endl;  //Note, that this will also execute when target is reached
    }

}

int main () {
    //while1();
    //while2();
    int i = 20;
    while (i > 1) {
        cout << i << ", ";
        i--;
    }
    cout << i << endl;
    return 0;
}