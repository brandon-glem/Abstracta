#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <stdlib.h>
#include <time.h>
#include "matematica.h"

using namespace std;

class RSA{
private:
	unsigned long long int clave_privada;
	unsigned long long int N;

public:
	unsigned long long int clave_publica;

	RSA();

	vector<unsigned long long int> cifrado(unsigned long long int c_publica, unsigned long long int N, string mensaje);

	string descifrado(vector<unsigned long long int> mensaje);
};

template<class T>
void generar(T &p, T &q);