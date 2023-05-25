#include "menu.h"
std::string input(const std::string &str)
{
	std::cout << str
						<< "\n> ";
	std::string Answer;
	std::cin >> Answer;
	return Answer;
}

void menu()
{
	while (true)
	{
		system("clear");
		std::string choose = input(
				"Добро пожаловать в игру \"Сто спичек\"!\n"
				"1) Начать игру\n"
				"2) Правила игры\n"
				"3) Авторы игры\n"
				"Для выхода из игры введите клавишу \'q\'\n");
		switch (choose[0])
		{
		case '1':
			menu__Game();
			break;
		case '2':
			menu__Rules();
			break;
		case '3':
			menu__Authors();
			break;
		case 'q':
		case 'Q':
			menu__Quit();
			return;
		default:
			std::cout << "\nОшибка! Такого выбора нет в списке.\n"
								<< "Для продолжения нажмите Enter...\n";
			std::cin.ignore().get();
		}
	}
}
void menu__Game()
{
	while (true)
	{
		system("clear");
		std::string choose = input(
				"Выберите режим игры:\n"
				"1) Игра с компьютером\n"
				"2) Игра с другим игроком\n"
				"Для выхода из игры введите клавишу \'q\'\n");
		switch (choose[0])
		{
		case '1':
			game__Computer();
			break;
		case '2':
			game__Players();
			break;
		case '3':
			game__Secret();
			break;
		case 'q':
		case 'Q':
			return;
		default:
			std::cout << "\nОшибка! Такого выбора нет в списке.\n"
								<< "Для продолжения нажмите Enter...\n";
			std::cin.ignore().get();
		}
	}
}
void menu__Rules()
{
	system("clear");
	std::cout << "\"Сто спичек\" - это игра, где изначально имеется куча, состоящая из 100 спичек.\n"
						<< "Игроки берут поочередно из этой кучи от 1 до 10 спичек в один ход.\n"
						<< "Игра заканчивается, если один из игроков возьмет последнюю оставшуюся спичку.\n"
						<< "\nДля продолжения нажмите Enter...\n";
	std::cin.ignore().get();
}
void menu__Authors()
{
	system("clear");
	std::cout
			<< "\bАвторы игры:\n"
			<< "\tИП-111 Корнилов А.А. (-=Foxyn=-);\n"
			<< "\tИП-111 Попов М.И (Underground_Evo)\n"
			<< "\nДля продолжения нажмите Enter...\n";
	std::cin.ignore().get();
}
void menu__Quit()
{
	system("clear");
	std::cout << "Спасибо, что пользовались нашим продуктом.\n"
						<< "Всего вам хорошего!\n"
						<< "\nДля продолжения нажмите Enter...\n";
	std::cin.ignore().get();
}