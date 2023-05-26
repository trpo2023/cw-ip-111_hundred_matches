#include "game.hpp"

void game__Computer()
{
}

void game__Players()
{
}

void game__Secret()
{
}

void game__End()
{
	system("clear");
	while (true)
	{
		std::string choose = input("\nЖелаете начать новую игру? (y|n)");
		switch (choose[0])
		{
		case 'y':
			menu__Game();
			break;
		case 'n':
			menu();
			break;
		default:
			std::cout << "\nОшибка! Такого выбора нет в списке.\n"
								<< "Для продолжения нажмите Enter...\n";
			std::cin.ignore().get();
		}
	}
}