#include "Sudoku.h"



SudokuSolver::SudokuSolver(int a)
{
    for (unsigned int i = 0; i < 81; i++) {//перебор от 0 до конца строки
        grid[i] = 0;
    }
   
}



    SudokuSolver::SudokuSolver(string s)
{
    for (unsigned int i = 0; i < s.length(); i++) {//перебор от 0 до конца строки
        grid[i] = (int)(s[i] - '0');
    }
}
    

void SudokuSolver::solve()
{
    try {
        placeNumber(0);
        cout << "Unsolvable!" << endl;
    }
    catch (char* ex) {
        cout << ex << endl;
        cout << this->toString() << endl;
    }
}

void SudokuSolver::placeNumber(int pos)
{
    if (pos == 81) {
        throw (char*)"Finished!";
    }
    if (grid[pos] > 0) {
        placeNumber(pos + 1);
        return;
    }
    for (int n = 1; n <= 9; n++) {

        if (checkValidity(n, pos % 9, pos / 9)) {
            grid[pos] = n;

            placeNumber(pos + 1);

            grid[pos] = 0;
        }
    }
}

bool SudokuSolver::checkValidity(int val, int x, int y)
{
    for (int i = 0; i < 9; i++) {
        if (grid[y * 9 + i] == val || grid[i * 9 + x] == val)//проверка по горизонтали и вертикали
            return false;
    }
    int startX = (x / 3) * 3;
    int startY = (y / 3) * 3;
    for (int i = startY; i < startY + 3; i++) {
        for (int j = startX; j < startX + 3; j++) {
            if (grid[i * 9 + j] == val)// проверка блока 3х3
                return false;
        }
    }
    return true;
}

string SudokuSolver::toString()
{
    string sb;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c[2];
            c[0] = grid[i * 9 + j] + '0';
            c[1] = '\0';
            sb.append(c);
            sb.append(" ");
            if (j == 2 || j == 5)
                sb.append("| "); //вертикальные поля
        }
        sb.append("\n");
        if (i == 2 || i == 5)
            sb.append("------+-------+------\n"); //горизонтальные поля
    }
    
    return sb;
}
