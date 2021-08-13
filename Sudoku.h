#pragma once
#include <iostream>
using namespace std;
class SudokuSolver {
private:
    int grid[81];  //кол-во полей 9х9
    

public:
    SudokuSolver(int a);

    SudokuSolver(string s);

    void SetGrid() {
       cout<<this-> toString();
        cout << endl;
        int x=0;
        int y=0;
        int meaning;
        char end = 'o';
        while (x <10 &&y<10) {

            cout << "Enter the coordinates" << endl;
            
            cin >> x;
            if (x-1 > 8)break;
            cin >> y;
            if (y-1 > 8)break;
            cout << x << " : " << y << endl;
            cout << "Input meaning" << endl;
            cin >> meaning;
            grid[(x-1) * 9 + (y-1)] = meaning;
            
            cout << this->toString();
            cout << "to continue, click any letter." << endl;
            cout << "to solve it, press >9" << endl;
            
        }
    }
   

    void solve();

    void placeNumber(int pos);

    bool checkValidity(int val, int x, int y);

    string toString();

};