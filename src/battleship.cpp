#include "battleship.hpp"

//#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <assert.h> 
using namespace std;

void input(int** sea) 
{
	int N = 10;
	int number_of_ships = 4; /** \brief Integer number_of_ships's value defines ships quantity */
	int ships[4]; /** \brief creating array with the length of 4 */
	ships[0] = 1;
	ships[1] = 1;
	ships[2] = 1;
	ships[3] = 1;
	int number_of_units = 0; /** \brief Initial unit number is 0 */

	int x = 0;
	int y = 0;	
	int position = 0; /** \brief how to put ships(vertical or hotizontal) */
	int returned_value; /** \brief cheks if the position is ok/invalid position/out of sea */
	int kill_result; /** \brief is the result of shooting */

	for (int i = 0; i < number_of_ships; i++) {
		number_of_units += ships[i] * (i + 1);
	}

	for (int i = number_of_ships - 1; i >= 0; --i) {
		while (ships[i] > 0) {
			cout << "the size of ship is " << i + 1 << "put it on a position you want..." << ships[i] << endl;
			cout << "choose the ordinate" << endl;
			cin >> x;
			cout << "choose the abscissa" << endl;
			cin >> y;
			assert(x);
			assert(y);
			cout << "choose the direction, 0 denotes vertical, 1 denotes horisontal \n";
			cin >> position;
			if (position == 0) {
				returned_value = put_vertical(sea, x - 1, y - 1, i + 1, N);
			}	else if (position == 1) {
				returned_value = put_horizontal(sea, x - 1, y - 1, i + 1, N);
			}	else {
				cout << "Incorrect direction\n";
				continue;
			}
	    
			if (returned_value == 0) {
				ships[i]--;
				show_sea(sea, N);
			} else if (returned_value == 1) {
				cout << "invalid position\n";
			} else if (returned_value == 2) {
				cout << "out of the sea \n";
			}
		}
	}
	//show_sea(sea, N);
	cout << "starting the game\n";

	while (number_of_units > 0) 
	{
		cout << "insert axis\n";
		cin >> x;
		cout << "insert ordinate\n";
		cin >> y;
		cout << endl;
		kill_result = kill_ship(sea, x - 1, y - 1, N);
		if (kill_result == 2) {
			cout << "out of the sea!!!\n";
		} else if (kill_result == 1) {
			cout << "Missed\n";
		} else if (kill_result == 0) {
			cout << "Ship is destroyed\n";
			number_of_units--;
		} else if (kill_result == 3) {
			cout << "...\n";
		}
		show_sea(sea, N);
	}

	cout << "You won\n";
	clean(sea,N);
}
void clean(int** sea,int N)
{
	for (int i = 0; i < N; i++)
		delete[] sea[i];
	delete[] sea;
}
int** create_sea(int N) {
	int** sea = new int*[N];
	for (int i = 0; i < N; i++)
	{
		sea[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			sea[i][j] = 0;
		}
	}

	return sea;
}

void show_sea(int** sea, int N) 
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << sea[i][j] << " ";
		}
		cout << endl;
	}
}

int put_horizontal(int** sea, int startX, int startY, int lenght, int N) {
	if (startX + lenght > N || startY >= N || startX < 0 || startY < 0) {
		return 2;
	}

	for (int i = startX - 1; i<startX + lenght + 1; ++i) {
		for (int j = startY - 1; j<startY + 2; ++j) {
			if (i >= N || j >= N || i<0 || j<0 || (j != startY && (i == startX - 1 || i == startX + lenght))) {
				continue;
			}
			if (sea[j][i] == 1) {
				return 1;
			}
		}
	}

	for (int i = startX; i< startX + lenght; ++i) {
		sea[startY][i] = 1;
	}
	return 0;
}

int put_vertical(int** sea, int startX, int startY, int lenght, int N) 
{
	if (startY + lenght > N || startX >= N || startX < 0 || startY < 0) {
		return 2;
	}

	for (int i = startY - 1; i<startY + lenght + 1; ++i) {
		for (int j = startX - 1; j<startX + 2; ++j) {
			if (i >= N || j >= N || i<0 || j<0 || (j != startX && (i == startY - 1 || i == startX + lenght))) {
				continue;
			}
			if (sea[i][j] == 1) {
				return 1;
			}

		}
	}
	for (int i = startY; i< startY + lenght; ++i) {
		sea[i][startX] = 1;
	}
	return 0;
}

int kill_ship(int** sea, int x, int y, int N) 
{
	if (x > N || x < 0 || y > N || y < 0) {
		return 2;
	}
	if (*(*(sea + y) + x) == 0) {
		sea[y][x] = 8;
		return 1;
	}	else if (*(*(sea + y) + x) == 1) {
		sea[y][x] = 6;
		return 0;
	}	else {
		return 3;
	}

}
bool normal_coordinates(int x,int y,int size)
{
	if (x < 1 || x > 10 || y < 1 || y > 10) {
		return false;
	}
	return true;
}

int** matrix ( int** sea,int N){
	int k = 4;

	for(int i = 0;i < k;i++) {
		
		for(int j = 0;j < k; j++) {
			sea[i][j] = 1;
		}
		k = k-1;
	}
	return sea;
}


int right_number_of_squares(int** sea,int size)
{
	int count = 0;
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
				if(sea[i][j] == 1) {
							count +=1;
				}
		}
	}
	return count;
}
