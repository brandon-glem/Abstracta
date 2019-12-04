#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <NTL/ZZ.h>
#include <sstream>

using namespace std;
using namespace NTL;

class RC4
{
private:
	vector<ZZ> S;
	vector<ZZ> key;
public:
	RC4(long bits);
	void inicializacion(long bits);
	ZZ num_ale(long bits, ZZ in, ZZ fin);
};