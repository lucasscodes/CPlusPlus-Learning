#include <iostream>
using namespace std;

void switches(int i) {
    switch (i) {
        case 1:
            cout << "You entered 1!";
            //without a break here it will run all the next cases without checking!
        case 42:
            cout << "You entered 1 or 42!";
            break;
        default:
            cout << "You didnt entered 1 or 42!";
            break; //not needed, but helps to remember writing it always
    }
}

int main () {
    if(true and true){
        cout << "always printed!" << '\n';
    }
    if(false or ((true))){
        cout << "always printed2!" << '\n';
    }
    else if (true){
        //never reached because line 9
    }

    if(false) {}
    else if(true){
        cout << "only because false in line 15!" << '\n';
    }
    else {
        //never reached, line 15/16 will catch all cases
    }
    
    int length = 7;
    int age[] = {16,48,72,66,23,-2,200};
    for(int i = 0; i < length; i++)
    {        
        //catch crazy stuff
        if ((age[i] < 0) or (age[i] > 175)) {
            cout << "Person No."<< i+1 << " Error! " << age[i] << " is not a valid age!" << endl;
        }
        else {
            //Print the mainpattern
            cout << "Person No." << i+1 << " is " << age[i] << "yrs. old and belongs to the ";   
            //Children ( < 20 years old)
            if (age[i] < 20) {
                cout << "children!" << endl;
            }
            //Adult ( >= 20 and < 60 years old) 
            else if ((age[i] >= 20) and (age[i] < 60)) {
                cout << "adults!" << endl;
            }
            //Retired ( >= 60 years old)
            else if (age[i] >= 60){
                cout << "retired adults!" << endl;
            }
        }
    }
    switches(1);
    switches(42);
    return 0;
}