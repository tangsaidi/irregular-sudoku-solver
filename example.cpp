#include <iostream>
#include <vector>
#include <utility>
#include <ctime>
#include "IrregularSudoku.h"

int main(int argc, char *argv[]) {
    // Construct IrregularSudoku Object
    bool silent = false;
    if (argc != 1) {
        const char * silentFlag = "--silent";
        if (!strcmp(argv[1], silentFlag)) {
            silent = true;    
        }
    }

    IrregularSudoku iso = IrregularSudoku(silent);
    std::cout << iso;

    int repeats = 20;
    std::vector<IrregularSudoku> isoArr(repeats, IrregularSudoku(iso));
    std::cout << "=====================" << std::endl;
    clock_t tStart = clock();
    
    if (iso.runDfs(0, 0) == 0) {
        std::cout << "Time taken: " << (double)(clock() - tStart)/(CLOCKS_PER_SEC) << "s" << std::endl;
        std::cout << "Solved Board" << std::endl;
        std::cout << iso;
        double sum = 0;
        for (int i = 0; i < repeats; i++) {
            tStart = clock();
            isoArr[i].runDfs(0, 0);
            sum += clock() - tStart;
        }
        std::cout << "Average time over " << repeats << " runs is " << sum / repeats / CLOCKS_PER_SEC << " seconds" << std::endl;
    } else {
        std::cout << "Time taken: " << (double)(clock() - tStart)/(CLOCKS_PER_SEC) << "s" << std::endl;
        std::cout << "No solution found" << std::endl;
    }
    return 0;
}