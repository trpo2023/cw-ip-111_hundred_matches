#include "player.hpp"

int player__GetChoice(int matches)
{
	matches__Get(matches);

	std::cout << "Сколько спичек хотите взять?\n"
						<< "> ";
	int choice;
	std::cin >> choice;

	while (choice < MIN_MATCHES ||
				 choice > MAX_MATCHES ||
				 choice > matches)
	{
		std::cout << "Ошибка! Пожалуйста возьмите спички от 1 до " << std::min(10, matches) << ":\t";
		std::cin >> choice;
	}

	return choice;
}