#include "enigma.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>


using namespace std;

int main(){

	ifstream texto;
	string mensaje;
	texto.open("mensaje.txt");
	getline(texto, mensaje);
	texto.close();

	string a = "hola todos";
	enigma x("b","y","g");
	x.cifrado(mensaje);
	//enigma y(x.cifrado(mensaje),"b","y","g", "cf bamsgdotypiknxuvlrwzjqhe", "qknsyvrbefaomclhgpujzidw xt", "kutfhevqwnymorjp bxscgiadzl");
	return 0;
}