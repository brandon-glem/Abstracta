#include "affine.h"

#include <iostream>
#include <string>
#include "matematica.h"

using namespace std;

string alfabeto = "abcdefghijklmnopqrstuvwxyz0123456789 ";

int inversa(int a, int b) {
	vector<int> x;
	x = euclides_ext(a, b);
	int inverso = modulo(modulo(x[1], b) + b, b);
	return inverso;
}

affine::affine() {
	clav1 = aleatorio(alfabeto.size());
	while(euclides(clav1, alfabeto.size()) != 1) {
		clav1 = aleatorio(alfabeto.size());
	}
	clav2 = aleatorio(alfabeto.size()-1);
}

affine::affine(int a, int b) {
	clav1 = inversa(a, alfabeto.size());
	clav2 = b;
}

string affine::cifrado(string mensaje) { 
	string cifrado;
	for (int i = 0; i < mensaje.size(); i++) {
		int pos = alfabeto.find(mensaje[i]);
		pos = modulo((clav1 * pos) + clav2, alfabeto.size());
		cifrado += alfabeto[pos];
	}
	cout << "clave1: " << clav1 << " " << "clave2: " << clav2 << endl;
	return cifrado;
}

string affine::descifrado(string mensaje) { 
	string descifrado;
	for (int i = 0; i < mensaje.size(); i++) {
		int pos = alfabeto.find(mensaje[i]);
		pos = modulo(clav1 * (pos - clav2), alfabeto.size());
		descifrado += alfabeto[pos];
	}
	return descifrado;
}