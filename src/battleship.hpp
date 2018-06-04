#pragma once

///the function must create the matrix by the given size and initialize it with 0_s
/**
 * @param N - Size of sea N*N
 **/
int** create_sea(int N);

///the function must show the sea;
/**
 * @param sea - sea which is generated...
 **/
void show_sea(int** sea, int N);

///the function must put a ship on the sea in horizontal possition
/**
 * @param startx - Rows
 * @param starty - Columns
 * @param length - Length of ship
 **/
int put_horizontal(int** sea, int startX, int startY, int lenght, int N);

///the function must put a ship on the sea in vertical possition
/**
 * @param startx - Rows
 * @param starty - Columns
 * @param length - Length of ship
 **/
int put_vertical(int** sea, int startX, int startY, int lenght, int N);

///the function shoots the ships
/**
 * @param startx - Rows
 * @param starty - Columns
 * @param length - Length of ship
 **/
int kill_ship(int** sea, int x, int y, int N);

///inputs the ships and starts the game
void input(int** sea);
void clean(int** sea,int N);
bool normal_coordinates(int x,int y,int size);

int** matrix (int** sea,int N);
int right_number_of_squares(int** sea,int size);