#include <iostream>
#include "matematica.h"
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <bitset>
#include "RSA.h"

using namespace std;

int main(){

	RSA a;
	
	bool exit = false;

	cout << '\n';
	cout << "CIFRAR -> c" << endl << "DESCIFRAR -> d" << endl << "CLAVE PUBLICA -> clave" << endl << "EXIT -> salir" << endl;
	cout << '\n';
	while(exit == false){
		string opcion;
		vector<unsigned long long int> cifra;
		string men;
		unsigned long long int mod;
		unsigned long long int c_publica;

		vector<unsigned long long int> temp;
		unsigned long long int letras;
		unsigned long long int number;

		cout << "opcion: ";
		cin >> opcion;

		if (opcion == "c") {
			cifra.clear();
			cout << "ingrese mensaje: ";
			cin >> men;
			cout << "ingrse modulo: ";
			cin >> mod;
			cout << "ingrese clave publica: ";
			cin >> c_publica;
			cifra = a.cifrado(c_publica, mod, men);
			for (unsigned long long int i = 0; i < cifra.size(); i++) {
				cout << cifra[i] << endl;
			}
		}
		if (opcion == "d") {
			temp.clear();
			cout << "cuantas letras tiene el mensaje: ";
			cin >> letras;
			for (unsigned long long int i = 0; i < letras; i++) {
				cout << "numero: ";
				cin >> number;
				temp.push_back(number);
			}
			men = a.descifrado(temp);
			cout << "el mensaje es: " << men << endl;
		}
		if (opcion == "clave") {
			cout << "PUBLICA: " << a.clave_publica << endl;
		}
		if (opcion == "salir") {
			exit = true;
		}
	}
	return 0;
}