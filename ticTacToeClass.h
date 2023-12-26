#pragma once
#include <iostream>
#include <vector>
#include <memory>
class ticTacToe 
{
private:
    std::unique_ptr<std::vector<std::vector<int>>> grid;
    int prevPlayed;
    int n;
    int turn;
    bool gameEnded;

public:
    template<typename onlyInt> ticTacToe(onlyInt n);
    ticTacToe() = delete;
    ticTacToe(const ticTacToe& obj) = delete;
    ticTacToe& operator=(const ticTacToe&) = delete;

    template <typename type> int Move(type col, type row, type player);
    void print();
    void newGame();
    int checkForWinner();
};
