#include "vigennere.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <time.h>

using namespace std;


int main() {
	string mensaje = "oa6hc9ce825191vxlaf6qhl2k3a24rpf1lcxb8qn0ui w";
	vigennere receptor("hxvhd7z3u31jq1dy6rb78ha3 3b0tr8b2i9yb7970s0 x", "oa6hc9ce825191vxlaf6qhl2k3a24rpf1lcxb8qn0ui w");

	cout << "ingrse mensaje: ";
	string men;
	getline(cin, men);
	vigennere emisor(men);
	
	vigennere recep(emisor.get_clave(), emisor.cifrado(men));
	return 0;
}