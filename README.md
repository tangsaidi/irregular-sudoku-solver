# Irregular Sudoku Solver
> *A Sudoku solver that solves Sudoku of any shapes*

Sudoku nowadays not only come in the shape of typical 9*9 grids, lots of variants have emerged over the years. There are lots of variants, and normal Sudoku solvers are not designed for these problems. Irregular Sudoku solver is a solver that aims to solve Sudoku's with the grids in any arbitrary shapes!

Exmples of such Sudokus can be found here:
[Puzzles by Andrew Lamonica](http://lamonica.info/CAOSPuzzle/U.html)
[Jigsaw Sudoku](https://www.puzzle-jigsaw-sudoku.com/)

### Board Construction Manual
> By default, the program provides hints on what to be entered next. The hints can be silenced with "--silent" flag
> Example inputs can be found in the [/tests](/tests) folder

1. Enter the size of the Sudoku, `n`. `n` can be any integer greater than 0. Numbers greater than 15 can lead to relatively long runtime.
2. Divide your board into `n` regions. And denote them as region `0`to region `n - 1`. For each region, denote each cell within the region from cell `0` to cell `n - 1`. So, now each cell on the board can be expressed as a binary tuple `(region, cell)` 
3. Enter already filled in numbers into the board, in the format of `region cell number` for each number. `number` should be restricted to `1` to `n`.
4. When all the filled numbers are entered. Enter `-1`.
5. Finally, enter the layout of the board row by row, so our program knows which cells belong to this row. For each row, we expect `n` pairs of tuple in the format of `region cell`.

Note: The order of how regions or cells are numbered do not matter, as long as it makes sense to you. This structure is complex but ensures that sudoku in any shapes can be supported. The regions don't even need to be connected.

### Get Started with Examples
1. Compile the program using command
```
g++ -std=c++14 -o solver IrregularSudoku.cc example.cpp
```
2. Run the compiled program with provided test files
```
./solver --silent < tests/test7.txt
```

### Program in Action
#### Solve 6 \* 6
![6 * 6 Puzzle from lamonica.info](/assets/solve6.png)

#### Solve 7 \* 7
![7 * 7 Puzzle from lamonica.info](/assets/solve7.png)

#### Solve 9 \* 9
![9 * 9 Puzzle from lamonica.info](/assets/solve9.png)


### Performance
Benchmarked on MacBook Air 2014 with 1.4 GHz Intel i5 processor, 8 GB RAM

Below is an average over 20 runs of each puzzle
```
 __________________________
| 6 * 6  |  0.0001865 sec  |
|________|_________________|
| 7 * 7  |  0.0001777 sec  |
|________|_________________|
| 9 * 9  |  0.0489505 sec  |
|________|_________________|
```
Note: The shorter runtime of the 7\*7 puzzle in this case is not representative. As the puzzle itself can have varying level of diffuclties.

### Test Files
5 test files are provided and include sudoku of size 1, 2, 6, 7, 9
The irregular sudoku of size 6, 7, 9 are credit to [Lamonica.info](http://lamonica.info/CAOSPuzzle/U.html) 

### Major TODOs
- Decouple board and solver into separate classes
- Optimize solver strategy
- Provide better user interface
