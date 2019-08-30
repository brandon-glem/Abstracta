#include "vigennere.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	vigennere emisor;
	emisor.cifrado();

	vigennere receptor(emisor.get_clave(), emisor.get_mensaje());
	receptor.descifrado();
	return 0;
}