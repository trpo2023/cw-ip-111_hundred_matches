#include "player.hpp"

int player__GetChoice(int matches)
{
    matches__Get(matches);

    int choice;
    std::cout << "Сколько спичек хотите взять?\n"
              << "> ";
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

int player__Move(int matches)
{
    system("clear");
    std::cout << "Ваш ход:\n";
    int playerChoice = player__GetChoice(matches);
    return matches__Update(matches, playerChoice);
}

void player__Check(int matches)
{
    if (matches == 0)
    {
        std::cout << "Поражение! Вы взяли последнюю спичку на столе!\n"
                  << "\nДля продолжения нажмите Enter...\n";
        std::cin.ignore().get();
        game__End();
    }
}

int player__Move(int matches, std::string playerName)
{
    system("clear");
    std::cout << "Ходит " << playerName << ":\n";
    int playerChoice = player__GetChoice(matches);
    return matches__Update(matches, playerChoice);
}

void player__Check(int matches, std::string playerName)
{
    if (matches == 0)
    {
        std::cout << "Поражение! Игрок " << playerName
                  << " взял последнюю спичку на столе!\n"
                  << "\nДля продолжения нажмите Enter...\n";
        std::cin.ignore().get();
        game__End();
    }
}

void player__Change()
{
    std::cout << "\nВаш ход закончен!\n"
              << "Передайте управление другому игроку.\n"
              << "\nДля продолжения нажмите Enter...\n";
    std::cin.ignore().get();
}