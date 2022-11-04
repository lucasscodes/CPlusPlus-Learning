//latest: https://github.com/NationalSecurityAgency/ghidra/releases/latest
//Guide: https://htmlpreview.github.io/?https://github.com/NationalSecurityAgency/ghidra/blob/Ghidra_10.2_build/GhidraDocs/InstallationGuide.html#Install
#include <iostream>
using namespace std;

//Declares a Class
class VerifyPass
{
private: //Hidden method inside the class
    bool validate(string name, string pass) {
        if(name == "test" && pass == "abc123") {
            return true;
        }
        return false;
    }
public: //Functions inside are callable from outside of the class
    //Constructor Method:
    VerifyPass () {
        //no need for construction
    }
    bool verifyPass(string name, string pass) {
        return validate(name, pass);
    }
};


int main() {
    VerifyPass tester;
    string name = "";
    string pass = "";
    if (tester.verifyPass(name, pass)) {
        cout << "Login successfull!" << endl;
    }
    else {
        cout << "Login failed!" << endl;
    }
    return 0;
}


/*Steps:
0.Install Ghidra
1.Open Ghidra and the exe
2.Open codeBrwoser on File
3.Analyze File
4.Symboltree/Functions/main
5.Display Decompiler
6.uVar1&2 trigger the action
7.click uVar1 definition-function
8.click uVar1 definition-function
9.Refactoring a bit yields:
    undefined _func_name1_(undefined8 param_1,undefined8 param_2,undefined8 param_3) {
        undefined uVar1; //Seems to be the return boolean!
        ulonglong uVar2;
        
        uVar2 = _func_name2_(param_2,&DAT_140004000);
        if (((char)uVar2 == '\0') || (uVar2 = _func_name2_(param_3,"abc123"), (char)uVar2 == '\0')) {
            uVar1 = 0;
        }
        else {
            uVar1 = 1;
        }
        return uVar1;
    }
10.Resolving Adress &DAT_140004000
                             //
                             // .rdata 
                             // ram:140004000-ram:140004bff
                             //
                             DAT_140004000                                   XREF[2]:     1400001e4(*), 
                                                                                          _func_name1_c
       140004000 74              ??         74h    t
       140004001 65              ??         65h    e
       140004002 73              ??         73h    s
       140004003 74              ??         74h    t
       140004004 00              ??         00h
11. So the hidden function uses 2 strings "test" & "abc123"!
12.Extract _func_name2_() for internal understanding
    ulonglong _func_name2_(undefined8 param_1,undefined8 param_2) {
        ulonglong uVar1;

        uVar1 = _func_name3_(param_1,param_2);
        return (uVar1 & 0xffffffffffffff00) | (ulonglong)((int)uVar1 == 0);
    }
13.Func Pointer resolve
                            **************************************************************
                            *                POINTER to EXTERNAL FUNCTION                *
                            **************************************************************
                            undefined _ZNKSt7__cxx1112basic_stringIcSt11char_traitsI
            undefined         AL:1           <RETURN>
                            1087  _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7
                            .idata$5                                        XREF[1]:     _ZNKSt7__cxx1112basic_stringIcSt
                            __imp__ZNKSt7__cxx1112basic_stringIcSt11char_t
    1400083ac c4 86 00        addr       LIBSTDC++-6.DLL::(...)basic_string(...)char_traits(...)compare(...)
                00 00 00 
                00 00
14.Sounds alot like std::basic_string<CharT,Traits,Allocator>::compare
15.Combine into result:
    boolean checkStrings(string param_2,string param_3) {
        if (!(param_2 == "test") || !(param_3 == "abc123")) {
            return false;
        }
        else {
            return true;
        }
    }
*/