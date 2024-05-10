#pragma once
#include <map>
#include <iostream>

const enum products
{
	wood, 
	stone,
	iron,
	
	wheat,
	bread
};

static std::map<products, float> inv;

static void test() {
	inv[wood] = 10.0f;

	for (auto& [pk, am] : inv) {
		std::cout << pk << "\n" << am << std::endl;
	}
}
