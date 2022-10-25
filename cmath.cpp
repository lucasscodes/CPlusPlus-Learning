#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
using namespace std;

/*https://cplusplus.com/reference/cmath/
cos, sin, tan, acos, asin, atan, atan2, 
cosh, sinh, tanh, acosh, asinh, atanh, 
exp, log, log10, log1p, 
float and binary stuff,
pow, sqrt, cbrt, hypot,
erf, erfc, tgamma, lgamma, 
ceil, floor, trunc, round, lround, rint, lrint, llrint, nerbyint,
etc*/

void showRndFlrCeilTrnc() {
    const char * format = "%.1f \t%.1f \t%.1f \t%.1f \t%.1f\n";
    printf ("value\tround\tfloor\tceil\ttrunc\n");
    printf ("-----\t-----\t-----\t----\t-----\n");
    printf (format, 2.3,round( 2.3),floor( 2.3),ceil( 2.3),trunc( 2.3));
    printf (format, 3.8,round( 3.8),floor( 3.8),ceil( 3.8),trunc( 3.8));
    printf (format, 5.5,round( 5.5),floor( 5.5),ceil( 5.5),trunc( 5.5));
    printf (format,-2.3,round(-2.3),floor(-2.3),ceil(-2.3),trunc(-2.3));
    printf (format,-3.8,round(-3.8),floor(-3.8),ceil(-3.8),trunc(-3.8));
    printf (format,-5.5,round(-5.5),floor(-5.5),ceil(-5.5),trunc(-5.5));
}

int main ()
{
    //Terminal Snail for fun
    int width = 100; //width of the snail in terminal
    float sin2arr = (width-1)/2;
    float deg2rad = 180/3.1415926535897932384626433; //rad = deg/deg2rad
    char arr[width+1];
    for (char& c : arr) { c=' ';} //fill arr with spaces
    arr[width+1] = '\n'; //last one triggers newline

    for (int i=0; i<1; i++) { //for every repetition
        for(int deg = 0; deg < 360; deg++) {
            float rad = deg/deg2rad;//rad = deg/(180/pi)
            float x = sin (rad); //-1 to 1
            x = round((x+1)*sin2arr); //0 to width-1 in int

            arr[(int)x] = 'O';
            cout << arr;
            arr[(int)x] = ' ';
            
            this_thread::sleep_for(chrono::milliseconds(1)); //C++ is far too fast
        }
    }
    return 0;
}