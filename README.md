# batlleship

This is the README file of Battleship game developed by me.

CONTENTS
        1. AUTHOR
        2. INTRODUCTION
        3. PREREQUISITES
        4. DIRECTORY STRUCTURE
        5. USAGE
        6. DOCUMENTATION

1. AUTHOR
Vahan Kalenteryan
E-mail: kalenteryan.vahan@gmail.com
Tel: +374-94-697277

Project Maintainer
	Instigate CJSC
	info@instigatedesign.com

2. INTRODUCTION
This project is a game called Battliship which is written in C++ and is intended to be used only for entertainment purposes. 
The game implements several basic features: 
1) Creation of game battlefield of 10x10 plates.
2) Gives you the opportunity to place vessels where you want by typing coordinates in the terminal - 1 Battleship of 4 squares, 1 Destroyer of 3 squares, 1 ship of 2 squares and 1 ship for one square
3) Providing a simple parameters based way of firing shots for the console application.
The game will end when all ships will be destroyed. 

3. PREREQUISITES
The following third party tools should be installed before the
compilation.

Tools:
g++
doxygen

1) Battleship game uses prerequisite tools which would be
executed in the current environment. I.e. it does this by searching the
PATH for executable files. So if the prerequisite tools are not installed in
standard paths in your system, make sure you have setup your environment
properly. I.e. PATH contains paths of prerequisite paths.

2) Build the project
	make

3) Generate doxygen documantation
	make doxygen

4) Delete the project
	make clean


4. DIRECTORY STRUCTURE

src/            - the source files of the project
docs/        	- the documentation of the project.
tests/          - the file for testing the source code
makefile        - top level makefile to build / run the project
docs/Doxyfile   - doxygen configuration for the documentation of the project


5. USAGE

After downloading the project open terminal in battlefild folder and enter "make" command. There will be created folder bin and obj. In obj will be object files of source code and in bin will be executable file with the help of which one car run the game. Go to the bin folder and type in terminal "./battleships.exe". After typing the command the game will start, it'll ask you to type coordinates for placing the ships. After finishing placement of ships (4 of them) the game will ask you to type coordinates for shooting untill you destroy all the ships. The game will be finished after destroying all the ships. In battleship folder you can also run "make doxygen" and doxygen documentation will be created in docs folder. Besides, in battleship folder you can run "make clean" command which will delete bin, obj folders and doxygen documentation.


6. DOCUMENTATION

Documentation for the project is in docs folder. One can also run "make doxygen" command which generates documentation from C/C++ code comments.
To see the generated documentation use ./docs/html/index.html.



