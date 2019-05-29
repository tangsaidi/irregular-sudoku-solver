#include "IrregularSodoku.h"
#include <vector>
#include <iostream>


// Checks whether the guess is legal within the region
bool IrregularSodoku::checkValidInRegion(int guess, std::vector<int>& region) {
    for (int i = 0; i < region.size(); ++i) {
        if (region[i] == guess) return false;
    }
    return true;
}

// Checks whether the guess is legal within the row and column
bool IrregularSodoku::checkValidInRowCol(int guess, int row, int col, std::vector<std::vector<int>> &boardByRegion,
                        std::vector<std::vector<std::pair<int, int>>> &boardByRow) {
    std::vector<std::pair<int, int>>& rowVec = boardByRow[row];
    for (int i = 0; i < rowVec.size(); ++i) {
        if (boardByRegion[rowVec[i].first][rowVec[i].second] == guess) return false;
    }
    for (int i = 0; i < rowVec.size(); ++i) {
        if (boardByRegion[boardByRow[i][col].first][boardByRow[i][col].second] == guess) return false;
    }
    return true;
}

// A constructor that reads input from standard in
IrregularSodoku::IrregularSodoku(bool silent) {
    std::cin >> n;
    if (!silent) {
        std::cout << "Please enter filled number in the format of 'i j n' where i is the region number, j is j-th number within the region and n is the number you are entering (i, j are 0 indexed)"<< std::endl;
        std::cout << "When you are done, simply enter '-1'" << std::endl;
    }
    
    int region, jth, filledNumber;
    boardByRegion = std::vector<std::vector<int>> (n, std::vector<int> (n, -1));
    boardByRow = std::vector<std::vector<std::pair<int, int>>>(n, std::vector<std::pair<int, int>> (n, std::make_pair(-1, -1)));
    regionToRowCol = std::vector<std::vector<std::pair<int, int>>>(n, std::vector<std::pair<int, int>> (n, std::make_pair(-1, -1)));
    filled = std::vector<std::vector<bool>> (n, std::vector<bool> (n, false));

    while (std::cin >> region) {
        if (region != -1) {
            std::cin >> jth >> filledNumber;
            boardByRegion[region][jth] = filledNumber;
            filled[region][jth] = true;
        } else {
            break;
        }
    }
    if (!silent) {
        std::cout << "You have entered all filled numbers by region" << std::endl;
        std::cout << "Enter the board by row next, we expect n pairs of 'i j' for each row, i is region, j is j-th number in the region" << std::endl;
    }
    
    // Creates a bijection between region and board
    for (int i = 0; i < n; ++i) {
        if (!silent) std::cout << "Row " <<  i << std::endl;
        for (int j = 0; j < n; ++j) {
            std::cin >> region >> jth;
            boardByRow[i][j] = std::make_pair(region, jth);
            regionToRowCol[region][jth] = std::make_pair(i, j);
        }
    }
}

IrregularSodoku::IrregularSodoku(int n, std::vector<std::vector<int>> boardByRegion, std::vector<std::vector<std::pair<int, int>>> boardByRow,
                std::vector<std::vector<std::pair<int, int>>> regionToRowCol, std::vector<std::vector<bool>> filled): n(n), boardByRegion(boardByRegion),
                boardByRow(boardByRow), regionToRowCol(regionToRowCol), filled(filled) {};

IrregularSodoku::IrregularSodoku(const IrregularSodoku & other): n(other.n), boardByRegion(other.boardByRegion),
                boardByRow(other.boardByRow), regionToRowCol(other.regionToRowCol), filled(other.filled) {}

IrregularSodoku& IrregularSodoku::operator=(IrregularSodoku & other) {
    if (this == &other) return *this;
    IrregularSodoku tmp = IrregularSodoku(other);
    std::swap(n, tmp.n);
    std::swap(boardByRegion, other.boardByRegion);
    std::swap(boardByRow, tmp.boardByRow);
    std::swap(regionToRowCol, tmp.regionToRowCol);
    std::swap(filled, tmp.filled);
    return *this;
}

int IrregularSodoku::runDfs(int region, int jth) {
    int ending = boardByRegion.size();
    // check ending condition
    if (region >= ending) return 0;

    // if the slot is filled, skip
    if (filled[region][jth]) {
        if (jth < ending - 1) return runDfs(region, jth + 1);
        return runDfs(region + 1, 0);
    }


    // Attempting all possible numbers
    for (int i = 1; i < ending + 1; ++i) {
        if (checkValidInRegion(i, boardByRegion[region]) &&
            checkValidInRowCol(i, regionToRowCol[region][jth].first,
                regionToRowCol[region][jth].second, boardByRegion, boardByRow)) {
            boardByRegion[region][jth] = i;
            if (jth < ending - 1){
                if (runDfs(region, jth + 1) == 0) {
                    return 0;
                }
            } else {
                if (runDfs(region + 1, 0) == 0) {
                    return 0;
                }
            }
            boardByRegion[region][jth] = -1;
        }
    }
    return -1;
}


std::ostream& operator<<(std::ostream & outs, const IrregularSodoku & iso) {
    for (int i = 0; i < iso.n; ++i) {
        for (int j = 0; j < iso.n; ++j) {
            int num = iso.boardByRegion[iso.boardByRow[i][j].first][iso.boardByRow[i][j].second];
            if (num  == -1) {
                std::cout << "| " ;
            } else {
                std::cout << "|" << num;
            }
        }
    std::cout << "|" << std::endl;
    }
    return outs;
}