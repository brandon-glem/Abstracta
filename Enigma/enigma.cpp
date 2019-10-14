#include "enigma.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

string alf = "abcdefghijklmnopqrstuvwxyz ";
string alf_1;
string alf_2;
string alf_3;

int vueltas = 4;

void orden_alf(string &a, string inicio) {
	string temp,temp1;
	temp.assign(alf, 0, alf.find(inicio));
	temp1.assign(alf, alf.find(inicio), size(alf));
	a += temp1;
	a += temp;
}

enigma::enigma(string r3, string r2, string r1) {
	orden_alf(alf_1, r1);
	orden_alf(alf_2, r2);
	orden_alf(alf_3, r3);
}

string enigma::cifrado(string mensaje) {
	string cifrado;
	for (int i = 0; i < size(mensaje); i++) {
		string letra;
		int pos;
		
		pos = alf.find(mensaje[i]);
		letra = r_3[pos];
		pos = alf_3.find(letra);
		letra = r_2[pos];
		pos = alf_2.find(letra);
		letra = r_1[pos];
		pos = alf_1.find(letra);
		letra = alf[pos];
		cifrado += letra;

		string mover1;
		//string mover2;
		mover1.assign(alf_3, 0, 1);
		//mover2.assign(r_3, 0, 1);
		alf_3.erase(0,1);
		//r_3.erase(0, 1);
		alf_3 += mover1;
		//r_3 += mover2;

		if (i > vueltas) {
			mover1 = mover1.assign(alf_2, 0, 1);
			//mover2 = mover2.assign(r_2, 0, 1);
			alf_2.erase(0, 1);
			//r_2.erase(0, 1);
			alf_2 += mover1;
			//r_2 += mover2;
		}

		if (i > (vueltas * 2)) {
			mover1 = mover1.assign(alf_1, 0, 1);
			//mover2 = mover2.assign(r_1, 0, 1);
			alf_1.erase(0, 1);
			//r_1.erase(0, 1);
			alf_1 += mover1;
			//r_1 += mover2;
		}
	}
	cout << "EL MENSAJE CIFRADO ES: " << cifrado << endl;
	return cifrado;
}

enigma::enigma(string mensaje, string r3, string r2, string r1, string alf3, string alf2, string alf1) {
	alf_1.clear();
	alf_2.clear();
	alf_3.clear();
	orden_alf(alf_1, r1);
	orden_alf(alf_2, r2);
	orden_alf(alf_3, r3);
	r_3 = alf3;
	r_2 = alf2;
	r_1 = alf1;
	cout << "EL MENSAJE ES: " << decifrado(mensaje) << endl;
}

string enigma::decifrado(string mensaje) {
	string decifrado;
	for (int i = 0; i < size(mensaje); i++) {
		string letra;
		int pos;

		pos = alf.find(mensaje[i]);
		letra = alf_1[pos];
		pos = r_1.find(letra);
		letra = alf_2[pos];
		pos = r_2.find(letra);
		letra = alf_3[pos];
		pos = r_3.find(letra);
		letra = alf[pos];
		decifrado += letra;

		string mover1;
		//string mover2;
		mover1.assign(alf_3, 0, 1);
		//mover2.assign(r_3, 0, 1);
		alf_3.erase(0, 1);
		//r_3.erase(0, 1);
		alf_3 += mover1;
		//r_3 += mover2;

		if (i > vueltas) {
			mover1 = mover1.assign(alf_2, 0, 1);
			//mover2 = mover2.assign(r_2, 0, 1);
			alf_2.erase(0, 1);
			//r_2.erase(0, 1);
			alf_2 += mover1;
			//r_2 += mover2;
		}

		if (i > (vueltas * 2)) {
			mover1 = mover1.assign(alf_1, 0, 1);
			//mover2 = mover2.assign(r_1, 0, 1);
			alf_1.erase(0, 1);
			//r_1.erase(0, 1);
			alf_1 += mover1;
			//r_1 += mover2;
		}
	}
	return decifrado;
}