# include "../../src/battleship.hpp"
# include <iostream>
# include <fstream>
# include <string>
using namespace std;

 
int main(int argc, char const *argv[])
{
    /* code */
    int x = 2;
    int y = 1;
    ofstream file;
    file.open("./test_results/test1.txt");
    if ( ! file.is_open() ) {
        std::cerr << "couldn't open the file to write test results..." << '\n';
    }
    file << "results of test1"<<endl;
    bool ok = normal_coordinates(x,y,10);
    if (ok) {
        file << " test1 passed"<<endl;
    } else {
        file << "test1 failed"<<endl;
    }
    file.close();
    return 0;
}