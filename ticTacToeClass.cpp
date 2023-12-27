#include <iostream>
#include <memory>
#include <vector>
#include <type_traits>
#include "ticTacToeClass.h"

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
int ticTacToe::checkForWinner() 
{
    int count1{}, count2{};

    if (turn == n * n) 
    {
        gameEnded = true;
    }

    for (size_t i = 0; i < n; ++i) 
    {
        count1 = 0;
        count2 = 0;

        for (size_t j = 0; j < n; ++j) 
        {
            if (count1 != 0 && count2 != 0)
                break;

            if ((*grid)[i][j] == 1)
                count1++;
            else if ((*grid)[i][j] == 2)
                count2++;
        }
        if (count1 == n)
            return 1;
        if (count2 == n)
            return 2;
    }

    for (size_t i = 0; i < n; ++i) 
    {
        count1 = 0;
        count2 = 0;

        for (size_t j = 0; j < n; ++j) 
        {
            if (count1 != 0 && count2 != 0)
                break;

            if ((*grid)[j][i] == 1)
                count1++;
            else if ((*grid)[j][i] == 2)
                count2++;
        }
        if (count1 == n)
            return 1;
        if (count2 == n)
            return 2;
    }

    count1 = 0;
    count2 = 0;

    for (size_t i = 0; i < n; ++i) 
    {
        if (count1 != 0 && count2 != 0)
            break;
        if ((*grid)[i][i] == 1)
            count1++;
        else if ((*grid)[i][i] == 2)
            count2++;
    }

    if (count1 == n)
        return 1;
    if (count2 == n)
        return 2;

    count1 = 0;
    count2 = 0;

    for (size_t i = 0; i < n; ++i) 
    {
        if (count1 != 0 && count2 != 0)
            break;
        if ((*grid)[n - i - 1][i] == 1)
            count1++;
        else if ((*grid)[n - i - 1][i] == 2)
            count2++;
    }

    if (count1 == n)
        return 1;
    if (count2 == n)
        return 2;

    return 0;
}

void ticTacToe::newGame() 
{
    grid->clear();
    grid = std::make_unique<std::vector<std::vector<int>>>(n, std::vector<int>(n, 0));
    gameEnded = false;
    turn = 0;
    prevPlayed = 0;
}


