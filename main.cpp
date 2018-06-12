#include <iostream>
#include "Digital.h"

int main(int argc, char** argv) {
	std::cout << "Hello world!\n";
	Digital *digital = new Digital(3, 3);
	digital->showMap();
	delete digital;
}
