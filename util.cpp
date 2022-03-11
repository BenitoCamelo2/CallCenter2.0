#include <iostream>
#include "util.h"

using namespace std;

int countDigits(int n){
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}

//if there is no upper or lower limit, you assign max or min to -1 depending on the situation
bool verifyINT(int min, int max, int n){
    if(max == -1){
        if(n >= min){
            return true;
        } else {
            return false;
        }
    } else if (min == -1){
        if(n <= max){
            return true;
        } else {
            return false;
        }
    } else {
        if(n >= min && n <= max){
            return true;
        } else {
            return false;
        }
    }
}

void listHeader(){
    cout << "|Nombre             " << "|Codigo             " << "|Especialidad       " << "|Horas        " << "|Horas extras|" << endl;
}