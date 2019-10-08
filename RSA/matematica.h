#pragma once
#include <vector>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

template<class T>
T modulo(T dividendo, T divisor) {
	T cociente = dividendo / divisor, residuo = dividendo - cociente * divisor;

	if (dividendo < 0) {
		residuo = divisor + residuo;
		return residuo;
	}
	return residuo;
}

template<class T>
T exponensiacion(T base, T exponente, T mod) {

	T resultado = 1;
	while (exponente > 0) {
		if ((exponente & 1) > 0) {
			resultado = modulo<T>((resultado * base), mod);
		}
		exponente >>= 1;
		base = modulo<T>((base * base), mod);
	}
	return resultado;
}

template<class T>
T aleatorio(T final, T inicio = 0) {
	
	T numero = inicio + modulo<T>(rand(), final-inicio);
	T* ptr;
	ptr = &numero;
	return *ptr;
}

template<class T>
T inversa_mod(T a, T b) {
	a = modulo<T>(a, b);
	for (T x = 1; x < b; x++) {
		if (modulo<T>((a * x), b) == 1) {
			return x;
		}
	}
}

template<class T>
T euclides(T a, T b) {
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

template<class T>
vector<T> euclides_ext(T a, T b) {
	T x, y, d;
	if (b == 0) {
		d = a;
		x = 1;
		y = 0;
		vector<T> gcd = { d, x, y };
		return gcd;
	}
	T x1 = 0, x2 = 1, y1 = 1, y2 = 0;
	while (b > 0) {
		T q = a / b;
		T r = a - (q * b);
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
	vector<T> gcd = { d,x,y };
	return gcd;
}

template<class T>
vector<T> criba(T n) {
	vector<bool> marcas;
	marcas.push_back(false);
	marcas.push_back(false);
	for (T i = 2; i <= n; ++i) {
		marcas.push_back(true);
	}
	for (T i = 2; i * i <= n; ++i) {
		if (marcas[i]) {
			for (T j = 2; i * j <= n; ++j) {
				marcas[i * j] = false;
			}
		}
	}
	vector<T> numeros;
	for (T i = 2; i <= n; i++) {
		if (marcas[i] == true) {
			numeros.push_back(i);
		}
	}
	return (numeros);
}

template<class T>
T inversa(T a, T b) {
	vector<T> x;
	x = euclides_ext<T>(a, b);
	T inverso;
	inverso = modulo<T>(modulo<T>(x[1], b) + b, b);
	return inverso;
}