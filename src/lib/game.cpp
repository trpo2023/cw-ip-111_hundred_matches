#include "game.hpp"

void game__Computer()
{
	int matches = MATCHES;
	while (matches > 0)
	{
		matches = player__Move(matches);
		player__Check(matches);
		matches = computer__Move(matches);
		computer__Check(matches);
	}
}

void game__Players()
{
	std::string firstPlayerName = input(
			"\nВведите имя первого игрока:\t");
	std::string secondPlayerName = input(
			"Введите имя второго игрока:\t");
	system("clear");

	int matches = MATCHES;
	while (matches > 0)
	{
		matches = player__Move(matches, firstPlayerName);
		player__Check(matches, firstPlayerName);
		player__Change();
		matches = player__Move(matches, secondPlayerName);
		player__Check(matches, secondPlayerName);
		player__Change();
	}
}

void game__Secret()
{
	int matches = MATCHES;
	while (matches > 0)
	{
		matches = computer__Move(matches, 1);
		computer__Check(matches);
		std::cin.ignore().get();
		matches = computer__Move(matches, 2);
		computer__Check(matches);
		std::cin.ignore().get();
	}
}

void game__End()
{
	bool flag = true;
	system("clear");
	while (flag)
	{
		std::string choose = input("\nЖелаете начать новую игру? (y|n)");
		switch (choose[0])
		{
		case 'y':
			menu__Game();
			flag = false;
			break;
		case 'n':
			menu();
			flag = false;
			break;
		default:
			std::cout << "\nОшибка! Такого выбора нет в списке.\n"
								<< "Для продолжения нажмите Enter...\n";
			std::cin.ignore().get();
		}
	}
}