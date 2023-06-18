#include "matches.hpp"

void matches__Get(int matches)
{
	std::cout << "Сейчас " << matches << " спичек на столе.\n";
}

int matches__Update(int matches, int choice)
{
	return matches - choice;
}
