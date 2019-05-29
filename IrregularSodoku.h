#ifndef IRREGULARSODOKU
#define IRREGULARSODOKU
#include <iostream>
#include <vector>

class IrregularSodoku {
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
        IrregularSodoku(bool = false);
        IrregularSodoku(int, std::vector<std::vector<int>>, std::vector<std::vector<std::pair<int, int>>>,
                std::vector<std::vector<std::pair<int, int>>>, std::vector<std::vector<bool>>);
        
        // Copy Constructor
        IrregularSodoku(const IrregularSodoku &);
        // Copy Assignment
        IrregularSodoku& operator=(IrregularSodoku &);

        int runDfs(int, int);

        friend std::ostream& operator<<(std::ostream &, const IrregularSodoku &);
};

std::ostream& operator<<(std::ostream &, const IrregularSodoku &);

#endif
