#include "Pelican.h"
#include <iostream>

const float Pelican::density = 0.45f;

Pelican::Pelican(int w, int h) {
	width = w;
	height = h;
	weight = w * h;
}

void Pelican::Eat(int quantity) {
	int water = 11;
	weight = weight + quantity + water;
	int* waterptr = &water;
	int* weightptr = &weight;
	int* quantityptr = &quantity;
	std::cout << "Eating: " << quantity << std::endl;
}

void Pelican::Fly() {
	std::cout << "Flying" << std::endl;
}

void Pelican::MakeEggs() {
	std::cout << "Making eggs" << std::endl;
}