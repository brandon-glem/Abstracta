#pragma once
#include <string>

using namespace std;

class vigennere
{
private:
	string alf = "abcdefghijklmnopqrstuvwxyz0123456789 ";
	string clave;
	string mensaje;

public:
	vigennere();
	vigennere(string, string);

	void cifrado();
	void descifrado();

	string get_mensaje();
	string get_clave();
};
