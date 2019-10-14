#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class enigma{
private:
	string r_1 = "kutfhevqwnymorjp bxscgiadzl";
	string r_2 = "qknsyvrbefaomclhgpujzidw xt";
	string r_3 = "cf bamsgdotypiknxuvlrwzjqhe";

public:
	enigma(string r1, string r2, string r3);
	string cifrado(string mensaje);
	enigma(string mensaje, string r1, string r2, string r3, string alf3, string alf2, string alf1);
	string decifrado(string mensaje);
};

void orden_alf(string& a, string inicio);

