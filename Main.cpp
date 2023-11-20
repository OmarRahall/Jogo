#include "Principal.h"
#include "vetor2D.h"
#include <iostream>

int main() {

	vetor2D<float> v(1.0, 3.15);

	std::cout << 'C' << v.x << ',' << 'y' << std::endl;

	Principal principal;

	return principal.executar();
}
