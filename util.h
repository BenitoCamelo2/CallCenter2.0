//
// Created by Benito on 09/02/2022.
//

#ifndef PROGRAMA_UTIL_H
#define PROGRAMA_UTIL_H

enum opcionesSplash{
    SPLASH_AGENTE=1,
    SPLASH_CLIENTE,
    SPLASH_READ,
    SPLASH_WRITE
};

int countDigits(long long n);

bool verifyINT(int min, int max, int n);

void listHeader();


#endif //PROGRAMA_UTIL_H
