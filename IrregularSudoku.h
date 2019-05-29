#ifndef IRREGULARSudoku
#define IRREGULARSudoku
#include <iostream>
#include <vector>

class IrregularSudoku {
    private:
        int n;

        std::vector<std::vector<int>> boardByRegion;
        std::vector<std::vector<std::pair<int, int>>> boardByRow;
        std::vector<std::vector<std::pair<int, int>>> regionToRowCol;
        std::vector<std::vector<bool>> filled;

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

std::ostream& operator<<(std::ostream &, const IrregularSudoku &);

#endif
