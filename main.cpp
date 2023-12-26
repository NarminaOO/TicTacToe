#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "ticTacToeClass.h"
#include "readAndOutput.h"
#include <gtest\gtest.h>

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

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();


	 std::ifstream in("input.txt");
        if (!in.is_open() ) {
            std::cerr << "Error opening file\n";
            return -1;
        }

        std::ofstream out("output.txt") ;
        if(!out.is_open() ) {
            std::cerr << "Error opening output file\n" ;
           return -1 ;
        }

    readAndOutput(in,out) ;
    return 0 ;

}


