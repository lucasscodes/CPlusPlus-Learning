// rememb-o-matic
#include <iostream>
#include <new>
#include <iomanip>
using namespace std;

void help () {
    int i,n;
    int * p; //Creates a int array len=x
    cout << "How many numbers would you like to type? ";
    cin >> i; //gets x
    //p= new int[i]; would throw a bad_alloc exception
    p= new (nothrow) int[i]; //catches the exception, pointer would get nullptr
    if (p == nullptr)
    cout << "Error: memory could not be allocated";
    else {
        for (n=0; n<i; n++) {
            cout << "Enter number: ";
            cin >> p[n];  //write each number into the dynamicMem
        }
        cout << "You have entered: ";
        for (n=0; n<i-1; n++)
            cout << p[n] << ", ";
        cout << p[i-1] << endl; 
        delete[] p; //free the dynamicMem
    }
}
void alloc() {
    int len = 500000000;
    long double * ds; //each long double requires 128 bits = 16bytes
    ds = new (nothrow) long double[len]; 
    for (int i = 0; i<len; i++) { //Fill it, so the memory is always really in use
        ds[i]=1.0; 
    }
    //16Bytes * len / (2^10^3)Byte/GiB = GiB
    //16 * (len / 1.073.741.824) = GiB
    //len / (1.073.741.824 / 16) = GiB
    //len / 67.108.864 = GiB
    float gib = len/67108864.; //Either one of the numbers is a float or a typecast infront!
    cout << fixed << setprecision(2) << "Just allocated " << gib << "GiB of dynamic Memory!" << endl;
    delete[] ds;
    cout << "Now its free again!" << endl;
}
int main ()
{
    //help();
    //alloc();

    // TODO: Find more literature and tasks about this!
    return 0;
}
