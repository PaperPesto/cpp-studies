#include <iostream>
#include "Pelican.h"

#define log(x) std::cout << x << std::endl

int main(int argc, char* argv[]) {

	log("hello world!");

	Pelican* pelican = new Pelican(2, 3);
	std::cout << "density: " << pelican->density << std::endl;

	pelican->Eat(32);
}