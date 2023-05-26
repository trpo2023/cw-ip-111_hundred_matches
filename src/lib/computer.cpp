#include "computer.hpp"

int computer__GetChoice(int matches)
{
	matches__Get(matches);
	return rand() % std::min(MAX_MATCHES, matches) + 1;
}

int computer__Move(int matches)
{
	system("clear");
	std::cout << "Ход компьютера:\n";
	int computerChoice = computer__GetChoice(matches);
	std::cout << "Компьютер взял "
						<< computerChoice << " спичек\n";
	return matches__Update(matches, computerChoice);
}

void computer__Check(int matches)
{
	if (matches == 0)
	{
		std::cout << "Победа! Компьютер взял последнюю спичку на столе!\n"
							<< "\nДля продолжения нажмите Enter...\n";
		std::cin.ignore().get();
		game__End();
	}
}