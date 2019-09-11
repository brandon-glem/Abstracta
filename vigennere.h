#pragma once
#include <iostream>
#include <string.h>
#include <cstring>
#include <stdlib.h>
#include <time.h>

using namespace std;

int modulo(int dividendo, int divisor);

class vigennere{
private:
	string clave;

public:
	string alf = "abcdefghijklmnopqrstuvwxyz0123456789 ";

	vigennere(string);
	vigennere(string, string);

	string cifrado(string);
	string descifrado(string);

	string get_clave();
};