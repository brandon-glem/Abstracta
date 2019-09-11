#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <bitset>
#include <cstring>
#include <stdlib.h>
#include <time.h>

using namespace std;

class citala{
private:
	int filas, columnas;

public:
	citala(int fil, int col);
	citala(int fil, int colum ,string mensaje);

	string cifrado(string mensaje);
	string decifrado(string mensaje);
};