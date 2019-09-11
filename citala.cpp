#include "citala.h"
#include <string>
#include <iostream>
#include <vector>
#include <bitset>
#include <cstring>
#include <stdlib.h>
#include <time.h>
using namespace std;

citala::citala(int fil, int col) {
	filas = fil;
	columnas = col;
}

citala::citala(int fil, int colum ,string mensaje) {
	filas = fil;
	columnas = colum;
	cout << "EL MENSAJE ES: " << decifrado(mensaje) << endl;
}

string citala::cifrado(string mensaje) {
	string cifrado;
	for (int i = 0; i < columnas; i++) {
		int t = i;
		while (t < size(mensaje)) {
			cifrado += mensaje[t];
			t += columnas;
		}
	}
	cout << "EL MENSAJE CIFRADO ES: " << cifrado << endl;
	return cifrado;
}

string citala::decifrado(string mensaje) {
	string decifrado;
	for (int i = 0; i < filas; i++) {
		int t = i;
		while (t < size(mensaje)) {
			decifrado += mensaje[t];
			t += filas;
		}
	}
	return decifrado;
}