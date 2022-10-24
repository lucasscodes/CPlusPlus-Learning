#include <iostream>
using namespace std;
int main () {
    //<type> Name[no of elements];
    int marks[5];
    marks[0] = 96;
    marks[1] = 92;
    marks[2] = 78;
    marks[3] = 54;
    marks[4] = 86;
    //int marks[5] = { 96, 92, 78, 54, 86};
    //int marks[] = { 96, 92, 78, 54, 86};
    //cout<<marks[0]<<endl;
    for(int i=0;i<5;i++) {
        cout<< marks[i] << '\n';  //for printing the i'th element
    }

    char keys[6] = {'b','c','d','a','b','b'};
    
    cout << "Third Element: "<< keys[2] << std::endl;

    return 0;
}
