#pragma once
#include <vector>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <NTL/ZZ.h>
#include "RC4.h"

using namespace std;
using namespace NTL;

class Gamal
{
private:
	
public:
	ZZ d;
	ZZ e1;
	ZZ e2;
	ZZ P;

	Gamal(long bits);
	Gamal(ZZ e1, ZZ e2, ZZ P);

	vector<ZZ> cifrado(string mensaje);
	string descifrado(string archivo);

};
