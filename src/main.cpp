#include "battleship.hpp"
#include <iostream>
using namespace std;
int main() 
{
	
	int N = 10;  /** Intenger N's value determine sea (board) size (N*N) */
	int** sea = create_sea(N); /** \brief creating sea matrix */
  //int** sea_new = matrix (  sea , N);
	//show_sea( sea_new,  N);
	//int n = right_number_of_squares(sea_new,N);
	//cout << n;
	input(sea);
	
	return 0;
}






