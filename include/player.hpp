#include "include.hpp"

#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

int player__GetChoice(int matches);

int player__Move(int matches);
void player__Check(int matches);

int player__Move(int matches, std::string playerName);
void player__Check(int matches, std::string playerName);
void player__Change();

#endif
