# TicTacToe
![2911080](https://github.com/NarminaOO/TicTacToe/assets/149943881/ea6c1055-2c77-443d-b1e6-a01ba00e7493)

**tic-tac-toe class** allows user to create n*n grid to play a game of tic-tac-toe.Since default constructor is deleted,the only way to create a grid is via constructor that takes type OnlyInt which permits user to give as parameter any type besides int(otherwise compilation error will occur).Smart pointer is used for creating vector 'n' elements of which are vectors with size 'n',unique_ptr allows us to stick to default constructor. 

**int turn** - counter of turns,makes it possible not ot check after every turn whether grid is full and just end game if turn=n*n(i.e all squares are filled).
**bool gameEnded** - checks whether game ended or not.

**Move function** takes row and column on which player makes their move . Following conditions are checked: 
1)If game ended,user has a choice to start a new game. Any move is prohibited since all squares are filled . 
2)Only 2 players are allowed to play.
3)Player can't make their move twice in a row. 
(Additionally .at ensures that input is not out of range) 
At the end,function that checks,whether there is a winner,is invoked and corresponding value is returned: 
0 if neither player won yet,or if it's draw.
1 if player N1 won.
2 if player N2 won.

**CheckForWinner()** checks for winner(or draw if are squares are filled) by checking necessary conditions horizontally,vertically,diagonally from bottom to top and from top to bottom(check for count1!=0 && count2!=0 ensures that there won't be unnecessary checks)

**Print()** prints the current state of the game . 

**NewGame()** starts a new game . 



**readAndOutput()** reads first line from input which is supposed to be line with arguments separated by space.It then adds them to vector.
Same happens with arguments.
By iterating over two vectors given commands and their corresponding arguments are extracted and,if command is correct,it is invoked.
(Commands are case-insensetive).
**IMPORTANT:** function does not verify whether input is correct or not,for correct output all commands has to be correct,separated by space,and given their corresponding arguments. 

**CMakeLists:**
It's required to have at least CMake 3.10,having c++20 standart(in order to use type_traits) and having GTest installed.


**main.cpp:**
4 tests are used to verify correctness of code for following conditions:
1)Player 1 wins
2)Player 2 wins
3)It's draw and all squares are filled.
4)Out of range conditions described in Move function description.


**Time complexity-O(n^2)** because Move function is constant(since accessing element in vector requires constant time) and in Move function we invoke checkForWinner() function in which we iterate over vector of vectors 4 times,which gives time complexity O(4n^2)=O(n^2).
Memory requirment is also O(n^2) since we allocate vector of n vectors with size n.Other types take constant space.
