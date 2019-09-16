#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <bitset>
#include <cstring>
#include <stdlib.h>
#include <time.h>

using namespace std;

int modulo(int dividendo, int divisor);

class vernam{
private:
	string clave;

public:
	string alf = "abcdefghijklmnopqrstuvwxyz0123456789 ";

	vernam(string mensaje);
	vernam(string clav, vector<string> mensaje);

	vector<string> cifrado(string mensaje);
	string decifrado(vector<string> mensaje);
	string get_clave() {return clave;}
};