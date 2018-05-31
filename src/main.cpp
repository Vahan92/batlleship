#include "battleship.hpp"

int main() 
{
	int N = 10;  /** Intenger N's value determine sea (board) size (N*N) */
	int** sea = create_sea(N); /** \brief creating sea matrix */
	input(sea);
	return 0;
}






