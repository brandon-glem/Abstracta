#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	string alf = "abcdefghijklmnopqrstuvwxyz0123456789 ";
	string pal;
	getline(cin, pal);

	srand(time(NULL));
	
	string clave;
	for (int i = 0; i < size(pal); i++) {
		int num = rand() % (0 - 36);
		clave += alf[num];
	}

	cout << clave;

	

	return 0;
}