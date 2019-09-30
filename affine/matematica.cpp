#include "matematica.h"
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
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

int aleatorio(int final) {
	srand(time(NULL));
	int numero = 1 + modulo(rand(),final);
	int* ptr;
	ptr = &numero;
	return *ptr;
}


int inversa_mod(int a, int b) {
	a = modulo(a, b);
	for (int x = 1; x < b; x++) {
		if (modulo((a * x),b) == 1)
			return x;
	}
}

int euclides(int a, int b) {
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

vector<int> euclides_ext(int a, int b) {
	int x, y, d;
	if (b == 0) {
		d = a;
		x = 1;
		y = 0;
		vector<int> gcd = { d, x, y };
		return gcd;
	}
	int x1 = 0, x2 = 1, y1 = 1, y2 = 0;
	while (b > 0) {
		int q = a / b;
		int r = a - (q * b);
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
	vector<int> gcd = { d,x,y };
	return gcd;
}

vector<int> criba(int n) {
	vector<bool> marcas;
	marcas.push_back(false);
	marcas.push_back(false);
	for (int i = 2; i <= n; ++i) {
		marcas.push_back(true);
	}
	for (int i = 2; i*i <= n; ++i){
		cout << "i:" << i << " " << i*i << endl;
		if (marcas[i]) {
			for (int j = 2; i*j <= n; ++j) {
				cout <<"j:"<< j << " " << i * j << endl;
				marcas[i * j] = false;
			}
		}
	}
	vector<int> numeros;
	for (int i = 2; i <= n; i++) {
		if (marcas[i] == true) {
			numeros.push_back(i);
		}
	}
	return numeros;
}