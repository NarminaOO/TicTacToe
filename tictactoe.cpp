#include <iostream>
#include <memory>
#include <vector>
#include <type_traits>
#include "tictactoe.h"

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

void ticTacToe::print() 
{
    for (auto iter1 = grid->begin(); iter1 != grid->end(); ++iter1) 
    {
        for (auto iter2 = iter1->begin(); iter2 != iter1->end(); ++iter2) 
        {
            if (*iter2 == 0)
                std::cout << " ? ";
            else if (*iter2 == 1)
                std::cout << " X ";
            else if (*iter2 == 2)
                std::cout << " O ";
        }
        std::cout << "\n";
    }
}

