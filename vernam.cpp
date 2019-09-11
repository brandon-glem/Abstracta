#include "vernam.h"
#include <string>
#include <iostream>
#include <vector>
#include <bitset>
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

vernam::vernam(string mensaje){
	srand(time(NULL));

	for (int i = 0; i < size(mensaje); i++) {
		int num = modulo(rand(),size(alf)-1);
		clave += alf[num];
	}
	cout << "CLAVE: " << clave << endl;
}

string vernam::cifrado(string mensaje) {
	vector<string> m;
	vector<string> c;

	vector<string> cifradoB;
	string cifrado;

	int tam = size(mensaje);

	for (int i = 0; i < tam; i++) {
		int temp = alf.find(mensaje[i]);
		m.push_back(to_string(temp));

		temp = alf.find(clave[i]);
		c.push_back(to_string(temp));

		int temp2 = stoi(m[i]);
		bitset<6> a(temp2);
		m[i] = a.to_string();

		temp2 = stoi(c[i]);
		bitset<6> b(temp2);
		c[i] = b.to_string();
	}

	for (int i = 0; i < tam; i++) {
		string numero;
		for (int j = 0; j < size(m[i]); j++) {
			string temp = (m[i][j] != c[i][j]) ? "1" : "0";
			numero += temp;
		}
		cifradoB.push_back(numero);
		int tem = stoi(cifradoB[i], nullptr, 2);
		cifrado += (tem > size(alf)) ? alf[tem - size(alf)] : alf[tem];
	}
	cout << "EL MENSAJE CIFRADO ES: " << cifrado << endl;
	return cifrado;
}

vernam::vernam(string clav, string mensaje) {
	clave = clav;
	cout << "EL MENSAJE ES: "<< decifrado(mensaje)<<endl;
}


string vernam::decifrado(string mensaje) {
	vector<string> a;
	vector<string> b;

	vector<string> decifradoB;
	string decifrado;

	int tam = size(mensaje);

	for (int i = 0; i < tam; i++) {
		int temp = alf.find(mensaje[i]);
		a.push_back(to_string(temp));

		temp = alf.find(clave[i]);
		b.push_back(to_string(temp));

		int temp2 = stoi(a[i]);
		bitset<6> x(temp2);
		a[i] = x.to_string();

		temp2 = stoi(b[i]);
		bitset<6> y(temp2);
		b[i] = y.to_string();
	}
	for (int i = 0; i < tam; i++) {
		string numero;
		for (int j = 0; j < size(a[i]); j++) {
			string temp = ((a[i][j] == '0') && (b[i][j] == '0')) ? "0" : "1";
			numero += temp;
		}
		decifradoB.push_back(numero);
		int tem = stoi(decifradoB[i], nullptr, 2);
		decifrado += alf[tem];
	}
	return decifrado;
}