#include "RSA.h"
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <stdlib.h>
#include <time.h>
#include "matematica.h"

using namespace std;

string alf = "*abcdefghijklmnopqrstuvwxyz0123456789 ";

template<class T>
void generar(T &p, T &q) {

	srand(time(NULL));
	T tam = aleatorio<T>(alf.size(), alf.size() / 2);
	while (modulo<T>(tam, 2) != 0) {
		srand(time(NULL));
		tam = aleatorio<T>(alf.size(), alf.size() / 2);
	}

	string clave;

	srand(time(NULL));
	for (unsigned long long int i = 0; i < tam; i++) {
		T num = aleatorio<T>(size(alf), (size(alf)) / 2);
		clave += alf[num];
	}
	//cout << "CLAVE: " << clave << endl;

	vector<string> c;
	for (T i = 0; i < tam; i++) {

		T temp = alf.find(clave[i]);
		c.push_back(to_string(temp));

		T temp2 = stoi(c[i]);
		bitset<6> b(temp2);
		c[i] = b.to_string();
	}

	vector<T> n;
	for (T i = 0; i < c.size(); i += 2) {
		string num = c[i] + c[i + 1] ; //+c[i + 2]
		T temp = stoi(num, nullptr, 2);
		//cout << temp << endl;
		n.push_back(temp);
	}

	vector<T> crina;
	crina = criba<T>(999999);
	//cout << "TAMANO DE LA CRIBA: " << crina.size() << endl;

	srand(time(NULL));
	p = crina[n[aleatorio(n.size())]];
	q = crina[n[aleatorio(n.size() - 1)]];
	while(q == p){
		srand(time(NULL));
		q = crina[n[aleatorio(n.size())]];
	}
}

RSA::RSA() {
	
	unsigned long long int p, q;
	generar<unsigned long long int>(p, q);
	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
	N = p * q;
	cout << "N: " << N << endl;
	unsigned long long int fi_N = (p - 1) * (q - 1);
	cout << "fi_N: " << fi_N << endl;
	srand(time(NULL));
	unsigned long long int e = aleatorio<unsigned long long int>(fi_N, 2);
	while(euclides<unsigned long long int>(e,fi_N)!= 1){
		srand(time(NULL));
		e = aleatorio<unsigned long long int>(fi_N, 2);
	}
	cout << "e: " << e << endl;
	clave_publica = e;
	clave_privada = inversa<unsigned long long int>(clave_publica, fi_N);
	cout << '\n';
	cout << "clave_privada: " << clave_privada << endl;
	cout << "clave_publica: " << clave_publica << endl;
	/*
	clave_privada = 40053119;
	clave_publica = 15815;
	N = 197916379;
	*/
}

vector<unsigned long long int> RSA::cifrado(unsigned long long int c_publica, unsigned long long int N, string mensaje) {
	vector<unsigned long long int> sms;
	for (unsigned long long int i = 0; i < mensaje.size(); i++) {
		unsigned long long int num = alf.find(mensaje[i]);
		sms.push_back(exponensiacion<unsigned long long int>(num, c_publica, N));
	}
	return sms;
}

string RSA::descifrado(vector<unsigned long long int> mensaje) {
	string resultado;
	for (unsigned long long int i = 0; i < mensaje.size(); i++) {
		unsigned long long int temp = exponensiacion<unsigned long long int>(mensaje[i], clave_privada, N);
		resultado += alf[temp];
	}
	return resultado;
}