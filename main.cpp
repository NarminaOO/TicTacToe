#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "tictactoe.h"
#include <gtest/gtest.h>
#include "TicTacToe.cpp"

TEST(ticTacToe,firstPlayerWins) {
  ticTacToe obj(3) ;
  ASSERT_EQ(0,obj.Move(0,0,1)) ;
  ASSERT_EQ(0,obj.Move(0,1,2)) ;
  ASSERT_EQ(0,obj.Move(1,0,1)) ;
  ASSERT_EQ(0,obj.Move(0,2,2)) ;
  ASSERT_EQ(1,obj.Move(2,0,1)) ;
}

TEST(ticTacToe,SecondPlayerWins) {
  ticTacToe obj(3) ;
  ASSERT_EQ(0,obj.Move(0,0,2)) ;
  ASSERT_EQ(0,obj.Move(0,1,1)) ;
  ASSERT_EQ(0,obj.Move(1,0,2)) ;
  ASSERT_EQ(0,obj.Move(0,2,1)) ;
  ASSERT_EQ(2,obj.Move(2,0,2)) ;
}

TEST(ticTacToe,Draw) {
  ticTacToe obj(3) ;
  ASSERT_EQ(0,obj.Move(0,0,1)) ;
  ASSERT_EQ(0,obj.Move(0,1,2)) ;
  ASSERT_EQ(0,obj.Move(0,2,1)) ;
  ASSERT_EQ(0,obj.Move(1,0,2)) ;
  ASSERT_EQ(0,obj.Move(1,1,1)) ;
  ASSERT_EQ(0,obj.Move(2,2,2)) ;
  ASSERT_EQ(0,obj.Move(2,1,1));
  ASSERT_EQ(0,obj.Move(2,0,2));
  ASSERT_EQ(0,obj.Move(1,2,1)) ;
}

TEST(ticTacToe,OutOfRange)
{
  ticTacToe obj(3) ;
  ASSERT_EQ(0,obj.Move(0,0,1) ) ;
  ASSERT_EQ(-1,obj.Move(0,0,2)) ;
  ASSERT_EQ(-1,obj.Move(4,1,1)) ;
  ASSERT_EQ(-1,obj.Move(2,2,4)) ;
}

/*void readAndOutput(std::ifstream& in,std::ostream& out)
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
 } */

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();


	/*std::ifstream in("input.txt");
        if (!in.is_open() ) {
            std::cerr << "Error opening file\n";
            return -1;
        }

        std::ofstream out("output.txt") ;
        if(!out.is_open() ) {
            std::cerr << "Error opening output file\n" ;
           return -1 ;
        }

    readAndOutput(in,out) ; */
    return 0 ;

}


