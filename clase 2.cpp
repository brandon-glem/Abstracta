#include <string>
#include <iostream>
#include <vector>
#include <bitset>
#include "vernam.h"
#include "citala.h"

using namespace std;

int main() {
	
	cout << "ingrese mensaje: ";
	string pal;
	getline(cin, pal);

	vernam emisor(pal);

	vernam receptor(emisor.get_clave(), emisor.cifrado(pal));

	string mensaje = "la incriptacion es muy interesante pero mi cerebro explota wwww";
	citala emi(8,8);

	citala recep(8, 8, emi.cifrado(mensaje));

	return 0;
}