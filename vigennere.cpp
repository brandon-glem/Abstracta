#include "vigennere.h"
#include <iostream>
#include <string.h>
#include <cstring>
#include <stdlib.h>
#include <time.h>

using namespace std;

int modulo(int dividendo, int divisor) {
	int cociente = dividendo / divisor, residuo = dividendo - cociente * divisor;

	if (dividendo < 0) {
		residuo = divisor + residuo;
		return residuo;
	}
	return residuo;
}

vigennere::vigennere(string mensaje) {
	srand(time(NULL));

	for (int i = 0; i < size(mensaje); i++) {
		int num = modulo(rand(),36);
		clave += alf[num];
	}
	cout << "CLAVE: " << clave << endl;
}

vigennere::vigennere(string c, string m) {
	clave = c;
	cout << "EL MENSAJE ES: " << descifrado(m) << endl;
}

string vigennere::cifrado(string mensaje) {
	string cifrado;
	for (int i = 0; i < size(mensaje); i++) {
		int suma = alf.find(mensaje[i]) + alf.find(clave[i]);
		cifrado += alf[modulo(suma,size(alf))];
	}
	cout << "EL MENSAJE CIFRADO ES: " << cifrado << endl;
	return cifrado;
}

string vigennere::descifrado(string mensaje) {
	for (int i = 0; i < size(mensaje); i++) {
		int m = alf.find(mensaje[i]) - alf.find(clave[i]);
		mensaje[i] = (m >= 0) ? alf[m] : alf[m + size(alf)];
	}
	return mensaje;
}

string vigennere::get_clave() {
	return clave;
}