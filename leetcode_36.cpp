// 36. Valid Sudoku

// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

// The Sudoku board could be partially filled, where empty cells are filled 
// with the character '.'.

// A partially filled sudoku which is valid.

// Note:
// A valid Sudoku board (partially filled) is not necessarily solvable. 
// Only the filled cells need to be validated.

#include "leetcode.hpp"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> aux(9, 0);
        for(const auto& vc : board)
        {
            for(char ch : vc)
            {
                if(ch == '.') continue;
                if(aux[ch - '1']) return false;
                ++aux[ch - '1'];
            }
            aux.assign(9, 0);
        }
        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                char ch = board[j][i];
                if(ch == '.') continue;
                if(aux[ch - '1']) return false;
                ++aux[ch - '1'];
            }
            aux.assign(9, 0);
        }
        for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                for(int x = 3 * i; x < 3 * (i + 1); ++x)
                {
                    for(int y = 3 * j; y < 3 * (j + 1); ++y)
                    {
                        char ch = board[x][y];
                        if(ch == '.') continue;
                        if(aux[ch - '1']) return false;
                        ++aux[ch - '1'];
                    }
                }
                aux.assign(9, 0);
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    CHECK_TRUE(sln.isValidSudoku(board));
    
    TEST_REPORT();
}
