#ifndef IRREGULARSudoku
#define IRREGULARSudoku
#include <iostream>
#include <vector>

class IrregularSudoku {
    private:
        // size of board
        int n;
        // boardByRegion[i][j] stores j-th cell of region i
        std::vector<std::vector<int>> boardByRegion;
        // boardByRow[i][j] stores which (region, cell) does i-th row, j-th column corresponds to
        std::vector<std::vector<std::pair<int, int>>> boardByRow;
        // regionToRowCol[i][j] is the inverse mapping of boardByRow, this is helps us map between region, row and column
        std::vector<std::vector<std::pair<int, int>>> regionToRowCol;
        // filled[i][j] == 1 means region i's j-th cell is prefilled
        std::vector<std::vector<bool>> filled;

        // helper functions
        int readInput();
        bool checkValidInRegion(int, std::vector<int>&);
        bool checkValidInRowCol(int, int, int, std::vector<std::vector<int>> &,
                        std::vector<std::vector<std::pair<int, int>>> &);
    
    public:
        IrregularSudoku(bool = false);
        IrregularSudoku(int, std::vector<std::vector<int>>, std::vector<std::vector<std::pair<int, int>>>,
                std::vector<std::vector<std::pair<int, int>>>, std::vector<std::vector<bool>>);
        
        // Copy Constructor
        IrregularSudoku(const IrregularSudoku &);
        // Copy Assignment
        IrregularSudoku& operator=(IrregularSudoku &);

        int runDfs(int, int);

        friend std::ostream& operator<<(std::ostream &, const IrregularSudoku &);
};

// Overloading << operator for IrregularSudoku
std::ostream& operator<<(std::ostream &, const IrregularSudoku &);

#endif
