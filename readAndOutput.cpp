#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "ticTacToeClass.h"

void readAndOutput(std::ifstream& in,std::ostream& out)
 {
        std::vector<std::string> commands{};
        std::vector<int> args{};

        std::string str{};
        std::string word{};

        getline(in, str);
        std::stringstream ss(str);
        while (ss >> word)
            commands.push_back(word) ;

        getline(in, str);
        ss.str(str) ;
        ss.clear();

        while(ss>>word)
              args.push_back(std::stoi(word)) ;

        auto format = [](std::string str) {
            for (auto &ch : str) ch = tolower(ch);
            return str;
        };

        auto iter1 = args.begin();
        auto iter2 = commands.begin()+1;

        if (iter1 != args.end()) {
            ticTacToe obj(*iter1++);
            out<<"Null " ;
            while (iter2 != commands.end()) {
                if (format(*iter2) == "move") {
                    if (iter1 != args.end() && iter1 + 1 != args.end() && iter1 + 2 != args.end()) {
                        out<<obj.Move(*iter1, *(iter1 + 1), *(iter1 + 2)) << " " ;
                        iter1 += 3;
                    }
                } else if (format(*iter2) == "print") {
                    obj.print();
                } else if (format(*iter2) == "newgame") {
                    obj.newGame();
                }

                iter2++;
            }
       }
 }
