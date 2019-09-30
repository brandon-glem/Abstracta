#pragma once
#include <iostream>
#include <string>
#include "matematica.h"

using namespace std;

class affine{
private:
	int clav1;
	int clav2;
public:
	affine();
	affine(int a, int b);

	string cifrado(string mensaje);
	string descifrado(string mensaje);
};

