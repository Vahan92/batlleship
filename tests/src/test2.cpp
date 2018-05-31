# include "../../src/battleship.hpp"
# include <iostream>
#include <fstream>
using namespace std;

 
int main()
{
    /* code */
    //int** sea = 0;
    int size = 10;
    int units_of_ships = 9;
    int** sea =  create_sea ( size);
    int** matrix = sea;
    ofstream file;
    file.open("test2.txt");
    file << "results of test2"<<endl;
    int countShip = rightNumberOfSquares( matrix, size);
    
    if(countShip == units_of_ships)
    {
        file << " test2 passed"<<endl;
    }
    else{
        file << "test2 failed"<<endl;
    }
    file.close();
    return 0;
}