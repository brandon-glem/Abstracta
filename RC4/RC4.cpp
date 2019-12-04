#include "RC4.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <NTL/ZZ.h>
#include <sstream>

using namespace std;
using namespace NTL;

ZZ moduloZZ(ZZ dividendo, ZZ divisor) {
	ZZ cociente = dividendo / divisor, residuo = dividendo - cociente * divisor;

	if (dividendo < 0) {
		residuo = divisor + residuo;
		return residuo;
	}
	return residuo;
}

int moduloint(int dividendo, int divisor) {
	int cociente = dividendo / divisor, residuo = dividendo - cociente * divisor;

	if (dividendo < 0) {
		residuo = divisor + residuo;
		return residuo;
	}
	return residuo;
}


string ZZ_To_String(ZZ num) {

	string var;
	stringstream y;

	y << num;
	y >> var;
	return var;

}


ZZ string_To_ZZ(string num) {
	ZZ var;
	stringstream y;

	y << num;
	y >> var;
	return var;

}

////////////////////////////////////////////////////////////////////////

RC4::RC4(long bits) {
	for (int i = 0; i < bits; i++) {
		S.push_back(ZZ(i));
	}
}

void RC4::inicializacion(long bits) {
	srand(time(NULL));

	vector<ZZ> K;
	for (int i = 0; i < bits; i++) {
		K.push_back(ZZ(rand()));
	}
	ZZ f = ZZ(0);
	for (int i = 0; i < bits; i++) {
		f = moduloZZ((f + S[i] + K[i]), ZZ(bits));
		swap(S[i], S[to_int(f)]);
	}
}

ZZ RC4::num_ale(long bits, ZZ in, ZZ fin) {
	inicializacion(bits);

	int i = 0, f = 0, t = 0, k = 0;
	while (k < bits) {
		i = moduloint((i + 1), int(bits));
		f = moduloint((f + to_int(S[i])), int(bits));
		swap(S[i], S[f]);
		t = moduloint(to_int(S[i]) + to_int(S[f]), int(bits));
		key.push_back(S[t]);
		k++;
	}

	string ale;
	string tamZZ = ZZ_To_String(fin);
	int tam = 0;
	for (int j = 0; tam < tamZZ.size(); j++) {
		ale += ZZ_To_String(key[j]);
		tam = ale.size();
	}
	ZZ num = string_To_ZZ(ale);

	return num;
}