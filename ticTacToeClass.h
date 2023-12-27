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

template <typename onlyInt>
ticTacToe::ticTacToe(onlyInt n) : n(n), turn(0), gameEnded(false), prevPlayed(0)
{
    static_assert(std::is_same<onlyInt, int>::value, "input must be integer");

    try
    {
        grid = std::make_unique<std::vector<std::vector<int>>>(n, std::vector<int>(n, 0));
    }
    catch (const std::bad_alloc& ex)
    {
        std::cout << "Error:" << ex.what() << "\n";
        std::cout << "Deleting object:" << "\n";
        grid.reset(nullptr);
    }
}

template <typename onlyInt>
int ticTacToe::Move(onlyInt col, onlyInt row, onlyInt player) {
    static_assert(std::is_same<onlyInt, int>::value, "input must be integer");

    if (gameEnded) {
        std::cout << "Game is over\n"
            << "Start a new game?\ny/n?\n";

        char choice{};
        std::cin >> choice;

        switch (choice) {
        case 'y': {
            newGame();
            return -1;
        }
        case 'n': {
            return -1;
        }
        default:
            return -1;
        }
    }

    if (player != 1 && player != 2) {
        std::cout << "Only 2 players are allowed\n";
        return -1;
    }

    if (prevPlayed == player) {
        std::cout << "Player " << player << " made their turn twice in a row\n";
        return -1;
    }

    try {
        if ((*grid).at(row).at(col) != 0) {
            std::cout << "This square is already occupied\n";
            return -1;
        }

        if (player == 1)
            (*grid)[row][col] = player;
        else if (player == 2)
            (*grid)[row][col] = player;
    }
    catch (const std::out_of_range& exc) {
        std::cout << "Error: " << exc.what() << "\n";
        return -1;
    }

    turn++;
    int win = checkForWinner();
    if (win == 0)
        return 0;
    if (win == 1) {
        gameEnded = true;
        return 1;
    }

    if (win == 2) {
        gameEnded = true;
        return 2;
    }

    return 0;
}
