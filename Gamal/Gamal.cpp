#include "Gamal.h"
#include <vector>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <NTL/ZZ.h>
#include "RC4.h"
#include <fstream>
#include <math.h>
#include <sstream>

using namespace std;
using namespace NTL;

string alf = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";

ZZ modulo(ZZ dividendo, ZZ divisor) {
	ZZ cociente = dividendo / divisor, residuo = dividendo - cociente * divisor;

	if (dividendo < 0) {
		residuo = divisor + residuo;
		return residuo;
	}
	return residuo;
}

ZZ exponensiacion(ZZ base, ZZ exponente, ZZ mod) {

	ZZ resultado = to_ZZ("1");
	while (exponente > 0) {
		if ((exponente & 1) > 0) {
			resultado = modulo((resultado * base), mod);
		}
		exponente >>= 1;
		base = modulo((base * base), mod);
	}
	return resultado;
}

ZZ aleatorio(ZZ final, ZZ inicio = to_ZZ("0")) {

	ZZ numero = inicio + modulo((ZZ)rand(), final - inicio);
	ZZ* ptr;
	ptr = &numero;
	return *ptr;
}

ZZ euclides(ZZ a, ZZ b) {
	while (a != b) {
		if (a > b) {
			a -= b;
		}
		else {
			b -= a;
		}
	}
	return a;
}

vector<ZZ> euclides_ext(ZZ a, ZZ b) {
	ZZ x, y, d;
	if (b == 0) {
		d = a;
		x = 1;
		y = 0;
		vector<ZZ> gcd = { d, x, y };
		return gcd;
	}
	ZZ x1 = to_ZZ("0"), x2 = to_ZZ("1"), y1 = to_ZZ("1"), y2 = to_ZZ("0");
	while (b > 0) {
		ZZ q = a / b;
		ZZ r = a - (q * b);
		x = x2 - (q * x1);
		y = y2 - (q * y1);
		a = b;
		b = r;
		x2 = x1;
		x1 = x;
		y2 = y1;
		y1 = y;
	}
	d = a;
	x = x2;
	y = y2;
	vector<ZZ> gcd = { d,x,y };
	return gcd;
}

ZZ inv(ZZ a, ZZ b) {
	ZZ inver = to_ZZ("1");
	while (modulo(a * inver, b) != 1) {
		inver++;
	}
	return inver;
}

ZZ generador(ZZ p) {
	ZZ q = (p - 1) / 2;
	bool found = false;
	ZZ g = to_ZZ("0");
	while (found != true && g <= (p - 1)) {
		g++;
		if ((exponensiacion(g, ZZ(2), p) != 1) && (exponensiacion(g, q, p) != 1)) {
			found = true;
		}
	}
	return g;
}

bool miillerTest(ZZ d, ZZ n) {
	ZZ a = 2 + modulo(ZZ(rand()), (n - 4));

	ZZ x = exponensiacion(a, d, n);

	if (x == 1 || x == n - 1)
		return true;

	while (d != n - 1) {
		x = modulo((x * x), n);
		d *= 2;

		if (x == 1)      return false;
		if (x == n - 1)    return true;
	}
	return false;
}

bool prim_test(ZZ n, int k = 5) {
	if (n <= 1 || n == 4)  return false;
	if (n <= 3) return true;

	ZZ d = n - 1;
	while (modulo(d, ZZ(2)) == 0)
		d /= 2;

	for (int i = 0; i < k; i++)
		if (!miillerTest(d, n))
			return false;

	return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int modulo_int(int dividendo, int divisor) {
	int cociente = dividendo / divisor, residuo = dividendo - cociente * divisor;

	if (dividendo < 0) {
		residuo = divisor + residuo;
		return residuo;
	}
	return residuo;
}

string ZZToString(ZZ num) {

	string var;
	stringstream y;

	y << num;
	y >> var;
	return var;

}

ZZ stringToZZ(string num) {
	ZZ var;
	stringstream y;

	y << num;
	y >> var;
	return var;

}

Gamal::Gamal(long bits) {
	P = RandomPrime_ZZ(bits);
	/*
	ZZ inter_may = power2_ZZ(bits) - 1;
	ZZ inter_men = power2_ZZ(bits) / 2;

	RC4 a(bits);
	P = a.num_ale(bits, inter_men, inter_may);

	while (prim_test(P) != true) {
		P = a.num_ale(bits, inter_men, inter_may);
	}*/
	
	cout << "P: " << P << endl;
	
	e1=generador(P);
	cout << "e1: " << e1 << endl;

	srand(time(NULL));
	d = aleatorio(P - 2, ZZ(2));
	cout << "d: " << d << endl;

	e2 = exponensiacion(e1, d, P);
	cout << "e2: " << e2 << endl;
}

Gamal::Gamal(ZZ _e1, ZZ _e2, ZZ _P) {
	e1 = _e1;
	e2 = _e2;
	P = _P;
}

vector<ZZ> Gamal::cifrado(string mensaje) {
	ofstream tex;
	tex.open("texto.txt");

	string numero;
	for (int i = 0; i < mensaje.size(); i++) {
		if (alf.find(mensaje[i]) > alf.find(" "))
			numero += to_string(alf.find(mensaje[i]));
		else
			numero += ("0"+to_string(alf.find(mensaje[i])));
	}

	cout << numero << endl;

	vector<ZZ> texto;
	srand(time(NULL));
	ZZ r = aleatorio(P - 2, ZZ(2));
	
	ZZ C1 = exponensiacion(e1, r, P);
	ZZ KM = exponensiacion(e2, r, P);
	cout << C1 << endl;

	texto.push_back(C1);
	tex << C1 << endl;

	for (int i = 0; i < mensaje.size(); i++) {
		ZZ C2 = modulo(KM*ZZ(alf.find(mensaje[i])),P);
		texto.push_back(C2);
		tex << C2 << endl;
	}
	tex.close();
	return texto;
}

string Gamal::descifrado(string archivo) {
	string texto;
	ifstream tex;
	tex.open(archivo);

	string num;
	getline(tex,num);

	//cout << num << endl;
	ZZ alk;
	alk = stringToZZ(num);

	ZZ KM = exponensiacion(alk,d,P);
	KM = inv(KM, P);
	
	while (!tex.eof()) {
		getline(tex, num);
		alk = stringToZZ(num);
		ZZ temp = alk * KM;
		temp = modulo(temp, P);
		texto += alf[to_int(temp)];
	}
	/*
	for (int i = 1; i < mensaje.size(); i++) {
		ZZ temp = mensaje[i] * KM;
		temp = modulo(temp, P);
		texto += alf[to_int(temp)];
	}*/

	tex.close();
	return texto;
}