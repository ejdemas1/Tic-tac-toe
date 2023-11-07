#include <iostream>
#include <vector>

std::vector<std::vector<int> > PlayerTurn(int player, std::vector<std::vector<int> > board);

void PrintBoard(std::vector<std::vector<int> > board);

bool CheckWin(std::vector<std::vector<int> > board, int player);

bool CheckFull(std::vector<std::vector<int> > board);