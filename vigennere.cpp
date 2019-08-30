#include "vigennere.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <time.h>

using namespace std;

vigennere::vigennere() {
	clave = "";
	mensaje = "";
}

vigennere::vigennere(string c, string m) {
	clave = c;
	mensaje = m;
}

void vigennere::cifrado() {
	string pal;
	cout << "ingrese mensaje: ";
	getline(cin, pal);
	srand(time(NULL));

	for (int i = 0; i < size(pal); i++) {
		int num = rand() % (36);
		clave += alf[num];
	}
	cout << endl;

	for (int i = 0; i < size(pal); i++) {
		int suma = alf.find(pal[i]) + alf.find(clave[i]);
		mensaje += alf[suma % 37];
	}
}

void vigennere::descifrado() {
	for (int i = 0; i < size(mensaje); i++) {
		int m = alf.find(mensaje[i]) - alf.find(clave[i]);
		(m >= 0) ? mensaje[i] = alf[m] : mensaje[i] = alf[m + 37];
	}
	cout <<"el mensaje es: "<< mensaje;
}

string vigennere::get_mensaje() {
	return mensaje;
}

string vigennere::get_clave() {
	return clave;
}