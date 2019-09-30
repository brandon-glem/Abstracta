#pragma once
#include <vector>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

int modulo(int dividendo, int divisor);

int aleatorio(int final);

int inversa_mod(int a, int b);

int euclides(int a, int b);

vector<int> euclides_ext(int a, int b);

vector<int> criba(int n);