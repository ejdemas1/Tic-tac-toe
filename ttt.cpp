#include <iostream>
#include "ttt.h"

int main() {
    
    //board setup
    std::vector<std::vector<int> > board;
    std::vector<int> empty(3, 0);
    board.push_back(empty);
    board.push_back(empty);
    board.push_back(empty);
    PrintBoard(board);

    bool game_over = false;

    while(game_over == false) {
        board = PlayerTurn(1, board);

        if (CheckWin(board, 1)) {
            PrintBoard(board);
            std::cout << "Player 1 wins!!!";
            game_over = true;
            break;
        } else {
            if (CheckFull(board)) {
            std::cout << "BOARD FULL NO WINNER" << std::endl;
            break;
        }
        }
        PrintBoard(board);

        board = PlayerTurn(2, board);
        if (CheckWin(board, 2)) {
            PrintBoard(board);
            std::cout << "Player 2 wins!!!";
            game_over = true;
            break;
        }  else {
            if(CheckFull(board)) {
                std::cout << "BOARD FULL NO WINNER" << std::endl;
                break;
            }
        }
        PrintBoard(board);
    }
    std::cout << "Game Over!" << std::endl;
    return 0;
}


std::vector<std::vector<int> >  PlayerTurn(int player, std::vector<std::vector<int> > board) {
    int row;
    int col;
    bool is_valid_turn = false;

    while (!is_valid_turn) {
        std::cout << "Player: " << player << " turn, select row (1, 2, or 3): " << std::endl;
        std::cin >> row;
        std::cout << "Player: " << player << " turn, select col (1, 2, or 3): " << std::endl;
        std::cin >> col;
        if (row >= 1 && row <= 3 && col >= 1 && col <= 3) {
            if (board[row - 1][col - 1] != 0) {
                std::cout << "Invalid spot already taken, try again" << std::endl;
            } else {
                std::cout << "Valid spot!" << std::endl;
                board[row - 1][col - 1] = player;
                is_valid_turn = true;
            }
        } else {
            std::cout << "Invalid spot out of range, try again" << std::endl;
        }
    }
    return board;
}

void PrintBoard(std::vector<std::vector<int> > board) {
    for(int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            std::cout << board[i][j];
        }
        std::cout << "\n";
    }
}

bool CheckWin(std::vector<std::vector<int> > board, int player) {
    //rows
    for (int i = 0; i < board.size(); i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == player) {
            return true;
        }
    }

    //cols
    for (int i = 0; i < board.size(); i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == player) {
            return true;
        }
    }


    //diagnols
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[1][3] == player) {
        return true;
    }

    return false;
}

bool CheckFull(std::vector<std::vector<int> > board) {
    int counter = 0;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] != 0) {
                counter++;
            }
        }
    }
    if (counter == 9) {
        return true;
    }
    return false;
}
