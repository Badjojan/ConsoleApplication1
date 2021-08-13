#include <iostream>
#include "Sudoku.h"
using namespace std;



int main() {
    SudokuSolver ss("080090000"
        "007000509"
        "003400000"
        "000641000"
        "000008200"
        "000003870"
        "160000008"
        "400030010"
        "000000060");
    
    SudokuSolver sss(2);
    
    sss.SetGrid();
    
    sss.solve();
   
    return EXIT_SUCCESS;
    
}
