#include <include.hpp>
#include <sstream>


CTEST(menu_test, menu) {
// проверка успешного запуска меню
    menu();
}

CTEST(matches_math, matches__Update) {
// проверка подсчета спичек
    ASSERT_EQUAL(5, matches__Update(10, 5));
    ASSERT_EQUAL(0, matches__Update(5, 5));
}

CTEST(test_computer_choice, computer__GetChoice) {
// проверка выбора спичек компьютера
    int matches = 10;
    int choice = computer__GetChoice(matches);
    ASSERT_TRUE(choice >= 1 && choice <= 10 && choice <= matches);
}

CTEST(test_player_choice, player__GetChoice) {
// проверка выбора спичек игрока
    int matches = 10;
    int choice = player__GetChoice(matches);
    ASSERT_TRUE(choice >= 1 && choice <= 10 && choice <= matches);
}

