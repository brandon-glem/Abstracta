#include <iostream>
#include <fstream>
#include "affine.h"

using namespace std;


int main(){
	cout << "ingrese su mensaje: ";
	string mensaje;
	getline(cin, mensaje);

	affine a;
	string tex = a.cifrado(mensaje);
	ofstream mensajecifrado;
	mensajecifrado.open("CIFRADO.txt");
	mensajecifrado << tex;
	mensajecifrado.close();
	
	
	ifstream mensajedescifrado;
	mensaje.clear();
	
	mensajedescifrado.open("CIFRADO.txt");
	getline(mensajedescifrado, mensaje);
	mensajedescifrado.close();
	
	int x,c;
	cout << "ingrese los numeros: ";
	cin >> x >> c;
	affine b(x, c);
	mensaje = b.descifrado(mensaje);
	cout << mensaje;
	
	return 0;
}